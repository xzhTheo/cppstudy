#include <iostream>
#include <stdio.h>
#include <queue>
#include <thread>


#ifdef __ANDROID__
	string port("/dev/ttyUSB1");
#elif __linux__
	#include <unistd.h>
    #include <mutex>
    #include <condition_variable>
#endif
using namespace std;
//https://www.zhihu.com/question/68017337/answer/796332672
//https://zhuanlan.zhihu.com/p/75220465
//https://www.zhihu.com/question/68017337/answer/796332672
template<typename T>
class MessageQueue
{
public:
    MessageQueue()
    {
        m_isrun = false;
    }
    int32_t push(const T& message)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_queue.push( message);
        m_condition.notify_one();
        return m_queue.size();
    }

    T pop(int32_t& size)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_condition.wait(lock, [this]
        {
            std::cout << "m_condition.wait" << std::endl;
            return (!m_queue.empty());

        });
        T message = m_queue.front();
        std::cout << "prepare pop" << std::endl;
        m_queue.pop();
        size = m_queue.size();
        return message;
    }

    void clear()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_isrun =  false;
        m_condition.notify_one();
    }
    void start()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_isrun = true;
    }
    void stop()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_isrun = false;
    }
    bool isrun()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_isrun;
    }

    void test()
    {
        m_condition.notify_one();
        m_condition.notify_one();
        m_condition.notify_one();
        m_queue.push(1);
        //m_condition.notify_one();
    }
private:
    bool                    m_isrun;
    std::queue<T>           m_queue;
    std::mutex              m_mutex;
    std::condition_variable m_condition;
};
MessageQueue<int>       mq_;

void producer()
{
    for (int i = 0; i < 100000; ++i)
    {
        mq_.push(i);
        //std::printf("producer push : %d\n", i);
        //std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}
void consumer1()
{
    while (1)
    {
        int size = 0;
        auto front = mq_.pop(size);
        //std::printf("consumer1 pop : %d\n", front);
    }
}
void consumer2()
{
    while (1)
    {
        int size = 0;
        auto front = mq_.pop(size);
        //std::printf("consumer2 pop : %d\n", front);
        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{

    //1. auto front = mq_.pop(size);  //程序会阻塞wait那一行，说明wait会阻塞等待，直到消息过来。

    std::thread t([]()
    {
        int size = 0;
        auto front = mq_.pop(size);  //程序不会阻塞
    });
    //2
    std::thread p([]()
    {

        mq_.test();

    });
    t.join();
    p.join();
    //当test为m_queue.push(1); + m_condition.notify_one();时，小概率出现下面打印，这是由于notify_one先到达，wait重新判断
    //m_condition.wait
    //m_condition.wait
    //prepare pop

    //std::thread th1(producer);
    // std::thread th2(consumer1);
    // std::thread th3(consumer2);
    // th1.join();
    // th2.join();
    // th3.join();



    return 0;
}
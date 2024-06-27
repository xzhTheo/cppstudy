#include <iostream> // std::cout
#include <deque>    // std::deque
#include <thread>   // std::thread
#include <chrono>   // std::chrono
#include <mutex>    // std::mutex

//参考：https://blog.csdn.net/qq_34827674/article/details/100180791
//通过锁来跑生产者消费者模型，当消费速度大于生产速度时
//消费者必定要通过while中轮询判断队列是否为空。5个消费者都在while中 if，这样会占用大量cpu
//可以选择让没抢到生产用品的消费者进行睡眠，来减少cpu消耗。
//但是仍然存在问题：睡眠时间不好选择，太短----仍会有无用功，  太长 ---- 生产者生产快时会产生减慢了数据处理速度
/*
    因此需要使用条件变量，解决了下问题：多个生产者不需要不断轮询，可以睡眠，这样就不会有时间损耗了等待生产者通知


*/

// 全局队列
std::deque<int> g_deque;

// 全局锁
std::mutex g_mutex;

// 生产者运行标记
bool producer_is_running = true;

// 生产者线程函数
void Producer()
{
    // 库存个数
    int count = 8;

    do
    {
        // 智能锁，初始化后即加锁，保护的范围是代码花括号内，花括号退出即会自动解锁
        // 可以手动解锁，从而控制互斥锁的细粒度
        std::unique_lock<std::mutex> locker( g_mutex );
        // 入队一个数据
        g_deque.push_front( count );
        // 提前解锁，缩小互斥锁的细粒度，只针对共享的队列数据进行同步保护
        locker.unlock();

        std::cout << "生产者    ：我现在库存有 :" << count << std::endl;

        // 放慢生产者生产速度，睡1秒
        std::this_thread::sleep_for( std::chrono::seconds( 1 ) );

        // 库存自减少
        count--;
    }
    while ( count > 0 );

    // 标记生产者打样了
    producer_is_running = false;

    std::cout << "生产者    ： 我的库存没有了，我要打样了！"  << std::endl;
}

// 消费者线程函数
void Consumer(int id)
{
    int data = 0;

    do
    {
        std::unique_lock<std::mutex> locker( g_mutex );

        if ( !g_deque.empty() )
        {
            data = g_deque.back();
            g_deque.pop_back();
            locker.unlock();

            std::cout << "消费者[" << id << "] : 我抢到货的编号是 :" << data << std::endl;
        }
        else
        {
            locker.unlock();
        }
    }
    while ( producer_is_running );

    std::cout << "消费者[" << id << "] ：卖家没有货打样了，真可惜，下次再来抢！"  << std::endl;
}

int main(void)
{
    std::cout << "1 producer start ..." << std::endl;
    std::thread producer( Producer );

    std::cout << "5 consumer start ..." << std::endl;
    std::thread consumer[ 5 ];

    for (int i = 0; i < 5; i++)
    {
        consumer[i] = std::thread(Consumer, i + 1);
    }

    producer.join();

    for (int i = 0; i < 5; i++)
    {
        consumer[i].join();
    }

    std::cout << "All threads joined." << std::endl;

    return 0;
}


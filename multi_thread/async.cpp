#include <future>
#include <iostream>
#include <thread>

/*
1. 只有当参数为std::launch::async时，函数才会异步执行。
2. 参数还可以是std::launch::deferred，参数为这个时，函数不会异步执行，只有当对应的future调用了get时，函数才会执行，而且是在当前线程执行。
3. 普通的future有个特点，它不能拷贝，只能移动，这就意味着只能有一个线程一个实例可以通过get()拿到对应的结果,如果想要多个线程多个实例拿到结果，就可以使用shared_future
和thread区别
1. std::thread直接创建线程，而std::async异步创建一个任务，这个任务可以创建新线程，也可以不创建线程，可以避免占用系统资源。
2. 由于std::async不一定会创建新线程，因此，当系统内存资源不足的时候，继续运行std::thread会使系统崩溃，而std::async此时不会创建新线程，避免了系统崩溃。
std::thread创建的线程不容易获取线程函数的返回值，std::async执行完返回一个std::future对象，可以很容易获取线程函数的返回值。
*/

int main()
{
    std::promise<int> prom;
    auto fu = prom.get_future();
    auto shared_fu = fu.share();
    auto f1 = std::async(std::launch::async, [shared_fu]()
    {
        std::cout << shared_fu.get() << std::endl;
    });
    auto f2 = std::async(std::launch::async, [shared_fu]()
    {
        std::cout << shared_fu.get() << std::endl;
    });
    prom.set_value(102);
    f1.get();
    f2.get();
}

#include <future>
#include <iostream>
#include <thread>

//通过promise可以拿到future
/*
    future有wait()和get()等方法，这两种方法会阻塞当前线程。
    get()方法会阻塞，直到future的源promise调用了set_value。
    wait()只有阻塞功能。

    注意：一个promise的set_value()只能调用一次，如果调用多次，就会throw exception，如果外部没catch exception，程序就会crash。
*/
int main()
{
    std::promise<int> prom;
    auto f = prom.get_future();
    std::thread t(
        [](std::promise<int> p)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        p.set_value(100);
    },
    std::move(prom));

    std::cout << f.get() << std::endl;

    if (t.joinable())
        t.join();
}
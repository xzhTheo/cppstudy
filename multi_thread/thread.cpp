// #include <future>
// #include <iostream>
// #include <thread>

// int main() {
// std::promise<int> prom;
// auto f = prom.get_future();
// std::thread t(
//    [](std::promise<int> p) {
//     std::this_thread::sleep_for(std::chrono::seconds(2));
//     p.set_value(100);
//    },
//    std::move(prom));

// std::thread p(
//     []()
//     {
//         long x = 0;
//         while(x < 10000000000)
//         {
//             //std::cout << x << std::endl;
//             x++;

//         }
//         std::cout << x << std::endl;
//     }
// );

// std::cout << f.get() << std::endl;
// if(t.joinable())
//     t.join();

// if(p.joinable())
//     p.join();
// }
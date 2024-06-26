#include <iostream>
//参考：https://blog.csdn.net/yanxiangtianji/article/details/21045525
//https://zhuanlan.zhihu.com/p/670867561



//①递归函数方式展开

// void FormatPrint()
// {
//     std::cout << std::endl;
// }
// template <class T, class ...Args>
// void FormatPrint(T first, Args... args)
// {
//     std::cout << "[" << first << "]";
//     //std::cout << sizeof...(args);
//     FormatPrint(args...);
// }


//②逗号表达式展开
template <class ...Args>
void FormatPrint(Args... args)
{
    //(void)std::initializer_list<int>{ (std::cout << "[" << args << "]", 0)... };
    std::vector<int> vec = std::vector<int> { (std::cout << "[" << args << "]", 0)... };

    for (auto x : vec)
    {
        std::cout << x;
    }

    std::cout << std::endl;
}

int main(void)
{
    FormatPrint(1, 2, 3, 4);
    FormatPrint("good", 2, "hello", 4, 110);

//  测试逗号表达式
    // std::cout << (std::cout << "33" ,2) << std::endl;
    return 0;
}
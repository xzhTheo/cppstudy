/*
通过std::variant<>，C++标准库提供了一种 可辨识的联合(closed discriminated union) （这意味着要指明一个可能的类型列表）

当前值的类型已知
可以持有任何类型的值
可以从它派生

参考：https://github.com/MeouSker77/Cpp17/blob/master/markdown/src/ch16.md
https://zhuanlan.zhihu.com/p/645810896

any和variant区别   https://blog.csdn.net/qq_21438461/article/details/132453206

any和void* 区别    https://wanghenshui.github.io/2020/11/24/std-any-void-star.html
https://www.cnblogs.com/gnivor/p/12793239.html

*/

#include <variant>
#include <iostream>
#include <any>

int main()
{
    std::variant<int, std::string> var{"hi"};   // 初始化为string选项
    std::cout << var.index() << '\n';           // 打印出1
    var = 42;                                   // 现在持有int选项
    std::cout << var.index() << '\n';           // 打印出0

    try
    {
        int i = std::get<0>(var);                   // 通过索引访问
        std::string s = std::get<std::string>(var); // 通过类型访问（这里会抛出异常）
    }
    catch (const std::bad_variant_access& e)        // 当索引/类型错误时进行处理
    {
        std::cerr << "EXCEPTION: " << e.what() << '\n';
    }


    // 方法一，创建一个std::any对象
    std::any data = std::make_any<int>(4);

    // 方法二，创建一个std::any对象
    // std::any data;
    // data = 4;

    // 可以对data进行任意类型的赋值
    data = "hello world";
    data = true;
    bool s = std::any_cast<bool>(data);

    std::cout << s << std::endl;

}
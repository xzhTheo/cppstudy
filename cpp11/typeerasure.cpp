#include <iostream>

struct Base
{
    virtual void foo() const = 0;
};

template <typename T>
struct Derived : public Base
{
    void foo() const override
    {
        std::cout << "Derived<" << typeid(T).name() << ">::foo()" << std::endl;
    }
};

void process(const Base& obj)
{
    obj.foo();  // 调用适当的派生类实现
}

int main()
{
    Derived<int> d1;
    Derived<double> d2;

    process(d1);  // 调用Derived<int>::foo()
    process(d2);  // 调用Derived<double>::foo()

    return 0;
}

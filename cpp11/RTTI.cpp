#include<string>
#include<iostream>
class SceneEntry
{
public:
    SceneEntry(unsigned long long id, const std::string& name) {};
    virtual ~SceneEntry() = default;
};

class SceneUser : public SceneEntry
{
public:
    SceneUser(unsigned long long id, const std::string& name): SceneEntry(id, name) {};
    virtual ~SceneUser() = default;
};


int main()
{
    //当 typeid 作用于指针时，会返回指针自身的类型，但当作用于派生类（有虚函数）的对象或引用时，则会返回这个对象实际的类型。
    SceneEntry* entry = new SceneUser(1, "xiaoming");
    SceneUser user(1, "");
    SceneEntry& entry2 = user;
    std::cout << typeid(entry).name() << std::endl;
    std::cout << typeid(*entry).name() << std::endl;
    std::cout << typeid(entry2).name() << std::endl;

    return 0;
}
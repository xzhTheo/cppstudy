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
    SceneEntry* entry = new SceneUser(1, "xiaoming");
    SceneUser user(1, "");
    SceneEntry& entry2 = user;
    std::cout << typeid(entry).name() << std::endl;
    std::cout << typeid(*entry).name() << std::endl;
    std::cout << typeid(entry2).name() << std::endl;

    return 0;
}
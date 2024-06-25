#include <map>


//在 C++98/03 中 ，typedef 重定义有一些限制，比如，模板。
//我们想实现这样一个模板：将一个 int 映射到任意类型，类似于我们想表达这种效果：
typedef std::map<int, int> map_int_t;
typedef std::map<int, std::string> map_str_t;
typedef std::map<int, bool> map_b_t;
//... Others

// 我们在 C++98/03 中必须这样写：
template<typename Val>
struct int_map{
    typedef std::map<int, Val> type;
};

//在C++11 中，我们可以使用 using 重定义模板
template<typename Val>
using int_map_t = std::map<int, Val>;


int main(){
    int_map_t<int> imap_t;
    int_map<int>::type imap;
    return 0;
}
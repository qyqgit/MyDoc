#include <iostream>
using namespace std;
namespace ns{
	int g_val;
}
namespace ns2{
	int g_val;
}
int main(){
	ns::g_val = 100;
	using namespace ns;//从该行代码开始ns名字空间中的内容在当前作用域可见
	
	std::cout << g_val << std::endl;
	std::cout << ns::g_val << std::endl;
	using ns::g_val;//从这行代码开始将ns::g_val引入当前作用域
	g_val = 99;
	cout << ns::g_val << endl;
	//using ns2::g_val;
	//cout << ns::g_val << "," << ns2::g_val <<endl;
	return 0;
}

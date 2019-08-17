#include <iostream>
namespace icbc{
	int g_val = 0;
	void save(int money){
		g_val += money;
	}
	void pay(int money){
		g_val -= money; 
	}
}
namespace ccb{
	int g_val = 0;
	void save(int money){
		g_val += money;
	}
	void pay(int money){
		g_val -= money; 
	}
}
int main(){
	icbc::save(100);
	icbc::pay(50);
	std::cout << icbc::g_val << std::endl;
	ccb::save(100);
	ccb::pay(150);
	std::cout << ccb::g_val << std::endl;
	return 0;
}

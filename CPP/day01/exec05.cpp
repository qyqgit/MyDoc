#include <iostream>
using namespace std;
namespace ns1{
	int g_val;
	namespace ns2{
		int g_val;
		namespace ns3{
			int g_val;
		}
	}
}
int main(){
	ns1::ns2::ns3::g_val = 100;
	cout << ns1::ns2::ns3::g_val << endl;
	namespace ns_three = ns1::ns2::ns3;
	cout << ns_three::g_val << endl;
	return 0;
}

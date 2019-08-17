#include <iostream>
namespace network{
	void recv(){
		std::cout << "recv data end." << std::endl;
	}
	void send(){
		std::cout << "send data end." << std::endl;	
	}
}
namespace compress{
	void zip(){
		std::cout << "zip data end." << std::endl;
	}
	void unzip(){
		std::cout << "unzip data end." << std::endl;
	}
}
namespace entrypt{
	void encode(){
		std::cout << "encode data end." << std::endl;
	}
	void decode(){
		std::cout << "decode data end." << std::endl;
	}
}
int main(void){
	network::recv();
	compress::unzip();
	entrypt::decode();
	entrypt::encode();
	compress::zip();
	network::send();
	return 0;
}

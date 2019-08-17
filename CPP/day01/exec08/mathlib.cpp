extern "C" int add(int a, int b) {return a + b;}
extern "C" int sub(int a, int b) {return a - b;}

extern "C" {
	extern "C" int add1(int a, int b) {return a + b;}
	extern "C" int sub1(int a, int b) {return a - b;}

}

#include "com.h"
void main(void){
	//关闭时钟
	UARTCLKENB0 &= ~(1 << 2);
	//工作参数配置为：8n1,轮询方式
	ULCON0 &= ~(0xFFFFFFFF);
	ULCON0 |= 3;
	UCON0 |= 5;
	
	//set uart gen clock 10mhz
	//800mhz / 80 = 10mhz
	//n + 1 = 80
	//n = 79
	UARTCLKGEN0L &= ~(0xFF << 5);
	UARTCLKGEN0L |= (79 << 5);

	//set uart bps 115200
	//UBRDIV0+UFRACVAL0/16=（10000000)/(115200*16)-1
	UBRDIV0 = 4;
	//UFRACVAL0/16= 0.7
	UFRACVAL0 = 11;

	GPIODALTFN0 &= ~(3 << 28);
	GPIODALTFN0 |= (1 << 28);
	GPIODALTFN1 &= ~(3 << 4);
	GPIODALTFN1 |= (1 << 4);

	//使能UART时钟
	UARTCLKENB0 |= (1 << 2);

}

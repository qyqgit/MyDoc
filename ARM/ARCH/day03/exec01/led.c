#include "led.h"

/*定义入口函数*/
void led_test(void)
{
    /*1.初始化LED*/
    led_init();

    /*2.循环开关灯*/
    while(1) {
        led_on();
        delay(0x1000000);
        led_off();
        delay(0x1000000);
    }
}

/*定义初始化函数*/
void led_init(void)
{
    //1.四选一
    GPIOCALTFN0 &= ~(3 << 24);
    GPIOCALTFN0 |= (1 << 24);

    GPIOBALTFN1 &= ~(3 << 20);
    GPIOBALTFN1 |= (1 << 20);

    //2.二选一
    GPIOCOUTENB |= (1 << 12);
    GPIOCOUTENB |= (1 << 7);
    GPIOCOUTENB |= (1 << 11);
    GPIOBOUTENB |= (1 << 26);

    GPIOCOUTENB |= (1 << 14);
    //3.关灯(省电)
    GPIOCOUT |= (1 << 12);
    GPIOCOUT |= (1 << 7);
    GPIOCOUT |= (1 << 11);
    GPIOBOUT |= (1 << 26);

    GPIOCOUT |= (1 << 14);
}

/*定义开灯函数*/
void led_on(void)
{
    GPIOCOUT &= ~(1 << 12);
    delay(0x1000000);
    GPIOCOUT &= ~(1 << 7);
    delay(0x1000000);
    GPIOCOUT &= ~(1 << 11);
    delay(0x1000000);
    GPIOBOUT &= ~(1 << 26);
    delay(0x1000000);
}

/*定义关灯函数*/
void led_off(void)
{
    GPIOCOUT |= (1 << 12);
    delay(0x1000000);
    GPIOCOUT |= (1 << 7);
    delay(0x1000000);
    GPIOCOUT |= (1 << 11);
    delay(0x1000000);
    GPIOBOUT |= (1 << 26);
    delay(0x1000000);
}

/*定义延时函数*/
void delay(int n)
{
    int i = n;
    for(; i != 0; i--); //CPU原地空转n次
}


















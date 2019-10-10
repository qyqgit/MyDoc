#ifndef __LED_H
#define __LED_H

/*寄存器地址定义*/
#define GPIOCOUT    (*(unsigned long *)0xC001C000)
#define GPIOCOUTENB (*(unsigned long *)0xC001C004)
#define GPIOCALTFN0 (*(unsigned long *)0xC001C020)

#define GPIOBOUT    (*(unsigned long *)0xC001B000)
#define GPIOBOUTENB (*(unsigned long *)0xC001B004)
#define GPIOBALTFN0 (*(unsigned long *)0xC001B020)
#define GPIOBALTFN1 (*(unsigned long *)0xC001B024)
/*函数操作函数*/
extern void led_init(void);
extern void led_on(void);
extern void led_off(void);
extern void delay(int n);
#endif

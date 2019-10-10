#ifndef __COM_H__
#define __COM_H__

#define UARTCLKENB0     (*(unsigned long *)0xC00A9000)
#define ULCON0          (*(unsigned long *)0xC00A1000)
#define UCON0           (*(unsigned long *)0xC00A1004)
#define UARTCLKGEN0L    (*(unsigned long *)0xC00A9004)
#define UBRDIV0         (*(unsigned long *)0xC00A1028)
#define UFRACVAL0       (*(unsigned long *)0xC00A102C)
#define GPIODALTFN0     (*(unsigned long *)0xC001D020)
#define GPIODALTFN1     (*(unsigned long *)0xC001D024)

#endif

#ifndef __LED_H
#define __LED_H

#ifdef __cplusplus
extern "C" {
#endif

/*头文件*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <pthread.h>

/*调试宏*/
#define DEBUG

#ifdef DEBUG
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define pr_debug(fmt, ...) 
#endif

/*设备文件名*/
#define EMOTOR_DEVFILE_NAME	"/dev/emotor"

#define EMOTOR_FORWARD_A       (0X100001)
#define EMOTOR_FORWARD_B       (0X100002)
#define EMOTOR_OFF_A           (0X100003)
#define EMOTOR_OFF_B           (0X100004)
#define EMOTOR_ENABLE_A        (0X100005)
#define EMOTOR_ENABLE_B        (0X100006)
#define EMOTOR_DISABLE_A       (0X100007)
#define EMOTOR_DISABLE_B       (0X100008)
#define EMOTOR_BACKWARD_A      (0X100009)
#define EMOTOR_BACKWARD_B      (0X100010)

#define CAR_FORWARD     (1)
#define CAR_BACK        (2)
#define CAR_LEFT        (3)
#define CAR_RIGHT       (4)
#define CAR_STOP        (5)

extern int emotor_open(void);
extern void emotor_close(void);
extern int emotor_control_direction(int direction);
extern void emotor_control_speed(int speed);
extern int emotor_pwm_task(void);

#ifdef __cplusplus
}
#endif

#endif

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    char arr[10][10] = {0};//坐标对应数
    int x = 0,y = 0;// 点开的坐标
    int x1 = 0,y1 = 0;//雷在的坐标
    int xx = 0,yy = 0;//版面坐标
    int i = 0;//放置雷次数循环变量
    int a = 10;//如果雷重复循环变量
    srand(time(0));
    for(i = 0;i <= a;i++)
    {
        if( arr[rand()%10][rand()%10] !=1)
        {
            arr[rand()%10][rand()%10] = 1;
        }
        else
        {
            a = a++;
        }    
    }
    while(arr[x-1][y-1] !=1)
    {    
        printf("请输入要点击的坐标");
        scanf("%d%d",&x,&y);
    

        for(xx=0;xx<10;xx++)
        {
            for(yy=0;yy<10;yy++)
            {
                if(arr[x-1][y-1] == arr[xx][yy] && arr[xx][yy] ==1)
                {
                    printf("X");
                }
                else if(arr[x-1][y-1] ==0)
                {
                    arr[x-1][y-1] = '#';
                    printf("%c",arr[x-1][y-1]);    
                }    
                else
                {
                printf("*");
                }
        
            }
            printf("\n");
    
        }
        for(xx=0;xx<10;xx++)
        {
            for(yy=0;yy<10;yy++)
            {
                if(arr[x-1][y-1]==arr[xx][yy]||arr[xx][yy]==1)
                {
                printf("%d",arr[x-1][y-1]);
                }
        
            }
            printf("\n");
    
        }
    }        
        if(arr[x-1][y-1]==x)
        {
        printf("游戏结束");
        }    
    
    return 0;
}

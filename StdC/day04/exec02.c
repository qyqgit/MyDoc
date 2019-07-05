#include<stdio.h>
#include<math.h>
int main(){
     int a = 54321; 
     for(int i = 0; i < 5; i++){
          printf("%d\n",a / (int)pow(10, i));
     }
 }      

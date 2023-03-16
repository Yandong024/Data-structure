/*
打印 0-N 个数字
方法1:循环打印
方法2:递归打印
目的：使用不用的方法，记录打印的时间
*/

#include <stdio.h>

// 方法1:循环打印
void printN_1(int N){
  int i;
  for ( i = 0; i <= N; i++)
  {
    printf("%d\n", i);
  }
  return;
  

}

// 方法2:递归打印
void printN_2(int N){
  if (N)
  {
    printN_2(N-1);
    printf("%d\n",N);
  }
  else
  {
    printf("%d\n",N);
  }
  return;
  
}


// 主函数入口
int main(){
  int num=3;   //修改num的数值
  printN_2(num);
  return 0;

}
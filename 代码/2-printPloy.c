/*
打印多项式
f(x) = x^1+2x^2+3x^3+...
方法1:循环相加
方法2:提取公因式
目的：算法的效率和算法的巧妙程度有关
*/

#include<stdio.h>
#include<math.h>
#include<time.h>

#define MAXN 1000
#define NUM 100000

//函数声明
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);

//主函数
int main(){
  //（1）多项式的系数
  int i=0;
  double a[MAXN];
  for ( i = 0; i < MAXN; i++)
  {
    a[i] = (double) i;
  }

  // (2) 调用 f1 计算多项式并打印计算时间
  clock_t start = clock();
  double result_1 = 0;
  for (int i = 0; i < NUM ; i++)
  {
    result_1 = f1(MAXN-1, a, 1.1); //x=1.1处的结果 
  }
  clock_t stop = clock();
  printf("方法1的计算结果：%.3f, 用时：%.10f s\n", result_1, ((double)(stop-start))/CLOCKS_PER_SEC/NUM);

  // (3) 调用 f2 计算多项式并打印计算时间
  start = clock();
  double result_2 = 0;
  for (int i = 0; i < NUM ; i++)
  {
    result_2 = f2(MAXN-1, a, 1.1); //x=1.1处的结果 
  }
  stop = clock();
  printf("方法2的计算结果：%.3f, 用时：%.10f s\n", result_2, ((double)(stop-start))/CLOCKS_PER_SEC/NUM);
  return 0;
}

// 方法1:循环相加
double f1(int n, double a[], double x){
  double result = a[0];
  for (int i = 1; i <= n; i++)
  {
    result += (a[i]*pow(x, i));
  }
  return result;
}

// 方法2:提取公因式
double f2(int n, double a[], double x){
  double result = a[n];
  for (int i = n; i > 0; i--)
  {
    result = a[i-1]+x*result;
  }
  return result;
  
}

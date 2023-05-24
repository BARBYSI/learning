#include <stdio.h>
int main(void)
{
  int c = 5, d;
  double a = 5, b;
  printf("b=");
  scanf("%lf", &b);
  printf("%lf\n", b);
  a=a+b-2;
  printf("a = a + b - 2 : a=%lf b=%lf\n", a, b);
  printf("d=");
  scanf("%d", &d);
  c=c+1, d=c-a+d;
  printf("c=c+1, d=c-a+d : c=%d, d=%d, a=%lf\n", c, d, a);
  a=a*c, c=c-1;
  printf("a=a*c, c=c-1 : a=%lf, c=%d\n", a, c);
  a=a/10, c=c/2, b=b-1, d=d*(c+b+a);
  printf("a=a/10, c=c/2, b=b-1, d=d*(c+b+a) : a=%lf b=%lf, c=%d, d=%d\n", a, b, c, d);
}
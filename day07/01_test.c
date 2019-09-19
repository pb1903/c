#include <stdio.h>
int my_add(int x,int y);
int my_sub(int x,int y);
int my_calc(int data1,int data2,int (*func)(int,int));
void test01()
{
    int (*p)(int,int) = NULL;
    p = my_add;
    //printf("%d\n",my_add(10,20));
    printf("%d\n",p(10,20));
}
void test02()
{
    printf("%d\n",my_calc(10,20,my_add));
    printf("%d\n",my_calc(10,20,my_sub));
}

int main(int argc, char const *argv[])
{
    test02();
    return 0;
}
int my_add(int x,int y)
{
    return x + y;
}
int my_sub(int x,int y)
{
    return x - y;
}
int my_calc(int data1,int data2,int (*func)(int,int))
{
    return func(data1,data2,func);
}
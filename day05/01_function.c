#include <stdio.h>
int my_add(int x,int y);
void test01()
{
    int a = 10,b = 20;
    int ret = my_add(a,b);
    printf("ret = %d\n",ret); 
}
int my_add(int x,int y)
    {
        return x+y;
    }
int main(int argc, char const *argv[])
{
    test01();
    return 0;
}

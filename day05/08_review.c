#include <stdio.h>
void test01()
{
    int num = 10;
    printf("&num = %p\n",&num);
    int *p;
    printf("sizeof(p) = %d\n",sizeof(p));
    p = &num;
    printf("p = %p\n",p);
    printf("&num = %p\n",&num);
}
void test02()
{
    int num = 10;
    int *p;
    p = &num;
    printf("%d\n",*p); //10
    *p = 100;
    printf("%d\n",num);  //100
    scanf("%d",p);  //若输入2000
    printf("%d\n",num); //输出2000
}
void test03()
{
    int num = 0x01020304;
    short *p;
    p = &num;
    p = p + 1;
    printf("%#x\n",*p);
    char *p2;
    p2 = &num;
    p2 = p2+3;
    printf("%#x\n",*p2);
    char *p3;
    p3 = &num;
    p3 = p3 + 1;
    printf("%#x\n",*(short *)p3);
}
int main(int argc, char const *argv[])
{
    test03();
    return 0;
}

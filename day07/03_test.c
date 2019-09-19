#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test01()
{
    printf("%d\n",atoi("123"));// "" 内为字母时？
    printf("%ld\n",atol("123"));
    printf("%f\n",atof("3.14"));
}
void test02()
{
    char str[] = "hehe haha";//注意！定义字符串时记得加[]!
    char str2[30] = "";
    strcpy(str2,str);
    printf("%s\n",str2);
}
int main(int argc, char const *argv[])
{
    test02();
    return 0;
}

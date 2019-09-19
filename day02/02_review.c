#include <stdio.h>
void test01()
{
    printf("sizeof(char) = %d\n",sizeof(char));
    printf("sizeof(short) = %d\n",sizeof(short));
    printf("sizeof(int) = %d\n",sizeof(int));
    printf("sizeof(long) = %d\n",sizeof(long));
    printf("sizeof(float) = %d\n",sizeof(float));
    printf("sizeof(double = %d\n)",sizeof(double));
}
void test02()
{
    signed int num1 = -10;
    int num2 = -20;
    unsigned int num3 = 100;
}
void test03()
{
    int num = 100;
    printf("八进制输出：%#o\n",num);
    printf("十进制输出：%d\n",num);
    printf("十六进制输出：%#x\n",num);
}

void test04()
{
    char data = -10;
    printf("data = %#x\n",data);
    printf("data = %d\n",data);
}

void test05()
{
    char data = 0x34;
    printf("data = %#x\n",data);
    char data2 = 0xb4;
    printf("data2 = %#x\n",data2);
    printf("data2 = %d\n",data2);

}

int main(int argc, char const *argv[])
{
    test05();
    return 0;
}


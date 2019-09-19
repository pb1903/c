#include <stdio.h>
void test01()
{
    //将 num的1, 3 ,5位清0, 2, 4 , 6 位置1
    //令 num 为 1100 0011    1101 0101 0xd5
    unsigned char num = 0xc3;
    //num = num & 1101 0101 | 0101 0100
    //1101 0101 == ~(0010 1010) == ~(0010 0000 | 0000 1000 | 0000 0010)
    //1101 0101 == ~(0x01<<5 | 0x01<<3 | 0x01<<1)
    //0101 0100 == (0100 0000 | 0001 0000 | 0000 0100)
    //0101 0100 == (0x01<<6 | 0x01<<4 | 0x01<<2)
    num = num & ~(0x01<<5 | 0x01<<3 | 0x01<<1) | (0x01<<6 | 0x01<<4 | 0x01<<2);
    printf("%#x\n",num);
}
void test02()
{
    printf("\\r\n"); // \r
    printf("%%%d\n",50); //%50
    //八进制转义 \hhh 每个h0~7
    printf("%d\n",'\123');
    printf("%d\n",'\129');
    printf("%d\n",'\1234');
    //十六进制转义 \xhh 每个h0~9a~f
    printf("%d\n",'\x12');//18
    printf("%d\n",'\xaf');//-81
}
int main(int argc, char const *argv[])
{ 
    test01();
    return 0;
}

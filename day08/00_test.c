#include <stdio.h>
void test01()
{
    int data2 = 0;
    int data3 = 0;
    char buf[32] = "";
    char buf2[32] = "";
    /* 
    sscanf("12345678","%*2s%2d%*2s%s",&data2,buf);
    printf("data2 = %d\n",data2);//34
    printf("buf = %s\n",buf);//"78"
    */
    //sscanf("12345 5678","1234%d",&data3);
    sscanf("12345 5678","1234 %d",&data3); //？空格识别有问题？
    printf("data3 = %d\n",data3);
}
void test02()
{
    char buf5[32] = "";
    char buf6[32] = "";
    //sscanf("lianghe@1000phone.cn","%[^@]%*1s%[^.]",buf5,buf6);
    //sscanf("lianghe@1000phone.cn","%[a-z]%*[@]%[^.]",buf5,buf6);
    sscanf("lianghe@1000phone.cn","%[^@]%*[@]%[^.]",buf5,buf6);
    printf("buf5 = %s\n",buf5);//"lianghe"
    printf("buf6 = %s\n",buf6);//"1000phhone"
}
int main(int argc, char const *argv[])
{
    test01();
    return 0;
}

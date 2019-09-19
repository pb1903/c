#include <stdio.h>
void test01()
{
    char ch = 0;
    printf("请输入一个小写字母：");
    scanf("%c",&ch);
    ch = ch - 32;
    //h = ch - ('a'-'A');
    printf("转换为大写字母为：%c\n",ch); 

   /*  char ch = 0;
    printf("请输入一个大写字母：");
    scanf("%c",&ch);
    ch = ch + 32;
    //ch = ch + ('a'-'A');
    printf("转换为小写字母为：%c\n",ch);*/
    
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}

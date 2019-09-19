#include <stdio.h>
void test01()
{
    //输入字符串，将其中的 大小写字母相互转换
    char str[128] = "";
    printf("请输入字符串：\n");
    fgets(str,sizeof(str),stdin);
    //printf("输出：\n##%s##",str);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
        i++;
    }
    printf("转换后为：\n%s",str);
}
int main(int argc, char const *argv[])
{
    test01();
    return 0;
}

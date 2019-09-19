#include <stdio.h>
test01()
{
    double score = 0;
    printf("请输入int类型数据：");
    scanf("%lf",&score);
    if (score < 0 || score > 100)
    {
        printf("输入有误");
    }
    else if (score >= 90)
    {
        printf("A\n");
    }
    else if (score >= 80)
    {
        printf("B\n");
    }
    else if (score >= 70)
    {
        printf("C\n");
    }
    else if (score >= 60)
    {
        printf("D\n");
    }
    else if (score < 60)
    {
        printf("E 不合格\n");
    }
    
}
int main(int argc, char const *argv[])
{
    test01();
    return 0;
}

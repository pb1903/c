#include <stdio.h>

void test01()
{
    int num1 = 0,num2 = 0;
    printf("请输入两个数字:num1 num2:");
    scanf("%d %d",&num1,&num2);
    if(num1-num2>0)
    {
        printf("%d大于%d\n",num1,num2);
    }else if(num1-num2==0){
        printf("%d等于%d\n",num1,num2);
    }else{
        printf("%d小于%d\n",num1,num2);
    }
}

void test02()
{
    int num1=0,num2=0;
    printf("请输入两个数字：");
    scanf("%d %d",&num1,&num2);
    printf("%d",num1>num2?num1:num2);
}

void test03()
{
    int data1=0,data2=0;
    printf("请输出两个int数据：");
    scanf("%d %d",&data1,&data2);
    printf("最大值为:%d\n",data1>data2 ? data1:data2);
    printf("最小值为:%d\n",data1<data2 ? data1:data2);

}

void test04()
{
    int num = 0;
    printf("请输入一个int类型数据：");
    scanf("%d",&num);
    if(num>=0 && num<=9)
    {
        printf("在\n");
    }else
    {
        printf("不在\n");
    }
}

int main(int argc, char const *argv[])
{
    test04();
    return 0;
}

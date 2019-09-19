#include <stdio.h>
struct stu
{
    int num;
    char name[32];
    int age;
};

void test01()
{
    struct stu arr[5];
    int n = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
    printf("请输入%d个学生信息num name age:\n",n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d %s %d",&arr[i].num,arr[i].name,&arr[i].age);
    }
    i = 0;
    int sum = 0;
    for ( i = 0; i < n; i++)
    {
        sum += arr[i].age;
    }
    printf("平均年龄%d\n",sum/n);  
}
int main(int argc, char const *argv[])
{
    test01();
    return 0;
}

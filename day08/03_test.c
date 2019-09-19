#include <stdio.h>
#include <stdlib.h>
STU * mygetArray(int n);
void MyInputArray(STU *arr,int n);
void MyPrintfArray(STU *arr,int n);
typedef struct stu
{
    int num;
    char name[32];
    float score;
}STU;
STU * mygetArray(int n)
{
    return (STU *)calloc(n,sizeof(STU));
}
void MyInputArray(STU *arr,int n)
{
    int i = 0;
    for ( i = 0; i < n; i++)
    {
        printf("请输入第%d个学生的信息：num name age",n);
        scanf("%d %s %d",&STU *->num,STU *->name,&STU *->age);
    }
}
void MyPrintfArray(STU *arr,int n)
{
    int i = 0;
    for ( i = 0; i < n; i++)
    {
        printf("%d %s %d\n",STU *->num,STU *->name,STU *->age)；
    }   
}
void test01()
{
    STU *arr = NULL;
    int n = 0;
    printf("请输入学生个数：");
    scanf("%d",&n);
    arr = mygetArray(n);
    myInputArray(arr,n);
    myPrintfArray(arr,n);
    if (arr != NULL)
    {
        free(arr);
        STU *arr = NULL;
    }
    
}
int main(int argc, char const *argv[])
{
    test01();
    return 0;
}

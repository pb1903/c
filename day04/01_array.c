#include <stdio.h>
//元素逆置
void test01()
{
    int arr[10] = {0};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("请输入%d个int型数据：",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 0,j=n-1; i<j; i++,j--)
    {
        int tmp = 0;
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");  
}
//求平均数
void test02()
{
    int arr[10] = {0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    printf("请输入%d个int型数据：",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    printf("平均数为：%d",sum/n);
    printf("\n");
    
}
int main(int argc, char const *argv[])
{
    test02();
    return 0;
}

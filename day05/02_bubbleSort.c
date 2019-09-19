#include <stdio.h>
//函数的声明
void myInputIntArray(int arr[],int n);
void myOutputIntArray(int arr[],int n);
void mySortIntArray(int arr[],int n);
int main(int argc, char const *argv[])
{
    int arr[10] = {0};//数组的定义
    int n = sizeof(arr)/sizeof(arr[0]);//数组中元素的个数
    myInputIntArray(arr,n);//获取数组
    mySortIntArray(arr,n);//排序
    printf("排序后为：\n");
    myOutputIntArray(arr,n);//输出
    return 0;
}
//从键盘获取数组
void myInputIntArray(int arr[],int n)
{
    printf("请输入%d个int型数据：\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    return;
}
//遍历数组
void myOutputIntArray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return;
}
//数组的冒泡排序
void mySortIntArray(int arr[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            } 
        }
    } 
    return;
}

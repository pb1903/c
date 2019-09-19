#include <stdio.h>
void mySetInt(int *p);
void myPrintfIntArray(int *arr,int n);
void myInIntArray(int *arr,int n);
void test01()
{
    int data = 0;
    printf("%d\n",data);
    mySetInt(&data);
    printf("%d\n",data);
}
void test02()
{
    int arr[5] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",n);
    myPrintfIntArray(arr,n);
    myInIntArray(arr,n);
    myPrintfIntArray(arr,n);
}
int main(int argc, char const *argv[])
{
    test02();
    return 0;
}
void mySetInt(int *p)
{
    *p = 1000;
    return;
}
void myPrintfIntArray(int *arr,int n)
{
    int i = 0;
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void myInIntArray(int *arr,int n)
{
    int i = 0;
    for ( i = 0; i < n; i++)
    {
        scanf("%d",arr + i);
    }
    
}
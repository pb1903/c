#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[10] = {0};
    int n = sizeof(arr)/sizeof(arr[0]);
    //输入
    printf("请输入%d个int元素：\n",n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    //选择排序
    int j = 0,min = 0;
    for ( i = 0; i < n - 1; i++)
    {
        for (j = i+1, min = i; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;  //记录下标
            }
        }
        if (i != min)
        {
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }

    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

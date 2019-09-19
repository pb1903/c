#include <stdio.h>
void my_Input(int arr[], int n);
void my_Output(int arr[], int n);
void sort_bul(int arr[], int n);
void sort_cic(int arr[], int n);

int main(int argc, char const *argv[])
{
    int n = 0;
    printf("请输入元素的个数：\n");
    scanf("%d", &n);
    int arr[n];
    
    //冒泡排序
    my_Input(arr, n);
    sort_bul(arr, n);
    my_Output(arr, n);
    //选择排序
    my_Input(arr, n);
    sort_cic(arr, n);
    my_Output(arr, n);

    return 0;
}

//输入
void my_Input(int arr[], int n)
{
    printf("请输入%d个元素：\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    return;
}

//输出
void my_Output(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

//冒泡排序
void sort_bul(int arr[], int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = 0;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    return;
}

//选择排序
void sort_cic(int arr[], int n)
{
    int i = 0;
    for (i = 0; i < n - 1; i++)
    {
        int j = 0, min = 0;
        for (j = i + 1, min = i; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (i != min)
        {
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
    return;
}
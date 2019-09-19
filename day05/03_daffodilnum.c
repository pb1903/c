#include <stdio.h>
int test_shui(int data);
/* test01()
{
    int x=0,y=0,z=0;
    int arr[1000] = {0};
    int num[100] = {0};
    for (int i = 0; i < 1000; i++)
    {
        x=arr[i]/100;
        y=arr[i]%100;
        z=arr[i]%10;
        if (arr[i] == x*x*x+y*y*y+z*z*z)
        {
            num = arr[i];
        }
    }
    printf("num = %d\n",num); 
} */

void test02()
{
    for (int i = 0; i < 1000; i++)
    {
        int num = test_shui(i);
        if (num != -1)
        {
             printf("%d ",num);
        }     
    }  
    printf("\n");
}
int test_shui(int data)
{
    int x=0,y=0,z=0;
    x = data/100;
    y = data%100/10;
    z = data%10;
    if (data == (x*x*x + y*y*y + z*z*z))
    {
        return data;
    }
    else
    {
        return -1;
    }
    return -1;  
}
int main(int argc, char const *argv[])
{
    test02();
    return 0;
}


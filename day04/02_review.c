#include <stdio.h>
void test01()
{
    //二维数组的遍历
   int arr[3][4];
   int row = sizeof(arr)/sizeof(arr[0]);
   int col = sizeof(arr[0])/sizeof(arr[0][0]);

   for (int i = 0; i < row; i++)
   {
       for (int j = 0; j < col; j++)
            {
                printf("%d ",arr[i][j]);
            }
        printf("\n");
   }
}
void test02()
{
    //二维数组的初始化
    int arr[3][4] = { {1,2,3,4} , {5,6,7,8} , {9,10,11,12} }; //分段初始化
    //int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 }; //连续初始化
    //int arr[3][4] = {{1,2},{3},{4,5}}; //综合案例
    //int arr[3][4] = {1,2,3,4,5}; //综合案例
    int row = sizeof(arr)/sizeof(arr[0]);
    int col = sizeof(arr[0])/sizeof(arr[0][0]);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            {
                printf("%d ",arr[i][j]);
            }
        printf("\n");
    }   
}
test03()
{
    int arr[5][3] = {0};
    int row = sizeof(arr)/sizeof(arr[0]);
    int col = sizeof(arr[0])/sizeof(arr[0][0]);
    for (int i = 0; i < row; i++)
    {
        //获取键盘输入
        printf("请输入第%d个学生的 语 数 外 成绩：\n",i+1);
        for (int j = 0; j < col; j++)
            {
                scanf("%d",&arr[i][j]);
            }
    }
    //求个人的平均成绩
    int avg[5] = {0};
    for (int i = 0; i < row; i++)
    {   
        int sum = 0;
        for (int j = 0; j < col; j++)
            {
                sum += arr[i][j]; //sum = sum + arr[i][j]
            }
        avg[i] = sum/col;
    }
    //求各学科平均成绩
    int avg2[3] = {0};
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
            {
                sum += arr[j][i];//sum = sum + arr[j][i]
            }
        avg2[i] = sum/row;
    }
    //输出平均成绩
    printf("————个人的平均成绩————\n");
    for (int i = 0; i < row; i++)
    {
        printf("%d ",avg[i]);
    }
    printf("\n");
    printf("————各学科的平均成绩————\n");
    for (int i = 0; i < col; i++)
    {
        printf("%d ",avg2[i]);
    } 
    printf("\n");
}
void test04()
{
    //键盘输入 1~7 ，打印 周一 ~ 周日
    int num = 0;
    printf("请输入数字1~7中的一个：");
    scanf("%d",&num);
    switch (num)
    {
    case 1:
        printf("周一\n");
        break;
    case 2:
        printf("周二\n");
        break;
    case 3:
        printf("周三\n");
        break;
    case 4:
        printf("周四\n");
        break;
    case 5:
        printf("周五\n");
        break;
    case 6:
        printf("周六\n");
        break;
    case 7:
        printf("周日\n");
        break;
    }
}
void test05()
{
    //合理省略 break 的案例
    char ch = 0;
    printf("请输入方向键：%c",ch);
    //scanf("%c",&ch);
    ch = getchar();
    getchar();//去掉回车
    switch (ch)
    {
    case 'w':
    case 'W':
        printf("向上\n");
        break;
    case 'a':
    case 'A':
        printf("向左\n");
        break;
    case 's':
    case 'S':
        printf("向下\n");
        break;
    case 'd':
    case 'D':
        printf("向右\n");
        break;
    default:
        printf("输入有误");
        break;
    }
}
void test06()
{
    char ch = 0;
    printf("请输入一个小写字母：");
    scanf("%c",&ch);
    printf("ch = %c\n",ch);
    //核心是获取一个字符
    getchar();//去掉回车

    char ch2 = 0;
    printf("请输入一个小写字母：");
    //ch2 = getchar(); 用getchar()获取该字母
    scanf("%c",&ch2);
    printf("ch2 = ##%c##\n",ch2);// # 在验证是否输出了回车时可以使用
}
int main(int argc, char const *argv[])
{
    test06();
    return 0;
}

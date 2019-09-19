#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <termios.h>
#include <unistd.h>
#define N 50
char mygetch();
void test01()
{
    char src[N] = "";
    char any = 0;
    any = mygetch();
    int start_time = 0,end_time = 0;
    srand(time(NULL));
    if (any != NULL)
    {
        for (int i = 0; i < N - 1; i++)
        {
            src[i] = rand()%26 + 'a';
        }
    printf("%s\n",src);
    }
    int j = 0;
    for (int i = 0; i < N - 1; i++)
    {
        char ch = mygetch();
        if (i == 0)
        {
            start_time = time(NULL);
        }
        if (ch == src[i])
        {
            printf("%c",ch);
            j++;
        }
        else
        {
            printf("_");
        }   
    }
    char next = mygetch();
   
    while (next = )
    {
        /* code */
    }
    
    printf("\n");
    double s = (double)j/(N-1);
    end_time = time(NULL);
    printf("准确率为：%.2f%%\n",s*100);
    printf("用时：%d秒\n",end_time - start_time);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
char mygetch()
    {
    struct termios oldt, newt;
    char ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
    }
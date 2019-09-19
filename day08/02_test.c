#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int num;
    char name[32];
    float score;
}STU;

void test01()
{
    STU *p = NULL;
    p = (STU *)calloc(1,sizeof(STU));
    printf("请输入num name score:");
    scanf("%d %s %f",&p->num,p->name,&p->score);
    printf("%d %s %f",p->num,p->name,p->score);
    if(p != NULL)
    {
        free(p);
        p = NULL;
    }

}
int main(int argc, char const *argv[])
{
    test01();
    return 0;
}

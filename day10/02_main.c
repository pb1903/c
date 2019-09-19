#include <stdio.h>
#include <stdlib.h>


typedef struct stu
{
    int num;
    char name[32];
    float score;
    struct stu *pre;
    struct stu *next;
}STU;



int main(int argc, char const *argv[])
{
    STU *head = NULL;
    STU tmp;
    
    scanf("%d %s %f",&tmp.num,tmp.name,&tmp.score);
    return 0;
}

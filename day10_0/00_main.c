#include <stdio.h>
#include <string.h>
#include "link.h"
void help(void)
{
    printf("******************************\n");
    printf("**help:帮助信息              *\n");
    printf("**insert:插入一个节点        *\n");
    printf("**print:遍历链表的所有节点   *\n");
    printf("**find:查找链表的某个节点    *\n");
    printf("**delete:删除链表的某个节点  *\n");
    printf("**free:释放整个链表          *\n");
    printf("**quit:退出进程              *\n");
    printf("******************************\n");
}
int main(int argc, char const *argv[])
{
    STU *head = NULL;
    char cmd[32] = "";
    while (1)
    {
        printf("请输入要执行的命令:\n");
        scanf("%s",cmd);
        getchar();  //去掉回车！！ ？？
        if (strcmp(cmd,"help") == 0)
        {
            help();
        }
        else if (strcmp(cmd,"insert") == 0)
        {
            printf("请输入学生信息：num name score:\n");
            STU tmp;
            scanf("%d %s %f",&tmp.num,tmp.name,&tmp.score);
            head = insert_link(head,tmp);
        }
        else if (strcmp(cmd,"print") == 0)
        {
            print_link(head);   
        }
        else if (strcmp(cmd,"find") == 0)
        {
            printf("请输入要查找的姓名：\n");
            char name[32] = "";
            fgets(name,sizeof(name),stdin);
            name[strlen(name)-1] = 0;  //去掉回车！！ ？？

            STU *ret = NULL;
            ret = find_link(head,name);
            if (ret != NULL)
            {
                printf("查找的信息为：%d %s %f\n",ret -> num,ret -> name,ret -> score);
            }
            else
            {
                printf("姓名不存在\n");
            }    
        }
        else if (strcmp(cmd,"delete") == 0)
        {
            printf("请输入要删除的分数:\n");
            float score = 0;
            scanf("%f",&score);
            head = delete_link(head,score);
        }
        else if (strcmp(cmd,"free") == 0)
        {
            
        }
        else if (strcmp(cmd,"quit") == 0)
        {
            break;
        }
    }
    return 0;
}

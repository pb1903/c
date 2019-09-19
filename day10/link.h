#pragma once
//定义一个链表节点类型
typedef struct stu
{
    int num;
    char name[32];
    float score;
    struct stu *next;
}STU;

extern STU* insert_link(STU *head,STU tmp);
extern void print_link(const STU *head);
extern STU* find_link(STU *head,char *name);
extern STU* delete_link(STU *head,float score);
extern STU *free_link(STU* head);
extern STU* reverse_link(STU* head);
extern void sort_link(STU *head);

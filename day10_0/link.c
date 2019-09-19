#include <stdlib.h>
#include <stdio.h>
#include "link.h"

#if 0
//头插
STU* insert_link(STU* head,STU tmp)
{
    STU* pi = (STU*)calloc(1,sizeof(STU));
    *pi = tmp;
    pi -> next = NULL;

    if (head == NULL)
    {
        head = pi;
    }
    else
    {
        pi -> next = head;
        head = pi;
    }
    return head;
}
#endif

#if 0
//尾插
STU* insert_link(STU* head,STU tmp)
{
    STU* pi = (STU*)calloc(1,sizeof(STU));
    *pi = tmp;
    pi -> next = NULL;

    if (head == NULL)
    {
        head = pi;    
    }
    else
    {
        STU *pb = head;
        while (pb -> next != NULL)
        {
            pb = pb -> next;
        }
        pb -> next = pi;
    }
    return head;
}
#endif

#if 1
//有序插入
STU *insert_link(STU *head, STU tmp)
{
    STU *pi = (STU *)calloc(1, sizeof(STU));
    *pi = tmp;
    pi->next = NULL;

    if (head == NULL)
    {
        head = pi;
        return head;
    }
    else
    {
        STU *pb = head;
        STU *pf = head;
        while ((pb->num < pi->num) && (pb->next != NULL))
        {
            pf = pb;
            pb = pb->next;
        }
        if (pb->num >= pi->num)
        {
            if (pb == head) //头
            {
                pi->next = head;
                head = pi;
            }
            else //中
            {
                pf->next = pi;
                pi->next = pb;
            }
        }
        else if (pb->next == NULL)
        //尾
        {
            pb->next = pi;
        }
        /*  错误的！！

         if (pb == head) //头
        {
            pi->next = head;
            head = pi;
        }
        else if (pb->next == NULL) //尾
        {
            pb->next = pi;
        }
        else //中
        {
            pf->next = pi;
            pi->next = pb;
        }
        
         */
    }
    return head;
}
#endif

#if 0
//有序插入 是错误的！！第一次写错的!!
STU* insert_link(STU* head,STU tmp)
{
    STU* pi = (STU*)calloc(1,sizeof(STU));
    *pi = tmp;
    pi -> next = NULL;
    if (head == NULL)
    {
        head = pi; 
    }
    else
    {
        STU *pb = head,*pf = head;
        while (pb->num < pi->num)
        {
            pf = pb;
            pb = pb -> next;
        }
        if (pb == head) //头
        {
            pi -> next = head;
            head = pi;
        }
        else if (pb->next == NULL) //尾
        {
            while (pb -> next != NULL)
            {
                pb = pb -> next;
            }
            pb -> next = pi;
        }
        else  //中
        {
            pf -> next = pi;
            pi -> next = pb;
        }
        
    }
    return head;
}
#endif
//遍历
void print_link(const STU *head)
{
    if (head == NULL)
    {
        printf("链表不存在\n");
    }
    else
    {
        const STU *pb = head;
        while (pb != NULL)
        {
            printf("num=%d,name=%s,score=%f\n",
                   pb->num, pb->name, pb->score);
            pb = pb->next;
        }
    }
}

STU *find_link(STU *head, char *name)
{
    if (head == NULL)
    {
        printf("链表不存在\n");
        return NULL;
    }
    else
    {
        STU *pb = head;
        while (pb != NULL)
        {
            if (strcmp(pb->name, name) == 0)
            {
                return pb;
            }
            pb = pb->next;
        }
        return pb;
    }
}

STU *delete_link(STU *head, float score)
{
    if (head == NULL)
    {
        printf("链表不存在\n");
        return head;
    }
    else
    {
        STU *pb = head, *pf = head;
        while ((pb -> score != score) && (pb -> next != NULL))
        {
            pf = pb;
            pb = pb -> next;
        }
        if (pb -> score == score)
        {
            if (pb == head)  //头
            {
                head = pb -> next;
            }
            else if (pb -> next == NULL)  //尾
            {
                pf -> next = NULL;
            }
            else  //中
            {
                pf -> next = pb->next;
            }
            free(pb);
        }
        else
        {
            printf("该数据不存在\n");
        }
        return head;
    }
}
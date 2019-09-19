#include <stdlib.h>
#include <stdio.h>
#include "link.h"
#if 0
//头部之前插入
STU* insert_link(STU *head,STU tmp)
{
    STU *pi = (STU *)calloc(1,sizeof(STU));
    *pi = tmp;
    pi -> next = NULL;
    if (head == NULL) 
    {
        head = pi;
        //return head;
    }
    else
    {
        pi -> next = head;
        head = pi;
        //return head;
    }
    return head;  
}
#endif
#if 1
//尾部插入
STU* insert_link(STU *head,STU tmp)
{
    STU *pi = (STU *)calloc(1,sizeof(STU));
    *pi = tmp;
    pi -> next = NULL;
    if (head == NULL)
    {
        head = pi;
        //return head;
    }
    else
    {
        STU *pb = head;
        while (pb->next != NULL)
        {
            pb = pb->next;
        }
        pb -> next = pi;
        //return head;
    }
    return head;
}
#endif

#if 0
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
        //逐个节点寻找插入点的位置
        STU *pf = head, *pb = head;
        //按num 从小到大
        while ((pb->num < pi->num) && (pb->next != NULL))
        {
            //pf记录pb移动之前的位置
            pf = pb;
            pb = pb->next;
        }
        //判断插入点的位置(前 中 尾)
        if (pb->num >= pi->num)
        {
            if (pb == head) //前
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
        {
            pb->next = pi;
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
        return;
    }
    else
    {
        const STU *pb = head;
        while (pb != NULL)
        {
            printf("num=%d,name=%s,score=%f\n", pb->num, pb->name, pb->score);
            pb = pb->next;
        }
    }
}
//查找某个节点
STU *find_link(STU *head, char *name)
{
    if (head == NULL)
    {
        printf("链表不存在\n");
        return NULL;
    }
    else
    {
        //逐个节点查找
        STU *pb = head;
        while ((strcmp(pb->name, name) != 0) && (pb->next != NULL))
        {
            pb = pb->next;
        }
        //判断越界 还是找到相应的节点
        if (strcmp(pb->name, name) == 0)
        {
            return pb;
        }
        else if (pb->next == NULL)
        {
            printf("未找到姓名为%s的节点信息\n", name);
            return NULL;
        }
    }
    return NULL;
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
        //逐个节点查询删除点
        STU *pf = head, *pb = head;
        while ((pb->score != score) && (pb->next != NULL))
        {
            pf = pb;
            pb = pb->next;
        }
        if (pb->score == score) //找到删除点
        {
            if (pb == head) //删除头节点
            {
                head = head->next;
                //free(pb);
            }
            else //删除 尾 中 节点
            {
                pf->next = pb->next;
                //free(pb);
            }
            free(pb); //释放要删除的节点
            printf("节点删除成功\n");
            return head; //更新头节点
        }
        else
        {
            printf("未找到删除点\n");
            return head;
        }
    }
    return head;
}

STU *free_link(STU *head)
{
    if (head == NULL)
    {
        printf("链表不存在\n");
        return head;
    }
    else
    {
        STU *pb = head;
        //
        while (pb != NULL)
        {
            head = head->next;
            free(pb);
            pb = head;
        }
        return head;
    }
}
//逆序
STU *reverse_link(STU *head)
{
    if (head == NULL)
    {
        printf("链表不存在\n");
        return head;
    }
    else
    {
        STU *pb = NULL, *pr = NULL;
        pb = head->next;
        head->next = NULL;

        while (pb != NULL)
        {
            pr = pb->next;
            pb->next = head;
            head = pb;
            pb = pr;
        }
    }
    return head;
}
//选择排序
void sort_link(STU *head)
{
    if (head == NULL)
    {
        printf("链表不存在\n");
        return;
    }
    else
    {
        STU *p_i = head;

        while (p_i->next != NULL)
        {

            STU *p_min = p_i;
            STU *p_j = p_i->next;
            while (p_j != NULL)
            {
                if (p_j->num < p_min->num)
                {
                    p_min = p_j;
                }
                p_j = p_j->next;
            }
            if (p_i != p_min)
            {
                STU tmp = *p_i;
                *p_i = *p_min;
                *p_min = tmp;

                STU *p_tmp = p_i->mext;
                p_i->next = p_min->next;
                p_min->next = p_tmp;
            }

            p_i = p_i->next;
        }
    }
}


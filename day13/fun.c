#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include "console.h"

//歌词读取
char *read_lrc(void)
{
    //获取文件总大小
    FILE *lp = fopen("简单爱.lrc", "r");
    fseek(lp, 0, 2); //流指针定位到尾部
    long lenth = ftell(lp);
    rewind(lp); //复位流指针
    //堆区申请空间,读取数据
    char *lrc_text = (char *)calloc(1, lenth + 1);
    fread(lrc_text, lenth, 1, lp);

    //printf("lrc_text************** = %s\n", lrc_text);
    //释放堆区空间

    fclose(lp);
    return lrc_text;
}

/*
//歌词切割
char** lrc_cut(char *lrc)
{
    char* lrc_c[258] = {NULL};
    
    int i = 0;
    lrc_c[i] = strtok(lrc,"\r\n");

    while (lrc[i] != NULL)
    {
        i++;
        lrc_c[i] = strtok(NULL,"\r\n");
        
    }

    i = 0;
    while (lrc_c[i] != NULL)
    {
        printf("lrc_c************** = %s\n",lrc_c[i]);
        i++;
    }

    return lrc_c;
}

 */
//歌词切割
void lrc_cut(char **lrc_c, char *lrc_r)
{
    int i = 0;
    lrc_c[i] = strtok(lrc_r, "\r\n");

    while (lrc_c[i] != NULL)
    {
        i++;
        lrc_c[i] = strtok(NULL, "\r\n");
    }

    /*
    
    i = 0;
    while (lrc_c[i] != NULL)
    {
        printf("%s\n", lrc_c[i]);
        i++;
    }

    */

    return;
}

//链表的有序插入
LRC *insert_link(LRC *head, LRC tmp)
{
    LRC *pi = (LRC *)calloc(1, sizeof(LRC));
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
        LRC *pf = head, *pb = head;

        //要用到 time 的 秒数 ！！！
        while ((pb->time < pi->time) && (pb->next != NULL))
        {
            //pf记录pb移动之前的位置
            pf = pb;
            pb = pb->next;
        }
        //判断插入点的位置(前 中 尾)
        if (pb->time >= pi->time)
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

//链表的遍历
void print_link(const LRC *head)
{
    if (head == NULL)
    {
        printf("链表不存在\n");
        return;
    }
    else
    {
        const LRC *pb = head;
        while (pb != NULL)
        {
            printf("time = %d,stc = %s\n", pb->time, pb->stc);
            pb = pb->next;
        }
    }
}

//逐行分开歌词的时间和文字
LRC *lrc_spt(char **lrc_c, LRC *head, int *row)
{
    //获取行数
    int i = 0;
    while (lrc_c[i] != NULL)
    {
        *row = i++;
    }
    //获得歌词的位置 时间 文字
    i = 4;
    for (i = 4; i < *row; i++)
    {

        char *pt = lrc_c[i];
        while (*pt == '[')
        {
            pt += 10;
        }

        char *ps = lrc_c[i];
        while (*ps == '[')
        {
            //提取 分 秒 毫秒
            //int m = 0, s = 0, ms = 0;
            //sscanf(ps, "[%d:%d.%d", &m, &s, &ms);
            int m = 0, s = 0;
            sscanf(ps, "[%d:%d", &m, &s);
            LRC tmp;
            //结构体中的 time 设为毫秒
            //tmp.time = m*60000 + s*1000 + ms;
            tmp.time = m * 60 + s;
            strcpy(tmp.stc, pt);

            head = insert_link(head, tmp);

            ps += 10;
        }
    }

    return head;
}

#if 1
//模拟时钟
void lrc_clk(LRC *head, char **lrc_c)
{
    clear_screen();
    cusor_moveto(0, 2);
    int time = 0;
    LRC *pb = head;
    //显示前四个歌词信息
    int i = 0;
    int n = 0;
    int j = 0;

    for (i = 0; i < 4; i++)
    {
        set_fg_color(COLOR_CYAN);
        printf("\t\t\t\t%s\n", lrc_c[i]);
    }

    printf("\n");

    while (pb != NULL)
    {
        cusor_moveto(35,6);
        printf("%02d:%02d",time/60,time%60);
       // cusor_hide();
        fflush(stdout);

        if (time == pb->time)
        {
            
            //打印5行歌词
            cusor_moveto(0,7);
            for (i = 0; i < 5; i++)
            {
                set_fg_color(COLOR_YELLOW);
                printf("\t\t\t%s                  \n", pb->stc);
                pb = pb->next;
            }
            //光标定位
            if (i == 5)
            {
                cusor_moveto(0,7);
            }
        }
        i = 0;
        sleep(1); //延迟一秒
        time++;
    }

    return;
}
#endif

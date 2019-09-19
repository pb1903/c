#include <stdio.h>
#include "fun.h"
#include "start_mplayer.h"
#include "console.h"

int main(int argc, char const *argv[])
{
    //将歌词文件存放到内存
    char *lrc_r = read_lrc();

    //将歌词切割               //char** lrc_c = lrc_cut(lrc_r);
    char *lrc_c[128] = {NULL};
    lrc_cut(lrc_c, lrc_r);

    //定义链表 头结点
    LRC* head = NULL;
    //行数
    int row = 0;
    //逐行分开歌词的 时间和文字 , 插入存放到链表中 //提取毫秒！！
    head = lrc_spt(lrc_c,head,&row);
    //链表遍历
    //print_link(head);
    

    
    //启动播放器
    mplayer_play("./简单爱.mp3");
    //模拟时钟
    lrc_clk(head,lrc_c);


    return 0;
}

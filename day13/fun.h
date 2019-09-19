#pragma once
extern char* read_lrc(void);
//extern char** lrc_cut(char *lrc);
extern void lrc_cut(char **lrc_c, char *lrc_r);

typedef struct lrc
{
    int time;  //秒数
    char stc[256];  //歌词

    struct lrc *next;
}LRC;

extern LRC* insert_link(LRC *head, LRC tmp);
extern void print_link(const LRC *head);
extern LRC *lrc_spt(char **lrc_c, LRC *head,int *row);
extern void mplay_play(char* name);
extern void lrc_clk(LRC *head,char** lrc_c);
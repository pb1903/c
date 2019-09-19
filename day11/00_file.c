#include <stdio.h>
#include <string.h>
void test01()
{
    printf("请输入你要写入文件的字符串：\n");
    char msg[128] = "";
    fgets(msg, sizeof(msg), stdin);

    FILE *fp = fopen("a.txt", "w");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }
    int i = 0;
    while (msg[i] != '\0')
    {
        fputc(msg[i++], fp);
    }
    fclose(fp);
}
void test02()
{
    FILE *fp = fopen("a.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }

    char msg[128] = "";
    int i = 0;

    while ((msg[i++] = fgetc(fp)) != EOF)
        ;
    /*
    /while (1)        //这两种i都多了1？？？ 有空选查看注释的代码是否正确？
    {
        msg[i] = fget(fp);
        if fgetc(fp) == EOF)
        {
            break;
        }
        i++;
    }
     */
    msg[i - 1] = 0; //将回车变为'\0'
    printf("msg = %s\n", msg);

    fclose(fp);
}
typedef struct
{
    char name[8];
    int def;
    int atk;
} HERO;
void test03()
{
    HERO hero[] =
        {
            {"德玛", 90, 40},
            {"提莫", 30, 120},
            {"盲僧", 50, 80}};
    int n = sizeof(hero) / sizeof(hero[0]);
    FILE *fp = fopen("a.txt", "w");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }
    //块写
    fwrite(hero, sizeof(HERO), n, fp);
    fclose(fp);
}
void test04()
{
    HERO hero[3];
    memset(hero, 0, sizeof(hero));

    FILE *fp = fopen("a.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }
    //块读
    fread(hero, sizeof(HERO), 3, fp);
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("name = %s,def = %d,atk = %d\n",
               hero[i].name, hero[i].def, hero[i].atk);
    }

    fclose(fp);
}

void test05()
{
    HERO hero[] =
        {
            {"德玛", 90, 40},
            {"提莫", 30, 120},
            {"盲僧", 50, 80}};
    int n = sizeof(hero) / sizeof(hero[0]);
    FILE *fp = fopen("a.txt", "w");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }
    //格式化写
    int i = 0;
    for (i = 0; i < n; i++)
    {
        fprintf(fp, "英雄：%s 防御：%d 攻击：%d\n",
                hero[i].name, hero[i].def, hero[i].atk);
    }

    fclose(fp);
}

void test06()
{
    HERO hero[3];
    memset(hero, 0, sizeof(hero));

    FILE *fp = fopen("a.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }
    //格式化读
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        fscanf(fp, "英雄：%s 防御：%d 攻击：%d\n",
               hero[i].name, &hero[i].def, &hero[i].atk);
    }

    for (i = 0; i < 3; i++)
    {
        printf("name = %s,def = %d,atk = %d\n",
               hero[i].name, hero[i].def, hero[i].atk);
    }

    fclose(fp);
}

int main(int argc, char const *argv[])
{
    test06();
    return 0;
}

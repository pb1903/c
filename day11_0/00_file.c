#include <stdio.h>
#include <stdlib.h>
char *encpn(char *name,char *key);
void decpn(char *name, char *key);

void help(void)
{
    printf("**加密文件：数字1**********\n");
    printf("**解密文件：数字2**********\n");
    printf("**退出：数字3*************\n");
    printf("请输入数字：\n");
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        help();
        int num = 0;
        scanf("%d", &num);
        char* key[128] = "";
        if (num == 1)
        {
            printf("请输入要加密的文件名称：\n");
            char name[32] = "";
            scanf("%s", name);
            key = encpn(name);
            printf("文件已加密\n");
        }
        else if (num == 2)
        {
            printf("请输入要解密的文件名称：\n");
            char name[128] = "";
            scanf("%s", name);
            decpn(name, key);
        }
        else if (num == 3)
        {
            break;
        }
        else
        {
            printf("输入错误\n");
        }
    }

    return 0;
}

char *encpn(char *name,char *key)
{
    printf("请输入新文件名称：\n");
    char name_new[32] = "";
    scanf("%s", name_new);

    printf("请输入密码：\n");
    scanf("%s",key);

    FILE *fp = fopen(name, "r");
    fseek(fp, 0, 2);
    long len = ftell(fp);  
    rewind(fp);

    char *file = (char *)calloc(1, sizeof(len) + 1);
    fread(file, len + 1, 1, fp);

    int i = 0;
    for (i = 0; i < len; i++)
    {
        file[i] = file[i] + 'm';
    }
    fclose(fp);

    FILE *fp1 = fopen(name_new, "w");
    fwrite(file, len + 1, 1, fp1);
    fclose(fp1);
    return key;
}

void decpn(char *name, char *key)
{
    printf("请输入密码：\n");
    char key1[128] = "";
    scanf("%s", key1);
    if (strcmp(key, key1) == 0)
    {
        printf("请输入新的文件名称：\n");
        char* name_new[32] = "";
        scanf("%s", name_new);
        FILE *fp = fopen(name, "r");
        fseek(fp, 0, 2);
        long len = ftell(fp);
        rewind(fp);

        char *file = (char *)calloc(1, sizeof(len) + 1);
        fread(file, len + 1, 1, fp);

        int i = 0;
        for (i = 0; i < len; i++)
        {
            file[i] = file[i] - 'm';
        }

        FILE *fp1 = fopen(name_new, "w");
        fwrite(file, len + 1, 1, fp1);
        fclose(fp1);

        FILE *fp = fopen(name, "r");
        fseek(fp, 0, 2);
        long len = ftell(fp);
        rewind(fp);

        char *file = (char *)calloc(1, sizeof(len) + 1);
        fread(file, len + 1, 1, fp);
        int i = 0;
        for (i = 0; i < len; i++)
        {
            file[i] = file[i] - 'm';
        }
        fclose(fp);

        FILE *fp1 = fopen(name_new, "w");
        fwrite(file, len + 1, 1, fp1);
        fclose(fp1);
        printf("文件已解密\n")；
    }
    else
    {
        printf("密码错误\n");
    }
}

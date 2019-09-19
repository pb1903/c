#include <stdio.h>
#include <stdlib.h>
void test01()
{
    //加密过程
    //读取原文件
    FILE *fp = fopen("a.txt", "r");
    fseek(fp, 0, 2);
    long len = ftell(fp); //fp file
    char *file = (char *)calloc(1, len + 1);
    rewind(fp);
    fread(file, len, 1, fp);
    //输入文件名
    printf("请输入新的文件名称：\n");
    char name[32] = "";
    scanf("%s", name);
    getchar();
    //创建新文件
    FILE *fp_1 = fopen(name, "w"); //fp_1 file_1
   // char *file_1 = (char *)calloc(1, len + 1);
    rewind(fp_1);
    fwrite(file_1, len, 1, fp_1);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        //file_1[i] = file[i] + 'k';
        file[i] = file[i] + 'k';
    }
    printf("请输入密码：\n");
    char key[32] = "";
    fgets(key, sizeof(key), stdin);
    //写入
    fwrite(file, len, 1, fp_1);

    //解密过程
    //输入要解密的文件名称
    rewind(fp_1);
    printf("请输入要解密的文件名称：\n");
    char name_1[32] = "";
    scanf("%s", name_1);
    getchar();
    //printf("%s\n",name_1);

    //读取解密文件
    FILE *fp_2 = fopen(name_1, "r"); //fp_2 file_2
    fseek(fp_2, 0, 2);
    long len_1 = ftell(fp_2);
    char *file_2 = (char *)calloc(1, len_1 + 1);
    rewind(fp_2);
    fread(file_2, len_1, 1, fp_2);

    rewind(fp_2);
    //创建新文件
    printf("请输入新的文件名称：\n"); //fp_3 file_3
    char name_2[32] = "";
    scanf("%s", name_2);
    getchar();
    FILE *fp_3 = fopen(name_2, "w");
    char *file_3 = (char *)calloc(1, len_1 + 1);
    rewind(fp_3);



    //密码验证
    printf("请输入密码：\n");
    char key_1[32] = "";
    fgets(key_1,sizeof(key_1),stdin);
    if (strcmp(key_1,key) == 0)
    {    
        i = 0;
        for ( i = 0; i < len_1; i++)
        {
            file_3[i] = file_2[i] - 'k';
        }
        fwrite(file_3,len_1,1,fp_3);
        printf("%c\n",file_3);
    }
    else
    {
        fwrite(file_1,len_1,1,fp_1);
    }
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}

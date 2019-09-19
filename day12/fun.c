#include <stdio.h>
#include <stdlib.h>
void help(void )
{
    printf("1:加密文件\n");
    printf("2:解密文件\n");
    printf("3:退出程序\n");
    return;
}
void get_file_name(char *dst_file,char *src_file)
{
    printf("请输入源文件的名字(30个字符):");
    scanf("%s", src_file);
    printf("请输入目标文件的名字(30个字符):");
    scanf("%s", dst_file);
    return;
}
char * read_src_file(unsigned long *file_length,char *src_file_name)
{
    //打开文件
    FILE *fp = fopen(src_file_name, "r");
    if(fp == NULL)
    {
        perror("src file:");
        return NULL;
    }

    //将文件的流指针定位到文件的尾部
    fseek(fp, 0, 2);
    //获取文件的大小
    *file_length = ftell(fp);
    //复位文件流指针
    rewind(fp);

    //给读取的内容申请堆区空间
    char *text = (char *)calloc(1, *file_length+1);
    fread(text, *file_length, 1, fp);

    fclose(fp);
    return text;
}

char * file_text_encrypt(char * src_file_text,unsigned long length,unsigned int password)
{
    int i= 0;
    for ( i = 0; i < length; i++)
    {
        src_file_text[i] += password;
    }
    return src_file_text;
}
void save_file(char* text,unsigned long int length,char * file_name)
{
    //打开文件
    FILE *fp = fopen(file_name, "w");
    if(fp == NULL)
    {
        perror("src file:");
        return;
    }

    fwrite(text,length, 1, fp);

    fclose(fp);
    printf("文件保存成功\n");

    //释放空间
    if(text != NULL)
    {
        free(text);
        text=NULL;
    }
    
    return;
}
char * file_text_decrypt(char * src_file_text,unsigned long length,unsigned int password)
{
    int i= 0;
    for ( i = 0; i < length; i++)
    {
        src_file_text[i] -= password;
    }
    return src_file_text;
}
#include <stdio.h>
#include "fun.h"
int main(int argc, char const *argv[])
{
    while(1)
    {
        char src_file[32]="";
        char dst_file[32]="";
        unsigned int password=0;
        unsigned long file_len = 0;
        char *src_text = NULL;
        int cmd = 0;

        help();

        scanf("%d", &cmd);
        if(cmd == 3)
        {
            break;
        }
           
        //获取源文件 和目标文件的名字
        get_file_name(dst_file,src_file);

        //读取源文件的内容
        src_text = read_src_file(&file_len, src_file);

        //获取密码
        printf("请输入密码:");
        scanf("%d", &password);

        if(cmd == 1)//对文件的加密
            src_text = file_text_encrypt(src_text, file_len, password);
        else if(cmd == 2)//对文件的解密
            src_text = file_text_decrypt(src_text, file_len, password);
        
        //将加密号的文本内容存储文件中
        save_file(src_text, file_len, dst_file);
    }
    
    return 0;
}
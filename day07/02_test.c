#include <stdio.h>
#include <string.h>
void test01()
{
    char data[] = "hehe:haha:heihei:henhen:enen:yaya:lala:wuwu";
    char *buf[20] = {NULL};
    int i = 0;
    buf[i] = strtok(data,":");
    while(buf[i] != NULL)
    {
        i++;
        //buf[i] = strtok(buf[i],":");
        buf[i] = strtok(NULL,":");
    }
    i = 0;
    while (buf[i] != NULL)
    {
        printf("%s\n",buf[i]);
        i++;
    } 
}
void test02()
{
    char data[] = "hehe:haha:heihei:henhen:enen:yaya:lala:wuwu";
    char *buf[20] = {data,NULL};
    int i = 0;
    while (1)
    {
        buf[i] = strtok(buf[i],":");
        if (buf[i] == NULL)
        {
            break;
        }
        else
        {
            i++;
        }  
    }
    i = 0;
    while (buf[i] != NULL)
    {
        printf("%s\n",buf[i]);
        i++;
    }
}
void test03()
{
    char data[] = "hehe:haha:heihei:henhen:enen:lala:yaya:wuwu";
    char *buf[20] = {data,NULL};
    int i = 0;
    //while ( (buf[i] = strtok(buf[i],":") ) && (buf[i++] = strtok(NULL,":") ));//err 但是不懂该结果是如何算出的
    while ((buf[i] = strtok(buf[i],":")) && ++i);
    i = 0;
    while (buf[i] != NULL)
    {
        printf("%s\n",buf[i++]);
    }
    
}
int main(int argc, char const *argv[])
{
    test03();
    return 0;
}

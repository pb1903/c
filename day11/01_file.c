#include <stdio.h>
#include <stdlib.h>
void test01()
{
    FILE *fp = fopen("b.txt","r");
    fseek(fp,0,2);
    long len = ftell(fp);
    printf("%ld\n",len);
    char* file = (char*)calloc(1,len+1);
    rewind(fp);
    fread(file,len,1,fp);
    printf("file = %s\n",file);
    if (file != NULL)
    {
        free(file);
        file = NULL;
    }
    
}
int main(int argc, char const *argv[])
{
    test01();
    return 0;
}

#include <stdio.h>
char* conj(char *p1,char *p2);
void test01()
{
    char s1[80],s2[80];
    gets(s1); 
    gets(s2);
    conj(s1,s2);
    puts(s1);
    
}
int main(int argc, char const *argv[])
{
    
    test01();
    return 0;
}
char* conj(char *p1,char *p2)
{
  char *p=p1;
        
          
        while(*p1)
        p1++;
 
      
           while(*p2)
        {
            *p1=*p2;
            p1++;
            p2++;
        }
   // *p1 ='\0';  
    return p;
}

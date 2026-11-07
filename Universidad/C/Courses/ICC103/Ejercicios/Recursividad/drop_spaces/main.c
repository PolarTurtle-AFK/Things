#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void drop_spaces(char *s);

int main()
{
    char s[] = "  SIX    SEVE   N ";
    drop_spaces(s);
    printf("%s",s);
    return 0;
}


void drop_spaces(char *s)
{
    if(*s=='\0'){
        return;
    }


    if(*s==' ' && *(s+1)==' '|| *s==' ' && *(s-1)=='\0')
    {
        strcpy(s,s+1);
        drop_spaces(s);
    }else{
        if (*s != '\0'){
            {
                drop_spaces(s+1);
            }
        }

    }
}

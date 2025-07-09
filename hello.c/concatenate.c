#include <stdio.h>
#include <string.h>

int main()
        {
  
            char str1[20] = "ADARSH IS \0";
            char str2[]  = "BAD";
            char str3[] = "REAL";

            strcat(str1,str2);
            
            printf("%s",str1);

            strcat(str1, str3);
            printf("%s",str1);
           








        return 0;
        }
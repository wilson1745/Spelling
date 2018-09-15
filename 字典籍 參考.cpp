#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
 
int main(void)
{
    int i, j;
    char str[10][50], temp[50];
 
    printf("輸入十個詞:\n");
 
    for(i=0; i<10; ++i){
        scanf("%s[^\n]",str[i]);
        printf("%s\n", str[i]);
	}
 
 
    for(i=0; i<9; ++i)
        for(j=i+1; j<10 ; ++j)
        {
            if(strcmp(str[i], str[j])>0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
 
    printf("\n排序后: \n");
    for(i=0; i<10; ++i)
    {
        puts(str[i]);
    }
 	system("pause");
    return 0;
}

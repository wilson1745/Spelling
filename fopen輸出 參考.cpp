#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
	char ch;
	FILE *fp;
	if((fp=fopen("C:\\Users\\Wei-Shen Lo\\Google ¶³ºÝµwºÐ\\Computer Science\\C»y¨¥\\§@·~\\Week 6\\eowl_shuffle.txt","r")) == NULL){
		printf("Cannot open file ! \n"); 
		system("pause");
		return(1);  	
  	}
	   
  	while((ch = fgetc(fp)) != EOF){
  	    fputc(ch,stdout);
	}
	
  	fclose(fp);
  	system("pause");
}

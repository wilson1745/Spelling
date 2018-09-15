#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#define SIZE 128773
#define LEN 11
#define CSEC (double)(CLOCKS_PER_SEC)
 
int main(int argc, char *argv[])
{
    int i, j, k;
    char str[SIZE][LEN], temp[SIZE];		// SIZE定義幾個單字 後面的LEN為字元長度 
 	char ch;
 	clock_t start, end;
 	
 	start = clock();		    // Start Record the time
 	
	FILE *fp;
	if((fp=fopen("C:\\Users\\Wei-Shen Lo\\Google 雲端硬碟\\Computer Science\\C語言\\作業\\Week 6\\apple.txt","r")) == NULL){
		printf("Cannot open file ! \n"); 
		system("pause");
		return 0;  	
  	}
 
	while(!feof(fp)){
		fscanf(fp,"%s\n",str[i]);
		i++;
	} 	
			
/*	for(j=0;j<i;j++){
		printf("%6d   %s\n", j+1, str[j]);
	}*/
	
	char key[50];
	
	printf("Please input string: ");
	scanf("%s", key);
	

	
    printf("\n排序後: \n");	
	
    for(k=0;k<i-1;k++){
        for(j=k+1;j<i;j++){
			if(strcmp(str[k], str[j])>0){
                strcpy(temp, str[k]);
                strcpy(str[k], str[j]);
                strcpy(str[j], temp);
            }
        }   	
	} 	
		
/*	for(k=0;k<i;k++){
		printf("%6d   %s\n", k+1, str[k]);
	}*/
	
	int l, r, m; 
	
	l = 0; 
	r = SIZE - 1;	
			
	while(l <= r){ 		
		m = (l+r)/2;
		printf("m = %d %s\n", m, str[m]);	
		printf("str[m]-key = %d\n", strcmp(str[m], key));
		if(strcmp(key, str[m])==0){
			printf("Found It ! \n%s \n", key);
			break;
		}
		else if (strcmp(key, str[m])>0){		
			l = m + 1;
			printf("l=m+1\n\n");
		} 
		else if(strcmp(key, str[m])<0){
			r = m- 1; 
			printf("r=m-1\n\n");
		} 
		else{
			printf("Cannot find it! \n");
			break;
		}
	}	
	
    end = clock();			    // Record the end time
    printf("\nTime(s) : %f seconds\n\n", (double)(end-start)/CSEC);
	
 	system("pause");
    return 0;
}


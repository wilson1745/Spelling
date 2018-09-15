#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#define CSEC (double)(CLOCKS_PER_SEC)
#define NUMNAME 128773
#define LENNAME 15

struct node {
    char name[LENNAME];
    struct node *next;
};

typedef struct node Node;
Node *AllocateNode(char *s);
void PrintList(Node *l);

int main(int argc, char **argv)
{
	FILE *fp;
	char ch;
	char array[NUMNAME][LENNAME];
	int i=0, j=0, begin=0;
	Node *start, *tmp1, *tmp2, *current, *end;
 	
    fp = fopen("C:\\Users\\Wei-Shen Lo\\Google 雲端硬碟\\Computer Science\\C語言\\作業\\Week 6\\apple1.txt", "r");
	
	if(fp){
		while((ch=getc(fp))!=EOF){
    		array[j][i]=ch;
    		i++;
	    	if(ch=='\n'){
   		 		current = AllocateNode(array[j]);
    			if(begin==0){
    				printf("進到if(begin==0)\n");
    				getchar();
    				start=current;
    				end=start;
    				begin++;	
/*	  	  		printf("%s", start->name);
    			printf("%s", current->name);
    			printf("%s", end->name);*/
				}
				else{
    				printf("\n進到else\n");
    				printf("current = %s", current->name);
    				getchar();
					if(strcmp(current->name, start->name)<0){
						
    					printf("進到if(strcmp(current->name, start->name)<0\n");
    					printf("start->name         %s", start->name);    				
						printf("current->name       %s", current->name);
    					getchar();
    				
						current->next=start;
						start=current;
						
    					printf("start->name         %s", start->name);
    					printf("current->name       %s", current->name);											
						printf("current->next->name %s", current->next->name);
						
					}
					else if(strcmp(current->name, end->name)>0){
						
    				printf("進到else if(strcmp(current->name, end->name)>0\n");
    				getchar();
    				
						end->next=current;
						end=current;
					}
					else{
						
    				printf("進到tmp1=start, tmp2=tmp1->next\n");
    				getchar();
    				
						tmp1=start;
						tmp2=tmp1->next;
						
						do{
							if(strcmp(current->name, tmp1->name)>=0 && strcmp(current->name, tmp2->name)<=0){
    							printf("tmp2->name %s", tmp2->name);
								printf("進到do if(strcmp(current->name, tmp1->name)>=0 && strcmp(current->name, tmp2->name)<=0)\n");				
    							getchar();							
							
								tmp1->next=current;
								current->next=tmp2;			
							}
							else{
								
								printf("進到do else\n");												
								
								tmp1=tmp1->next;
								tmp2=tmp2->next;
								
								printf("tmp1 %s", tmp1->name);
								printf("tmp2 %s", tmp2->name);
							}
						}while(current->next==NULL);
					}	
				}
				j++;
				i=0;
			}
		}		
	}
	else{
		printf("Err: no file found! \n");
	}
	
	PrintList(start);    
	
    fclose(fp);
 
    system("pause");
    return 0;
}

Node *AllocateNode(char *s)
{
   Node *p;   
   p = (Node*)malloc(sizeof(Node));

   if(p==NULL){
      printf("cannot find it\n");
      exit(2);      
   }      
   
   strcpy(p->name,s);
   p->next = NULL ;
   return p ; 
}

void PrintList(Node *l)
{
	int k=1;
   do{
      printf("%6d  %s", k, l->name);
      l = l->next;
      k++;
   }while(l!=NULL);
}



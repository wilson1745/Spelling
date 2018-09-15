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
	
 	clock_t head, ended;
 	head = clock();		    // Start Record the time
 	
    fp = fopen("C:\\Users\\Wei-Shen Lo\\Google ¶³ºÝµwºÐ\\Computer Science\\C»y¨¥\\§@·~\\Week 6\\apple.txt", "r");
	
	if(fp){
		while((ch=getc(fp))!=EOF){
    		array[j][i]=ch;
    		i++;
	    	if(ch=='\n'){
   		 		current = AllocateNode(array[j]);
    			if(begin==0){
    				start=current;
    				end=start;
    				begin++;	
				}
				else{
					if(strcmp(current->name, start->name)<0){
						current->next=start;
						start=current;
					}
					else if(strcmp(current->name, end->name)>0){
						end->next=current;
						end=current;
					}
					else{
						tmp1=start;
						tmp2=tmp1->next;
		
						do{
							if(strcmp(current->name, tmp1->name)>=0 && strcmp(current->name, tmp2->name)<=0){
								tmp1->next=current;
								current->next=tmp2;			
							}
							else{
								tmp1=tmp1->next;
								tmp2=tmp2->next;
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
    
    ended = clock();			    // Record the end time
    printf("\nTime(s) : %f seconds\n\n", (double)(ended-head)/CSEC);    
 
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



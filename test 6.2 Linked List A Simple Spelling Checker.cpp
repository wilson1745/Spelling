#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#define CSEC (double)(CLOCKS_PER_SEC)

struct list {
    char *string;
    struct list *next;
};

typedef struct list LIST;

void InsertionSort(LIST *head);

int main(void)
{
    char line[128];
    int i=1; 
	FILE *fp;
    LIST *current, *head;

 	clock_t start, end;
 	start = clock();		    // Start Record the time
 	
    head = current = NULL;
    fp = fopen("C:\\Users\\Wei-Shen Lo\\Google ���ݵw��\\Computer Science\\C�y��\\�@�~\\Week 6\\apple.txt", "r");

    while(fgets(line, sizeof(line), fp)!=NULL){
        LIST *node = (LIST*)malloc(sizeof(LIST));
        node->string = strdup(line);				// ��line���r���ƽƻs��node���V��string[]���Anote : strdup is not standard function
		node->next = NULL;							// �����wnode->next���Ū� 

        if(head == NULL){							// ���]����head���Ū��A�]�w�Ĥ@�Ӧr�굹head 
            current = head = node;
/*            printf("head == NULL %d\n", current);
            printf("head->string : %s\n", current->string);*/		// �]�i�g head->string 

        } 
		else{
            current = current->next = node;						// current �s�� current -> next����} 
 /*           printf("current == current -> next %d\n", current);
            printf("current->string : %s\n", current->string);
			printf("�Ĥ@���� head->string : %s\n", head->string);*/		// head still�O���L�Ĥ@�ӭȪ����� 
        }
    }
    
/*    for(current=head;current!=NULL;current=current->next){				    //test print
        printf("%6d   %s", i, current->string);
        i++;
    }*/
    //need free for each node    
    
    printf("\n�ƪ���...\n\n");
    
	InsertionSort(head);
    
/*    do{
        printf("%6d   %s", i, current->string);
		current=current->next;
		i++;    	
	}while(current!=NULL);*/
	
/*    for(current=head;current!=NULL;current=current->next){				    //test print
        printf("%6d   %s", i, current->string);
        i++;
    }*/
    //need free for each node

    fclose(fp);
    end = clock();			    // Record the end time
    printf("\nTime(s) : %f seconds\n\n", (double)(end-start)/CSEC);

    system("pause");
    return 0;
}

void InsertionSort(LIST *head)
{
    LIST *q, *p, *qt, *pt;
    LIST *node = (LIST*)malloc(sizeof(LIST));
    p=node;
    q=node;
    qt=node;
    pt=node;
    int k=1;
    
    for(p=head;p!=NULL;p=p->next){
    	qt=p;
    	for(q=p->next;q!=NULL;q=q->next){
    		if(strcmp(qt->string, q->string)>0){
    			pt->string=qt->string;
    			qt->string=q->string;
    			q->string=pt->string;
			}

		}
		printf("%6d %s", k, p->string);
		k++;
	}	
}



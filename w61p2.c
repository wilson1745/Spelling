#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMNAME 130000
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
   char *filename;
   char ch;
   char strings[NUMNAME][LENNAME];
   int i=0,j=0,begin=0;
   Node *start,*tmp1,*tmp2,*current,*end;
   if(argc==2)
   {
      filename = argv[1];
      printf("name = %s\n\n",filename);
   }
   fp=fopen("C:\\Users\\Wei-Shen Lo\\Desktop\\apple1.txt","r");
   if(fp)
   {
      while((ch=getc(fp))!=EOF)
      {
         strings[j][i]=ch;
         i++;
         if(ch=='\n')
         {  
            current =  AllocateNode(strings[j]) ;
            if(begin==0)
            {
               start = current ;
               end = start ;
               begin++ ;
            }
            else
            {
                  if(strcmp(current->name,start->name)<0)
                  {
                     current->next = start ;
                     start = current ;
                  }
                  else if(strcmp(current->name,end->name)>0)
                  {
                     end->next = current ;
                     end = current ;
                  }
                  else
                  {
                     tmp1 = start ;
                     tmp2 = tmp1->next ;
                     do{
                        if(strcmp(current->name,tmp1->name)>=0&&strcmp(current->name,tmp2->name)<=0)
                        {
                           tmp1->next = current ;
                           current->next = tmp2 ;
                        }
                        else
                        {
                           tmp1 = tmp1->next ;
                           tmp2 = tmp2->next ;
                        }
                     }while(current->next==NULL);
                  }
            }
            j++;
            i=0;
         }
      }
   }
   else
      printf("Err: no file\n");

   PrintList(start);
   
   system("pause");
   return 0 ;

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
   do{
      printf("%s\n",l->name);
      l = l->next;
   }while(l!=NULL);
}

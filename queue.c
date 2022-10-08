#include<stdio.h>
#include<ctype.h>

struct Node
{
   int data;
   struct Node *next;
}*front = NULL;

void main()
{
 int choice,value;
 
 while(1){
    mainMenu:
    printf("\n\n****** CHOOSE FUNCTION ******\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
    scanf("%d",&choice);
     switch (choice)
     {
     case 1: 	
     printf("Enter the value to be insert: ");
	 scanf("%d",&value);
     struct Node *newNode;
      newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data = value;
     newNode->next = NULL;
     if(front == NULL)
	 front = newNode;
     else
     {
      struct Node *temp = front;
      while(temp->next != NULL)
	   temp = temp->next;
       temp->next = newNode;
     }
     printf("\nOne value inserted!!!\n");
     break;
   

     case 2:
     if(front == NULL)
	  printf("\n\nQueue is Empty!!!");
     else
     {
      struct Node *temp = front;
      if(front->next == NULL)
      {
	 front = NULL;
     printf("\nOne node deleted!!!\n\n");
	 free(temp);
      }
      else
      {
	 front = temp->next;
	 free(temp);
	 printf("\nOne node deleted!!!\n\n");
      }
     }
      break;
     
     case 3:
     if(front == NULL)
     {
      printf("\nQueue is Empty\n");
     }
     else
     {
      struct Node *temp = front;
      printf("\n\nQueue elements are - \n");
      while(temp->next != NULL)
      {
	  printf("%d --->",temp->data);
	  temp = temp->next;
      }
      printf("%d --->NULL",temp->data);
     }
      break;


     case 4: 	
     exit(0);

     default: 
     printf("\nWrong input!!! Try again!!\n\n");   
     }
     goto mainMenu;
     
    }

   }

     




        
  
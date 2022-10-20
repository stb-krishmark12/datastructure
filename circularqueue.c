#include <stdio.h>
int front = -1, rear = -1;
int items[];
// Check if the queue is full
int isFull(int SIZE) {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// Adding an element
void enQueue(int element,int SIZE) {
  if (isFull(SIZE))
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}

// Removing an element
int deQueue(int SIZE) {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // Q has only one element, so reset the 
    // queue after dequeing it.
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

// Display the queue
void display(int SIZE) {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main() {
    int l,choice;
  printf("Enter array size\n");
  scanf("%d",&l);


  while (1)
  {
    mainMenu:
    printf("\n****** CHOOSE FUNCTION ******\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
    scanf("%d",&choice);
    int x;
     switch (choice)
    {
   
    case 1:
    printf("Enter the value\n");
    scanf("%d",&x);
    enQueue(x,l);
    break;
    
    case 2:
    deQueue(l);
    break;

    case 3:
    display(l);
    break;

    case 4:
    exit(0);

    default:
    printf("Wrong input try again!!\n");
    break;
    }
  goto mainMenu;
  }
  return 0;
}
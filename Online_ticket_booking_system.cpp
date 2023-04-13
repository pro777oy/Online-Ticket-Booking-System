#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


int front=-1;
int rear=-1;
int index=0;
int *queue=new int[index];




void createqueue();
void enqueue(int a);
int dequeue();
int isfull();
int isempty();
void find();
void display();
void option();


void option()
{

     int opt;
     cout<<"******************************welcome to Online Ticket Booking System******************************"<<endl;
     cout<<endl;
     cout<<"press 1 to create a booking queue"<<endl;
     cout<<"press 2 to request for a booking"<<endl;
     cout<<"press 3 to cancel request"<<endl;
     cout<<"press 4 to see the booking list"<<endl;
     cout<<"press 5 to find booking number in the list"<<endl;
     cout<<"press 6 to check if all seats are booked"<<endl;
     cout<<"press 0 to exit"<<endl;
     cout<<"enter option"<<endl;
     cin>>opt;

     switch(opt)
     {
     case 1:
          createqueue();
          option();
          break;


     case 2:   // this case will call display function and will display queue items

          int a;

          if(front==-1&&rear==-1)
          cout<<"queue not created\n";
          else
          if(isfull()==1)

          cout<<"queue is already full\n";

          else
          {
          cout<<"enter element to enqueue\n";
          cin>>a;
          enqueue(a);
          }
          option();
          break;




    case 3:



          if(front==-1&&rear==-1){
          cout<<"queue not created\n";
          }
          else
          if(isempty()==1)
          {
          cout<<"queue is already empty\n";
          }
          else
          {
          cout<<"element dequeued is :"<<dequeue();
          cout<<endl;
          }
          option();

          break;


     case 4:
          display();
          option();
          break;

     case 5:
          find();
          option();
          break;

     case 6:
          {
          int a;
          if(front==-1&&rear==-1)
          cout<<"queue not created\n";
          else
          isfull();
          if(a==1)
          cout<<"queue is full\n";
          else
          cout<<"queue is not full\n";
          }
         option();
          break;




     case 0:
          exit(0);
          break;

    default:
          cout<<"invalid input\n";
          break;
          }
          }


void createqueue()
{

     do
     {
     cout<<"enter size of queue:";
     cin>>index;
     }
     while(index<=0);




     do
     {
     cout<<"enter current size of queue:";
     cin>>rear;
     }
     while(rear>index||rear<0);

     front=0;
     cout<<"enter elements\n";
     for(int i=front;i<rear;i++)
     {
        cin>>queue[i];
     }
 cout<<"queue is successfully created\n";
}


void display()
{
     if(front==-1&&rear==-1)
     cout<<"Nothing to display\n";
     else
     if(front<rear)
     {
     cout<<"The Booking list is:";
     cout<<rear-front<<endl;
    //  cout<<"elements are\n";
     for(int i=front;i<rear;i++)
     cout<<queue[i]<<endl;
     }
     else
     {
     int length;
     length=(index-front)+rear;
     cout<<"total number of elements in queue are:";
     cout<<length<<endl;
     cout<<"elements are\n";
     for(int i=front;i<index;i++)
     for(int j=0;j<rear;j++)
     cout<<queue[1]<<endl;
     }
}








void find()
{
     int temp=0;
     int number;
     int i;
     if(front==-1&&rear==-1)
     cout<<"queue not created\n";
     else
     cout<<"Enter number to find in queue\n";
     cin>>number;
     for(i=front;i<rear;i++)
     {
     if(queue[i]==number)
     {
     cout<<"Booking number found at position "<<i<<endl;
     temp=1;

     }
     }

     if(temp==0)
     cout<<"number not found!\n";

     }



void enqueue(int a)
{
     queue[rear]=a;
     rear=(rear+1)%index;
     cout<<"element is successfully enqueued\n";
}



int dequeue()
{
    int a=queue[front];
    front=(front+1)%index;
    return a;
}



int isfull()
{
    if(rear-front==rear)
    return 1;
    else
    return 0;
}


int isempty()
{
    if(front==rear)
    return 1;
    else
    return 0;
}





int main()
{
    option();
    return 0;
}


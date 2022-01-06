// it is circular queue i can use function for check empty or full .
#include <iostream>
using namespace std;
class cqueue
{
private:
    int rear,front,data[5];
public:
    cqueue()
    {
        rear=-1;
        front=-1;
    }
    void add(int x)
    {
        if(front==-1&&rear==-1)
        { ++front;data[++rear]=x;
            return;
        }
         if((rear==4 && front==0)||(rear+1==front))
            cout<<"queue is full\n";
         else if(rear<4)
        {
            data[++rear]=x;
        }
        else if (rear==4&&front>0)
        {
            rear=-1;
            data[++rear]=x;
        }
       
    }
    void dell( )
    {
        if(front==-1 )
            cout<<"queue already empty\n";
       else  if(rear==front)
        {rear=-1;front=-1;
            cout<<"all element now deleted\n";
        }
        else if(front==4)//&&front>rear//else // cout<<"all is deleted\n";
            front=0;
        else
        {
            ++front;
        }
    }
    void show()
    {
        if(rear==-1&&front==-1)
        cout<<"'it is empty'\n";
        else if(rear>=front )
        {
            for( int i=front;i<=rear;i++)
            { cout<<data[i]<<" ";}
            cout<<endl;
        }
        else //if( front>rear)
        {
            for( int i=front;i<5;i++)
            {
                cout<<data[i]<<" ";
            }
            for( int i=0;i<=rear;i++)
            {
                cout<<data[i]<<" ";;
            }
            cout<<endl;
        }
    }
};
int main()
{
    cqueue a;
    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5);
    a.show();
   // a.add(6);
    a.dell();
    a.dell();
    a.show();
    a.add(6);
    a.add(7);
    a.show();
    a.dell();
    a.dell();
    a.dell();
    a.dell();
    a.dell();
    a.dell();
    a.show();
}
/*
 // this is method for circle queue i creat it and it easy
 #include <iostream>
 using namespace std;
 #define size 5
 class queue
 {
 private:
     int rear ,data[5];
     //int front;
 public:
     queue()
     {
         rear=0;
         //front=0;
     }
     void push(int n)
     {
     //  if(front==-1 )
     //    { front++;}
         if(rear==5)
         {
             cout<<"queue is full\n";
         }
         else
             data[rear++]=n;
     }
     void pop( )
     {
         if(rear==0)
             cout<<"queue is empty\n";
         else
         {
             rear--;
             for(int i=0;i<4;i++)
             {
                 data[i]=data[i+1];
             }
             
         }
     }
     void show( )
     {
         if(rear==0)
             cout<<"queue is empty\n";
         else
         {
             for(int i=0;i<rear;i++)
                {
                    cout<<data[i]<<" ";
                 }
             cout<<endl;
         }
      //   cout<<"?"<<endl;
     }
 };
 int main()
 {
    
     queue q;
     q.push(1);
     q.push(2);
     q.push(3);
     q.push(4);
     q.push(5);
     q.show();
     //q.push(6);
     //q.show();
     q.pop();
     q.pop();
     //q.pop();
     //q.pop();
     //q.pop();
     q.push(1);
     q.push(2);
     q.show();
     q.pop();
     q.pop();
     q.pop();
     q.push(3);
     q.push(4);
     q.push(5);
     q.show();
 }



 */

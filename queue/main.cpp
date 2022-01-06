#include <iostream>
using namespace std;
#define size 5
class queue
{
private:
    int rear,front ,data[5];
public:
    queue()
    {
        rear=-1;
        front=-1;
    }
    void push(int n)
    {
       
        if((rear==size-1&&front==0)||front==rear+1)
            cout<<"queue is full\n";
        else
        {
            if(front==-1)
            {
                front=0;
                data[++rear]=n;
            }
           else if(rear<5)
                data[++rear]=n;
            else
                if(rear==4)
                  {
                      rear=0;
                      data[rear]=n;
                  }
        }
        
    }
    void pop( )
    {
        if(front==-1)
        {cout<<"queue is empty\n";}
        else if(rear==front)
        {
            rear=-1;
            front=0;
            cout<<"queue is becom empty\n";
        }
        else if(front==size-1)
            front=0;
        else
            front++;
    }
    void show( )
    {
        if(rear>front)
        {
            for(int i=front;i<=rear;i++)
            {
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
        else if(rear<front)
        {
            for(int i=front;i<size;i++)
            {
                cout<<data[i]<<" ";
            }
            for(int i=0;i<=rear;i++)
            {
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    queue w;
    w.push(1);
    w.push(2);
    w.push(3);
    w.push(4);
    w.push(5);
    w.push(6);
    w.push(7);
    w.show();
    w.pop();
    w.pop();
    w.show();
    w.push(6);
    w.push(7);
    w.show();
}
// this algorithm is soo good 
/*
 #include <iostream>
 using namespace std;
 template<typename t>
 class queue
 {
 private:
     int front,rear;
     int max;
     int conter;
     t*t1;
 public:
     queue(int max)
     {
         this->max=max;
         rear=front=-1;
         t1=new t[max];
         conter=0;
     }
     bool empyt()
     {
         return conter==0;
     }
     bool full()
     {
         return conter==max;
     }
     void add(t val)
     {
         if(full())
             return;
         else
         {
             rear = (rear + 1) % max;
             conter++;
             t1[rear] = val;
         }
     }
     void del()
     {
       if(empyt())
           return;
         {
             front=(front+1)%max;
             conter--;
         }
     }
    void display()
     {
         cout<<t1[(front+1)%max]<<endl;
     }
 };
 int main()
 {
     queue<int> q1(5);
     q1.add(1);
     q1.add(2);
     q1.add(3);
     q1.add(4);
     q1.add(5);
     while(!q1.empyt())
     {
         q1.display();
         q1.del();
     }
 }

 */

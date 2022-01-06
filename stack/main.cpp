/* ************************** __________ stack______________*********************************/
#include<iostream>
using namespace std;
#define size 5
class stack
{
private:
    int top=-1;
    long int data[size];
public:
    stack( )
    {
       // top=-1;
    }
    void pop(int z);
    void push( );
    void show( );
};
void stack::pop(int z)
{
    if(top==size-1)
        cout<<"stack is full\n";
    else
       data[++top]=z;
}
void stack::push( )
{
    if(top==-1)
        cout<<"stack is empty\n";
    else
        top--;
}
void stack::show( )
{
    if(top==-1)
        cout<<"stack is empty\n";
    else
    {
        for(int i=top;i>=0;i--)//------------filo-------------//
        {
            cout<<data[i];
            cout<<"\t\t\t\t\t\t\t\t\t\t\t_\n";
        }
    }
}
int main( )
{
    stack s1;
    int q,r,num;
    while(1)
    {
        cout<<"what u want?"
        <<"1-add\n"
        <<"\t\t\t2-delete\n"
        <<"\t\t\t3-print\n";
        cin>>q;
        switch (q)
        {
            case 1:
                cout<<"how many number u wanna to add?\n";
                cin>>r;
                while(r>0)
                {
                    cout<<"enter the number which u waana to add";
                    cin>>num;
                    s1.pop(num);
                    r--;
                }
               // r=0;
                break;
            case 2:
                cout<<"how many number u wanna to delete?\n";
                cin>>r;
                while(r>0)
                {
                    s1.push();
                    r--;
                }
          //      r=0;
                break;
            case 3:
                cout<<"_____________________________________________\n";
                
                   s1.show();
                cout<<"______________________________________________\n";
                break;
            default:
                cout<<"error->enter just 1 or 2 or 3\n";
                break;
        }
    }
    
}
/*
 pop( )-> add
 push()->delet
 show()->print
 top  as pointer
 size
 */


#include <iostream>
using namespace std;
class stack
{
private:
    struct node
    {
        int val;
        node* next;
    };
    node* top=NULL;
public:
    bool isempty( )
    {
        if(top==NULL)
            return 1;
        else
            return 0;
    }
    void push(int val )
    {
        node* newnode=new node;
        newnode->val=val;
        if(isempty())
        {
            newnode->next=NULL;
            top=newnode;
        }
        else
        {
        newnode->next=top;
        top=newnode;
        }
    }
    void pop( )
    {
        if(isempty())
        {cout<<"it is empty";return;}
        node* temp=top;//to deleete the //position from memory;
        top=top->next;
         delete temp;
    }
    int topvalue( )
    {
        if(isempty())
            return 0;
        else
        return top->val;
    }
};
int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    while(! s.isempty( ))
    {
        cout<<s.topvalue()<<endl;
        s.pop();
    }
}

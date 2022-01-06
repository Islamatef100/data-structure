
#include<iostream>
using namespace std;
class dubbly_linked_lits
{
private:
    struct node
    {
        int val;
        node *next,*prev;
        node()
        {
            val=NULL;
            next=NULL;
            prev=NULL;
        }
    };
    node* head=NULL;
public:
    void append(int val)
    {
        node *newnode=new node;
        newnode->val=val;
        if(head==NULL)
        {head=newnode;
            //newnode->prev=NULL;
            
        }
        node* tempe=head;
        while(tempe->next!=NULL)
        {
            tempe=tempe->next;
        }
        newnode->prev=tempe;
        tempe->next=newnode;
        delete tempe;
    }
    void insert_at_pos(int val,int pos)
    {
        node *newnode=new node;
        newnode->val=val;
        if(head==NULL)
            head=newnode;
        if(pos==0)
        {
            newnode->next=head;
            newnode->prev=NULL;
            head=newnode;
        }
        node *tempe=head;
        for(int i=0;i<pos;i++)
        {
            if(tempe==NULL)
                break;
            tempe=tempe->next;
        }
        if(tempe==NULL)
           this-> append(val);
        newnode->next=tempe;
        tempe->prev=newnode;
        newnode->prev=tempe->prev;
        tempe->prev->next=newnode;
    }
    void remove(int val)
    {
        node* tempe=head;
        if( head==NULL)//a
            return;
        if(tempe->val==val)
        {
            head=head->next;//head changed hear
            if(head!=NULL)//very importan if i have one element i have not head->prev for one element
            head->prev=NULL;
            delete tempe;
            return;
        }
        while(tempe->val!=val)
        {
            if(tempe==NULL)
                break;
            tempe=tempe->next;
        }
        if(tempe==NULL)
            return;
        tempe->prev->next=tempe->next;// if it last element it must be (null)
        if(tempe->next!=NULL)// if i use last element trmp->next shoud be null
        tempe->next->prev=tempe->prev;
        delete tempe;
    }
    void desplay()
    {
        node* temple=head;
        while(temple->next!=NULL)
        {
            cout<<temple->val<<" ";
            temple=temple->next;
        }
        delete temple;
        cout<<endl;
    }
    void reverse( )
    {
        node* temple=head;
        while(temple->next!=NULL)
        {
            temple=temple->next;
        }
        while(temple->prev!=NULL)
        {
            cout<<temple->val<<" ";
            temple=temple->prev;
        }
        cout<<endl;
    }
};
int main( )
{
    dubbly_linked_lits l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);
    l.append(6);
   // l.desplay();
   // l.reverse();
   // l.desplay();
}

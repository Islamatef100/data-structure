// -----------------linked list whith HARD CODE-----------------------
#include <iostream>
using namespace std;
class linked
{
private:
    struct node
    {
        int value;
        node* next;
    };
    node* head;
public:
    linked( )
    {
        head=NULL;
    }
    void append(int v)
    {
       node*newnode= new node;
        newnode->value=v;
        newnode->next=NULL;
        if(head==NULL)
            head=newnode;
        else
        {
            node* temple=head;
            while(temple->next!=NULL)
            {
                temple=temple->next;
            }
            temple->next=newnode;
        }
        
    }
    void desplay()
    {
        node* tempe;
        tempe=head;
        if(tempe==NULL)
        {cout<<"this linked have not elements\n"; delete tempe;return;}
        while(tempe!=NULL)
        {
            cout<<tempe->value<<" ";
            tempe=tempe->next;
        }
        delete tempe;
    }
    void remove(int val)
    {
        node* tempe,*preve;
        preve=tempe=head;
        if(val==tempe->value)
        {
            head=tempe->next;
            delete tempe;
            return;
        }   
        while(tempe!=NULL&&tempe->value!=val)
        {
            preve=tempe;
            tempe=tempe->next;
        }
        if(tempe==NULL)
        {
            cout<<"this value dos not thier\n";
            delete tempe;
            return;
        }
        else
        {
            preve->next=tempe->next;
            delete tempe;
        }
    }
    void insert_at_pos(int val,int pos)
    {
        node*newnode=new node;
        newnode->value=val;
        newnode->next=NULL;
        node* tempe;
        tempe=head;
        if(pos==0)
        {
            newnode->next=head;
            head=newnode;
            return;
        }
        for(int i=0;i<pos-1;i++)
        {
            if(tempe->next==NULL)
                break;
            tempe=tempe->next;
        }
        newnode->next=tempe->next;
        tempe->next=newnode;
    }
    void remove_at_pos(int pos)
    {
        node* temp;
        temp=head;
        if(pos==0)
        {
            head=head->next;
        }
        else
        {
            for(int i=0;i<pos-1;i++)
            {
                if(temp->next==NULL)
                    break;
                temp=temp->next;
            }
            if(temp->next==NULL)
            {
                cout<<"this possition have not any element\n";
                return;
            }
            else
            {
                node*temp2=temp->next;
                temp->next=temp->next->next;
                delete temp2;
                delete temp;
            }
        }
        
    }
    void reverse()
    {
        node *current=head,*prev=NULL,*next=NULL;
        if(head==NULL)
        {cout<<"list is empty\n";return;}
        while(current!=NULL)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
        delete current,prev,next;
    }
};
int main()
{
    linked l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);
    l.desplay();
    cout<<endl;
    l.reverse();
    l.desplay();
}

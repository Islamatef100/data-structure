#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
    double data;
    node* left;
    node* right;
    
};
class binary_search_tree
{
private:
    node*head;
    //this function of get minimum number inside the tree.and this part private in function
    double getmin(node* temp)
    {
        if(temp->left==nullptr)
            return temp->data;
        else
        return getmin(temp->left);
        
    }
    /*this function is a part of gethieght function but it private becouse recursion and private data in this part*/
    int gethieghthealper(node* temp)
    {
        //recursion in data structur need to drawn to understand it.
        if(temp==nullptr)
            return 0;
        int left_subtree=gethieghthealper(temp->left);
        int right_subtree=gethieghthealper(temp->right);
        //note that if u want to use existed function in liberaries u must write ::befor the function
        //but in class just not in main function.
        return 1+ ::max(left_subtree,right_subtree);
    }
    //this function for print pre order
    void help_print_pre_order(node*temp)
    {
        if(temp==nullptr)return;
        cout<<temp->data<<" ";
        help_print_pre_order(temp->left);
        help_print_pre_order(temp->right);
    }
    void help_print_in_order(node*temp)
    {
        if(temp==nullptr)return;
        help_print_pre_order(temp->left);
        cout<<temp->data<<" ";
        help_print_pre_order(temp->right);
    }
    void help_print_post_order(node*temp)
    {
        if(temp==nullptr)return;
        help_print_pre_order(temp->left);
        help_print_pre_order(temp->right);
        cout<<temp->data<<" ";
    }
public:
    binary_search_tree( )
    {
        head=nullptr;
    }
    void add(double data)
    {
        node*newnode=new node;
        newnode->left=nullptr;
        newnode->right=nullptr;
        newnode->data=data;
        if(head==nullptr)
        {
            head=newnode;
        }
        else
        {
            node*temp=head;
            node*parent=nullptr;
            while(temp!=nullptr)
            {
                parent=temp;
                if(data>temp->data)
                    temp=temp->right;
                else
                {
                    temp=temp->left;
                }
            }
            if(data>parent->data)
            parent->right=newnode;
            else
                parent->left=newnode;
        }
        
    }
    double max()
    {
        node*temp=head;
        while(temp->right !=nullptr){ temp=temp->right;}
        return temp->data;
    }
   /* double min()
    {
        node*temp=head;
        while(temp->left!=nullptr){temp=temp->left;}
        return temp->data;
    }*/
    //this the same code but by recursion
    void min()
    {
        cout<< getmin(head)<<endl;;
    }
    int getheight()
    {
        return gethieghthealper(head);
    }
    //this technique is breadth order.
    void print_level_order( )
    {
        queue<node*> q;
        if(head==nullptr)
            return;
        node*temp=head;
        q.push(temp);
        while(!q.empty())
        {
            temp=q.front();
            cout<<temp->data<<" ";
            q.pop();
           if(temp->left!=nullptr)q.push(temp->left);//i must check becouse it possible to add null ptr.
            if(temp->right!=nullptr)q.push(temp->right);
            
        }
        cout<<endl;
    }
    //this function for searsh if the element exist in the tree or not.
    bool find(double data)
    {
        if(head==nullptr)
            return false;
        node*temp=head;
            while(temp!=nullptr)
            {
                if(temp->data==data)
                    return true;
                if(data>temp->data)
                      temp=temp->right;
                else
                        temp=temp->left;
            }
        if(temp==nullptr)
            return false;
        return 0;
    }
    void print_pre_order()
    {
        //this function in private becouse i used private data.
        if(head==nullptr)return;
        help_print_pre_order(head);
        cout<<endl;
    }
    void print_in_order()
    {
        //this function in private becouse i used private data.
        if(head==nullptr)return;
        help_print_in_order(head);
        cout<<endl;
    }
    void print_post_order()
    {
        //this function in private becouse i used private data.
        if(head==nullptr)return;
        help_print_post_order(head);
        cout<<endl;
    }
    //this code for first and second case wich i created it and it corect
    //but there is code of hard code solve this function.
    void delet(double data)
    {
     if(head==nullptr)
     {cout<<"tree if empty.\n";return;}
        node*temp=head;
        node*temp2=nullptr;
        while(temp!=nullptr&&temp->data!=data)
        {
            temp2=temp;
            if(data>temp->data)
                temp=temp->right;
            else
                temp=temp->left;
        }
        if(temp==NULL)
            cout<<"the element not exist:\n";
        else if(temp->right==nullptr&&temp->left==nullptr)
        {
            if(data>temp2->data)
                temp2->right=nullptr;
            else if(data<temp2->data)
                  temp2->left=nullptr;
            delete temp;
            cout<<"the element with value->"<<data<<" is deleted:\n";
        }
        else if(temp->right==nullptr||temp->left==nullptr)
        {
            if(data>temp2->data)
            {
                if(temp->right!=nullptr)
                {
                    temp2->right=temp->right;
                }
                else
                {
                    temp2->right=temp->left;
                }
             }
                else
                {
                    if(temp->right!=nullptr)
                    {
                        temp2->left=temp->right;
                    }
                    else
                    {
                        temp2->left=temp->left;
                    }
                }
            delete temp;
            cout<<"the element with value->"<<data<<" is deleted:\n";
        }
        else
        {
            
            
        }
        
    }
};

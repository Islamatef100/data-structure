#include <iostream>
using namespace std;
#include<vector>
class heep_with_mustafa_saad
{
private://this function user dont use it
    vector<int>  heap;
    int left(int node);
    int right(int node);
    int parent(int node);
    void reheapUp(int pos);
    void reheapDown(int pos);
public://this function user willuse it.
    int top();
    void push(int key);
    void pop();
    void print();
    int size();
};
int heep_with_mustafa_saad::top()
{
    if(heap.size()==0)
        return -1;
    return heap.front();
}

void heep_with_mustafa_saad::push(int kay)
{
    heap.push_back(kay);
    reheapUp(heap.size()-1);
}
void heep_with_mustafa_saad::pop()
{
    if(heap.size())
    {
        heap[0]=heap.back();
        heap.pop_back();
        reheapDown(0);
    }
   
}
int heep_with_mustafa_saad::size()
{
    return heap.size();
}
void heep_with_mustafa_saad::print()
{
    for(auto it:heap)
        cout<<it<<" ";
    cout<<endl;
}
int heep_with_mustafa_saad::left(int node)
{
    return (2*node+1);
}
int heep_with_mustafa_saad::right(int node)
{
    return (2*node+2);
}
int heep_with_mustafa_saad::parent(int node)
{
    return ((node-1)/2);
}
void heep_with_mustafa_saad::reheapUp(int pos)
{
    if(pos==0||heap[pos]>heap[parent(pos)])
        return;
    swap(heap[pos],heap[parent(pos)] );
    reheapUp(parent(pos));
    
}
void heep_with_mustafa_saad::reheapDown(int pos)
{
    int seleft=left(pos);
    if(seleft==-1)
        return;
    
    if(heap[seleft]>heap[right(pos)]&&right(pos)!=-1)
        seleft=right(pos);
    if(heap[pos]>heap[seleft])
    {
        swap(heap[pos], heap[seleft]);
        reheapDown(seleft);
    }
}

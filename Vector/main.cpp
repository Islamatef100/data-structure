//this code already writen in liberary vector
//  main.cpp
//  vector
//  Created by Mac on 2/20/22.
#include <iostream>
using namespace std;
#include <vector>
template<typename storedata>
class Vector
{
    private:
        storedata* data=nullptr;
        int size,capacity;//size of vectore wich user need.
        static int exist_data;
    void expand_vector( )//to expand vector.
    {
        capacity*=2;
        storedata* newdata=new storedata[capacity];
        for(int i=0;i<exist_data;i++)
        {
            newdata[i]=data[i];
        }
        swap(data, newdata);
        delete [] newdata;
    }
    public:
        Vector(int size)//constructor.
        {
            capacity=size*2;
            data=new storedata[capacity];
        }
        Vector()//default constractor.
        {
            data=new storedata[50];
        }
        void set(storedata x);//set data
        storedata get();
        int find(storedata x);//for searching
        void print();//for print all data
        storedata get_front();//to get from start
        storedata get_back();//to get element from end
        void  push_front(storedata x);//to store in start.
        void push_back( storedata x);//to store in end.
    void inssert(int index,storedata x);//to store in any possition
    ~Vector()//deconstructor
    {
        delete []data;
    }
};
template<typename storedata>
int Vector<storedata>::exist_data=0;//siz of my vector
template<typename storedata>
void Vector<storedata>:: set(storedata x)
{
    store:
    if(exist_data<capacity){
    data[exist_data]=x;
        ++exist_data;}
    else
    {
        capacity*=2;
        cout<<"you hsve not space to store data but i increase storage space = ( "<<capacity<< " )\n";
        goto store;
    }
       
}
template<typename storedata>
storedata Vector<storedata>::get()
{
    return data[exist_data];
}
template<typename storedata>
int Vector<storedata>::find(storedata x)
{
    for(int i=0;i<exist_data;i++)
    {
        if(x==data[i])
            return i;
    }
    return -1;//if not exist.
}
template<typename storedata>
void Vector<storedata>::print()
{
    for(int i=0;i<exist_data;i++)
    cout<<data[i]<<endl;
}
template<typename storedata>
storedata Vector<storedata>:: get_front()
{
    return data[0];
}
template<typename storedata>
storedata Vector<storedata>:: get_back()
{
   // cout<<"back "<<exist_data<<endl;
    return data[exist_data-1];
}
template<typename storedata>
void Vector<storedata>::push_front(storedata x)
{
    if(exist_data>=capacity)
    {
        capacity*=2;
        storedata* newdata=new storedata[capacity];
        newdata[0]=x;
        for(int i=0;i<exist_data;i++)
        {
            newdata[i+1]=data[i];
        }
        swap(data, newdata);
        exist_data++;
        delete [] newdata;
    }
    else
    {
        storedata* newdata=new storedata[capacity];
        newdata[0]=x;
        for(int i=0;i<exist_data;i++)
        {
            newdata[i+1]=data[i];
        }
        swap(data, newdata);
        exist_data++;
        delete [] newdata;
    }
}
template<typename storedata>
void Vector<storedata>:: push_back(storedata x)
{
    if(exist_data>=capacity)
    {
        expand_vector();
        data[exist_data]=x;
        exist_data++;
    }
    else
    {
        storedata* newdata=new storedata[capacity];
        for(int i=0;i<exist_data;i++)
        {
            newdata[i]=data[i];
        }
        newdata[exist_data]=x;
        swap(data, newdata);
        exist_data++;
        delete [] newdata;
    }
}
template<typename storedata>
void Vector<storedata>:: inssert(int index,storedata x)
{
    if(index>=exist_data)
            expand_vector();
    for(int i=exist_data-1;i>index;i--)
    {
        data[i+1]=data[i];
    }
    data[index]=x;
    exist_data++;
}
int main()
{
    // this test sime funcion.
    Vector<int>v(5);
    v.set(1);
    v.set(2);
    v.set(3);
    v.set(4);
    v.set(5);
    v.set(6);
    v.set(7);
    v.set(8);
    v.set(9);
    v.set(10);
    v.inssert(4, 100);// not done
    v.print();
    v.push_back(100);
    v.push_front(100);
    v.print();
}












#include<iostream>
#include "tree.h"
using namespace std;
int main( )
{
    binary_search_tree b;
    b.add(15);
    b.add(6);
    b.add(20);
    b.add(25);
    b.add(3);
    b.add(9);
    b.add(8);
    b.delet(6);
    b.print_level_order();
    /*cout<<"____________________________________________\n";
    cout<<b.max()<<endl;
    cout<<"____________________________________________\n";
     b.min( );
    cout<<"____________________________________________\n";
    cout<<  b.getheight()<<endl;
    cout<<"____________________________________________\n";
    b.print_level_order();
    cout<<"____________________________________________\n";
    cout<<b.find(10)<<endl;
    cout<<"____________________________________________\n";
    b.print_pre_order();
    cout<<"____________________________________________\n";
    b.print_in_order();
    cout<<"____________________________________________\n";
    b.print_post_order();
    cout<<"____________________________________________\n";
  //  b.delet(8);
   // cout<<"____________________________________________\n";
   // b.print_level_order();
  //  cout<<"____________________________________________\n";
     */
   
}

#include <iostream>
#include "practice2.hpp"
using namespace std;
int main(){
    linkedlist list; 
    list.insertFront(1);
    list.insertFront(3);
    list.insertMiddle(2,2);
    list.insertEnd(5);
    list.deleteFront();
    list.deleteMiddle(1);
    list.SwapTwoNode(0,1);
    list.SearchInLinkedList(1);
    list.traverse();
}

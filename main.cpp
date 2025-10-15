#include <iostream>
using namespace std; 

struct Node{
    int value;
    Node* next; 
};

class linkedlist{
    private: 
    Node* head, *cur; 
    int n;
    public:
    linkedlist(){

        head = nullptr; 
        cur = nullptr; 
        n = 0;

    }
    int size(){return n;}

    void traverse(){
        if (n ==0 ){
            cout << "(empty!)\n";
            return ;
        }
        cur = head ;
        while (cur != nullptr){
            cout << cur-> value<<"->";
            cur = cur->next;
    }
    }
    Node* gethead(){return head;}

void insertFront ( int val){
        Node* nNode = new Node{ val, nullptr};
        nNode -> next = head; 
        head = nNode; 
        n++;
       }


void insertEnd(int val){
    if(n==0){
        insertFront(val);
        return;
    }
    cur = head; 
    while (cur->next != nullptr){
        cur = cur->next;
    }
    Node* nNode = new Node{val, nullptr};
    cur->next = nNode; 
    n++;
}

void insertMiddle( int val , int pos){
    if ( pos > n){
        cout <<" Out of node range!\n";
        return;
    }
    if(pos == 0 ){
        insertFront(val);
        return;
    }
    if ( pos == n){
        insertEnd(val);
        return;
    }
    cur = head;
    for (int i = 0; i < pos - 1; i++) {
        cur = cur->next;
    }
    Node* nNode = new Node{val, nullptr };
    nNode->next = cur->next; 
    cur->next = nNode;
    n++;
}


void deleteFront(){
    if ( n == 0){
        cout << " NO node to delete!\n"; 
        return;
    }
    Node* temp = head;
    head = head->next;  
    delete temp; 
    n--;
    cur = head;
    while (cur != nullptr) {
        cout << cur->value << "->";
        cur = cur->next;
    }
    cout << "\n";
}

void deleteEnd(){
    if(n == 0){
        cout<< " No node to delete!\n";
        return;
    }
    cur = head;
    while (cur->next->next != nullptr){
        cur = cur->next;
    cur->next = nullptr;
    n--;
}


void deleteMiddle(int pos){
    if ( pos >= n){
        cout << " NO node to delete!\n";
        return;
    }
    if ( pos == 0){
        deleteFront();
        return;
    }
    if ( pos == n-1){
        deleteEnd();
        return;
    }
    cur = head;
    for ( int i = 0; i < pos - 1; i++){
        cur = cur->next;
    }
    Node* temp = cur->next;
    cur->next = cur->next->next;
    delete temp;
    n--;
    cur = head;
    while (cur != nullptr) {
        cout << cur->value << "->";
        cur = cur->next;
    }
    cout << "\n";
}

void SwapTwoNode (int pos1, int pos2){
    if ( pos1 >= n || pos2 >= n){
        cout << " NO node to swap!\n";
        return;
    }
    if ( pos1 == pos2){
        return;
    }
    if ( pos1 > pos2){
        int temp = pos1;
        pos1 = pos2;
        pos2 = temp;
    }
    Node* prev1 = nullptr, *curr1 = head;
    for ( int i = 0; i < pos1; i++){
        prev1 = curr1;
        curr1 = curr1->next;
    }
    Node* prev2 = nullptr, *curr2 = head;
    for ( int i = 0; i < pos2; i++){
        prev2 = curr2;
        curr2 = curr2->next;
    }
    if ( prev1 != nullptr){
        prev1->next = curr2;
    } else {
        head = curr2;
    }
    if ( prev2 != nullptr){
        prev2->next = curr1;
    } else {
        head = curr1;
    }
    Node* temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;
}

void SearchInLinkedList(int val){
    if ( n == 0){
        cout << " No node to search!\n";
        return;
    }
    cur = head;
    int pos = 0;
    while ( cur != nullptr){
        if ( cur->value == val){
            cout <<"Value " << val << " found at position " << pos << "\n";
            return;
        }
        cur = cur->next;
        pos++;
    }
    cout <<"Value " << val << " not found in the list.\n";   
}


};

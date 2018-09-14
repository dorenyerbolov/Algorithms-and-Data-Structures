#include <iostream>
using namespace std;
 
class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
 
class Queue {
private:
    Node *head, *tail;
    int sz;
public:
    Queue(){
        head = tail = NULL;
        sz = 0;
    }
    int size(){
        return sz;
    }
    void clear(){
        head = tail = NULL;
        sz = 0;
    }
    int front(){
        if(head != NULL){
            return head->data;
        }
    }
    void pop(){
        if(head != NULL){
            head = head->prev;
            sz--;
        }
    }
    void push(int n){
        Node *node = new Node(n);
        if (head == NULL){
            head = node;
            tail = node;
        }
        else {
            node->next = tail;
            tail->prev = node;
            tail = node;
 
        }
        sz++;
    }
};
 
 
int main(){
    Queue myQueue;
    string str;
    while (cin >> str) {
        if (str == "push") {
            int n;
            cin >> n;
            myQueue.push(n);
            cout << "ok" << endl;
        }
        else if (str == "pop"){
            if(myQueue.size() > 0){
                cout << myQueue.front() << endl;
                myQueue.pop();
            }
            else {
                cout << "error" << endl;
            }
        }
        else if (str == "front") {
            if(myQueue.size() > 0){
                cout << myQueue.front() << endl;
            }
            else {
                cout << "error" << endl;
            }
        }
        else if (str == "size") cout << myQueue.size() << endl;
        else if (str == "clear") {
            myQueue.clear();
            cout << "ok" << endl;
        }
        else if (str == "exit") {
            cout << "bye" << endl;
            break;
        }
    }
    return 0;
}
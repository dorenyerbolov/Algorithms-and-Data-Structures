#include <iostream>
#include <string>   
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node(int data) {
        this->data = data;
        prev = NULL;
    }
};

class Stack {
private:
    Node *top;
    int sz;
public:
    Stack(){
        top = NULL;
        sz = 0;
    }

    int size(){
        return sz;
    }
    void clear(){
        top = NULL;
        sz = 0;
    }
    bool empty(){
        return sz == 0;
    }
    int back(){
        return top->data;
    }
    void push(int data){
        Node *node = new Node(data);
        node->prev = top;
        top = node;
        sz++; 
    }
    void pop(){
        top = top->prev;
        sz--;
    }
};
int main(){
    Stack myStack;
    string str;
    while (cin >> str) {
        if (str == "push") {
            int n;
            cin >> n;
            myStack.push(n);
            cout << "ok" << endl;
        }
        else if (str == "pop"){
            if(myStack.size() > 0){
                cout << myStack.back() << endl;
                myStack.pop();
            }
            else {
                cout << "error" << endl;
            }

        }
        else if (str == "back") {
            if(myStack.size() > 0){
                cout << myStack.back() << endl;
            }
            else {
                cout << "error" << endl;
            }
        }
        else if (str == "size") cout << myStack.size() << endl;
        else if (str == "clear") {
            myStack.clear();
            cout << "ok" << endl;
        }
        else if (str == "exit") {
            cout << "bye" << endl;
            break;
        }
    }
    return 0;
}
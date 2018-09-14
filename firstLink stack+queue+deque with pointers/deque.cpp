#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next, *prev;
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
	int back(){
		return tail->data;
	}
	int front(){
		return head->data;
	}
	void pop_back(){
		tail = tail->next;
		sz--;
		if (tail != NULL){
			tail->prev = NULL;
		}
		else head = NULL;
	}
	void pop_front(){
		head = head->prev;
		sz--;
		if (head != NULL) {
			head->next = NULL;
		}
		else tail = NULL;
	}
	void push_back(int n){
		Node *node = new Node(n);
		if (tail == NULL){
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
	void push_front(int n){
		Node *node = new Node(n);
		if (head == NULL){
			head = node;
			tail = node;
		}
		else {
			node->prev = head;
			head->next = node;
			head = node;

		}
		sz++;
	}
};


int main(){
	Queue myQueue;
	string str;
	while (cin >> str) {
		if (str == "push_back") {
			int n;
			cin >> n;
			myQueue.push_back(n);
			cout << "ok" << endl;
		}
		else if (str == "push_front") {
			int n;
			cin >> n;
			myQueue.push_front(n);
			cout << "ok" << endl;
		}
		else if (str == "pop_back"){
			if(myQueue.size() > 0){
				cout << myQueue.back() << endl;
				myQueue.pop_back();
			}
			else {
				cout << "error" << endl;
			}
		}
		else if (str == "pop_front"){
			if(myQueue.size() > 0){
				cout << myQueue.front() << endl;
				myQueue.pop_front();
			}
			else {
				cout << "error" << endl;
			}
		}
		else if (str == "back") {
			if(myQueue.size() > 0){
				cout << myQueue.back() << endl;
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
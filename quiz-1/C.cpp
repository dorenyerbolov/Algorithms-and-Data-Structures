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
	void popRight(){
		tail = tail->next;
		sz--;
		if (tail != NULL){
			tail->prev = NULL;
		}
		else head = NULL;
	}
	void popLeft(){
		head = head->prev;
		sz--;
		if (head != NULL) {
			head->next = NULL;
		}
		else tail = NULL;
	}
	void pushRight(int n){
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
	void pushLeft(int n){
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
	int num; // number of test cases
	int sizeOfQueue; // maxSize
	int numOfOperations; // number of Operations
    freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> num;
	string str;
	int i = 1;
	while(num--) {
		Queue *myQueue = new Queue();
		cin >> sizeOfQueue >> numOfOperations;
		cout << "Case " << i << ":" << endl;
		i++;
		while(numOfOperations--) {
		cin >> str;
		if (str == "pushRight") {
			int n;
			cin >> n;
			if(myQueue->size()<sizeOfQueue){
			myQueue->pushRight(n);	
			cout << "Pushed in right: ";
			cout << n << endl;
			}
			else cout << "The queue is full" << endl;
		}
		else if (str == "pushLeft") {
			int n;
			cin >> n;
			if(myQueue->size()<sizeOfQueue){
			myQueue->pushLeft(n);
			cout << "Pushed in left: ";
			cout << n << endl;
			}
			else cout << "The queue is full" << endl;

		}
		else if (str == "popRight"){
			if(myQueue->size()>0){
				int popped = myQueue->back();
				myQueue->popRight();
				cout << "Popped from right: ";
				cout << popped << endl;
			}
			else cout << "The queue is empty" << endl;
			
		}
		else if (str == "popLeft"){
			if(myQueue->size()>0){
			    int popped = myQueue->front();
				myQueue->popLeft();
				cout << "Popped from left: ";
				cout << popped << endl;
			}
			else cout << "The queue is empty" << endl;
		}
	}

	}
	return 0;
}
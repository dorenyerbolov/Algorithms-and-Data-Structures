#include <bits/stdc++.h>

using namespace std;
struct Node{
public:
	int key;
	Node *next;
	Node *prev;
	Node(int _key){
		key = _key;
		next = prev = NULL;
	}
};
struct Deque{
private:
	Node *tail;
	Node *head;
	int sz;
public:
	Deque(){
		head = tail = NULL;
		sz = 0;
	}
	void push_back(int n){
		Node *node = new Node(n);
		if(tail == NULL){
			tail = head = node;
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
		if(head == NULL){
			head = tail = node;
		}
		else {
			node->prev = head;
			head->next = node;
			head = node;
		}
		sz++;
	}
	void back(){
	    cout << tail->key << "\n";
		tail = tail->next;
		sz--;
		if(tail != NULL){
			tail->prev = NULL;
		}
		else head = NULL;
	}
	void front(){
		cout << head->key << "\n";
		head = head->prev;
		sz--;
		if(head != NULL){
			head->next = NULL;
		}
		else tail = NULL;
	}
	bool empty(){
		return sz == 0;
	}
};

void solve(int test_case){
	Deque dek;
	string cmd;
	int nt, n;
	cin >> nt;
	bool reverse = false;
	while(nt--){
		cin >> cmd;
		if(cmd == "push_front"){
			cin >> n;
			dek.push_front(n);
		}
		else if(cmd == "push_back"){
			cin >> n;
			dek.push_back(n);
		}
		else if(cmd == "front"){
			if(dek.empty()){
				cout << ";(\n";
				continue;
			}
			dek.front();
		}
		else if(cmd == "back"){
			if(dek.empty()){
				cout << ";(\n";
				continue;
			}
			dek.back();
		}
		else if(cmd == "reverse"){
			//dek.reverse();
			reverse = true;
		}
	}

}
int main(){
	solve(0);
	return 0;
}
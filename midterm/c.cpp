#include <iostream>

using namespace std;
struct Node {
	int val;
	Node *next, *prev;

	Node(int _val){
		val = _val;
		next = prev = NULL;
	}
};
struct LinkedList {
public:
	Node *head, *tail;

	LinkedList() {
		head = tail = NULL;
	}
	int cnt(int x){
		Node* current = head;
		int cnt = 0;
		while(current != NULL){
			if(current->val == x) cnt++;
			current = current->prev;
		}
		return cnt;
	}
	int getNth(int n){
		Node *current = head;
		int index = 0;
		while(current != NULL){
			if(index == n) return current->val;
			index++;
			current = current->prev;
		}
		return -1;
	}
	void insertLast(int x) {
		Node* node = new Node(x);
		if (tail == NULL) {
			head = tail = node;
			return;
		} else {
			tail->prev = node;
			node->next = tail;
			tail = node;
		}
	}
	void insertFirst(int x) {
		Node* node = new Node(x);
		if (head == NULL) {
			head = tail = node;
			return;
		} else {
			head->next = node;
			node->prev = head;
			head = node;
		}
	}
	void deleteLast() {
		tail = tail->next;
		if (tail != NULL) {
			tail->prev = NULL;
		} else {
			head = NULL;
		}
	}
	void deleteFirst() {
		head = head->prev;
		if(head != NULL) {
			head->next = NULL;
		} else {
			tail = NULL;
		}
	}
	void del(int x) {
		Node* cur = head;
		while(cur && cur->val != x){
			cur = cur->prev;
		}
		if (!cur) return;
		if (cur == head) deleteFirst();
		else if (cur == tail) deleteLast();
		else {
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
		}
	}
	void print() {
		Node* cur = head;
		while(cur) {
			if (cur != head) cout << " ";
			cout << cur->val;
			cur = cur->prev;
		}
		cout << "\n";
	}
};

int main(){
	int n, x;
	string s;
	LinkedList *linkedList = new LinkedList();
	cin >> n;
	while(n--) {
		cin >> s;
		if (s == "insertFirst") {
			cin >> x;
			linkedList->insertFirst(x);
		}
		if (s == "delete") {
			cin >> x;
			linkedList->del(x);
		}
		if (s == "deleteFirst") {
			linkedList->deleteFirst();
		}
		if (s == "deleteLast") {
			linkedList->deleteLast();
		}
		if (s == "insertLast") {
			cin >> x;
			linkedList->insertLast(x);
		}
		if (s == "cnt") {
			cin >> x;
			cout << linkedList->cnt(x) << "\n";
		}
		if (s == "getNth") {
			cin >> x;
			cout << linkedList->getNth(x) << "\n";
		}
	}
	linkedList->print();
}
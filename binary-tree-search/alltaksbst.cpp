#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;
map<int, int>::iterator it;
struct Node{
public:
	int value;
	Node* right;
	Node* left;
	Node(int data){
		value = data;
		right = left = NULL;
	}
};

struct Tree{
public:
	Node* root;
	Tree(){
		root =  NULL;
	}
	void insertHelper(Node*& newRoot, int data){
		Node* node = new Node(data);
		if(newRoot == NULL){
			newRoot = node;
		}
		else {
			if(data < newRoot->value){
					insertHelper(newRoot->left, data);
			}
			else if(data > newRoot->value){
					insertHelper(newRoot->right, data);
			}
		}
	}
	void printHelper(Node*& newRoot){
		if(newRoot == NULL) return;
		printHelper(newRoot->left);
		cout << newRoot->value << endl;
		printHelper(newRoot->right);
	}
	int heightHelper(Node*& newRoot){
		if(newRoot == NULL){
			return 0;
		}
		int leftHeight = heightHelper(newRoot->left);
		int rightHeight = heightHelper(newRoot->right);
		return max(leftHeight, rightHeight) + 1;
	}
	int sizeHelper(Node*& newRoot){
		if(newRoot == NULL){
			return 0;
		}
		else return (1 + sizeHelper(newRoot->left) + sizeHelper(newRoot->right));
	}
    void dfsHelper(Node*& newRoot){
    	if(newRoot->left != NULL) dfsHelper(newRoot->left);
    	printf("%d ", newRoot->value);
    	if(newRoot->right != NULL) dfsHelper(newRoot->right);
    }
    void leafHelper(Node*& newRoot){
    	if(newRoot == NULL) return;
    	if(newRoot->left == NULL and newRoot->right == NULL){
    		cout << newRoot->value << endl;
    	}
    	if(newRoot->left != NULL) leafHelper(newRoot->left);
    	if(newRoot->right != NULL) leafHelper(newRoot->right);
    }
    void twoChildrenHelper(Node*& newRoot){ //node which has only 2 children
    	if(newRoot == NULL) return;
    	if(newRoot->left != NULL) twoChildrenHelper(newRoot->left);
    	if(newRoot->left != NULL and newRoot->right != NULL){
    		cout << newRoot->value << endl;
    	}
    	if(newRoot->right != NULL) twoChildrenHelper(newRoot->right);
    }
    void oneChildrenHelper(Node*& newRoot){
    	if(newRoot == NULL) return;
    	if(newRoot->left != NULL) oneChildrenHelper(newRoot->left);
    	if((newRoot->left != NULL and newRoot->right == NULL) || (newRoot->left == NULL and newRoot->right != NULL)){
    		cout << newRoot->value << endl;
    	}
    	if(newRoot->right != NULL) oneChildrenHelper(newRoot->right);
    }
    bool isBalancedHelper(Node*& newRoot){
    	if(newRoot == NULL) return true;
    	if(abs(heightHelper(newRoot->left)-heightHelper(newRoot->right))<=1 and isBalancedHelper(newRoot->left) and isBalancedHelper(newRoot->right)) return true;
    	else return false;
    }
    int firstMaxHelper(Node*& newRoot){
    	while(newRoot->right != NULL){
    		newRoot = newRoot->right;
    	}
    	return newRoot->value;
    }
    void secondMaxHelper(Node*& newRoot){
    	if(newRoot->left == NULL and newRoot->right == NULL) cout << newRoot->value;
    	Node* parent;
    	while(newRoot->right != NULL){
    		parent = newRoot;
    		newRoot = newRoot->right;
    	}
    	if(newRoot->left != NULL){
    	cout << firstMaxHelper(newRoot->left);	
    	}
    	else cout << parent->value;
    }
	void insert(int data){
		insertHelper(root, data);
		mp[data]++;
	}
	void print(){
		printHelper(root);
	}
	int height(){
		return heightHelper(root);
	}
	int size(){
		return sizeHelper(root);
	}
	void dfs(){
		dfsHelper(root);
	}
	void leaf(){
		leafHelper(root);
	}
	void twoChildren(){
		twoChildrenHelper(root);
	}
	void oneChildren(){
		oneChildrenHelper(root);
	}
	void isBalanced(){
		if(isBalancedHelper(root)){
			cout << "YES";
		}
		else cout << "NO";
	}
	void secondMax(){
		secondMaxHelper(root);
	}

};
int main(){
	Tree* myTree = new Tree();

	int x;
	//freopen("input.txt.txt", "r", stdin);
	while(cin >> x){
		if(x == 0){
			break;
		}
		myTree->insert(x);
	}
	// for(it = mp.begin(); it != mp.end(); it++){
	// 	cout << (*it).first << " " << (*it).second << endl;
	// }
	myTree->secondMax();
	return 0;
}
#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;
	
	Node(int dataa){
		data = dataa;
		left = NULL;
		right = NULL;
	} 
	
	Node * first_common(Node *x, Node *y){
		Node *root = this;
		
		if (root == NULL){
			return NULL;
		}
		else if ((root->data == x->data) || (root->data == y->data)){
			return root;
		}
			
		Node *left_result = root->left -> first_common(x, y);
		Node *right_result = root->right -> first_common(x, y);

		if (left_result && right_result ){
			return root;
		}else if(left_result == NULL && right_result){
			return right_result;
		}else if(left_result && right_result == NULL){
			return left_result;
		}else{
			return NULL;
		}

	}
};

int main(){
	Node *root = new Node(4);
	Node *b = new Node(5);
	Node *c = new Node(6); 
	Node *d = new Node(7);
	Node *e = new Node(8);
	Node *f = new Node(9);
	root->left = b;
	root->right = c;
	b->left = d;
	b ->right = e;
	c ->right = f;
	Node *anc = root->first_common(e, c);
	cout << anc ->data;
	return 0;
}
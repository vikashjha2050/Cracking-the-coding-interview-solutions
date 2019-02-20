#include<iostream>
using namespace std;

class Node
{

	int data;
	class Node* next;
public:	
	Node(int passed_data){
		data = passed_data;
		next = NULL;
	}

	Node* push(Node **minstack, int passed_data ){
		Node *head = this;
		Node* a = new Node(passed_data);
		a ->next =head;
		head = a;
		Node *minstackhead = *minstack;
		if(passed_data <= minstackhead->data){
			Node* new_node = new Node(passed_data);
			new_node->next = *minstack;
			*minstack = new_node;
		}
		return head;
	}

	Node* pop(Node **minstack){
		Node *current =  this;
		Node *minstackhead = *minstack;
		if(current->data == minstackhead->data){
			minstackhead = minstackhead -> next;
		}
		*minstack = minstackhead;
		current  = current ->next ;
		return current;
	}

	int find_min(){
		Node* head = this;
		return head->data; 
	} 
	
	void display(){
		Node *current = this;
		while(current){
			cout<<current->data;
			current = current->next;
		}
		cout<<endl;
	}

};

int main()
{
    Node* a = new Node(10);
    Node* minstack = new Node(10);
    a = a->push(&minstack, 8);
    a = a->push(&minstack, 6);
    cout<< minstack->find_min();
    a = a->pop(&minstack);
    a = a->push(&minstack, 4);
    a = a->push(&minstack, 3);
    a = a->pop(&minstack);
    a = a->push(&minstack, 12);
    cout<< minstack->find_min();
	return 0;
}
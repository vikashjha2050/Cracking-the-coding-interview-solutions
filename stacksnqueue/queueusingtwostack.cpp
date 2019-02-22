#include<iostream>
using namespace std;

class Node
{
public:	
	int data;
	class Node* next;
	Node(int passed_data){
		data = passed_data;
		next = NULL;
	}

	Node* push( int passed_data ){
		Node *head = this;
		Node* a = new Node(passed_data);
		if(head == NULL){
			head = a;
			return head; 
		}
		a ->next = head;
		head = a;
		return head;
	}

	Node* pop(Node **p){
		Node *current = *p;
		Node *head = *p;
		current = current -> next ;
		*p = current;
		return head;
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

class Myqueue
{
	Node* stack1;
	Node* stack2;
public:	
	Myqueue(){
		stack1 = NULL;
		stack2 = NULL;
	}

	Myqueue* enqueue( int passed_data ){
		Myqueue *myqueue = this;
		myqueue->stack1 = myqueue ->stack1 ->push(passed_data);
		return myqueue;
	}

	Node* dequeue(){
		Myqueue *current = this;
		Node *s1 = current->stack1;
		Node *s2 = current->stack2;
		if(current->stack2){
			Node *poped = current->stack2->pop(&(current->stack2));
			return poped;
		}
		if(current->stack1){
			while(current->stack1){
				Node *s1poped = s1->pop(&(current->stack1));
				current->stack2 = current->stack2 ->push(s1poped->data);
			}
			Node *poped = s2->pop(&(current->stack2));
			return poped;
		}else{
			return NULL;
		}
	}

	void print(){
		Myqueue *current = this;
		cout<<"stack2 data: ";
		current ->stack2 ->display();
		cout<<"stack1 data: ";
		current ->stack1 ->display();		
	}
};

int main()
{
    Myqueue *a = new Myqueue();
    a = a->enqueue( 2);
    a = a->enqueue( 8);
    a = a->enqueue( 4);
    a = a->enqueue( 5);
    a = a->enqueue( 1);
    Node *dequeued = a->dequeue();
    a = a->enqueue( 5);
    a = a->enqueue( 1);
    a->print();
	return 0;
}
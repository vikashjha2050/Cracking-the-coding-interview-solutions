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

	Node* push( int passed_data ){
		Node *head = this;
		Node* a = new Node(passed_data);
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
	Node* rare;
	Node* front;
public:	
	Myqueue(){
		rare = NULL;
		front = NULL;
	}

	Node* enqueue( int passed_data ){
		Node *head = this;
		Node* a = new Node(passed_data);
		a ->next = head;
		head = a;
		return head;
	}

	Node* dequeue(Node **p){
		Node *current = *p;
		Node *head = *p;
		current = current -> next ;
		*p = current;
		return head;
	}

	void print(){
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
    Myqueue *a = new Myqueue();
    a = a->enqueue( 2);
    a = a->enqueue( 18);
    a = a->enqueue( 4);
    a = a->enqueue( 5);
    a = a->enqueue( 1);
    a->print();
	return 0;
}
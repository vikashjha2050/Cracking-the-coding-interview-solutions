#include<iostream>
using namespace std;

class Node
{
public:
	int name;
	int order;
	class Node* next;
	static int objectCount;
	Node(int name1){
		name = name1;
		order = objectCount++;
		next = NULL;
	}
};

int Node::objectCount = 0;

class animal
{
	Node *rear;
	Node *front;
public:
	animal(){
		rear = NULL;
		front = NULL;
	}

	animal* enqueue(int name){
		animal *a = this;
		Node* newnode = new Node(name);
		if(a->front == NULL){
			a->front = a->rear = newnode;
			return a; 
		}
		a->rear->next = newnode;
		a->rear = newnode;
		return a;
	}

	// Node* dequeue(Node **p){
	// 	Node *current = *p;
	// 	Node *head = *p;
	// 	current = current -> next ;
	// 	*p = current;
	// 	return head;
	// }

	void display(){
		animal *current = this;
		while(current->front){
			cout << current->front->name << "-" << current->front->order<<endl;
			current->front = current->front->next;
		}
		cout<<endl;
	}
};

int main()
{
    animal *dog = new animal();
    animal *cat = new animal();
    dog = dog->enqueue(1);
    dog = dog->enqueue(2);
    dog = dog->enqueue(3);
    cat = cat->enqueue(4);
    cat = cat->enqueue(5);
    cat = cat->enqueue(6);
    dog->display();
    cat->display();
	return 0;
}
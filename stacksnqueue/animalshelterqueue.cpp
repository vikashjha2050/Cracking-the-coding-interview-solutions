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

	Node* dequeudog(animal **dog1){
		animal *dog = *dog1;
		if(dog->front ){
			Node *dequequedog = dog->front;
			dog->front = dog->front->next;
			return dequequedog;
		}
	}

	Node* dequeucat(animal **cat1){
		animal *cat = *cat1;
		if(cat->front ){
			Node *dequequecat = cat->front;
			cat->front = cat->front->next;
			return dequequecat;
		}
	}
	
	Node* dequeueany(animal **dog1, animal **cat1){
		animal *dog = *dog1;
		animal *cat = *cat1;
		if(dog ->front == NULL){
			Node *dequequecat = cat->dequeucat(&cat);
			return dequequecat;
		}else if(cat ->front == NULL ){
			Node *dequequedog = dog->dequeudog(&dog);
			return dequequedog;
		}
		else if(dog->front->order < cat->front->order){
			Node *dequequedog = dog->dequeudog(&dog);
			return dequequedog;
		}else{
			Node *dequequecat = cat->dequeucat(&cat);
			return dequequecat;
		}
	}

	void display(){
		animal *current = this;
		while(current->front){
			cout << current->front->name << "-" << current->front->order<<endl;
			current->front = current->front->next;
		}
	}
};

int main()
{
    animal *dog = new animal();
    animal *cat = new animal();
    // dog = dog->enqueue(1);
    // dog = dog->enqueue(2);
    // dog = dog->enqueue(3);
    // cat = cat->enqueue(4);
    // cat = cat->enqueue(5);
    // cat = cat->enqueue(6);
    // Node *dequeuedog = dog->dequeudog(&dog);
    Node *dequequecat = cat->dequeucat(&cat);
    // Node *dequeued = dog->dequeueany(&dog,&cat);
    dog->display();
    cat->display();
	return 0;
}
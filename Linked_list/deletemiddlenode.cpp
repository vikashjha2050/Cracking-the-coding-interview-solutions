#include<iostream>
#include<string>
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

	int insert_node(int passed_data){
		Node *current = this;
		while(current->next){
			current = current->next;
		}
		Node* a = new Node(passed_data);
		current->next = a;
		return 0;
	}

	void delete_middle_node(){
		Node *slowptr = this;
		Node *fasptr = this;
		Node *prev = this;
		while(fasptr->next != NULL && fasptr->next->next != NULL){
			cout<<slowptr->data;
			cout<<fasptr->data<<endl;
			prev = slowptr;
			slowptr = slowptr->next;			
			fasptr = fasptr->next->next;			
		}
		prev->next = slowptr->next;
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
    Node* a = new Node(1);
    a->insert_node(2);
    a->insert_node(3);
    a->insert_node(4);
    a->insert_node(5);
    a->insert_node(6);
    a->insert_node(7);
    a->insert_node(8);
	a->delete_middle_node();
	a->display();
	return 0;
}
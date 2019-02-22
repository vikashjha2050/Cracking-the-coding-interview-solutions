#include<iostream>
#include<string>
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

	Node* insert_node(int passed_data){
		Node *current  = this;
		Node *head = current;
		Node* a = new Node(passed_data);
		if(current == NULL){
			current = a;
			return  current;
		}
		while(current->next){
			current = current->next;
		}		
		current->next = a;
		return head;
	}

	void delete_middle_node(){
		Node *slowptr = this;
		Node *fasptr = this;
		Node *prev = this;
		while(fasptr->next != NULL && fasptr->next->next != NULL){
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
    Node* a = NULL;
    a = a->insert_node(2);
    a = a->insert_node(3);
    a = a->insert_node(4);
    a = a->insert_node(5);
    a = a->insert_node(6);
    a = a->insert_node(7);
    a = a->insert_node(8);
    a = a->insert_node(9);
	a->delete_middle_node();
	a->display();
	return 0;
}
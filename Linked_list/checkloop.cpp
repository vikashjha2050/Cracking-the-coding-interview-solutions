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
	
	bool check_loop(){
		Node *slowptr, *fastptr = this;
		while(fastptr->next != NULL && fastptr->next->next != NULL){
			fastptr = fastptr ->next->next;
			slowptr = slowptr->next; 		
		}
		if(fastptr == slowptr){
			return true;
		}
		return false;
	}

	void display(){
		Node *current = this;
		while(current){
			cout<<current->data;
			current = current->next;
		}
	}

};

int main()
{
    Node* a = new Node(1);
    Node *head = a;
    a->insert_node(2);
    a->insert_node(3);
    a->insert_node(2);
    a->insert_node(5);
    a->next= head;
	bool result = a->check_loop();
	cout<< result;
	return 0;
}
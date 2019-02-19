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

	Node* insert_node(int passed_data){
		Node *current = this;
		while(current->next){
			current = current->next;
		}
		Node* a = new Node(passed_data);
		current->next = a;
		return a;
	}
	
	Node* check_loop(){
		Node *head = this;
		Node *slowptr = this;
		Node  *fastptr = this;
		while(fastptr && fastptr->next){
			fastptr = fastptr ->next->next;
			slowptr = slowptr->next; 		
			if(fastptr == slowptr){
				slowptr = head;
				break;
			}
		}
		if(fastptr == NULL or fastptr->next == NULL)
		{
			return NULL;
		}
		while(slowptr != fastptr){
			slowptr = slowptr->next;
			fastptr = fastptr->next;
		}
		return slowptr;
	}

};

int main()
{
    Node* a = new Node(1);
    Node* head = a;
    a->insert_node(2);
    a->insert_node(3);
    Node *b = a->insert_node(4);
    a->insert_node(5);
    a->insert_node(6);
    a->insert_node(7);
    while(a->next){
    	a= a->next;
    }
    a->next = b;
	Node* result = head->check_loop();
	if(result == NULL){
		cout<<"Loop not found";
	}else{
		cout<<"Loop found at " << result ->data;    
	}
	return 0;
}
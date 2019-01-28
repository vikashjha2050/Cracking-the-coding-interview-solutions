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
	
	void delete_node(){
		Node *current = this;
		current = current->next;
		while(current != NULL){
			Node *runner = current; 
			while(runner->next != NULL){
				if(current->data == runner->next->data){
					runner->next = runner->next->next;
			    }
				else{
					runner = runner ->next;
				}
			}
			current = current->next;	
		}
	};

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
    a->insert_node(2);
    a->insert_node(3);
    a->insert_node(2);
    a->insert_node(5);
	a->display();
	a->delete_node();
	a->display();
	return 0;
}
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

	Node* part(int k){
		Node *current = this;
		Node *smallertail = NULL, *greatertail = NULL, *smallerhead = NULL, *greaterhead = NULL;
		while(current != NULL){
			if(current->data < k){				
				if (smallerhead == NULL)
				{
					smallertail = smallerhead =  current;
				}else{
					smallertail ->next = current;
					smallertail = current;
				}
			}else{
				if(greaterhead == NULL){
					 greatertail = greaterhead = current;
				}else{
					greatertail->next = current;
					greatertail = current;
				}
				
			}
			current = current-> next; 
		}
		
		if (greatertail != NULL){ 
			greatertail->next = NULL;} 

		if (smallerhead == NULL){
			return greaterhead;
		}
		smallertail->next = greaterhead;
		return smallerhead;
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
    Node* a = new Node(2) ;
    a->insert_node(6);
    a->insert_node(7);
    a->insert_node(8);
    a->insert_node(9);
    a->insert_node(2);
    a->insert_node(3);
    a->insert_node(4);
    a->insert_node(5);
	a->display();
	a = a->part(7);
	a->display();
	return 0;
}
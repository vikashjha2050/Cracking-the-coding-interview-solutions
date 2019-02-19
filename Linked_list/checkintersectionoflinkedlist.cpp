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
	
	int count(Node *head){
		int length = 0;
		while(head){
			length = length +1;
			head = head ->next;
		}
		return length;
	}
	Node* intersection(Node *headb){
		Node *heada = this;
		int length_a = count(heada);
		int length_b = count(headb);
		int diff = length_a - length_b;
		int i = 1; 
		while(i <= diff ){
			heada = heada->next;
			i = i+1;
		}
		while(heada && headb){
			if(heada == headb){
				return heada;
			}
			heada = heada ->next;
			headb = headb ->next;
		} 
		return NULL;
	}

};

int main()
{
    Node* a = new Node(1);
    a->insert_node(2);
    a->insert_node(3);
    a->insert_node(4);
    a->insert_node(5);
    Node *internode = a->insert_node(6);
    a->insert_node(7);
    Node *b = new Node(8);
    Node *headb = b;
    b->insert_node(9);
    b->insert_node(10);
    while(b->next){
    	b = b->next;
    }
    b->next = internode;
    Node* result = a->intersection(headb);
	if(result == NULL){
		cout<<"intersection not found";
	}else{
		cout<<"intersection found at " << result ->data;    
	}
	return 0;
}
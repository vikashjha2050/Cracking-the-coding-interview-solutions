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

	Node* max(){
		Node *heada = this;
		Node *maxa = heada;
		while(heada){
			if(heada->data > maxa->data){
				maxa = heada;
			}
			heada = heada->next;
		}
		return maxa;
	} 

	Node* sort(){
		Node *heada = this;
		Node *sorted = NULL;
		while(heada){
			Node *maxa = heada -> max();			
			while(heada->data < maxa->data){
				Node *poped = heada->pop(&heada);
				sorted = sorted->push(poped->data);
			}
			Node *temp = heada -> pop(&heada);
			while(sorted && sorted->data < temp->data){
				Node *popeda = sorted->pop(&sorted);
				heada = heada->push(popeda->data);
			}
			sorted = sorted->push(maxa->data);					
		}
		return sorted;
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
    Node* a = new Node(9);
    a = a->push( 2);
    a = a->push( 18);
    a = a->push( 4);
    a = a->push( 5);
    a = a->push( 1);
    a->display();
    Node *sorteda = a->sort();
	sorteda->display();
	return 0;
}
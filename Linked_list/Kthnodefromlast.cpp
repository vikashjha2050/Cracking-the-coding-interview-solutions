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

	void display(int k){
		Node *kcurrent = this;
		for (int i = 1; i < k; i++)
		{
			kcurrent = kcurrent->next;
		}

		Node *current = this;
		while(kcurrent->next != NULL){
			kcurrent = kcurrent->next;
			current = current->next;
		}

		cout << current->data <<endl;
	}

};

int main()
{
    Node* a = new Node(1);
    a->insert_node(2);
    a->insert_node(3);
    a->insert_node(12);
    a->insert_node(5);
    a->insert_node(25);
    a->insert_node(9);
    a->insert_node(8);
    a->insert_node(15);
	a->display(2);
	return 0;
}
#include <iostream>
using namespace std;

struct node{ //linked list links/nodes
	int data;
	node* next;
};

void print(node* head){		//prints linked list to console given head pointer
	for (node* temp = head; temp != NULL; temp = temp->next)
		cout << temp->data << " ";
	cout << endl;
}


node* reverseList(node* head){	//reverse a linked list by traversing the list once while reversing the individual links.
	node* next1 = head->next;	//Reversal is acheived by saving the location of the adjacent nodes so that the next and previous nodes are known and can be used for assignment
	node* next2;
	head->next = NULL;
	while (next1 != NULL){
		next2 = next1->next;
		next1->next = head;
		head = next1;
		next1 = next2;
	}
	return head;
}

int main(){
	int i;
	cout << "How long would you like the list to be?" << endl;
	cin >> i;
	node* head = NULL;
	for (int j = 0; j < i; j++){
		node* temp = new node;
		temp->data = j;
		temp->next = head;
		head = temp;
	}
	cout << "Original List:" << endl;
	print(head);
	head = reverseList(head);
	cout << endl << endl << "Reversed List: " << endl;
	print(head);
}
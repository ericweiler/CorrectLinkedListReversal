#include <iostream>

using namespace std;

struct node{
	int data;
	node* next;
};

void print(node* head){
	for (node* temp = head; temp != NULL; temp = temp->next)
		cout << temp->data << " ";
	cout << endl;
}


node* reverseList(node* head){
	node* next1 = head->next;
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
// Code to find if a element exists in a linked list.

#include <bits/stdc++.h>
using namespace std;

class node {

	public:
		int data;
		node * next;

	node (int data){
		this -> data = data;
		this -> next = NULL;
	}

};

node * define_linkedlist(node * &head){

	int n;
	cin >> n;

	for (int i = 0; i < n; i++){
		int var;
		cin >> var;

		node *newnode = new node(var);
		if (head == NULL){
			head = newnode;
		} else {
			node * temp = head;
			while (temp -> next != NULL){
				temp = temp -> next;
			}
			temp -> next = newnode;
		}
	}
	return head;
}

void display_linkedkist(node * head){

	if (head == NULL)
		return;
	node *temp = head;
	while (temp){
		cout << temp -> data << "->";
		temp = temp -> next;
	}
	cout << "NULL" << endl;
}

bool find_element(node * head, int target_value){
	
	int count = 0;
	// head == NULL condition check is handled in above functions
	node  *temp = head;
	while(temp){
		if (temp -> data == target_value){
			cout << "Element Found!" << endl;
			cout << "The target value is at position : " << count + 1 << endl;
			return true;
		}
		count += 1;
		temp = temp -> next;
	}
	cout << "Element NOT Found!!!" << endl;
	return false;
}

bool find_element_recursive(node * head, int target_value, int count){

	// need two base cases
	// 1. 
	if (head == NULL){
		cout << "Element NOT Found!!!" << endl;
		return false;
	}
	node * temp = head;
	if (temp -> data == target_value){
		cout << "Element Found!" << endl;
		cout << "The target value is at position : " << count + 1 << endl;
		return true;
	}
	else {
		count += 1;
		find_element_recursive(temp -> next, target_value, count);
	}
	
	return false;
}

int main(){

	node * head = NULL;
	define_linkedlist(head);
	display_linkedkist(head);
	cout << "Enter the target value : " << endl;
	int target_value;
	cin >> target_value;
	cout << "---Iterative implementation:--- " << endl; 
	find_element(head, target_value);
	cout << "---Recursive implementation:--- " << endl;
	int count = 0;
	find_element_recursive(head, target_value, count);

	return 0;
}
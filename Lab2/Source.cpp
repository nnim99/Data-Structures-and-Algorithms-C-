#include <iostream>
using namespace std;

class intList {
protected:
	struct aNode {
		int value;

		struct aNode *next; // will indicate next node address
	};
	aNode *head;
public:
	intList(void) {
		head = NULL; // initializing the head pointer as NULL
	} // constructor
	~intList(void) {}; //destructor 
	void insert_at_head(int value);
	void insert_at_third(int value);
	void del(int value);
	void display(void);
	void count(void);


};
void intList::insert_at_head(int value) {
	aNode *newNode, *temp;
	newNode = new aNode;
	newNode->value = value;
	newNode->next = NULL;
	if (!head) // head == NULL
		head = newNode;
	else // Otherwise, insert newNode at beginning
	{
		temp = head;
		head = newNode;
		newNode->next = temp;

	}
}
void intList::insert_at_third(int value) {
	aNode *previous, *current, *newNode, *temp;

	newNode = new aNode;
	newNode->value = value;
	newNode->next = NULL;
	int i = 0;
	if (!head)
		return;
	temp = head;

	while (!temp->next) {// Find the last node in the list
		temp = temp->next;
		i++;
	}
	if (i<3) {
		cout << "Not Possible" << endl;

	}
	else {
		previous = head;
		current = head->next;
		int k = 1;
		while (k != 3) {
			previous = current;
			current = current->next;
			k++;

		}
		newNode = previous;
		newNode->next = current;

	}
}
void intList::del(int value) {
	{
		aNode *ptr, *previousN;
		// If the list is empty, do nothing.
		if (!head)
			return;
		// Determine if the first node is the one.
		if (head->value == value) {
			ptr = head->next;
			delete head;
			head = ptr;
		}
		else {
			// Initialize ptr to head of list
			previousN = NULL;
			ptr = head;

			while (ptr != NULL && ptr->value != value)
			{
				previousN = ptr;
				ptr = ptr->next;
			}
			// Link the previous node to the node after ptr and then delete ptr.
			previousN->next = ptr->next;
			delete ptr;
		}
	}
}
void intList::display()
{
	aNode *point;
	point = head;
	while (point) {

		cout << point->value << endl;
		point = point->next;
	}
	
}
void intList::count(void)
{
	aNode *pointer;
	pointer = head;
	int counts = 1;
	
		while (pointer)
		{

			pointer = pointer->next;
			counts++;
		}
		cout << counts << endl;
	}
void main(void)
{
	intList List;
	List.insert_at_head(3);
	List.insert_at_head(7);
	List.insert_at_head(8);
	List.insert_at_head(4);
	List.del(7);
	List.display();
	List.count();
	List.insert_at_third(1);
	List.display();
	system("pause");

}
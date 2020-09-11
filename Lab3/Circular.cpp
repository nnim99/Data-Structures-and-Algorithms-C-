#include <iostream>
using namespace std;

class aNode {
public:
	aNode *next, *previous;
	int value;
	aNode() {
		next = previous = 0;

	}
	aNode(int val, aNode *n = 0, aNode *p = 0) {
		value = val;
		next = n;
		previous = p;

	}
	aNode *head, *tail, *temp;
	void insert_at_tail(int element);
	void display_list();
	void sort();
	int average();
	int counter = 0;
};
void aNode::insert_at_tail(int element) {
	counter++;
	if (!head && !tail) {
		tail = head = new aNode(element);
		tail->next = tail;
		tail->previous = head;

	}
	else {
		
		tail->next = new aNode(element, tail->next);
		tail = tail->next;
		tail->previous = head;
		
	}
}
void aNode::display_list() {
	aNode *pointer;
	pointer = head;
	while (pointer->next != head) {
		cout << pointer->value << endl;
		pointer = pointer->next;
	}
	cout << pointer->value << endl;
	pointer = pointer->next;
}
void aNode::sort()
{
	int value, i;
	aNode *temp, *h;
	
	if (head == tail && head == NULL)
	{
		cout << "Empty List" << endl;
		return;
	}
	h = head;
	for (i = 0; i < counter; i++)
	{temp = h->next;
		while (temp != head)
		{
			if (h->value > temp->value)
			{
				int val = h->value;
				h->value = temp->value;
				temp->value = val;}
			temp = temp->next;
		}
		h = h->next;
	}
}
int aNode::average() {
	aNode *pointer;
	pointer = head;
	while (pointer->next != head) {
		value += pointer->value;
		pointer = pointer->next;
	}
	value += pointer->value;
	pointer = pointer->next;
	int average = ceil(value / counter);
	return average;
}
void main() {
	aNode list;
	list.insert_at_tail(4);
	list.insert_at_tail(3);
	list.insert_at_tail(2);
	list.insert_at_tail(5);
	list.insert_at_tail(1);
	list.display_list();
	list.sort();
	list.display_list();
	list.insert_at_tail(list.average());
	list.sort();
	list.display_list();
	system("pause");
}

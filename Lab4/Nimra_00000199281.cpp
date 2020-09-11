#include <iostream>
#include <string>
using namespace std;

class Stacks {
public:
	string statement;
	Stacks(string statement) {
		this->statement = statement;
	}
	int size = 5;
	char array[5];
	int array02[5];
	int index = -1;
	int i01 = 0;
	void Push(char element) {
		if (!isfull()) {
			//array[index++] = element;
			array[++index] = element;


		}
	}
	bool isfull() {
		return index == size - 1;
	}
	char Pop() {
		char element = 0;
		if (!isEmpty()) {
			element = array[index];
			index--;

			return element;

		}



	}
	bool isEmpty() {
		return index < 0;
	}
	void Check(string statement) {
		int length = statement.length();
		bool valid = true;
		for (int i = 0; i < length; i++) {
			if (statement[i] == '(' || statement[i] == '[' || statement[i] == '{') {
				Push(statement[i]);
				array02[i01] = i;
				valid = false;
			}
			else
				if (statement[i] == ')' || statement[i] == ']' || statement[i] == '}') {
					char element01 = statement[i];
					if (isEmpty()) {
						valid = false;

					}
					else {
						char word = Pop();
						if (((word == '(') && (element01 == ')')) || ((word == '[') && (element01 == ']')) || ((word == '{') && (element01 == '}'))) {
							valid = true;
						}
						else {
							valid = false;

						}

					}
				}
		}
		if (valid) {
			cout << "The expression is correct." << endl;
			system("pause");
		}
		else {
			cout << "The Expression is incorrect. Error at #" << array02[i01] << endl;
			system("pause");
		}
		//}
	}
};

int main() {
	string statement;
	cout << "Enter Expression: " << endl;

	cin >> statement;
	system("pause");
	Stacks obj = Stacks(statement);

	obj.Check(statement);


}

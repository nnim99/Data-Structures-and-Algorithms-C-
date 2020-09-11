#include <iostream>
#include <string>

using namespace std;

class Hospital {
public:
	int patients[15]; //array for patients in queue
	string names[15]; // names of patients respectively
	int length = 15; // length defined for queue
	int front, rear; // front represents first element in array, and rear represents last element in array 
	int id_number; // id numbers for patients
	string pName; // patient name saved

	Hospital() { // contructor which initializes front and rear
		front = length - 1; // both initialized at same point
		rear = length - 1;

	}
	bool IsEmpty() { // checks whether array of patients is empty or not
		return (front == rear);
	}
	bool IsFull() { // checks whether queue is full or not
		return ((rear + 1) % length == front);
	}
	void RegisterPatient(string name, int id) { // Adds patient in the patient array and names array
		pName = name;
		id_number = id;
		if ((rear + 1) % length == front) {

			cout << "Ward is full. " << endl;
		}
		else {
			rear = (rear + 1) % length;
			patients[rear] = id_number;
			names[rear] = pName;
		}
	}
	int ServePatient() { // removes patient from both aarrays
		if (!IsEmpty()) {
			front = (front + 1) % length;
			names[front] = '0'; // sets null like
			return patients[front];

		}
		else {
			cout << "Ward Empty" << endl;
		}
		return 0;
	}
	void CancelAll() { // remove data from both arrays
		for (int i = 0; i < length; i++)
		{
			patients[i] = -1;
			names[i] = '0';
		}
	}
	bool canDoctorGoHome() { // checks whether patients are all over
		return(IsEmpty());
	}
	void showAllPatients() { //sorted in alphabetical order
		for (int i = front; i <= rear; i++) // so that only names are sorted not null values
		{
			for (int j = 0; j <= rear - i; j++)
			{
				if (names[j]>names[j + 1]) // comparing first letters of names in array
				{
					string temp = names[j]; // storing name in temp 
					names[j] = names[j + 1];
					names[j + 1] = temp;
				}
			}
		}
		cout << "Names in asscending order: ";
		for ( int j = 0; j<length; j++){
		{
			if (names[j] != "0") // printing names which are valid
			cout << names[j] << endl;
		}
	
	}
	}
	void displayIdNumber() { // all patients are displayed
		for (int i = (front + 1) % length; i <= rear; i++) {
			if (patients[i] > 0){
				cout << patients[i] << endl;
			}
		}
			
		}
	

};


int main() {

	Hospital h1 = Hospital();
	h1.RegisterPatient("Nimra", 111);
	//h1.displayIdNumber();
	h1.RegisterPatient("Ali", 222);
	h1.RegisterPatient("Hamza", 333);
	h1.RegisterPatient("Sara", 444);
	h1.ServePatient();
	h1.displayIdNumber();
	h1.showAllPatients();
	h1.CancelAll();
	h1.displayIdNumber();

	system("pause");

};
#include <iostream>
using namespace std;

class bankAccount {
protected:
	char customer_name;
	int account_number;
	char account_type;
public:
	bankAccount(){
		

	}
	void setData();
	void getData();

};
void bankAccount::setData(){
	cout << "Enter name:";
	cin >> customer_name;
	cout << "Enter account number:";
	cin >> account_number;
	cout << "Enter account type:";
	cin >> account_type;


}
void bankAccount::getData(){
	cout << "Customer Name: "<<customer_name<< endl;
	cout << "Account Name: " <<account_number<< endl;
	cout << "Account type: " <<account_type<< endl;

}

class Saving : public bankAccount{
protected:
	float deposit;
	float balance;
	float withdraw;
public: 

	Saving(){
		deposit = 1000;
		balance = deposit;

	}
	void deposited();
	void withdrawal();


};
void Saving::deposited(){
	cout << "Enter the deposit amount:"; 
	cin >> deposit ; 
	balance = balance + deposit + 5 / 100 * (deposit);

}
void Saving::withdrawal(){
	cout << "Enter the withdrawal amount:";
	cin >> withdraw;
	balance = balance - withdraw;

}

class Current : public bankAccount{
protected:
	float deposit;
	float balance;
public:

	Current(){
		deposit = 1000;
		balance = deposit;

	}
	void depsited();
	void withdrawal();
	void currentBalance();

};
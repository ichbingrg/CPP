#include "Account.h"
#include <iostream>

using namespace std;

Account::Account(string name, double balance )
	:name(name), balance (balance){} 


bool Account::deposit(double amount){
	if (amount < 0)
		return 0;
	else {
		balance += amount;
		return 1;
	}
	
}
bool Account::withdraw (double amount){
	if (balance > amount){
		balance -= amount;
		return 1;
	}
	else {
		cout << "Insufficient funds " << endl;
		return 0;}
}

double Account::get_balance() const{
	return balance;
}


void Account::print(ostream &os) const {
	os.precision(2);
	os << fixed;
	os << "[Account " << name <<  " balance: " <<  balance << "]";

		
	}
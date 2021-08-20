#include "Savings_Account.h"
#include <string>

using namespace std;

Savings_Account::Savings_Account(string name, double balance , double rate)
			: Account (name,balance),rate(rate){
	
	
}


bool Savings_Account::deposit (double amount){
		amount = amount + (amount * (rate/100));
		return Account::deposit(amount); //very imp
		
}

bool Savings_Account:: withdraw (double amount){
	return Account::withdraw(amount);
}


void Savings_Account::print(ostream &os) const {
	os.precision(2);
	os << fixed;
	os << "[Savings Account: " << name <<  " balance: " <<  balance << ", Interest Rate: " << rate <<  "%]" << endl;;

		
	}
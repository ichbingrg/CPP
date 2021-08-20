#include "Account.h"
#include "Savings_Account.h"
#include <iostream>
#include <vector>
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std;



//helper functions for Account class
void display(const vector<Account *> &accounts){
	cout << "\n==== ACCOUNTS ===================================================" << endl;
	for (const auto a : accounts)
		cout << *a << endl;
}
void deposit(vector <Account *> &accounts, double amount){
	cout << "\n=== DEPOSITING TO ACCOUNTS =======================================" << endl;
		for (auto a:accounts){
			if (a->deposit(amount))
				cout << "Deposited... " <<amount << " to "<< *a <<  endl;
			else 
				cout << "Failed to deposit to " << *a << endl;
		}
}
void withdraw(vector <Account *> &accounts, double amount){
	cout << "\n=== WITHDRAWING FROM ACCOUNTS =======================================" << endl;
		for (auto a:accounts){
			if (a->withdraw(amount))
				cout << "Withdrew... " <<amount << " from "<< *a <<  endl;
			else 
				cout << "Failed to withdraw from :  " << *a << endl;
		}	
}


#ifndef ACCOUNT_UTIL_H
#define ACCOUNT_UTIL_H
#include <vector>
#include <iostream>
#include "Account.h"


using namespace std;
//helper functions for Accoun* class
void display(const vector<Account *> &accounts);
void deposit(vector <Account *> &accounts, double amount);
void withdraw(vector <Account *> &accounts, double amount);






#endif // ACCOUNT_UTIL_H

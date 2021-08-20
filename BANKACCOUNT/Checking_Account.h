#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include <iostream>
#include "Account.h"

using namespace std;


class Checking_Account:public Account
{
private: static constexpr const char *def_name = "Unnamed Checking Account";
		 static constexpr double def_balance = 0.0;
		 static constexpr double withdraw_fee = 1.5;
public:
	
	Checking_Account(string name = def_name, double balance = def_balance);
	virtual bool withdraw (double amount) override;
	virtual bool deposit( double) override;
	virtual ~Checking_Account() = default ;
	virtual void print(ostream &os) const override;
	//bool inherited
	
};

#endif // CHECKING_ACCOUNT_H

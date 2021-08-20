#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H
#include "Savings_Account.h"
#include <iostream>
 
 using namespace std;



class Trust_Account : public Savings_Account
{private:
	static constexpr const char *def_name = "Unnamed Trust Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_rate =0.0;
	static constexpr double bonus_amount =50.0;
	static constexpr double bonus_threshhold =5000.0;
	static constexpr int max_withdrawals =3;
	static constexpr double max_withdrawal_percent =0.2;
protected: int i = 0;
public:
	Trust_Account(string name = def_name, double balance = def_balance, double rate = def_rate);
	
	virtual bool deposit (double amount) override;
	virtual bool withdraw (double amount) override;
	virtual void print(ostream &os) const override;
	virtual ~Trust_Account() = default;
	
};

#endif // TRUST_ACCOUNT_H

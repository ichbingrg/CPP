#include "Trust_Account.h"



Trust_Account::Trust_Account(string name , double balance, double rate)
			: Savings_Account(name,balance, rate){
	
}
	
bool Trust_Account::deposit (double amount){
		if (amount >= bonus_threshhold){
			cout << "CONGRATULATIONS YOU ALSO GET A BONUS OF $50.00" << endl << endl;
			Account::deposit(bonus_amount);}
		return Savings_Account::deposit(amount);
}
	 
bool Trust_Account::withdraw (double amount){
	if ((i<max_withdrawals) && (amount < (max_withdrawal_percent*balance))){
		i++;
		return Account:: withdraw(amount);
	}
	else{ {if (i>=max_withdrawals)
				cout << "Withdrawal attempt reached for the year." << endl;
		  else if (amount > (max_withdrawal_percent*balance))
				cout << "Amount too high. " << endl;}
		 return 0;
	}
}
	

void Trust_Account::print(ostream &os) const {
	os.precision(2);
	os << fixed;
	os << "[Trust Account: " << name << " Balance: " << balance << " Interest rate: " << rate << " %]" << endl;
		
	}
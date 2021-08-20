#include <iostream>
#include <memory>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"


using namespace std;

class Test{
		int data;
public:
		Test(): data(0){
			cout << "TEST CONST (" << data << ")" << endl;
		}
		Test(int data): data(data){
			cout << "TEST CONST (" << data << ")" << endl;
		}
		~Test(){
			cout << "TEST DEST (" << data << ")" << endl;
		}
};

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

//Unique Pointers
int main(){
	//Test *t1 = new Test(1000);
	//delete t1;
	//
	//unique_ptr<Test> t1 {new Test(100)};
	//unique_ptr<Test> t2 ;
	//t2 = move(t1);
	//if (!t1)
	//	cout << "t1 is nullptr" << endl;
	
	unique_ptr<Account> a1= make_unique <Checking_Account>("Moe", 5000);
	cout << *a1 << endl;
	a1-> deposit(5000);
	cout << *a1 << endl;
	
	vector <unique_ptr<Account>> accounts;
	
	accounts.push_back(make_unique <Checking_Account>("James", 1000));
	accounts.push_back(make_unique <Savings_Account>("Billy", 4000, 5.2));
	accounts.push_back(make_unique <Trust_Account>("Bobby", 6000, 4.5));
	
	for (auto &acc: accounts)
		cout << *acc << endl;
	return 0;
}





// Challenge 
//int main(){
//	
//	Checking_Account c;
//	cout << c << endl;
//	
//	Savings_Account s{"Frank",5000,2.6};
//	cout << s << endl;
//	s.deposit(10000);
//	cout << s << endl;
//	s.withdraw(10000);
//	cout << s << endl;
//	
//	Trust_Account a("Leo", 1000, 2.6);
//	cout << a << endl;
//	
//	
//	Account *ptr = new Trust_Account("Leo", 10000,2.6);
//	cout << *ptr << endl;
//	
//	
//	
//	return 0;
//}
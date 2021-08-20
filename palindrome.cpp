//CHECKING PALINDROME USING STACK AND QUEUE

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <iomanip>



template <typename T>
void display (std::queue <T> q){
	std::cout << "[ ";
	while(!q.empty()){
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << "]" << std::endl;
}

template <typename T>
void display(std::stack <T> s){
	std::cout << "[ ";
	while (!s.empty()){
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << "]" << std::endl;
}


bool is_palindrome(const std::string &s){
	
	std::queue <char> q ;
	for (char i: s){
		if (std::isalpha(i))
			q.push(std::toupper(i));
	}
	//display(q);
	std::stack <char> r;
	for (char i: s){
		if (std::isalpha(i))
			r.push(std::toupper(i));
	}
	//display(r);
	
	while (!q.empty()){
	if (q.front() != r.top()){
		return false;}
	else{
		q.pop();
		r.pop();
	}}
	
	return true;
	
	
}


int main(){
	std::vector <std::string> test_strings{"a","aa","aba", "abba", "abbcbba", "ab","abc","radar","bob","ana",
				"avid diva","Amore, Roma","A Toyota's a toyota","A Santa at NASA","C++", "A man, a plan, a cat, a ham, a yak, a yam,  a hat, a canal-Panama!",
				"This is a palindrome", "palindrome"};
				
				
	std::cout << std::boolalpha;
	
	for (std::string s: test_strings)
		std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
	
	std::cout << std::endl;
	
	
	return 0;
}
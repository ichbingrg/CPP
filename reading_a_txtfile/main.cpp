#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>




void display_words(const std::map <std::string, int> &words){
	std::cout << std::setw(12) << std::left << "\nWORD"
			  << std::setw(7) << std::right << "COUNT" << std::endl;
	std::cout << std::setw(20) << std::setfill('=') << "" << std::setfill(' ') <<  std::endl;
	for (auto pair : words){
		std::cout << std::setw(12) << std::left << pair.first;
		std::cout << std::setw(7) << std::right << pair.second;
		std::cout << std::endl;
	}
}

void display_words(const std::map <std::string, std::set <int>> &words){
	std::cout << std::setw(12) << std::left << "\nWORD"
			  << "OCCURENCES" << std::endl;
	std::cout << std::setw(30) << std::setfill('=') << "" << std::setfill(' ') <<  std::endl;
	for (auto pair : words){
		std::cout << std::setw(12) << std::left << pair.first;
		std::cout << "[ ";
		for (auto j : pair.second){
			std::cout << j << " ";
		}
		std::cout << "]" << std::endl;
	}
	
}

std::string clean_string(const std::string &s){
	std::string result;
	for (char c: s){
		if (c=='.'|| c==','|| c == ';' || c == ':')
			continue;
		else 
			result += c;
	}
	return result;
}

void part1(){
	std::map <std::string, int> words;
	std::string line;
	std::string word;
	std::ifstream in_file("../words.txt");
	
	
	if (in_file.is_open()){
		while (!in_file.eof()){
			std::getline(in_file, line);
			
		std::stringstream ss(line);
		while (!ss.eof()){
			ss >> word;
			word = clean_string(word);
			words[word]++;
		}}	
		
		in_file.close();
		display_words(words);

	} else {
		std::cerr << "Error opening input file" << std::endl;
	}
}

void part2(){
	std::cout << "Part 2 =================================================" << std::endl;
	std::map <std::string, std::set <int>> words;
	std::string line;
	std::string word;
	int line_num= 0;
	std::ifstream in_file("../words.txt");
	if (in_file.is_open()){
		while (!in_file.eof()){
			std::getline(in_file, line);
			line_num++;
			
			std::stringstream ss(line);
			
			while (!ss.eof()){
				ss >> word;
				word = clean_string(word);
				words[word].insert(line_num);
			}
		}
		in_file.close();
		display_words(words);
	}else{
		std::cerr << "Error opening file" << std::endl;
	}
}


int main(){
	part1();
	part2();
	
	return 0;
}
//MUSIC PLAYER EXAMPLE


#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <limits>
#include <vector>
#include <algorithm>

class Song{
	friend std::ostream &operator<< (std::ostream &op, const Song &rhs);
	std::string name;
	std::string artist;
	size_t rating;
	
public:
	Song() = default;
	Song(std::string name, std::string artist , size_t rating)
			: name(name), artist(artist), rating(rating){}
	~Song() = default;
	
	std::string get_name() const{
		return name;
	}
	std::string get_artist() const{
		return artist;
	}
	size_t get_rating() const{
		return rating;
	}
	bool operator< (const Song &rhs){
		return this->name < rhs.name;
	}
	
	bool operator== (const Song &rhs){
		return this->name == rhs.name;
	}
};

std::ostream &operator<< (std::ostream &op, const Song &rhs){
	op  << std::setw(20) << std::left << rhs.name
		<< std::setw(30) << std::left << rhs.artist
		<< std::setw(2) << std::left << rhs.rating ;
		
	return op;
}


void display_menu(const std::list <Song> &l){
	std::cout << std::endl<<  std::endl;
	std::cout << "F - Play First Song" << std::endl
			  << "N - Play Next Song" << std::endl
			  << "P - Play Previous Song" << std::endl
			  << "A - Add and Play new song at the current location" << std::endl
			  << "L - List the current playlist" << std::endl
			  << "===========================================================" << std::endl;
			  std::cout << "Enter a Selection (Q to quit): " ;
}

void play_current_song(std::list <Song>::iterator current){
	//This function should display
	//Playing: followed by the song that is playing
	
	std::cout << std::endl << std::endl;
	std::cout << "Playing : " << std::endl;
	std::cout << *current << std::endl;
	
}


void display_playlist(std::list <Song> &l, const Song a ){
	
	std::cout << std::endl << std::endl;
	for (auto a: l)
		std::cout << a << std::endl;
	
	std::cout << "Current Song: " << std::endl;
	std::cout << a << std::endl;
	
}

void play_first_song(std::list <Song> &songs, std::list <Song>::iterator &current);
void play_next_song(std::list <Song> &songs, std::list <Song>::iterator &s);
void play_previous_song(std::list <Song> &songs,std::list <Song>::iterator &s);
void add_new_song(std::list <Song> &songs, std::list <Song>::iterator &s);

void check_response(std::list <Song> &songs,std::list <Song>::iterator &current, char &ip){
	display_menu(songs);
	std::cin >> ip;
	
	//std::cout << "You chose the option : " << ip << std::endl;
	
	switch (std::toupper(ip)){
		case 'F':
			std::cout << "Playing first song" << std :: endl;
			play_first_song(songs,current);
			break;
		case 'N':
			play_next_song(songs,current);
			break;
		case 'P':
			//std::cout << "Playing previous song"<< std::endl;
			play_previous_song(songs, current);
			break;
		case 'A':
			//std::cout << "Adding and playing a new song at the current location" << std::endl;
			add_new_song(songs,current);
			break;
		case 'L': 
			std::cout << "Showing the current playlist" << std::endl;
			display_playlist(songs, *current);
			break;
		case 'Q':
			std::cout <<"\n******************** Quitting program **************************" << std::endl;
			break;
		default: 
			std::cout <<  "Invalid input " << std::endl;
	
	}
	
	
}



void play_first_song(std::list <Song> &songs, std::list <Song>::iterator &current){
	current = songs.begin();
	play_current_song(current);
	//display_menu(songs);
	
}
void play_next_song(std::list <Song> &songs, std::list <Song>::iterator &s){
	if (*s == songs.back()){
		s= songs.begin();
		std::cout << "Playing the first song" << std::endl;
	}
	else {
		s++;
		std::cout << "Playing next song" << std::endl;}
	
	play_current_song(s);
	//display_menu(songs);
}
void play_previous_song(std::list <Song> &songs, std::list <Song>::iterator &s){
	if (s == songs.begin()){
		s = songs.end();
		s--;
		std::cout << "Playing the last song." << std::endl;
	}
	else {
		s--;
		std::cout << "Playing previous track" << std::endl;
	}
	play_current_song(s);
	//display_menu(songs);
}
void add_new_song(std::list <Song> &songs, std::list <Song>::iterator &s){
	std::string name;
	std::string artist;
	size_t rating;
	
	std::cin.clear();
	
	std::cout << "Enter a new name: ";
	std::getline(std::cin, name);
	
	std::cout << "Enter artist name: ";
	std::getline(std::cin, artist);
	
	std::cout << "Enter a rating: ";
	std::cin >> rating;
	
	
	Song new_song{name, artist, rating};
	int count=0;
	for (auto a: songs){
		if (a == new_song){
			count++;
		}
	}
	
	if (count == 0){
		songs.insert(s,new_song);
		std::cout << "Added the new song and Playing it" << std::endl;
		s--;
		play_current_song(s) ;}
	else
		std::cout << "***************** Already exists *********************" << std::endl;
	
}

int main(){
	
	std::list <Song> songs{
		Song{"God's Plan", "Drake" , 5},
		Song("Never be the same", "Camila Cabello", 5),
		Song("Pray for me", "The Weekend and L. Lamar", 5)
	};
	songs.emplace_back("The Middle","Zedd, Maren Morris & Grey" , 4);
	songs.emplace_back("Wait","Maroon 5" , 4);
	songs.emplace_back("Whatever it takes","Imagine Dragons" , 3);
	
	std::list <Song> :: iterator current = songs.begin();
	
	display_playlist(songs, *current);
	char ip;
	while (std::toupper(ip) != 'Q'){
		
	check_response(songs,current, ip);
	}
	return 0;
}
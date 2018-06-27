
#include <string>
#include "dog.h"
#include <vector>
#include <algorithm>
#include "Utilities.h"
using namespace std;

Dog::Dog(string breed, int age, string photograph) {
	this->breed = breed;
	this->age = age;
	this->photograph = photograph;
}

Dog::Dog() {
	this->breed = "";
	this->age = 0;
	this->photograph = "";
}

Dog::~Dog() {
	//destructor
}

void Dog::set_breed(string e) {
	this->breed = e;
}

void Dog::set_age(int e) {
	this->age = e;
}

void Dog::set_photograph(string e) {
	this->photograph = e;
}

string Dog::get_breed() const {
	return this->breed;
}

int Dog::get_age() const {
	return this->age;
}

string Dog::get_photograph() const {
	return this->photograph;
}

istream & operator >> (istream & is, Dog &s)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 3) // make sure all the starship data was valid
		return is;

	s.breed = tokens[0];
	s.age = stoi(tokens[1], nullptr, 10);
	s.photograph = tokens[2];

	return is;

}

ostream & operator<<(ostream & os, const Dog& s)
{
	os << s.breed << "," << s.age << "," << s.photograph << endl;
	return os;
}

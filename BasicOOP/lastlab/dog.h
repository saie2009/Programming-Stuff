#pragma once
#include <string>
using namespace std;

class Dog {

public:
	Dog(string breed, int age, string photograph);
	Dog();
	~Dog();
private:
	string breed;
	int age;
	string photograph;
public:
	void set_breed(string e);
	void set_age(int e);
	void set_photograph(string e);
	string get_breed() const;
	int get_age() const;
	string get_photograph() const;
	friend std::istream& operator >> (std::istream& is, Dog& s);
	friend std::ostream& operator<<(std::ostream& os, const Dog& s);


};
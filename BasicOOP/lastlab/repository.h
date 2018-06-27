#pragma once
#include <vector>
#include <string>
#include "dog.h"
using namespace std;

class Repository {
private:
	vector <Dog> dogs;
	vector <Dog> adoptionList;
	string filename;
public:
	//Initializing repository items from file
	Repository(const string &filename);
	//Function reads dogs from file
	void readFromFile();
	//Function writes to file in dog format
	void writeToFile();
	//Function write to special specified file, depending on filename it will write in a csv or html format the adoption
	//list
	void writeToCSVorHTML(const string &filename);
	//Function will open the special file in the notepad or browser acording to their type
	void openCSVorHTML(const string &filename);

	//Function adds a dog to the repository
	void addDog(const Dog& e);
	//Function removes a dog from the repository based on breed, age and photograph
	void removeDog(const string &breed, const int &age, const string &photograph);
	//Function returns all the dogs in repository
	vector <Dog> showDogs() const { return dogs; };
	//Function updates the data of a dog based on given breed,age and photograph
	void updateDog(const Dog &d, const string &breed2, const int &age2, const string &photograph2);

	//Function adds a dog to the adoption list
	void addDogAD(const Dog& e);
	//Function returns all the dogs in adoption list
	vector <Dog> showADL() const { return adoptionList; };
	/*dogsWithFilter - returns the number of dogs with the given breed and age*/
	int dogsWithFilter(const string &breed, const int &age);

};
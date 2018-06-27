#pragma once
#include "repository.h"
#include <string>
using namespace std;
class Controller {
private:
	Repository& repo;
public:
	Controller(Repository& repo) :repo{ repo } {}
	~Controller();
	void addDogToRepo(const string &breed, const int &age, const string &photograph);
	void removeDogFromRepo(const string &breed, const int &age, const string &photograph);
	vector <Dog> showDogs() const { return repo.showDogs(); };
	void updateDogInRepo(const string &breed, const int &age, const string &photograph, const string &breed2, const int &age2, const string &photograph2);
	void addDogToADL(const string &breed, const int &age, const string &photograph);
	vector <Dog> showADL() const { return repo.showADL(); };
	int dogsWithFilter(const string &breed, const int &age);
	void writeToCSVorHTML(const string &filename);
	void openCSVorHTML(const string &filename);
};
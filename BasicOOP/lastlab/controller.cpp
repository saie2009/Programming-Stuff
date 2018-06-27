#include "controller.h"
#include <iostream>
using namespace std;

void Controller::addDogToRepo(const string &breed, const int &age, const string &photograph) {
	Dog e{ breed,age,photograph };
	this->repo.addDog(e);
}

void Controller::removeDogFromRepo(const string &breed, const int &age, const string &photograph) {
	this->repo.removeDog(breed, age, photograph);
}

void Controller::updateDogInRepo(const string &breed, const int &age, const string &photograph, const string &breed2, const int &age2, const string &photograph2) {
	Dog e{ breed,age,photograph };
	this->repo.updateDog(e, breed2, age2, photograph2);
}

void Controller::addDogToADL(const string &breed, const int &age, const string &photograph) {
	Dog e{ breed,age,photograph };
	this->repo.addDogAD(e);
}

int Controller::dogsWithFilter(const string &breed, const int &age) {
	return this->repo.dogsWithFilter(breed, age);
}

void Controller::writeToCSVorHTML(const string &filename) {
	this->repo.writeToCSVorHTML(filename);
}

void Controller::openCSVorHTML(const string &filename) {
	this->repo.openCSVorHTML(filename);
}

Controller::~Controller() {

}
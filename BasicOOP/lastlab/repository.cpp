#include "repository.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

Repository::Repository(const string &filename) {
	this->filename = filename;
	this->readFromFile();
}

void Repository::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw "The file could not be opened!";

	Dog s;
	while (file >> s)
		this->dogs.push_back(s);

	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw "The file could not be opened!";

	for (auto s : this->dogs)
	{
		file << s;
	}

	file.close();
}

void Repository::writeToCSVorHTML(const string &filename) {
	ofstream file(filename);
	if (!file.is_open())
		throw "The file could not be opened!";

	if (filename == "adlist.csv") {
		for (auto s : this->adoptionList)
		{
			file << s;
		}
	}

	if (filename == "adlist.html") {
		file << "<!DOCTYPE html>" << endl;
		file << "<html>" << endl;
		file << "<head>" << endl;
		file << "<title>Adoption list</title>" << endl;
		file << "</head>" << endl;
		file << "<body>" << endl;
		file << "<table border = \"1\">" << endl;
		file << "<tr>" << endl;
		file << "<td>Breed</td>" << endl;
		file << "<td>Age</td>" << endl;
		file << "<td>Photograph</td>" << endl;
		file << "</tr>" << endl;
		for (const auto &s : adoptionList) {
			file << "<tr>" << endl;
			file << "<td>" << s.get_breed() << "</td>" << endl;
			file << "<td>" << s.get_age() << "</td>" << endl;
			file << "<td><a href =\"" << s.get_photograph() << "\" > Link</a></td>" << endl;
			file << "</tr>" << endl;
		}
		file << "	</table>" << endl;
		file << "</body>" << endl;
		file << "</html>" << endl;

	}



	file.close();

}

void Repository::openCSVorHTML(const string &filename) {
	if (filename == "adlist.html") {
		ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Google\\Chrome\\Application\\CHROME.EXE", filename.c_str(), NULL, SW_SHOWMAXIMIZED);

	}

	if (filename == "adlist.csv") {
		ShellExecuteA(NULL, NULL, "C:\\Users\\Andrei\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Accessories\\NOTEPAD", filename.c_str(), NULL, SW_SHOWMAXIMIZED);

	}
}

void Repository::addDog(const Dog& e) {

	auto foundIt = std::find_if(dogs.begin(), dogs.end(), [&e](const auto &s) {
		return e.get_breed() == s.get_breed() && e.get_age() == s.get_age() && e.get_photograph() == s.get_photograph(); });

	if (foundIt != dogs.end()) {
		throw "Dog already exists !";
	}

	this->dogs.push_back(e);
	this->writeToFile();
}

void Repository::removeDog(const string &breed, const int &age, const string &photograph) {
	auto foundIt = std::find_if(dogs.begin(), dogs.end(), [&breed, &age, &photograph](const auto &s) {
		return breed == s.get_breed() && age == s.get_age() && photograph == s.get_photograph(); });

	if (foundIt == dogs.end())
	{
		throw "Dog doesn't exist!";
	}

	dogs.erase(foundIt);
	this->writeToFile();

}

void Repository::updateDog(const Dog &d, const string &breed2, const int &age2, const string &photograph2) {
	auto foundIt = std::find_if(dogs.begin(), dogs.end(), [&d](const auto &s) {
		return d.get_breed() == s.get_breed() && d.get_age() == s.get_age() && d.get_photograph() == s.get_photograph(); });

	if (foundIt == dogs.end())
	{
		throw "Dog doesn't exist!";
	}

	auto pos = distance(dogs.begin(), foundIt);
	dogs[pos].set_breed(breed2);
	dogs[pos].set_age(age2);
	dogs[pos].set_photograph(photograph2);

	this->writeToFile();
}

void Repository::addDogAD(const Dog &e) {
	this->adoptionList.push_back(e);

}

int Repository::dogsWithFilter(const string &breed, const int &age) {
	int nr = 0;
	for (const auto &s : dogs)
		if (s.get_breed() == breed && s.get_age() <= age)
			nr++;
	return nr;
}
#include "lastlab.h"
#include <vector>
#include "dog.h"
#include "Utilities.h"
#include <QMessageBox>
using namespace std;

lastlab::lastlab(Controller& c, QWidget *parent) : ctrl{ c }, QWidget{ parent }
{
	this->initGUI();
	this->currentDogsInRepoList = this->ctrl.showDogs();
	this->populateRepoList();
}

lastlab::~lastlab()
{

}

void lastlab::initGUI()
{
	//General layout of the window
	QHBoxLayout* layout = new QHBoxLayout{ this };

	// Prepare left side components - vertical layout with: 
	// - list
	// - form layout with the dog data
	// - grid layout with buttons: add, delete, update, filter
	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	// list
	this->repoList = new QListWidget{};
	// set the selection model
	this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);

	// dog data
	QWidget* dogDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ dogDataWidget };
	this->breedEdit = new QLineEdit{};
	this->ageEdit = new QLineEdit{};
	this->photographEdit = new QLineEdit{};
	formLayout->addRow("&Breed:", breedEdit);
	formLayout->addRow("&Age:", ageEdit);
	formLayout->addRow("&Photograph:", photographEdit);


	// buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton("Add");
	this->deleteButton = new QPushButton("Delete");
	this->filterButton = new QPushButton("Filter");
	this->updateButton = new QPushButton("Update");

	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(filterButton, 1, 1);
	gridLayout->addWidget(updateButton, 1, 0);

	// add everything to the left layout
	leftSide->addWidget(new QLabel{ "All dogs" });
	leftSide->addWidget(repoList);
	leftSide->addWidget(dogDataWidget);
	leftSide->addWidget(buttonsWidget);

	// middle component: just two button - to add the dogs from the reposiotory to the adoption list
	QWidget* middleWidget = new QWidget{};
	QVBoxLayout* vLayoutMiddle = new QVBoxLayout{ middleWidget };
	this->moveDogButton = new QPushButton{ ">> Adopt the dog" };

	QWidget* upperPart = new QWidget{};
	QWidget* lowerPart = new QWidget{};
	QVBoxLayout* vLayoutUpperPart = new QVBoxLayout{ upperPart };
	vLayoutUpperPart->addWidget(this->moveDogButton);
	vLayoutMiddle->addWidget(upperPart);
	vLayoutMiddle->addWidget(lowerPart);

	// right component: the adoptionlist
	QWidget* rightWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };

	// adoptionList
	adoptionList = new QListWidget{};

	// two buttons
	QWidget* adoptionListButtonsWidget = new QWidget{};
	QGridLayout* gridLayoutADL = new QGridLayout{ adoptionListButtonsWidget };
	this->saveButtonHTML = new QPushButton{ "Save HTML" };
	this->openButtonHTML = new QPushButton{ "Open HTML" };
	this->saveButtonCSV = new QPushButton{ " Save CSV " };
	this->openButtonCSV = new QPushButton{ " Open CSV " };
	gridLayoutADL->addWidget(saveButtonHTML, 0, 0);
	gridLayoutADL->addWidget(openButtonHTML, 0, 1);
	gridLayoutADL->addWidget(saveButtonCSV, 1, 0);
	gridLayoutADL->addWidget(openButtonCSV, 1, 1);

	// add everything to the right layout
	rightSide->addWidget(new QLabel{ "Adoption list" });
	rightSide->addWidget(adoptionList);
	rightSide->addWidget(adoptionListButtonsWidget);

	// add the three layouts to the main layout
	layout->addWidget(leftWidget);
	layout->addWidget(middleWidget);
	layout->addWidget(rightWidget);

	// connect the signals and slots
	this->connectSignalsAndSlots();
}

void lastlab::connectSignalsAndSlots()
{
	// add a connection: function listItemChanged() will be called when an item in the list is selected
	QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

	// add button connections
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addNewDog()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteDog()));
	QObject::connect(this->filterButton, SIGNAL(clicked()), this, SLOT(filterRepoDogs()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateDog()));
	QObject::connect(this->moveDogButton, SIGNAL(clicked()), this, SLOT(moveDogToAdoptionList()));
	QObject::connect(this->saveButtonHTML, SIGNAL(clicked()), this, SLOT(saveHTML()));
	QObject::connect(this->openButtonHTML, SIGNAL(clicked()), this, SLOT(openHTML()));
	QObject::connect(this->saveButtonCSV, SIGNAL(clicked()), this, SLOT(saveCSV()));
	QObject::connect(this->openButtonCSV, SIGNAL(clicked()), this, SLOT(openCSV()));
}

void lastlab::populateRepoList()
{
	// clear the list, if there are elements in it
	if (this->repoList->count() > 0)
		this->repoList->clear();

	for (auto s : this->currentDogsInRepoList)
	{	
		string dogage = to_string(s.get_age());
		QString itemInList = QString::fromStdString(s.get_breed() + " - " + dogage + " - " + s.get_photograph());
		this->repoList->addItem(itemInList);
	}

	// set the selection on the first item in the list
	if (this->currentDogsInRepoList.size() > 0)
		this->repoList->setCurrentRow(0);
}

void lastlab::populateAdoptionList()
{
	// clear the list, if there are elements in it
	if (this->adoptionList->count() > 0)
		this->adoptionList->clear();

	for (auto s : this->ctrl.showADL())
	{	
		string dogage = to_string(s.get_age());
		QString itemInList = QString::fromStdString(s.get_breed() + " - " + dogage + " - " + s.get_photograph());
		this->adoptionList->addItem(itemInList);
	}
}

int lastlab::getRepoListSelectedIndex()
{
	if (this->repoList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->breedEdit->clear();
		this->ageEdit->clear();
		this->photographEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void lastlab::listItemChanged()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Dog> dogs = this->currentDogsInRepoList;

	// get the dog at the selected index
	if (idx >= dogs.size())
		return;
	Dog s = dogs[idx];
	string dogage = to_string(s.get_age());
	this->breedEdit->setText(QString::fromStdString(s.get_breed()));
	this->ageEdit->setText(QString::fromStdString(dogage));
	this->photographEdit->setText(QString::fromStdString(s.get_photograph()));
}

void lastlab::addNewDog()
{
	std::string breed = this->breedEdit->text().toStdString();
	int age = this->ageEdit->text().toInt();
	std::string photograph = this->photographEdit->text().toStdString();

	try
	{
		this->ctrl.addDogToRepo(breed,age,photograph);
		// refresh the list
		this->currentDogsInRepoList = this->ctrl.showDogs();
		this->populateRepoList();
	}
	catch (const char *message) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(message));
	}
	
}

void lastlab::deleteDog()
{
	std::string breed = this->breedEdit->text().toStdString();
	std::string photograph = this->photographEdit->text().toStdString();
	int age = this->ageEdit->text().toInt();
	try
	{
		this->ctrl.removeDogFromRepo(breed, age, photograph);
		// refresh the list
		this->currentDogsInRepoList = this->ctrl.showDogs();
		this->populateRepoList();
	}
	catch (const char *message)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(message));
	}
}

void lastlab::filterRepoDogs()
{
	std::string breed = this->breedEdit->text().toStdString();

	if (this->repoList->count() > 0)
		this->repoList->clear();

	this->currentDogsInRepoList = this->ctrl.showDogs();

	if (breed == "") {
		this->populateRepoList();
	}
	else {
		for (auto s : this->currentDogsInRepoList)
		{
			if (s.get_breed() == breed) {
				string dogage = to_string(s.get_age());
				QString itemInList = QString::fromStdString(s.get_breed() + " - " + dogage + " - " + s.get_photograph());
				this->repoList->addItem(itemInList);
			}
		}
	}
}

void lastlab::moveDogToAdoptionList()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1 || idx >= this->currentDogsInRepoList.size())
		return;

	const Dog& s = this->currentDogsInRepoList[idx];
	this->ctrl.addDogToADL(s.get_breed(), s.get_age(), s.get_photograph());
	this->ctrl.removeDogFromRepo(s.get_breed(), s.get_age(), s.get_photograph());
	this->populateAdoptionList();
	// refresh the repo list
	this->currentDogsInRepoList = this->ctrl.showDogs();
	this->populateRepoList();
}

void lastlab::updateDog() {
	
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Dog> dogs = this->currentDogsInRepoList;

	// get the dog at the selected index
	if (idx >= dogs.size())
		return;
	Dog s = dogs[idx];
	int age = s.get_age();
	string photograph = s.get_photograph();


	std::string breed = this->breedEdit->text().toStdString();
	int age2 = this->ageEdit->text().toInt();
	std::string photograph2 = this->photographEdit->text().toStdString();
	

	this->ctrl.updateDogInRepo(breed, age, photograph, breed, age2, photograph2);
	// refresh the list
	this->currentDogsInRepoList = this->ctrl.showDogs();
	this->populateRepoList();
}

void lastlab::saveHTML() {
	string filename = "adlist.html";
	try {
		this->ctrl.writeToCSVorHTML(filename);
		QMessageBox messageBox3;
		messageBox3.setText("Succesfully saved the HTML file");
		messageBox3.exec();
	}
	catch (const char* message) {
		QMessageBox messageBox2;
		messageBox2.critical(0,"Error",QString::fromStdString(message));
	}
}

void lastlab::saveCSV() {
	string filename = "adlist.csv";
	try {
		this->ctrl.writeToCSVorHTML(filename);
		QMessageBox messageBox4;
		messageBox4.setText("Succesfully saved the CSV file");
		messageBox4.exec();
	}
	catch (const char* message) {
		QMessageBox messageBox5;
		messageBox5.critical(0, "Error", QString::fromStdString(message));
	}
}

void lastlab::openCSV() {
	string filename = "adlist.csv";
	this->ctrl.openCSVorHTML(filename);
}

void lastlab::openHTML() {
	string filename = "adlist.html";
	this->ctrl.openCSVorHTML(filename);
}
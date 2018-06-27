#ifndef LASTLAB_H
#define LASTLAB_H

#include <QtWidgets/QMainWindow>
#include "controller.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class lastlab : public QWidget //public QMainWindow
{
	Q_OBJECT

public:
	lastlab(Controller& c, QWidget *parent = 0);
	~lastlab();

private:
	Controller& ctrl;
	std::vector<Dog> currentDogsInRepoList;

	QListWidget* repoList;
	QLineEdit* breedEdit;
	QLineEdit* ageEdit;
	QLineEdit* photographEdit;

	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* filterButton;
	QPushButton* moveDogButton;
	QPushButton* updateButton;
	QPushButton* saveButtonHTML;
	QPushButton* openButtonHTML;
	QPushButton* saveButtonCSV;
	QPushButton* openButtonCSV;

	QListWidget* adoptionList;

	void initGUI();
	void populateRepoList();
	void populateAdoptionList();
	int getRepoListSelectedIndex();

	void connectSignalsAndSlots();

	private slots:
	// When an item in the list is clicked, the text boxes get filled with the item's information
	void listItemChanged();

	void addNewDog();
	void deleteDog();
	void updateDog();
	// filters the elements in the list, by the breed written in the breed edit box
	void filterRepoDogs();

	void moveDogToAdoptionList();
	void saveHTML();
	void openHTML();
	void saveCSV();
	void openCSV();
};


#endif // LASTLAB_H

#include "lastlab.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{ "dogs.txt" };
	Controller ctrl{ repo };
	lastlab w{ ctrl };
	w.show();

	return a.exec();
}

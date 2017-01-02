#include <QApplication>
#include "myDialog.h"

int main(int argc, char * argv[ ])
{
	QApplication app(argc, argv);

	myDialog window;
	window.show();

	return app.exec();
}

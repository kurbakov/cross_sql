#include <gui.h>

#include <QMenu>
#include <QMenuBar>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QHBoxLayout>


Gui::Gui(QWidget *parent) : QMainWindow(parent)
{
  	createMenu();

  	// List of idgets to use in the App
  	QTextEdit *queryEdit = new QTextEdit();
  	queryEdit->setPlainText(tr("write query here..."));

  	QVBoxLayout *mainLayout = new QVBoxLayout();


  	mainLayout->addWidget(queryEdit);
  	setLayout(mainLayout);
  	setWindowTitle("CROSS");
  	resize(300, 200);

}

void Gui::createMenu()
{

  	QMenu *file;
  	file = menuBar()->addMenu("&File");

  	QMenu *connection;
  	connection = menuBar()->addMenu("&Connection");

  	QMenu *run; 
  	run = menuBar()->addMenu("&Run");
  	
  	QMenu *about;
  	about = menuBar()->addMenu("&About");

}

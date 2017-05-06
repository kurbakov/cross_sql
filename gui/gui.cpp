#include <gui.h>
#include <QtWidgets>


Gui::Gui()
{
  	createMenu();

  	// List of idgets to use in the App

    bigEditor = new QTextEdit;
    bigEditor->setPlainText(tr("This widget takes up all the remaining space in the top-level layout."));

  	QVBoxLayout *mainLayout = new QVBoxLayout;
  	mainLayout->setMenuBar(menuBar);
	mainLayout->addWidget(bigEditor);
  	setLayout(mainLayout);
  	
  	setWindowTitle("CROSS");
  	resize(300, 200);
}

void Gui::createMenu()
{

    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    connection = new QMenu(tr("&Connection"));
    run = new QMenu(tr("&Run"));
    about = new QMenu(tr("&About"));

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(connection);
    menuBar->addMenu(run);
    menuBar->addMenu(about);
}

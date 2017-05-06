#ifndef GUI_H
#define GUI_H

#pragma once

#include <QMainWindow>

class QTextEdit;
class QMenuBar;
class QMenu;

class Gui : public QMainWindow
{
	Q_OBJECT

private:
	
	QTextEdit *bigEditor;
	
	QMenuBar *menuBar;
	QMenu *fileMenu;
	QMenu *connection;
	QMenu *run;
	QMenu *about;

	void createMenu();

public:
	Gui();

};

#endif // GUI_H 
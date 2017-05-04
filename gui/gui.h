#ifndef GUI_H
#define GUI_H

#pragma once

#include <QMainWindow>
#include <QApplication>


class Gui : public QMainWindow
{
private:
	void createMenu();

public:
	Gui(QWidget *parent = 0);

};

#endif // GUI_H 
#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QtWidgets>

class QTextEdit;
class QListWidget;
class QTableWidget;
class QMenu;
class QAction;

class Gui : public QMainWindow
{
    Q_OBJECT

public:
    Gui();
  
private:
    void createMenu();
    void createDockWindows();

    void about();
    void addConnection();
    void deleteConnction();

    void run_query();

    QTextEdit *queryEdit;
    QListWidget *connectionList;
    QTableWidget *resultTable;

    QMenu *viewMenu;
};

#endif
#include <QtWidgets>
#include <QMenu>
#include <QMenuBar>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Layout 
    QListWidget *connectionList = new QListWidget();
    QTextEdit *queryEdit = new QTextEdit();
    QTableView *resultView = new QTableView();

    QSplitter *querySplitter = new QSplitter(Qt::Vertical);
    querySplitter->addWidget(queryEdit);
    querySplitter->addWidget(resultView);

    QSplitter *mainSplitter = new QSplitter(Qt::Horizontal);
    mainSplitter->addWidget(connectionList);
    mainSplitter->addWidget(querySplitter);

    // Menu

    QMenu *file;
    file = menuBar()->addMenu("&File");

    // QMenu *connection;
    // connection = menuBar()->addMenu("&Connection");

    // QMenu *run;
    // run = menuBar()->addMenu("&Run");

    // Set up the model and configure the view...

    QStandardItemModel model;

    // column names
    model.setHorizontalHeaderLabels(
        QStringList() << QApplication::translate("nestedlayouts", "Name")
                      << QApplication::translate("nestedlayouts", "Office"));

    // print the table
    QList<QStringList> rows = QList<QStringList>()
        << (QStringList() << "Verne Nilsen" << "123")
        << (QStringList() << "Carlos Tang" << "77")
        << (QStringList() << "Bronwyn Hawcroft" << "119")
        << (QStringList() << "Alessandro Hanssen" << "32")
        << (QStringList() << "Andrew John Bakken" << "54")
        << (QStringList() << "Vanessa Weatherley" << "85")
        << (QStringList() << "Rebecca Dickens" << "17")
        << (QStringList() << "David Bradley" << "42")
        << (QStringList() << "Knut Walters" << "25")
        << (QStringList() << "Andrea Jones" << "34");

    foreach (QStringList row, rows) {
        QList<QStandardItem *> items;
        foreach (QString text, row)
            items.append(new QStandardItem(text));
        model.appendRow(items);
    }

    resultView->setModel(&model);
    resultView->verticalHeader()->hide();
    resultView->horizontalHeader()->setStretchLastSection(true);

    mainSplitter->show();

    return app.exec();
}
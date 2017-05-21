#include <QApplication>

#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Q_INIT_RESOURCE(cross);
    
    Gui mainWin;
    mainWin.show();
    
    return app.exec();
}
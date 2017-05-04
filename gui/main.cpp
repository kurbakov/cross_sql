#include <gui.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Gui window;
    window.resize(800, 450);
    window.setWindowTitle("CROSS");

    window.show();

    return app.exec();
}
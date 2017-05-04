#include <gui.cpp>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Gui window;

    window.resize(250, 150);
    window.setWindowTitle("CROSS");
    window.show();

    return app.exec();
}
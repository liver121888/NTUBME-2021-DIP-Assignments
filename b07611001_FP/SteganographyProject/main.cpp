#include "steganographyproject.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("../Icon.ico"));
    SteganographyProject w;
    w.show();
    return a.exec();
}

#include "ukui_systemtrayicon_test.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UkuiSystemTrayIconTest w;
    w.show();
    return a.exec();
}

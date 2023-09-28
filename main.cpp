#include "creditvalidator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CreditValidator w;
    w.show();
    return a.exec();
}

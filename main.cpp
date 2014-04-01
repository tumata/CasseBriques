#include "cfenetreprincipale.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CFenetrePrincipale w;
    w.show();

    return a.exec();
}

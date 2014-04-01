#ifndef CFENETREPRINCIPALE_H
#define CFENETREPRINCIPALE_H

#include <QMainWindow>
#include "CGLArea.h"

namespace Ui {
class CFenetrePrincipale;
}

class CFenetrePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    explicit CFenetrePrincipale(QWidget *parent = 0);
    ~CFenetrePrincipale();

private:
    Ui::CFenetrePrincipale *ui;

    CGLArea *m_CGLArea;
};

#endif // CFENETREPRINCIPALE_H

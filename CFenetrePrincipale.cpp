#include "CFenetrePrincipale.h"
#include "ui_CFenetrePrincipale.h"
#include "CGLArea.h"

CFenetrePrincipale::CFenetrePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CFenetrePrincipale)
{
    ui->setupUi(this);

    // Creation de la zone openGL
    m_CGLArea = new CGLArea(this);

    setCentralWidget(m_CGLArea);
}

CFenetrePrincipale::~CFenetrePrincipale()
{
    delete ui;
}

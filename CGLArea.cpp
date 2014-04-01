#include "CGLArea.h"
#include <math.h>
#include <GLUT/glut.h>

CGLArea::CGLArea(QWidget* parent) : QGLWidget(parent)
{


    maSphere = new CSphere(100);

}

CGLArea::~CGLArea()
{

}

/**
 * @brief CGLArea::minimumSizeHint
 * @return taille minimum de la fenetre openGL
 */
QSize CGLArea::minimumSizeHint() const
{
    return QSize(50,50);
}

/**
 * @brief CGLArea::sizeHint
 * @return la taille par default
 */
QSize CGLArea::sizeHint() const
{
    return QSize(400,400);
}

/**
 * @brief CGLArea::initializeGL
 *
 * Initialise la fenetre openGL
 */
void CGLArea::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glDisable(GL_COLOR_MATERIAL);

    glViewport(0, 0, 400, 400);
    initializeCamera();

}

void CGLArea::initializeCamera()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float m_fRadius = 5.0;
    float m_fAzimuth = 0.0;
    float m_fElevation = 0.0;

    glOrtho(-2.0, +2.0, -2.0, +2.0, 0.0, 15.0);
    gluLookAt(m_fRadius*cos(m_fAzimuth)*cos(m_fElevation),
              m_fRadius*sin(m_fAzimuth)*cos(m_fElevation),
              m_fRadius*sin(m_fElevation),
              0,0,0,
              0,0,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/**
 * @brief CGLArea::paintGL
 *
 * Fonction de dessin sur la fenetre openGL
 */
void CGLArea::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    //    paintRef();



    GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat lightColor[] = {0.6f, 0.6f, 0.6f, 1.0f};
    GLfloat lightPos[] ={10,0,-15,1};

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);


    maSphere->vSetMaterialColor();


    CVector3 oPos;
    maSphere->vGetPosition(&oPos);

    glLoadIdentity();
    glTranslatef(oPos.fGetX(), oPos.fGetY(), oPos.fGetZ());

    // For each face...
    for(int j=0; j<maSphere->iGetNbFaces(); j++)
    {


        glBegin(GL_POLYGON);
        // For each vertex of the face
        for(int k=0;k<maSphere->iGetNbVertices(j);k++)
        {
            CVector3 oVertex;
            CVector3 oNormal;
            maSphere->vGetVertex(j,k,&oVertex);
            maSphere->vGetNormale(j,k,&oNormal);
            glNormal3f(oVertex.fGetX(), oVertex.fGetY(), oVertex.fGetZ());
            glVertex3f(oVertex.fGetX(), oVertex.fGetY(), oVertex.fGetZ());
        }
        glEnd();
    }
}

/**
 * @brief CGLArea::resizeGL
 * @param width
 * @param height
 *
 * Evenement lors du resize de la fenetre openGL
 */
void CGLArea::resizeGL(int _width, int _height)
{
    int side = qMin(_width, _height);
    glViewport((_width - side) / 2, (_height - side) / 2, side, side);

    initializeCamera();

}

void CGLArea::paintRef()
{
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    glColor3f(0, 1, 0);
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    glColor3f(0, 0, 1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    glEnd();
}

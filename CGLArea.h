#ifndef CGLAREA_H
#define CGLAREA_H

#include <QGLWidget>
#include <CObject.h>
#include <CSphere.h>

class CGLArea : public QGLWidget
{
    Q_OBJECT

public:
    CGLArea(QWidget* parent = 0);
    ~CGLArea();

    QSize   minimumSizeHint() const;
    QSize   sizeHint() const;

    void    initializeCamera();

protected:
    void    initializeGL();
    void    paintGL();
    void    resizeGL(int _width, int _height);

private:

    CObject* maSphere;

    void    paintRef();
};

#endif // CGLAREA_H

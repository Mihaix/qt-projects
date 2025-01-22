#ifndef DRAWING_H
#define DRAWING_H

#include "qevent.h"
#include <QWidget>
#include <QPainter>
#include <QColorDialog>
#include <QInputDialog>

class Drawing : public QWidget
{
    Q_OBJECT

public:
    Drawing(QWidget *parent = nullptr);

    void setPenColor();
    void setPenWidth();

    bool isModified() const { return modified; }

public slots:
    void clearImage();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void drawLineTo(QPoint const& endPoint);
    void resizeImage(QImage *image, QSize const& newSize);

    bool modified = false;
    bool drawing = false;
    int currentPenWidth = 5;
    QColor currentPenColor = Qt::green;
    QImage image;
    QPoint lastPoint;

};

#endif

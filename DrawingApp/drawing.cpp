#include "drawing.h"

Drawing::Drawing(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);

}

void Drawing::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->position().toPoint();
        drawing = true;
    }
}

void Drawing::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && drawing)
    {
        drawLineTo(event->position().toPoint());
    }
}

void Drawing::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && drawing)
    {
        drawLineTo(event->position().toPoint());
        drawing = false;
    }
}

void Drawing::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rec = event->rect();
    painter.drawImage(rec, image, rec);
}

void Drawing::drawLineTo(QPoint const& endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(currentPenColor, currentPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    painter.drawLine(lastPoint, endPoint);
    modified = true;

    update();
    lastPoint = endPoint;
}

void Drawing::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height())
    {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }

    QWidget::resizeEvent(event);
}

void Drawing::resizeImage(QImage *image, QSize const& newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void Drawing::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}

void Drawing::setPenColor()
{
    QColor newColor = QColorDialog::getColor(Qt::white, this);
    currentPenColor = newColor;
}

void Drawing::setPenWidth()
{
    int newWidth = QInputDialog::getInt(this, tr("Drawing"), tr("Select pen width:"),
                   currentPenWidth, 1, 200, 1);

    currentPenWidth = newWidth;
}






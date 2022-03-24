#ifndef CUERPOGRAV_H
#define CUERPOGRAV_H

#include <QGraphicsItem>
#include <QPainter>
class cuerpoGrav : public QGraphicsItem{
public:
    cuerpoGrav(double, double, double);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    double getX() const;
    void setX(double value);

    double getY() const;
    void setY(double value);

    double getM() const;
    void setM(double value);

private:
    double X;
    double Y;
    double m;
};

#endif // CUERPOGRAV_H

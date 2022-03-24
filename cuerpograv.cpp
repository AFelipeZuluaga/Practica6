#include "cuerpograv.h"
#define SCALE 0.01
cuerpoGrav::cuerpoGrav(double posX, double posY, double masa){
    X = posX;
    Y = posY;
    m = masa;
}
QRectF cuerpoGrav::boundingRect() const{
    return QRectF(-X-10,-Y-10,20,20);
}

void cuerpoGrav::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

double cuerpoGrav::getX() const{
    return X;
}

void cuerpoGrav::setX(double value){
    X = value;
}

double cuerpoGrav::getY() const{
    return Y;
}

void cuerpoGrav::setY(double value){
    Y = value;
}

double cuerpoGrav::getM() const{
    return m;
}

void cuerpoGrav::setM(double value){
    m = value;
}

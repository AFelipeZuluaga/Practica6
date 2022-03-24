#include "planeta.h"
#define SCALE 0.01
planeta::planeta(double posX, double posY, double masa, double VelX, double VelY,double X_1, double Y_1, double M){
    X    = posX;
    Y    = posY;
    m    = masa;
    VX   = VelX;
    VY   = VelY;
    m2   = M;
    X1   = X_1;
    Y1   = Y_1;
}
QRectF planeta::boundingRect() const{
    return QRectF(X-5,-Y-5,10,10);
    //return QRectF((-X*SCALE)-5,(-Y*SCALE)-5,10,10);
}

void planeta::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void planeta::calculatePosition(double dt){
    double theta =  0;
    double r2    =  0;

    /*if((X -X1) == 0){
        //theta = atan((Y1 - Y)/(0.0000000000001));
        theta = atan2((Y1 - Y),0.0000000000001);
    }else{
        //theta = atan((Y1 - Y)/(X1 - X));
        theta = atan2((Y1 - Y),(X1 - X));
    }*/

    r2 = ((pow(X1 - X, 2)) + (pow(Y1 - Y, 2)));
    theta = atan2((Y1 - Y),(X1 - X));

    //Calculamos aceleracion en ambos ejes
    Ax = (G * m2 * cos(theta))/(r2);
    Ay = (G * m2 * sin(theta))/(r2);

    //Calculamos velocidades en ambos ejes
    VX = VX + Ax * dt;
    VY = VY + Ay * dt;

    //Calculamos posicion en ambos ejes
    X = X + (VX*dt) + ((Ax*dt*dt)/2);
    Y = Y + (VY*dt) + ((Ay*dt*dt)/2);
}

float planeta::getX() const{
    return X;
}

void planeta::setX(float value){
    X = value;
}

float planeta::getY() const{
    return Y;
}

void planeta::setY(float value){
    Y = value;
}

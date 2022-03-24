#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>

#include "planeta.h"
#include "cuerpograv.h"

#include <iostream>
using namespace std;
QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void readSystem();
public slots:
    void calculatePosition();
private slots:
    void on_Start_clicked();

    void on_Scroll_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;//Declaracion de la escena
    QTimer *timer;

    cuerpoGrav *cuerpoGravitacional;
    planeta *planet;
    vector<planeta *> planets;

    ofstream coordenadas;

    float SCALE = 0.01;
    int aux=1;
};
#endif // MAINWINDOW_H

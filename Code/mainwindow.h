
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include "colorsystem.h"
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QMouseEvent>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QValidator>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    ~MainWindow();

private slots:
    void on_comboBox_activated(int index);

    void valueChangedSlider1(int);
    void valueChangedSlider2(int);
    void valueChangedSlider3(int);

    void valueChangedSpin1(double);
    void valueChangedSpin2(double);
    void valueChangedSpin3(double);

    void on_dialog_clicked();

private:
    Ui::MainWindow *ui;
    ColorSystem *first;
    ColorSystem *second;
    ColorSystem *third;
    QColor mainColor;

    void updateColor();
    void swichSignals(bool);
    void setFirst(int);
    void setSecond(int);
    void setThird(int);
    void setColor();






};

#endif // MAINWINDOW_H

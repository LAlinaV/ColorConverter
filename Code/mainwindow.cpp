
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->col->setStyleSheet("border-color: black; border-style: groove; border-width: 3px;");
    //ui->pal->setStyleSheet("border-color: black; border-style: groove; border-width: 3px;");
    setFirst(0);
    setSecond(0);
    setThird(0);

    first = new RGB(0, 0, 0);
    second = new Lab(0, 0, 0);
    third = new CMYK(0, 0, 0, 0);

    connect(ui->sb11, SIGNAL(valueChanged(double)), this, SLOT(valueChangedSpin1(double)));
    connect(ui->sb12, SIGNAL(valueChanged(double)), this, SLOT(valueChangedSpin1(double)));
    connect(ui->sb13, SIGNAL(valueChanged(double)), this, SLOT(valueChangedSpin1(double)));
    connect(ui->sb14, SIGNAL(valueChanged(double)), this, SLOT(valueChangedSpin1(double)));

    connect(ui->sb21, SIGNAL(valueChanged(double)), this, SLOT(valueChangedSpin2(double)));
    connect(ui->sb22, SIGNAL(valueChanged(double)), this, SLOT(valueChangedSpin2(double)));
    connect(ui->sb23, SIGNAL(valueChanged(double)), this, SLOT(valueChangedSpin2(double)));
    connect(ui->sb24, SIGNAL(valueChanged(double)), this, SLOT(valueChangedSpin2(double)));

    connect(ui->sb31, SIGNAL(valueChanged(double)), this, SLOT(valueChangedSpin3(double)));
    connect(ui->sb32, SIGNAL(valueChanged(double)), this, SLOT(valueChangedSpin3(double)));
    connect(ui->sb33, SIGNAL(valueChanged(double)), this, SLOT(valueChangedSpin3(double)));
    connect(ui->sb34, SIGNAL(valueChanged(double)), this, SLOT(valueChangedSpin3(double)));

    connect(ui->s11, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlider1(int)));
    connect(ui->s12, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlider1(int)));
    connect(ui->s13, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlider1(int)));
    connect(ui->s14, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlider1(int)));

    connect(ui->s21, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlider2(int)));
    connect(ui->s22, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlider2(int)));
    connect(ui->s23, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlider2(int)));
    connect(ui->s24, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlider2(int)));

    connect(ui->s31, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlider3(int)));
    connect(ui->s32, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlider3(int)));
    connect(ui->s33, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlider3(int)));
    connect(ui->s34, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlider3(int)));

    updateColor();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_comboBox_activated(int index)
{
    swichSignals(true);
    switch (index){
    case 0:

        setFirst(0);
        setSecond(0);
        setThird(0);
        setColor();
        break;
    case 1:
        setFirst(1);
        setSecond(1);
        setThird(1);
        setColor();
        break;
    case 2:
        setFirst(2);
        setSecond(2);
        setThird(2);
        setColor();
        break;
    case 3:
        setFirst(3);
        setSecond(3);
        setThird(3);
        setColor();
        break;
    case 4:
        setFirst(4);
        setSecond(4);
        setThird(4);
        setColor();
        break;
    case 5:
        setFirst(5);
        setSecond(5);
        setThird(5);
        setColor();
        break;
    case 6:
        setFirst(6);
        setSecond(6);
        setThird(6);
        updateColor();
        break;
    case 7:
        setFirst(7);
        setSecond(7);
        setThird(7);
        setColor();
        break;
    case 8:
        setFirst(8);
        setSecond(8);
        setThird(8);
        setColor();
        break;
    case 9:
        setFirst(9);
        setSecond(9);
        setThird(9);
        setColor();
        break;
    case 10:
        setFirst(10);
        setSecond(10);
        setThird(10);
        updateColor();
        break;
    case 11:
        setFirst(11);
        setSecond(11);
        setThird(11);
        setColor();
        break;
    case 12:
        setFirst(12);
        setSecond(12);
        setThird(12);
        setColor();
        break;
    case 13:
        setFirst(13);
        setSecond(13);
        setThird(13);
        setColor();
        break;
    case 14:
        setFirst(14);
        setSecond(14);
        setThird(14);
        setColor();
        break;
    case 15:
        setFirst(15);
        setSecond(15);
        setThird(15);
        setColor();
        break;
    case 16:
        setFirst(16);
        setSecond(16);
        setThird(16);
        setColor();
        break;
    case 17:
        setFirst(17);
        setSecond(17);
        setThird(17);
        setColor();
        break;
    }
    swichSignals(false);
}


void MainWindow::on_dialog_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Выберите цвет");

    if (color.isValid())
    {
        mainColor = color;
        RGB *rgb = new RGB(mainColor.red(), mainColor.green(), mainColor.blue());

        QString fir = ui->l1->text();
        if (fir == "RGB")
        {
            first = rgb->toRGB();
        }
        else if (fir == "CMYK")
        {
            first = rgb->toCMYK();
        }
        else if (fir == "HSV")
        {
            first = rgb->toHSV();
        }
        else if (fir == "HSL")
        {
            first = rgb->toHLS();
        }
        else if (fir == "XYZ")
        {
            first = rgb->toXYZ();
        }
        else
        {
            first = rgb->toLAB();
        }

        QString sec = ui->l2->text();
        if (sec == "RGB")
        {
            second = rgb->toRGB();
        }
        else if (sec == "CMYK")
        {
            second = rgb->toCMYK();
        }
        else if (sec == "HSV")
        {
            second = rgb->toHSV();
        }
        else if (sec == "HSL")
        {
            second = rgb->toHLS();
        }
        else if (sec == "XYZ")
        {
            second = rgb->toXYZ();
        }
        else
        {
            second = rgb->toLAB();
        }

        QString thi = ui->l3->text();
        if (thi == "RGB")
        {
            third = rgb->toRGB();
        }
        else if (thi == "CMYK")
        {
            third = rgb->toCMYK();
        }
        else if (thi == "HSV")
        {
            third = rgb->toHSV();
        }
        else if (thi == "HSL")
        {
            third = rgb->toHLS();
        }
        else if (thi == "XYZ")
        {
            third = rgb->toXYZ();
        }
        else
        {
            third = rgb->toLAB();
        }

        updateColor();
    }
}

void MainWindow::updateColor()
{
    QString styleSheet = QString("background-color: %1").arg(mainColor.name());
    ui->col->setStyleSheet(styleSheet);

    swichSignals(true);

    ui->s11->setValue(first->getComponent1());
    ui->s12->setValue(first->getComponent2());
    ui->s13->setValue(first->getComponent3());
    ui->s14->setValue(first->getComponent4());

    ui->s21->setValue(second->getComponent1());
    ui->s22->setValue(second->getComponent2());
    ui->s23->setValue(second->getComponent3());
    ui->s24->setValue(second->getComponent4());

    ui->s31->setValue(third->getComponent1());
    ui->s32->setValue(third->getComponent2());
    ui->s33->setValue(third->getComponent3());
    ui->s34->setValue(third->getComponent4());


    ui->sb11->setValue(first->getComponent1());
    ui->sb12->setValue(first->getComponent2());
    ui->sb13->setValue(first->getComponent3());
    ui->sb14->setValue(first->getComponent4());

    ui->sb21->setValue(second->getComponent1());
    ui->sb22->setValue(second->getComponent2());
    ui->sb23->setValue(second->getComponent3());
    ui->sb24->setValue(second->getComponent4());

    ui->sb31->setValue(third->getComponent1());
    ui->sb32->setValue(third->getComponent2());
    ui->sb33->setValue(third->getComponent3());
    ui->sb34->setValue(third->getComponent4());

    swichSignals(false);
}

void MainWindow::setFirst(int ind)
{
    if (ind == 0 || ind == 1 || ind == 2 || ind == 3 || ind == 7 || ind == 11 || ind == 12 || ind == 14 || ind == 16)
    {
        ui->l14->hide();
        ui->sb14->hide();
        ui->s14->hide();
        ui->l1->setText("RGB");
        ui->l11->setText("R");
        ui->l12->setText("G");
        ui->l13->setText("B");

        ui->s11->setRange(0, 255);

        ui->s12->setRange(0, 255);

        ui->s13->setRange(0, 255);
        ui->sb11->setRange(0, 255);

        ui->sb12->setRange(0, 255);

        ui->sb13->setRange(0, 255);





        return;
    }
    if (ind ==4 || ind == 5 || ind == 6 || ind == 9 || ind == 13 || ind == 15 || ind == 17)
    {
        ui->l1->setText("CMYK");
        ui->l11->setText("C");
        ui->l12->setText("M");
        ui->l13->setText("Y");
        ui->l14->setText("K");



        ui->l14->show();
        ui->sb14->show();
        ui->s14->show();


        ui->s11->setRange(0, 100);

        ui->s12->setRange(0, 100);

        ui->s13->setRange(0, 100);

        ui->s14->setRange(0, 100);
        ui->sb11->setRange(0, 100);

        ui->sb12->setRange(0, 100);

        ui->sb13->setRange(0, 100);

        ui->sb14->setRange(0, 100);



        return;
    }
    if (ind == 8)
    {
        ui->l14->hide();
        ui->sb14->hide();
        ui->s14->hide();
        ui->l1->setText("HSV");
        ui->l11->setText("H");
        ui->l12->setText("S");
        ui->l13->setText("V");


        ui->s11->setRange(0, 360);

        ui->s12->setRange(0, 100);

        ui->s13->setRange(0, 100);
        ui->sb11->setRange(0, 360);

        ui->sb12->setRange(0, 100);

        ui->sb13->setRange(0, 100);





        return;
    }

    if (ind == 10)
    {
        ui->l14->hide();
        ui->sb14->hide();
        ui->s14->hide();
        ui->l1->setText("XYZ");
        ui->l11->setText("X");
        ui->l12->setText("Y");
        ui->l13->setText("Z");


        ui->s11->setRange(0, 95);

        ui->s12->setRange(0, 100);

        ui->s13->setRange(0, 109);
        ui->sb11->setRange(0, 95);

        ui->sb12->setRange(0, 100);

        ui->sb13->setRange(0, 109);



        return;
    }

}

void MainWindow::setSecond(int ind)
{
    if (ind == 5 || ind == 6)
    {
        ui->l24->hide();
        ui->sb24->hide();
        ui->s24->hide();
        ui->l2->setText("RGB");
        ui->l21->setText("R");
        ui->l22->setText("G");
        ui->l23->setText("B");

        ui->s21->setRange(0, 255);

        ui->s22->setRange(0, 255);

        ui->s23->setRange(0, 255);

        ui->sb21->setRange(0, 255);

        ui->sb22->setRange(0, 255);

        ui->sb23->setRange(0, 255);



        return;
    }
    if (ind == 1 || ind == 14)
    {
        ui->l2->setText("CMYK");
        ui->l21->setText("C");
        ui->l22->setText("M");
        ui->l23->setText("Y");
        ui->l24->setText("K");



        ui->l24->show();
        ui->sb24->show();
        ui->s24->show();


        ui->s21->setRange(0, 100);

        ui->s22->setRange(0, 100);

        ui->s23->setRange(0, 100);

        ui->s24->setRange(0, 100);
        ui->sb21->setRange(0, 100);

        ui->sb22->setRange(0, 100);

        ui->sb23->setRange(0, 100);

        ui->sb24->setRange(0, 100);



        return;
    }
    if (ind == 3)
    {
        ui->l24->hide();
        ui->sb24->hide();
        ui->s24->hide();
        ui->l2->setText("HSV");
        ui->l21->setText("H");
        ui->l22->setText("S");
        ui->l23->setText("V");


        ui->s21->setRange(0, 360);

        ui->s22->setRange(0, 100);

        ui->s23->setRange(0, 100);
        ui->sb21->setRange(0, 360);

        ui->sb22->setRange(0, 100);

        ui->sb23->setRange(0, 100);



        return;
    }
    if (ind == 15 || ind == 16)
    {
        ui->l24->hide();
        ui->sb24->hide();
        ui->s24->hide();
        ui->l2->setText("HLS");
        ui->l21->setText("H");
        ui->l22->setText("L");
        ui->l23->setText("S");


        ui->s21->setRange(0, 360);

        ui->s22->setRange(0, 100);

        ui->s23->setRange(0, 100);
        ui->sb21->setRange(0, 360);

        ui->sb22->setRange(0, 100);

        ui->sb23->setRange(0, 100);


        return;
    }
    if (ind == 2 || ind == 7 || ind == 8 || ind == 11 || ind == 12 || ind == 17)
    {
        ui->l24->hide();
        ui->sb24->hide();
        ui->s24->hide();
        ui->l2->setText("XYZ");
        ui->l21->setText("X");
        ui->l22->setText("Y");
        ui->l23->setText("Z");


        ui->s21->setRange(0, 95);

        ui->s22->setRange(0, 100);

        ui->s23->setRange(0, 109);
        ui->sb21->setRange(0, 95);

        ui->sb22->setRange(0, 100);

        ui->sb23->setRange(0, 109);



        return;
    }
    if (ind == 0 || ind == 4 || ind == 9 || ind == 10 || ind == 13)
    {
        ui->l24->hide();
        ui->sb24->hide();
        ui->s24->hide();
        ui->l2->setText("LAB");
        ui->l21->setText("L");
        ui->l22->setText("A");
        ui->l23->setText("B");

        ui->s21->setRange(0, 100);

        ui->s22->setRange(-128, 128);
        ui->s23->setRange(-128, 128);
        ui->sb21->setRange(0, 100);

        ui->sb22->setRange(-128, 128);
        ui->sb23->setRange(-128, 128);



        return;
    }
}

void MainWindow::setThird(int ind)
{
    if (ind == 9 || ind == 17)
    {
        ui->l34->hide();
        ui->sb34->hide();
        ui->s34->hide();
        ui->l3->setText("RGB");
        ui->l31->setText("R");
        ui->l32->setText("G");
        ui->l33->setText("B");

        ui->s31->setRange(0, 255);

        ui->s32->setRange(0, 255);

        ui->s33->setRange(0, 255);
        ui->sb31->setRange(0, 255);

        ui->sb32->setRange(0, 255);

        ui->sb33->setRange(0, 255);


        return;
    }
    if (ind == 0 || ind == 12)
    {
        ui->l3->setText("CMYK");
        ui->l31->setText("C");
        ui->l32->setText("M");
        ui->l33->setText("Y");
        ui->l34->setText("K");



        ui->l34->show();
        ui->sb34->show();
        ui->s34->show();


        ui->s31->setRange(0, 100);

        ui->s32->setRange(0, 100);

        ui->s33->setRange(0, 100);

        ui->s34->setRange(0, 100);

        ui->sb31->setRange(0, 100);

        ui->sb32->setRange(0, 100);

        ui->sb33->setRange(0, 100);

        ui->sb34->setRange(0, 100);
        return;
    }
    if (ind == 4 || ind == 6 || ind == 7 || ind == 14)
    {
        ui->l34->hide();
        ui->sb34->hide();
        ui->s34->hide();
        ui->l3->setText("HSV");
        ui->l31->setText("H");
        ui->l32->setText("S");
        ui->l33->setText("V");


        ui->s31->setRange(0, 360);

        ui->s32->setRange(0, 100);

        ui->s33->setRange(0, 100);

        ui->sb31->setRange(0, 360);

        ui->sb32->setRange(0, 100);

        ui->sb33->setRange(0, 100);



        return;
    }
    if (ind == 1 || ind == 5 || ind == 10 || ind == 11)
    {

        ui->l34->hide();
        ui->sb34->hide();
        ui->s34->hide();
        ui->l3->setText("HLS");
        ui->l31->setText("H");
        ui->l32->setText("L");
        ui->l33->setText("S");


        ui->s31->setRange(0, 360);

        ui->s32->setRange(0, 100);

        ui->s33->setRange(0, 100);
        ui->sb31->setRange(0, 360);

        ui->sb32->setRange(0, 100);

        ui->sb33->setRange(0, 100);



        return;
    }
    if (ind == 13 || ind == 15)
    {
        ui->l34->hide();
        ui->sb34->hide();
        ui->s34->hide();
        ui->l3->setText("XYZ");
        ui->l31->setText("X");
        ui->l32->setText("Y");
        ui->l33->setText("Z");


        ui->s31->setRange(0, 95);

        ui->s32->setRange(0, 100);

        ui->s33->setRange(0, 109);
        ui->sb31->setRange(0, 95);

        ui->sb32->setRange(0, 100);

        ui->sb33->setRange(0, 109);


        return;
    }
    if (ind == 2 || ind == 3 || ind == 8 || ind == 16 )
    {
        ui->l34->hide();
        ui->sb34->hide();
        ui->s34->hide();
        ui->l3->setText("LAB");
        ui->l31->setText("L");
        ui->l32->setText("A");
        ui->l33->setText("B");

        ui->s31->setRange(0, 100);

        ui->s32->setRange(-128, 128);
        ui->s33->setRange(-128, 128);
        ui->sb31->setRange(0, 100);

        ui->sb32->setRange(-128, 128);

        ui->sb33->setRange(-128, 128);



        return;
    }
}

void MainWindow::setColor()
{
    RGB *rgb = new RGB(mainColor.red(), mainColor.green(), mainColor.blue());

    QString fir = ui->l1->text();
    if (fir == "RGB")
    {
        first = rgb->toRGB();
    }
    else if (fir == "CMYK")
    {
        first = rgb->toCMYK();
    }
    else if (fir == "HSV")
    {
        first = rgb->toHSV();
    }
    else if (fir == "HSL")
    {
        first = rgb->toHLS();
    }
    else if (fir == "XYZ")
    {
        first = rgb->toXYZ();
    }
    else
    {
        first = rgb->toLAB();
    }

    QString sec = ui->l2->text();
    if (sec == "RGB")
    {
        second = rgb->toRGB();
    }
    else if (sec == "CMYK")
    {
        second = rgb->toCMYK();
    }
    else if (sec == "HSV")
    {
        second = rgb->toHSV();
    }
    else if (sec == "HSL")
    {
        second = rgb->toHLS();
    }
    else if (sec == "XYZ")
    {
        second = rgb->toXYZ();
    }
    else
    {
        second = rgb->toLAB();
    }

    QString thi = ui->l3->text();
    if (thi == "RGB")
    {
        third = rgb->toRGB();
    }
    else if (thi == "CMYK")
    {
        third = rgb->toCMYK();
    }
    else if (thi == "HSV")
    {
        third = rgb->toHSV();
    }
    else if (thi == "HSL")
    {
        third = rgb->toHLS();
    }
    else if (thi == "XYZ")
    {
        third = rgb->toXYZ();
    }
    else
    {
        third = rgb->toLAB();
    }

    updateColor();

}


void MainWindow::valueChangedSlider1(int)
{
    double val1 = ui->s11->value(), val2 = ui->s12->value(),
        val3 = ui->s13->value(), val4 = ui->s14->value();

    first->setComponent1(val1);
    first->setComponent2(val2);
    first->setComponent3(val3);
    first->setComponent4(val4);

    QString sec = ui->l2->text();
    if (sec == "RGB")
    {
        second = first->toRGB();
    }
    else if (sec == "CMYK")
    {
        second = first->toCMYK();
    }
    else if (sec == "HSV")
    {
        second = first->toHSV();
    }
    else if (sec == "HSL")
    {
        second = first->toHLS();
    }
    else if (sec == "XYZ")
    {
        second = first->toXYZ();
    }
    else
    {
        second = first->toLAB();
    }

    QString thi = ui->l3->text();
    if (thi == "RGB")
    {
        third = first->toRGB();
    }
    else if (thi == "CMYK")
    {
        third = first->toCMYK();
    }
    else if (thi == "HSV")
    {
        third = first->toHSV();
    }
    else if (thi == "HSL")
    {
        third = first->toHLS();
    }
    else if (thi == "XYZ")
    {
        third = first->toXYZ();
    }
    else
    {
        third = first->toLAB();
    }

    mainColor.setRed(first->toRGB()->getComponent1());
    mainColor.setGreen(first->toRGB()->getComponent2());
    mainColor.setBlue(first->toRGB()->getComponent3());
    updateColor();
}

void MainWindow::valueChangedSlider2(int)
{
    double val1 = ui->s21->value(), val2 = ui->s22->value(),
        val3 = ui->s23->value(), val4 = ui->s24->value();

    second->setComponent1(val1);
    second->setComponent2(val2);
    second->setComponent3(val3);
    second->setComponent4(val4);

    QString fir = ui->l1->text();
    if (fir == "RGB")
    {
        first = second->toRGB();
    }
    else if (fir == "CMYK")
    {
        first = second->toCMYK();
    }
    else if (fir == "HSV")
    {
        first = second->toHSV();
    }
    else if (fir == "HSL")
    {
        first = second->toHLS();
    }
    else if (fir == "XYZ")
    {
        first = second->toXYZ();
    }
    else
    {
        first = second->toLAB();
    }

    QString thi = ui->l3->text();
    if (thi == "RGB")
    {
        third = second->toRGB();
    }
    else if (thi == "CMYK")
    {
        third = second->toCMYK();
    }
    else if (thi == "HSV")
    {
        third = second->toHSV();
    }
    else if (thi == "HSL")
    {
        third = second->toHLS();
    }
    else if (thi == "XYZ")
    {
        third = second->toXYZ();
    }
    else
    {
        third = second->toLAB();
    }

    mainColor.setRed(second->toRGB()->getComponent1());
    mainColor.setGreen(second->toRGB()->getComponent2());
    mainColor.setBlue(second->toRGB()->getComponent3());
    updateColor();
}

void MainWindow::valueChangedSlider3(int)
{
    double val1 = ui->s31->value(), val2 = ui->s32->value(),
        val3 = ui->s33->value(), val4 = ui->s34->value();

    third->setComponent1(val1);
    third->setComponent2(val2);
    third->setComponent3(val3);
    third->setComponent4(val4);

    QString fir = ui->l1->text();
    if (fir == "RGB")
    {
        first = third->toRGB();
    }
    else if (fir == "CMYK")
    {
        first = third->toCMYK();
    }
    else if (fir == "HSV")
    {
        first = third->toHSV();
    }
    else if (fir == "HSL")
    {
        first = third->toHLS();
    }
    else if (fir == "XYZ")
    {
        first = third->toXYZ();
    }
    else
    {
        first = third->toLAB();
    }

    QString sec = ui->l2->text();
    if (sec == "RGB")
    {
        second = third->toRGB();
    }
    else if (sec == "CMYK")
    {
        second = third->toCMYK();
    }
    else if (sec == "HSV")
    {
        second = third->toHSV();
    }
    else if (sec == "HSL")
    {
        second = third->toHLS();
    }
    else if (sec == "XYZ")
    {
        second = third->toXYZ();
    }
    else
    {
        second = third->toLAB();
    }

    mainColor.setRed(third->toRGB()->getComponent1());
    mainColor.setGreen(third->toRGB()->getComponent2());
    mainColor.setBlue(third->toRGB()->getComponent3());
    updateColor();
}

void MainWindow::valueChangedSpin1(double)
{
    double val1 = ui->sb11->value(), val2 = ui->sb12->value(),
        val3 = ui->sb13->value(), val4 = ui->sb14->value();

    first->setComponent1(val1);
    first->setComponent2(val2);
    first->setComponent3(val3);
    first->setComponent4(val4);

    QString sec = ui->l2->text();
    if (sec == "RGB")
    {
        second = first->toRGB();
    }
    else if (sec == "CMYK")
    {
        second = first->toCMYK();
    }
    else if (sec == "HSV")
    {
        second = first->toHSV();
    }
    else if (sec == "HSL")
    {
        second = first->toHLS();
    }
    else if (sec == "XYZ")
    {
        second = first->toXYZ();
    }
    else
    {
        second = first->toLAB();
    }

    QString thi = ui->l3->text();
    if (thi == "RGB")
    {
        third = first->toRGB();
    }
    else if (thi == "CMYK")
    {
        third = first->toCMYK();
    }
    else if (thi == "HSV")
    {
        third = first->toHSV();
    }
    else if (thi == "HSL")
    {
        third = first->toHLS();
    }
    else if (thi == "XYZ")
    {
        third = first->toXYZ();
    }
    else
    {
        third = first->toLAB();
    }

    mainColor.setRed(first->toRGB()->getComponent1());
    mainColor.setGreen(first->toRGB()->getComponent2());
    mainColor.setBlue(first->toRGB()->getComponent3());
    updateColor();
}

void MainWindow::valueChangedSpin2(double)
{
    double val1 = ui->sb21->value(), val2 = ui->sb22->value(),
        val3 = ui->sb23->value(), val4 = ui->sb24->value();

    second->setComponent1(val1);
    second->setComponent2(val2);
    second->setComponent3(val3);
    second->setComponent4(val4);

    QString fir = ui->l1->text();
    if (fir == "RGB")
    {
        first = second->toRGB();
    }
    else if (fir == "CMYK")
    {
        first = second->toCMYK();
    }
    else if (fir == "HSV")
    {
        first = second->toHSV();
    }
    else if (fir == "HSL")
    {
        first = second->toHLS();
    }
    else if (fir == "XYZ")
    {
        first = second->toXYZ();
    }
    else
    {
        first = second->toLAB();
    }

    QString thi = ui->l3->text();
    if (thi == "RGB")
    {
        third = second->toRGB();
    }
    else if (thi == "CMYK")
    {
        third = second->toCMYK();
    }
    else if (thi == "HSV")
    {
        third = second->toHSV();
    }
    else if (thi == "HSL")
    {
        third = second->toHLS();
    }
    else if (thi == "XYZ")
    {
        third = second->toXYZ();
    }
    else
    {
        third = second->toLAB();
    }

    mainColor.setRed(second->toRGB()->getComponent1());
    mainColor.setGreen(second->toRGB()->getComponent2());
    mainColor.setBlue(second->toRGB()->getComponent3());
    updateColor();
}

void MainWindow::valueChangedSpin3(double)
{
    double val1 = ui->sb31->value(), val2 = ui->sb32->value(),
        val3 = ui->sb33->value(), val4 = ui->sb34->value();

    third->setComponent1(val1);
    third->setComponent2(val2);
    third->setComponent3(val3);
    third->setComponent4(val4);

    QString fir = ui->l1->text();
    if (fir == "RGB")
    {
        first = third->toRGB();
    }
    else if (fir == "CMYK")
    {
        first = third->toCMYK();
    }
    else if (fir == "HSV")
    {
        first = third->toHSV();
    }
    else if (fir == "HSL")
    {
        first = third->toHLS();
    }
    else if (fir == "XYZ")
    {
        first = third->toXYZ();
    }
    else
    {
        first = third->toLAB();
    }

    QString sec = ui->l2->text();
    if (sec == "RGB")
    {
        second = third->toRGB();
    }
    else if (sec == "CMYK")
    {
        second = third->toCMYK();
    }
    else if (sec == "HSV")
    {
        second = third->toHSV();
    }
    else if (sec == "HSL")
    {
        second = third->toHLS();
    }
    else if (sec == "XYZ")
    {
        second = third->toXYZ();
    }
    else
    {
        second = third->toLAB();
    }

    mainColor.setRed(third->toRGB()->getComponent1());
    mainColor.setGreen(third->toRGB()->getComponent2());
    mainColor.setBlue(third->toRGB()->getComponent3());
    updateColor();
}

void MainWindow::swichSignals(bool val)
{
    ui->s11->blockSignals(val);
    ui->s12->blockSignals(val);
    ui->s13->blockSignals(val);
    ui->s14->blockSignals(val);
    ui->s21->blockSignals(val);
    ui->s22->blockSignals(val);
    ui->s23->blockSignals(val);
    ui->s24->blockSignals(val);
    ui->s31->blockSignals(val);
    ui->s32->blockSignals(val);
    ui->s33->blockSignals(val);
    ui->s34->blockSignals(val);

    ui->sb11->blockSignals(val);
    ui->sb12->blockSignals(val);
    ui->sb13->blockSignals(val);
    ui->sb14->blockSignals(val);
    ui->sb21->blockSignals(val);
    ui->sb22->blockSignals(val);
    ui->sb23->blockSignals(val);
    ui->sb24->blockSignals(val);
    ui->sb31->blockSignals(val);
    ui->sb32->blockSignals(val);
    ui->sb33->blockSignals(val);
    ui->sb34->blockSignals(val);
}

void MainWindow:: mousePressEvent(QMouseEvent *event)
{
    QPoint cpos = event->pos();
    QPixmap pixmap = ui->pal->grab();
    QColor color;
    if (cpos.x() >= ui->pal->pos().x() && cpos.x() <=ui->pal->pos().x()+ pixmap.width() && cpos.y() >=ui->pal->pos().y() && cpos.y() <=ui->pal->pos().x()+ pixmap.height())
    {
        color = pixmap.toImage().pixelColor(cpos);

        if (color.isValid())
        {
            mainColor = color;
            RGB *rgb = new RGB(mainColor.red(), mainColor.green(), mainColor.blue());

            QString fir = ui->l1->text();
            if (fir == "RGB")
            {
                first = rgb->toRGB();
            }
            else if (fir == "CMYK")
            {
                first = rgb->toCMYK();
            }
            else if (fir == "HSV")
            {
                first = rgb->toHSV();
            }
            else if (fir == "HSL")
            {
                first = rgb->toHLS();
            }
            else if (fir == "XYZ")
            {
                first = rgb->toXYZ();
            }
            else
            {
                first = rgb->toLAB();
            }

            QString sec = ui->l2->text();
            if (sec == "RGB")
            {
                second = rgb->toRGB();
            }
            else if (sec == "CMYK")
            {
                second = rgb->toCMYK();
            }
            else if (sec == "HSV")
            {
                second = rgb->toHSV();
            }
            else if (sec == "HSL")
            {
                second = rgb->toHLS();
            }
            else if (sec == "XYZ")
            {
                second = rgb->toXYZ();
            }
            else
            {
                second = rgb->toLAB();
            }

            QString thi = ui->l3->text();
            if (thi == "RGB")
            {
                third = rgb->toRGB();
            }
            else if (thi == "CMYK")
            {
                third = rgb->toCMYK();
            }
            else if (thi == "HSV")
            {
                third = rgb->toHSV();
            }
            else if (thi == "HSL")
            {
                third = rgb->toHLS();
            }
            else if (thi == "XYZ")
            {
                third = rgb->toXYZ();
            }
            else
            {
                third = rgb->toLAB();
            }

            updateColor();
        }
    }

    update();
}


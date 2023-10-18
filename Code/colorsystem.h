
#ifndef COLORSYSTEM_H
#define COLORSYSTEM_H




#include <cmath>
#include "QColor"

class ColorSystem
{
public:
    virtual double getComponent1() = 0;
    virtual double getComponent2() = 0;
    virtual double getComponent3() = 0;
    virtual double getComponent4() = 0;

    virtual void setComponent1(double val) = 0;
    virtual void setComponent2(double val) = 0;
    virtual void setComponent3(double val) = 0;
    virtual void setComponent4(double val) = 0;

    virtual ColorSystem *toRGB() = 0;
    virtual ColorSystem *toCMYK() = 0;
    virtual ColorSystem *toHSV() = 0;
    virtual ColorSystem *toHLS() = 0;
    virtual ColorSystem *toXYZ() = 0;
    virtual ColorSystem *toLAB() = 0;
};

///////////////////////////////////////////////////////////////////////////////////

class RGB : public ColorSystem
{
private:
    int r;
    int g;
    int b;

    double fXyz(double x);
    double fDop(double x);

public:
    RGB(int R, int G, int B);

    double getComponent1() override;
    double getComponent2() override;
    double getComponent3() override;
    double getComponent4() override;

    void setComponent1(double val) override;
    void setComponent2(double val) override;
    void setComponent3(double val) override;
    void setComponent4(double val) override;

    ColorSystem *toRGB() override;
    ColorSystem *toCMYK() override;
    ColorSystem *toHSV() override;
    ColorSystem *toHLS() override;
    ColorSystem *toXYZ() override;
    ColorSystem *toLAB() override;
};

///////////////////////////////////////////////////////////////////////////////////

class CMYK : public ColorSystem
{
private:
    double c;
    double m;
    double y;
    double k;

public:
    CMYK(double C, double M, double Y, double K);

    double getComponent1() override;
    double getComponent2() override;
    double getComponent3() override;
    double getComponent4() override;

    void setComponent1(double val) override;
    void setComponent2(double val) override;
    void setComponent3(double val) override;
    void setComponent4(double val) override;

    ColorSystem *toRGB() override;
    ColorSystem *toCMYK() override;
    ColorSystem *toHSV() override;
    ColorSystem *toHLS() override;
    ColorSystem *toXYZ() override;
    ColorSystem *toLAB() override;
};

///////////////////////////////////////////////////////////////////////////////////

class HSV : public ColorSystem
{
private:
    double h;
    double s;
    double v;

public:
    HSV(double H, double S, double V);

    double getComponent1() override;
    double getComponent2() override;
    double getComponent3() override;
    double getComponent4() override;

    void setComponent1(double val) override;
    void setComponent2(double val) override;
    void setComponent3(double val) override;
    void setComponent4(double val) override;

    ColorSystem *toRGB() override;
    ColorSystem *toCMYK() override;
    ColorSystem *toHSV() override;
    ColorSystem *toHLS() override;
    ColorSystem *toXYZ() override;
    ColorSystem *toLAB() override;
};

///////////////////////////////////////////////////////////////////////////////////

class HSL : public ColorSystem
{
private:
    double h;
    double s;
    double l;

public:
    HSL(double H, double S, double L);

    double getComponent1() override;
    double getComponent2() override;
    double getComponent3() override;
    double getComponent4() override;

    void setComponent1(double val) override;
    void setComponent2(double val) override;
    void setComponent3(double val) override;
    void setComponent4(double val) override;

    ColorSystem *toRGB() override;
    ColorSystem *toCMYK() override;
    ColorSystem *toHSV() override;
    ColorSystem *toHLS() override;
    ColorSystem *toXYZ() override;
    ColorSystem *toLAB() override;
};

///////////////////////////////////////////////////////////////////////////////////

class XYZ : public ColorSystem
{
private:
    double x;
    double y;
    double z;

    double F(double x_);

public:
    XYZ(double X, double Y, double Z);

    double getComponent1() override;
    double getComponent2() override;
    double getComponent3() override;
    double getComponent4() override;

    void setComponent1(double val) override;
    void setComponent2(double val) override;
    void setComponent3(double val) override;
    void setComponent4(double val) override;

    ColorSystem *toRGB() override;
    ColorSystem *toCMYK() override;
    ColorSystem *toHSV() override;
    ColorSystem *toHLS() override;
    ColorSystem *toXYZ() override;
    ColorSystem *toLAB() override;
};

///////////////////////////////////////////////////////////////////////////////////

class Lab : public ColorSystem
{
private:
    double L;
    double a;
    double b;

    double F(double x_);

public:
    Lab(double L_, double a_, double b_);

    double getComponent1() override;
    double getComponent2() override;
    double getComponent3() override;
    double getComponent4() override;

    void setComponent1(double val) override;
    void setComponent2(double val) override;
    void setComponent3(double val) override;
    void setComponent4(double val) override;

    ColorSystem *toRGB() override;
    ColorSystem *toCMYK() override;
    ColorSystem *toHSV() override;
    ColorSystem *toHLS() override;
    ColorSystem *toXYZ() override;
    ColorSystem *toLAB() override;
};
#endif // COLORSYSTEM_H

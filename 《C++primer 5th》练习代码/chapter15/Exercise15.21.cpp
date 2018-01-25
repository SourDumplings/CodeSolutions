/*
 @Date    : 2018-01-08 20:52:13
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p616
 */

class Figure
{
private:
    double xSize, ySize;
public:
    Figure(double, double);
};

class Figure_2D
{
public:
    Figure_2D(double, double);
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Figure_3D: public Figure
{
protected:
    double zSzie;
public:
    Figure_3D(double, double, double);
    virtual double cubage() = 0;
};

class Rectangle: public Figure_2D
{
public:
    Rectangle(double, double);
    virtual double area();
    virtual double perimeter();
};

class Circle: public Figure_2D
{
public:
    Circle(double, double);
    virtual double area();
    virtual double perimeter();
};

class Sphere: public Figure_3D
{
public:
    Sphere(double, double, double);
    virtual double cubage();
};

class Cone: public Figure_3D
{
public:
    Cone(double, double, double);
    virtual double cubage();
};

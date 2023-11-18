#include"point.h"
#include<cmath>
point::point(double x, double y) :
        d_x{x}, d_y{y}
{
}

point::point():
        d_x{0.0}, d_y{0.0}
{
}


double point::x() const
{
    return d_x;
}

double point::y() const
{
    return d_y;
}


void point::moveOn(double x, double y)
{
    d_x=x;
    d_y=y;
}

void point::moveOff(double deltax,double deltay)
{
    d_x+=deltax;
    d_y+=deltay;
}

double point::distance(const point&p)const
{
    double dx{p.x()-d_x};
    double dy{p.d_y-d_y};
    return sqrt(dx*dx+dy*dy);
}

bool point::operator==(const point &p2) const
{
    return (x()==p2.x() && y()==p2.y());
}

bool point::operator!=(const point &p2) const
{
    return (x()!=p2.x() || y()!=p2.y());
}

point& point::operator+=(const point &p2)
{
    moveOff(p2.x(),p2.y());
    return *this;
}
point& point::operator-=(const point &p2)
{
    moveOff(-p2.x(),-p2.y());
    return *this;
}
point&  point::operator=(const point &p2)
{
    moveOn(p2.x(),p2.y());
    return *this;
}

std::ostream& operator<<(std::ostream&ost,const point &p)
{
    ost<<'['<<p.x()<<','<<p.y()<<']'<<std::endl;
}

std::istream & operator>>(std:: istream&ist,const point &p)
{
    char trash;
    int x,y;
    ist>>trash>>x>>trash>>y>>trash;
}
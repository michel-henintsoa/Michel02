#include "class.h"
/*****************************//*****************************/
Center::Center(int xCoord, int yCoord) : x(xCoord), y(yCoord){}
Center::~Center(){}
/*void Center::setX(int _x){
	x=_x;
}
void Center::setY(int _y){
	y=_y;
}*/
int Center::getX(){
	return x;
}
int Center::getY(){
	return y;
}


/*****************************//*****************************/

Circle::Circle(int centerX, int centerY, int r, std::string c) : point(centerX, centerY), radius(r), color(c){}
Circle::~Circle(){}
/*void Circle::setCenter(int _x, int _y){
	point.x=_x;
	point.y=_y;
}*/
Center Circle::getCenter(){
	return point;
}
void Circle::translate(int dx, int dy){
	point.x+=dx;
	point.y+=dy;
}
/*void Circle::setRadius(int _r){
	radius=_r;
}*/
int Circle::getRadius(){
	return radius;
}
std::string Circle::getColor(){
	return color;
}
bool Circle::isOverlapping(const Circle& other){
	int dsquard  =	(point.x-other.point.x)*(point.x-other.point.x)
					+(point.y-other.point.y)*(point.y-other.point.y);
	int radSum=radius+other.radius;
	return dsquard<radSum*radSum;
}
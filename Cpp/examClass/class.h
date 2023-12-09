#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

class Center{
public:
	int x;
	int y;
	Center(int xCoord, int yCoord);
	~Center();
	int getX();
	int getY();
};

class Circle{
private:
	int radius;
	Center point;
	std::string color;
public:
	Circle(int centerX, int centerY, int r, std::string c);
	~Circle();
	//void setCenter(int _x, int _y);
	Center getCenter();
	//void setRadius(int _r);
	int getRadius();
	std::string getColor();
	void translate(int dx, int dy);
	bool isOverlapping(const Circle& other);
};

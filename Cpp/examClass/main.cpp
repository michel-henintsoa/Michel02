#include "class.h"

int main(){
	std::srand(std::time(0));
	int circleNum = std::rand()%6 + 2;
	std::vector<std::string> colors={"violet","blue","jaune","vert","cyan","rouge", "blanc"};

	std::vector<Circle> circles;
	for(int i=0; i<circleNum; i++){
		int x=std::rand()%10;
		int y=std::rand()%10;
		int radius=std::rand()%5+1;
		int c=std::rand()%7;
		circles.emplace_back(x, y, radius, colors[c]);
		std::cout<<"centre: ( "<<x<<","<<y<<" ) "<<"rayon: "<<radius<<", color: "<<colors[c]<<std::endl;
	}
	std::cout<<"\n\n\n";
	int k=0;
	while(k<circleNum){
		for(int i=0; i<circleNum; ++i){
			for(int j=i+1; j<circleNum; ++j){
	            if (circles[i].isOverlapping(circles[j])) {
	            	Center tmp1=circles[i].getCenter(), tmp2=circles[j].getCenter();
					int dx=tmp2.x-tmp1.x;
					int dy=tmp2.y-tmp1.y;
					circles[j].translate(dx, dy);
				}
			}
		}
		k++;
	}
	for (auto& circle : circles) {
        Center point = circle.getCenter();
        std::cout << "Cercle: Centre(" << point.x << ", " << point.y << "), Rayon: " << circle.getRadius() << ", couleur: "<<circle.getColor()<<"\n";
    }
    /*
	std::cout<<"\n\n\n";
	for(int i=0; i<circleNum; ++i){
			for(int j=i+1; j<circleNum; ++j){
	            if (circles[i].isOverlapping(circles[j])) {
	            	Center tmp1=circles[i].getCenter(), tmp2=circles[j].getCenter();
					int dx=tmp2.x-tmp1.x;
					int dy=tmp2.y-tmp1.y;
					circles[j].translate(dx, dy);
				}
			}
		}
	for (auto& circle : circles) {
        Center point = circle.getCenter();
        std::cout << "Cercle: Centre(" << point.x << ", " << point.y << "), Rayon: " << circle.getRadius() << ", couleur: "<<circle.getColor()<<"\n";
    }*/
	return 0;
}
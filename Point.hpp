#include <iostream>

class Point{
	public:
		double x;
		double y;
	
		Point(){}
		
		Point(double x, double y){
			this->x = x;
			this->y = y;
		}
		
		void show(){
			std:: cout << "x = " << x << ", y = " << y << std:: endl; 
		}
		
		void setCoordinates (double x, double y){
			this->x = x;
			this->y = y;
		}
		void swap(Point& p){
			Point temp(p.x, p.y);
			p.setCoordinates(this->x, this->y);
			this->setCoordinates(temp.x, temp.y);
		}
};

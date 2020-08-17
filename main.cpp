#include <iostream>
#include <Windows.h>
#include <memory>
#include <typeinfo>
#include <cstdlib>
#include "circle.hpp"
#include "ellipse.hpp"
#include "parabola.hpp"

using std::cin;
using std::cout;
using std::endl;

namespace Menu {
	#define START_MENU_TEXT \
	"Choose an action:\n"\
	"0. Get info about curves\n"\
	"1. Calculate coordinates for a given parameter\n"\
	"2. Calculation of the tangent to a curve for a given parameter\n"\
	"3. Is the curve closed?\n"\
	"4. Exit\n"
	
	void exit() {
		::exit(0);
	}
	
	void pause() {
		system("pause");
	}
	
	void clearScreen() {
		system("cls");
	}
	
	void printMenu() {
		clearScreen();
		cout << START_MENU_TEXT << endl;
	}
}

template <class T, class... Args>
std::shared_ptr<T> saveMakeCurve(Args... args) {
	try {
		std::shared_ptr<T> ptr = std::make_shared<T>(args...);
		return ptr;
	}
	catch(...) {
		//cout << "Can't make " << typeid(T).name() << endl;
		return std::shared_ptr<T>();
	}
}


int main(int argc, char** argv) {
	double x1, y1, x2, y2, x3, y3;
	cout << "Enter three points (x1, y1, x2, y2, x3, y3):\n";
 	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
 	cin.clear();
	Point p1(x1, y1); 
	Point p2(x2, y2); 
	Point p3(x3, y3);
	std::shared_ptr<myEllipse> ellipsePtr = saveMakeCurve<myEllipse>(p1, p2, p3);
	std::shared_ptr<Circle> circlePtr = saveMakeCurve<Circle>(p1, p2, p3);
 	std::shared_ptr<Parabola> parabolaPtr1 = saveMakeCurve<Parabola>(p1, p2, p3, true);
	std::shared_ptr<Parabola> parabolaPtr2 = saveMakeCurve<Parabola>(p1, p2, p3, false);
	std::vector<std::shared_ptr<Curve>> objects;
	if (ellipsePtr.get() != nullptr) {
		objects.push_back(ellipsePtr);
	}
	if (circlePtr.get() != nullptr) {
		objects.push_back(circlePtr);
	}
	if (parabolaPtr1.get() != nullptr) {
		objects.push_back(parabolaPtr1);
	}
	if (parabolaPtr2.get() != nullptr) {
		objects.push_back(parabolaPtr2);
	}
	Menu::pause();
	if (!objects.empty()) {
		while (true) {
			Menu::printMenu();
			int choice = -1;
			cin >> choice;
			cin.clear();
			switch (choice) {
				case 0: {
					cout << "Points:\n";
					p1.show();
					p2.show();
					p3.show();
					cout << endl;
					for (int i = 0; i < objects.size(); i++) {
						objects[i]->showInfo();
					}
					break;
				}
				case 1: {
					double t = 0;
					cout << "Enter parameter\n";
					cin >> t;
					cin.clear();
					for (int i = 0; i < objects.size(); i++) {
						std::cout << "Coordinates of " << typeid(*objects[i]).name() 
							<< " for parameter = " << t << " is (" << objects[i]->getX(t) << "; " << objects[i]->getY(t) << ")" << endl; 
					}
					break;
				}
				case 2: {
					double t = 0;
					cout << "Enter parameter\n";
					cin >> t;
					cin.clear();
					for (int i = 0; i < objects.size(); i++) {
						std::vector<Point> tangent = objects[i]->tangentVector(t);
						cout << "Tangent of " << typeid(*objects[i]).name() 
							<< " for parameter = " << t << " is (" 
							<< "(" << tangent[0].x << "; " << tangent[0].y << "), "
							<< "(" << tangent[1].x << "; " << tangent[1].y << "))" << endl; 
					}
					break;
				}
				case 3: {
					for (int i = 0; i < objects.size(); i++) {
						cout << "Curve " << typeid(*objects[i]).name() << (objects[i]->isClosed() ? " is closed" : " isn't closed") << endl;
					}
					break;
				}
				case 4: {
					Menu::exit();
					break;
				}
				default: {
					cout << "Incorrect choice\n";
					break;
				}
			}
			Menu::pause();
		}
	}
}


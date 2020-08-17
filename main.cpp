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
	myEllipse c(p1, p2, p3);
 //	Circle (p1,p2,p3);
 	//myEllipse ellipse1(p1,p2,p3);
 //	Parabola parabola(p1,p2,p3, false);
 	//std::cout << "x0 = " << ellipse1.getX0() << ", y0 = " << ellipse1.getY0() << ", R = " << ellipse1.getR() << std::endl;
       /*Â çàâèñèìîñòè îò çíà÷åíèé ó dx,dy ýëëèïñ áóäåò ìåíÿòü ôîðìó, ïîýêñïåðåìåíòèðóéòå*/
    //int R = 1; //Ðàäèóñ îïðåäåëÿåò ðàçìåð
    //int dx1=0, dy1=0, dx2=4, dy2=4;  //Åñëè dx2 == dy2, òî êðóã, èíà÷å ýëëèïñ
    //int X = ellipse1.getX0(), Y = ellipse1.getY0(); //Íà÷àëüíûå êîîðäèíàòû
  /*  Ellipse(dc, X+dx1, Y+dy1, X+dx2+R, Y+dy2+R);
    brush = CreateSolidBrush(RGB(255,0,0));
    for(double i = 0; i < 10; i+=0.1){
        X = (int)ellipse1.getX(i);
        Y = (int)ellipse1.getY(i);
        SelectObject(dc,brush);
	    Ellipse(dc, X+dx1, Y+dy1, X+dx2+R, Y+dy2+R);
	}
	X = p1.x;
    Y = p1.y;
         	 
    brush = CreateSolidBrush(RGB(0,0,255));
    SelectObject(dc,brush);
    Ellipse(dc, X+dx1, Y+dy1, X+dx2+R, Y+dy2+R);
    X = p2.x;
    Y = p2.y;
    Ellipse(dc, X+dx1, Y+dy1, X+dx2+R, Y+dy2+R);
    X = p3.x;
    Y = p3.y;
    Ellipse(dc, X+dx1, Y+dy1, X+dx2+R, Y+dy2+R);
    X = ellipse1.getX0();
	Y = ellipse1.getY0();
	brush = CreateSolidBrush(RGB(255,255,255));
    SelectObject(dc,brush);
	Ellipse(dc, X+dx1, Y+dy1, X+dx2+R, Y+dy2+R);
		 
    DeleteObject(brush);
	ReleaseDC(hwnd, dc); //Îñâîáîæäàåì îáùèé èëè îêîííûé (íå âëèÿþùèé íà êëàññ èëè ëîêàëüíîñòü) êîíòåêñò óñòpîéñòâà, äåëàÿ åãî äîñòóïíûì äëÿ äpóãèõ ïpèêëàäíûõ çàäà÷.
 
 
	std::cin.get();*/
	
}


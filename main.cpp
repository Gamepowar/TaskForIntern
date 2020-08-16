#include <iostream>
#include <Windows.h>
//#include "ellipse.hpp"
#include "circle.hpp"
#include "parabola.hpp"
int main(int argc, char** argv) {/*
	Ellipse ellipse(Point(12, 4), Point(6, 3), Point(-3, 1));
	return 0;*/
	
	
/*	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	RECT window = {}; //Переменная window будет использована для получения ширины и высоты окна
	HBRUSH brush; //Переменная brush - это кисть, она будет использоваться для закрашивания
 	*/
 	Point p1(250, 250); 
	Point p2(300, 250); 
	Point p3(270, 300);
 //	Circle circle(p1,p2,p3);
 	Parabola parabola(p1,p2,p3);
 	std::cout << "x0 = " << parabola.getX0() << ", y0 = " << parabola.getY0() << ", p = " << parabola.getP() << std::endl;
       /*В зависимости от значений у dx,dy эллипс будет менять форму, поэксперементируйте*/
    int R = 1; //Радиус определяет размер
    int dx1=0, dy1=0, dx2=4, dy2=4;  //Если dx2 == dy2, то круг, иначе эллипс
    int X = parabola.getX0(), Y = parabola.getY0(); //Начальные координаты
  /*  Ellipse(dc, X+dx1, Y+dy1, X+dx2+R, Y+dy2+R);
    brush = CreateSolidBrush(RGB(255,0,0));
    for(double i = 0; i < 100; i+=0.1){
        X = (int)parabola.getX(i);
        Y = (int)parabola.getY(i);
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
		 
    DeleteObject(brush);
	ReleaseDC(hwnd, dc); //Освобождаем общий или оконный (не влияющий на класс или локальность) контекст устpойства, делая его доступным для дpугих пpикладных задач.
 
 
	std::cin.get();
	std::cin.get();*/
}


#include <iostream>
#include <Windows.h>
//#include "ellipse.hpp"
#include "circle.hpp"
#include "parabola.hpp"
int main(int argc, char** argv) {/*
	Ellipse ellipse(Point(12, 4), Point(6, 3), Point(-3, 1));
	return 0;*/
	
	
	HWND hwnd = GetConsoleWindow(); //���� �������� �� ���������� ���� (� ��� ����� ��������)
	HDC dc = GetDC(hwnd); //��������� � ����������� ����
	RECT window = {}; //���������� window ����� ������������ ��� ��������� ������ � ������ ����
	HBRUSH brush; //���������� brush - ��� �����, ��� ����� �������������� ��� ������������
 	
 	Point p1(250, 250); 
	Point p2(300, 300); 
	Point p3(250, 300);
 	Circle circle(p1,p2,p3);
 //	Parabola parabola(p1,p2,p3, false);
 	std::cout << "x0 = " << circle.getX0() << ", y0 = " << circle.getY0() << ", R = " << circle.getR() << std::endl;
       /*� ����������� �� �������� � dx,dy ������ ����� ������ �����, �������������������*/
    int R = 1; //������ ���������� ������
    int dx1=0, dy1=0, dx2=4, dy2=4;  //���� dx2 == dy2, �� ����, ����� ������
    int X = circle.getX0(), Y = circle.getY0(); //��������� ����������
    Ellipse(dc, X+dx1, Y+dy1, X+dx2+R, Y+dy2+R);
    brush = CreateSolidBrush(RGB(255,0,0));
    for(double i = 0; i < 10; i+=0.1){
        X = (int)circle.getX(i);
        Y = (int)circle.getY(i);
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
    X = circle.getX0();
	Y = circle.getY0();
	brush = CreateSolidBrush(RGB(255,255,255));
    SelectObject(dc,brush);
	Ellipse(dc, X+dx1, Y+dy1, X+dx2+R, Y+dy2+R);
		 
    DeleteObject(brush);
	ReleaseDC(hwnd, dc); //����������� ����� ��� ������� (�� �������� �� ����� ��� �����������) �������� ���p������, ����� ��� ��������� ��� �p���� �p�������� �����.
 
 
	std::cin.get();
	
}


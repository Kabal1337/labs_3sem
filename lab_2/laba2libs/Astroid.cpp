// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "Astroid.h"
#include <iostream>
#include <cmath>
#define M_PI 3.14

Astroid::Astroid() {

	this->r = 1;
	this->x0 = (pow(r, 0.67));

}
float Astroid::get_x0() const {
	return(this->x0);
}
Astroid::Astroid(float r) {
	if (r < 0) {
		throw "invalid rad";
	}
	this->r = r;
	this->x0 = (pow(r, 0.67));

}

float Astroid::get_r() const
{
	return this->r;
}

float Astroid::get_length_0_t(float t) const {
	if (t<0 || t > M_PI / 2)
	{
		throw "invalid angle";
		std::cout << std::endl;
	}
	//float a = r * sqrt(pow(cos(t), 6) + pow(sin(t), 6)); // a-радиус вектор в пол€рных координатах;
	//float x0 = this->x0;
	//float x = sin(t) * a;
	//int y = cos(t) * a;
	//1+pow((sqrt(pow(r, 2/3)-pow(x0, 2/3)))/pow(x, 1/3), 2)
	float length = 1.5 * r * pow(sin(t), 2);
	return(length);

}

float Astroid::get_radius(float t) const {
	if (t<0 || t > M_PI / 2)
	{
		throw "invalid angle";
		std::cout << std::endl;
	}
	return(1.5 * r * sin(2 * t));

}

float Astroid::get_s() const {
	float m = pow(r, 2);
	float s = 0.375 * M_PI * m;
	return(s);
}

float Astroid::get_x_from_t(float t) const {
	if (t<0 || t > M_PI / 2)
	{
		throw "invalid x";
		std::cout << std::endl;
	}
	float x = r * pow(cos(t), 3);
	return x;
}

float Astroid::get_y_from_t(float t) const {

	if (t<0 || t > M_PI / 2)
	{
		throw "invalid t";
		std::cout << std::endl;
	}
	float y = r * pow(sin(t), 3);
	return y;
}
float  Astroid::get_y_from_x(float x) const {

	if (x > x0 || x < -x0)
	{
		throw "Invalid x";

	}



	float temp = pow(r, 0.67) - pow(abs(x), 0.67);
	float y = pow(abs(temp), 1.5);
	return(y);
}
float Astroid::get_all_length() const {
	return(6 * r);
}

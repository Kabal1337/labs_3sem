
#include "Astroid.h"
#include <iostream>
#include <cmath>
#define M_PI 3.14

Astroid::Astroid() {

	this->r = 1;
	this->x0 = (pow(r, 0.67));

}

Astroid::Astroid(float r) {

	this->r = r;
	this->x0 = (pow(r, 0.67));

}

const float Astroid::get_r()
{
	return this->r;
}

const float Astroid::get_length_0_t(float t) {

	//float a = r * sqrt(pow(cos(t), 6) + pow(sin(t), 6)); // a-радиус вектор в пол€рных координатах;
	//float x0 = this->x0;
	//float x = sin(t) * a;
	//int y = cos(t) * a;
	//1+pow((sqrt(pow(r, 2/3)-pow(x0, 2/3)))/pow(x, 1/3), 2)
	float length = 1.5 * r * pow(sin(t), 2);
	return(length);

}

const float Astroid::get_radius(float t) {
	return(1.5 * r * sin(2*t));

}

float Astroid::get_s() {
	float m= pow(r, 2);
	float s = 0.375 * M_PI *m;
	return(s);
}

const float Astroid::get_x_from_t(float t){
	float x = r * pow(cos(t), 3);
	return x;
}

const float Astroid::get_y_from_t(float t) {
	float y = r * pow(sin(t), 3);
	return y;
} 
const float  Astroid::get_y_from_x(){

	float x;
	std::cin >> x;

	while (!std::cin.good() || x>x0 || x<-x0)
	{
		std::cout << std::endl << "Invalid input, try again" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> x;
	}

	

	float temp = pow(r, 0.67) - pow(x, 0.67);
	float y = pow(abs(temp), 1.5);
	return(y);
}


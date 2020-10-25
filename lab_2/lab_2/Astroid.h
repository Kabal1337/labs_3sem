#pragma once

class Astroid
{
public:
	
	Astroid();
	Astroid(float r);

	const float get_r();
	const float get_length_0_t(float t);
	const float get_radius(float t);
	float get_s();
	const float get_x_from_t(float t);
	const float get_y_from_t(float t);
	const float get_y_from_x();

private:
	float r; // r - радиус 
	float x0;
};


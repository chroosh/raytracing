#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
	public:
		// constructors
		vec3() : e{0, 0, 0} {}
		vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
		
		// operators
		const vec3 operator-();
		const double operator[](int i) const;
		double& operator[](int i);

		vec3& operator+=(const vec3 &v);
		vec3& operator*=(const double t);
		vec3& operator/=(const double t);
	
		// methods
		double x() const { return e[0]; }
		double y() const { return e[1]; }
		double z() const { return e[2]; }

		const double length();
		const double length_squared();

		friend vec3 operator+(const vec3 &u, const vec3 &v);
		friend vec3 operator-(const vec3 &u, const vec3 &v);
		friend vec3 operator*(const vec3 &u, const vec3 &v);
		friend vec3 operator*(double t, const vec3 &v);
		friend vec3 operator*(const vec3 &v, double t);
		friend vec3 operator/(const vec3 &v, double t);
		friend std::ostream& operator<<(std::ostream &out, const vec3 &v);
	
		double dot(const vec3 &u, const vec3 &v);
		vec3 cross(const vec3 &u, const vec3 &v);
		vec3 unit_vector(vec3 v);
	public:
		// vec3 is implemented as an array with 3 elements
		double e[3];
};


// 3 dimensional vector can be used to represent a vector, a point in a 3d field and also an rgb color
using point3 = vec3;
using color = vec3;

#endif

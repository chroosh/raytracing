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
		vec3 operator-() const {
			return vec3(-e[0], -e[1], -e[2]);
		}
		const double operator[](int i) const {
			return e[i];
		}
		double& operator[](int i) {
			return e[i];
		}

		vec3& operator+=(const vec3 &v) {
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];
			return *this;
		}
		vec3& operator*=(const double t) {
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;
			return *this;	
		}
		vec3& operator/=(const double t) {
			return *this *= 1/t;
		}
	
		// methods
		double x() const { return e[0]; }
		double y() const { return e[1]; }
		double z() const { return e[2]; }

		const double length() {
			return std::sqrt(length_squared());
		}
		const double length_squared() {
			return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
		}

		friend vec3 operator+(const vec3 &u, const vec3 &v) {
			return vec3(u.e[0]+v.e[0], u.e[1]+v.e[1], u.e[2]+v.e[2]);
		}
		friend vec3 operator-(const vec3 &u, const vec3 &v) {
			return vec3(u.e[0]-v.e[0], u.e[1]-v.e[1], u.e[2]-v.e[2]);
		}
		friend vec3 operator*(const vec3 &u, const vec3 &v) {
			return vec3(u.e[0]*v.e[0], u.e[1]*v.e[1], u.e[2]*v.e[2]);
		}
		friend vec3 operator*(double t, const vec3 &v) {
			return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
		}
		friend vec3 operator*(const vec3 &v, double t) {
			return t*v;
		}
		friend vec3 operator/(const vec3 &v, double t) {
			return (1/t) * v;
		}
		friend std::ostream& operator<<(std::ostream &out, const vec3 &v) {
			return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
		}

		inline static vec3 random() {
			return vec3(random_double(), random_double(), random_double());
		}
		inline static vec3 random(double min, double max) {
			return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
		}
		
	public:
		// vec3 is implemented as an array with 3 elements
		double e[3];
};

// 3 dimensional vector can be used to represent a vector, a point in a 3d field and also an rgb color
using point3 = vec3;
using color = vec3;

double dot(const vec3 &u, const vec3 &v) {
	return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

vec3 cross(const vec3 &u, const vec3 &v) {
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
				u.e[2] * v.e[0] - u.e[0] * v.e[2],
				u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

vec3 unit_vector(vec3 v) {
	return v / v.length();
}
vec3 random_in_unit_sphere() {
	while (true) {
		auto p = vec3::random(-1, 1);
		if (p.length_squared() >= 1) continue;
		return p;
	}
}

#endif

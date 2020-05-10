#ifndef CAMERA_H
#define CAMERA_H

#include "common.h"

class camera {
	public:
		camera() {
			origin = point3(0.0, 0.0, 0.0);
			horizontal = vec3(4.0, 0.0, 0.0);
			vertical = vec3(0.0, 2.25, 0.0);
			lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, 1);
		}

		ray get_ray(double u, double v) {
			return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
		}

	public:
		point3 origin;
		point3 lower_left_corner;
		vec3 horizontal;
		vec3 vertical;
};

#endif

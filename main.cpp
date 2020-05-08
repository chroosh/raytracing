#include "color.h"
#include "ray.h"

#include <iostream>


// linear interpolation of ray colors in a unidirectional gradient
color ray_color(const ray& r) {
	vec3 unit_direction = unit_vector(r.direction());
	auto t = 0.5*(unit_direction.y() + 1.0);
	return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {
	const int image_width = 256;
	const int image_height = 256;


	// making a ppm image file
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	point3 origin(0.0, 0.0, 0.0);
	vec3 horizontal(4.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.25, 0.0);
	point3 lower_left_corner = origin - horizontal/2 -vertical/2 - vec3(0, 0, 1);

	for (int j = image_height-1; j >= 0; --j) {
		// wtf does std::flush do?
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i) {

			auto u = double(i) / (image_width-1);
			auto v = double(j) / (image_height-1);
			ray r(origin, lower_left_corner + u*horizontal + v*vertical);
			color pixel_color = ray_color(r);

			write_color(std::cout, pixel_color);
		}
	}
}

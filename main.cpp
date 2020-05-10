#include "common.h"

#include "hittable_list.h"
#include "sphere.h"
#include "color.h"

#include <iostream>

// determine "color" of a ray
color ray_color(const ray& r, const hittable& world) {
	hit_record rec;
	if (world.hit(r, 0, infinity, rec)) {
		return 0.5*(rec.normal + color(1, 1, 1));
	}

	// if doesn't hit, render background as a linear interpolation between blue and white
	vec3 unit_direction = unit_vector(r.direction());
	auto t = 0.5*(unit_direction.y() + 1.0);
	return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {

	// set dimensions
	const auto aspect_ratio = 16.0/9.0;
	const int image_width = 384;
	const int image_height = static_cast<int>(image_width / aspect_ratio);

	// making a ppm image file
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	// provide vec3 format of base points and vectors
	point3 origin(0.0, 0.0, 0.0);
	vec3 horizontal(4.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.25, 0.0);
	point3 lower_left_corner = origin - horizontal/2 -vertical/2 - vec3(0, 0, 1);

	hittable_list world;
	world.add(make_shared<sphere>(point3(0, 0, -1), 0.5)); // add a sphere
	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100)); // add another sphere as the "ground"

	for (int j = image_height-1; j >= 0; --j) {
		// wtf does std::flush do? - flushes standard output
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i) {

			auto u = double(i) / (image_width-1);
			auto v = double(j) / (image_height-1);
			ray r(origin, lower_left_corner + u*horizontal + v*vertical);
			color pixel_color = ray_color(r, world);

			write_color(std::cout, pixel_color);
		}
	}

	std::cerr << "\nDone\n";
}

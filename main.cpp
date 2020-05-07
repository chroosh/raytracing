#include "color.h"

#include <iostream>

int main() {
	const int image_width = 256;
	const int image_height = 256;


	// making a ppm image file
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height-1; j >= 0; --j) {
		// wtf does std::flush do?
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i) {
			// creates a color (vec3) object with the following dimensions
			// we can now do things with different c2olor objects - ie like add them together
			color pixel_color((double)(i)/(image_width-1), (double)(j)/(image_height-1), 0.25);
			write_color(std::cout, pixel_color);
		}
	}
}

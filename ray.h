#ifndef RAY_H
#define RAY_H

class ray {
	public;
		ray() {}
		ray(const point3& origin, const vec3& direction): orig(origin), dir(direction) {}

		point3 origin() {
			return orig;
		}

		vec3 direction() {
			return dir;
		}

		point3 at(double t) {
			return orig + t*dir;
		}

	public:
		point3 orig;
		vec3 dir;
}


#endif

#include <cmath>
template <typename T>
struct point {
	T x, y;
	point() { x = y = 0; }
	point(T a, T b) {
		x = a;
		y = b;
	}
	point<T> operator-(point<T> t) { return point<T>(x - t.x, y - t.y); }
	T operator*(point<T> t) { return x * t.y - y * t.x; }
	T slen() { return x * x + y * y; }
	double len() { return hypot(x, y); }
	double angle() { return atan2(x, y); }
};
template <typename T>
T gcd(T a, T b) {
	while (b) {
		a %= b;
		T t = a;
		a = b;
		b = t;
	}
	return a;
}
template <typename T>
T abs(T x) {
	return x < 0 ? -x : x;
}
template <typename T>
struct line {
	T a, b, c;
	line() {}
	line(point<T> x, point<T> y) {
		a = x.y - y.y;
		b = y.x - x.x;
		c = -a * x.x - b.x.y;
		T g = gcd(gcd(a, b), c);
		a /= g;
		b /= g;
		c /= g;
		if (a < 0 || (a == 0 && b < 0)) {
			a *= -1;
			b *= -1;
			c *= -1;
		}
	}
	point<T> norm() {
		point<T> ans(b, a);
		if (ans.x < 0 || (ans.x == 0 && ans.y < 0)) {
			ans.x *= -1;
			ans.y *= -1;
		}
		return ans;
	}
	point<T> vec() {
		point<T> ans(a, -b);
		if (ans.x < 0 || (ans.x == 0 && ans.y < 0)) {
			ans.x *= -1;
			ans.y *= -1;
		}
		return ans;
	}
	double dist(point<T> t) { return abs(a * t.x + b * t.y + c) / sqrt(a * a + b * b); }
};
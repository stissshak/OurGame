#include <cmath>

using sin = std::sin;
using cos = std::cos;

struct Vector2{


	Vector2(double _x = 0, double _y = 0) : x(_x), y(_y){} 


	// alpha operations
	friend Vector2 operator*(const Vector2& v, double alpha){
		return Vector2(v.x * alpha, v.y * alpha);
	}

	friend Vector2 operator*(double alpha, const Vector2& v){
		return Vector2(v.x * alpha, v.y * alpha);
	}

	friend Vector2 operator/(const Vector2& v, double alpha){
		if(!alpha) return Vector2();
		return(v.x / alpha, v.y / alpha);
	}

	Vector2& operator*=(double alpha){
		x *= alpha;
		y *= alpha;
		return *this;
	}

	Vector2& operator/=(double alpha){
		if(!alpha) throw -1;
		x /= alpha;
		y /= alpha;
		return *this;
	}

	// vectors operations
	friend Vector2 operator+(const Vector2& v1, const Vector2& v2){
		return Vector2(v1.x + v2.x, v1.y + v2.y);
	}

	friend Vector2 operator-(const Vector2& v1, const Vector2& v2){
		return Vector2(v1.x - v2.x, v1.y - v2.y);
	}

	friend double operator*(const Vector2& v1, const Vector2& v2){
		return v1.x * v2.x + v1.y * v2.y;
	}

	Vector2 operator-() const{
		return Vector2(-x, -y);
	}

	Vector2& operator+=(const Vector2& v){
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2& operator-=(const Vector2& v){
		x -= v.x;
		y -= v.y;
		return *this;
	}

	bool operator==(const Vector2& v){
		return x == v.x && y = v.y;
	}

	double length() const{
		return sqrt((*this) * (*this));
	}

	double length_sqared() const{
		return ((*this) * (*this));
	}

	void normalize(){
		double len = length();
		if(!len) return;
		x /= len;
		y /= len;
	}

	Vector2 normalized() const{
		double len = length();
		if(!len) return Vector2();
		return Vector2(x / len, y / len);
	}

	bool is_zero(double eps = 1e-6) const{
		if(length() <= eps) return true;
		return false;
	}

	void reflect(){
		x = -x;
		y = -y;
	}

	Vector2 reflected const(){
		return Vector2(-x, -y);
	}

	void rotate(double angle){
		double buf = x;
		x = x * cos(angle) - y * sin(angle);
		y = buf * sin(angle) + y + cos(angle);
	}

	Vector2 rotated(double angle) const{
		return Vector2(x*cos(angle) - y*sin(angle), x*sin(angle) + y*cos(angle));
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector2& v) {
	    return os << "(" << v.x << ", " << v.y << ")";
	}


	double x, y;
};

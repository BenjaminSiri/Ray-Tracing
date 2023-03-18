// Updated: Chapter 4
#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
    public:
        double e[3];
        vec3() {
            e[0] = 0;
            e[1] = 0;
            e[2] = 0;
        }
        vec3(double e0, double e1, double e2) {
            e[0] = e0;
            e[1] = e1;
            e[2] = e2;
        }

        inline double x() const {return e[0];}
        inline double y() const {return e[1];}
        inline double z() const {return e[2];}

        inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        inline double operator[](int i) const { return e[i]; } 
        inline double& operator[](int i) { return e[i]; }

        inline vec3& operator+=(const vec3 &v2);
        inline vec3& operator-=(const vec3 &v2);
        inline vec3& operator*=(const vec3 &v2);
        inline vec3& operator/=(const vec3 &v2);
        inline vec3& operator*=(double t);
        inline vec3& operator/=(double t);

        inline double length() const {
            return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
        }

        inline double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        inline static vec3 random() {
            return vec3(random_double(), random_double(), random_double());
        }

        inline static vec3 random(double min, double max) {
            return vec3(random_double(min,max), random_double(min,max), random_double(min,max));
        }

        inline void make_unit_vector();
};

vec3 random_in_unit_sphere() {
            while (true) {
                auto p = vec3::random(-1,1);
                if(p.length_squared() >= 1) continue;
                return p;
            }
        }

inline std::istream& operator>>(std::istream &is, vec3 &v){
    is >> v.e[0] >> v.e[1] >> v.e[2];
    return is;
}

inline std::ostream& operator<<(std::ostream &os, vec3 &v){
    os << v.e[0] << " " << v.e[1] << " " << v.e[2];
    return os;
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline vec3 operator*(float t, const vec3 &v) {
  return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}
inline vec3 operator*(const vec3 &v, float t) {
  return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}

inline vec3 operator/(const vec3 &v, float t) {
  return vec3(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}

inline float dot(const vec3 &v1, const vec3 &v2) {
  return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
  return vec3(
          v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
          -(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0]),
          v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]
  );
}

inline vec3& vec3::operator+=(const vec3 &v) {
  e[0] += v.e[0];
  e[1] += v.e[1];
  e[2] += v.e[2];
  return *this;
}

inline vec3& vec3::operator-=(const vec3 &v) {
  e[0] -= v.e[0];
  e[1] -= v.e[1];
  e[2] -= v.e[2];
  return *this;
}

inline vec3& vec3::operator*=(const vec3 &v) {
  e[0] *= v.e[0];
  e[1] *= v.e[1];
  e[2] *= v.e[2];
  return *this;
}

inline vec3& vec3::operator/=(const vec3 &v) {
  e[0] /= v.e[0];
  e[1] /= v.e[1];
  e[2] /= v.e[2];
  return *this;
}

inline vec3& vec3::operator*=(double t) {
  e[0] *= t;
  e[1] *= t;
  e[2] *= t;
  return *this;
}

inline vec3& vec3::operator/=(double t) {
  float k = 1.0/t;
  e[0] *= k;
  e[1] *= k;
  e[2] *= k;
  return *this;
}

inline vec3 unit_vector(const vec3 &v) {
  return v / v.length();
}

// Type aliases for vec3
using point3 = vec3;
using color = vec3;

#endif
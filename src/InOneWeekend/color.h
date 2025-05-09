#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "point3.h"

class Color : public Point3 {
 public:
  Color(Point3 p);
  Color(double r, double g, double b);
  Color(const Color& p);

  double r() const { return x(); }
  double g() const { return y(); }
  double b() const { return z(); }

  void write_color(std::ostream& out);

  Color operator+(const Color& rhs);
  Color& operator+=(const Color& rhs);

  Color operator*(double t);
  Color& operator*=(double t);
  friend Color operator*(double t, const Color& lhs);

  Color operator/(double t);
  Color& operator/=(double t);

  bool operator==(const Color& lhs) const;

 private:
  double linear_to_gamma(double linear_component);
};

inline Color operator*(double t, const Color& lhs) {
  return lhs * t;
}

#endif
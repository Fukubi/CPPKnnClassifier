#ifndef LINEAR_ALGEBRA_HPP
#define LINEAR_ALGEBRA_HPP

#include <vector>

typedef std::vector<float> vector;
typedef std::vector<vector> matrix;

class LinearAlgebraOperators {
 public:
  static float getDistance(vector v, vector w);
};

#endif
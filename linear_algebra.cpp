#include "linear_algebra.hpp"

#include <cmath>

float LinearAlgebraOperators::getDistance(vector v, vector w) {
    float result = 0;

    for (size_t i = 0; i < v.size(); i++) {
        result = pow((v[i] + w[i]), 2);
    }

    result = sqrt(result);

    return result;
}
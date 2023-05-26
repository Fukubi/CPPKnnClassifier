#ifndef KNN_HPP
#define KNN_HPP

#include <string>
#include <vector>

#include "linear_algebra.hpp"

class KnnClassifier {
 private:
 public:
  KnnClassifier();
  std::string classify(int k, std::vector<std::tuple<vector, std::string>> data,
                       vector point);
};

#endif
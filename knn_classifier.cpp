#include "knn_classifier.hpp"

#include <bits/stdc++.h>

KnnClassifier::KnnClassifier() {}

std::string KnnClassifier::classify(
    int k, std::vector<std::tuple<vector, std::string>> data, vector point) {
  std::map<std::string, int> counter;

  std::sort(
      data.begin(), data.end(),
      [=](std::tuple<vector, std::string> v1,
          std::tuple<vector, std::string> v2) {
        return (LinearAlgebraOperators::getDistance(std::get<0>(v1), point) >
                LinearAlgebraOperators::getDistance(std::get<0>(v2), point));
      });

  for (int i = 0; i < k; i++) {
    counter[std::get<1>(data[i])] += 1;
  }

  std::map<std::string, int>::iterator counter_it = counter.begin();

  if (counter.size() > 1) {
    return classify(k - 1, data, point);
  } else {
    return counter_it->first;
  }
}

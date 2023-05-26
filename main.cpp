#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "knn_classifier.hpp"
#include "linear_algebra.hpp"

std::vector<std::tuple<vector, std::string>> get_data();
std::vector<std::vector<std::tuple<vector, std::string>>> split_train_test(
    std::vector<std::tuple<vector, std::string>> data, float percentage);

int main(void) {
  std::vector<std::tuple<vector, std::string>> data = get_data();
  std::vector<std::vector<std::tuple<vector, std::string>>> input_train_test =
      split_train_test(data, 0.7);

  std::vector<std::tuple<vector, std::string>> train_data = input_train_test[0];
  std::vector<std::tuple<vector, std::string>> test_data = input_train_test[1];

  KnnClassifier clf;
  float rightPrevisionsCounter = 0;

  for (std::tuple<vector, std::string> el : test_data) {
    std::string predicted = clf.classify(5, train_data, std::get<0>(el));

    if (predicted.compare(std::get<1>(el)) == 0) {
      rightPrevisionsCounter += 1;
    }
  }

  std::cout << "Quantity of right previsions: " << rightPrevisionsCounter << "\n";
  std::cout << "Error of: " << (1 - (rightPrevisionsCounter / test_data.size())) << "%\n";

  return 0;
}

std::vector<std::tuple<vector, std::string>> get_data() {
  std::ifstream data_file("iris.data");
  std::string line;
  std::vector<std::tuple<vector, std::string>> data;

  while (std::getline(data_file, line)) {
    vector input_row;

    for (int i = 0; i < 4; i++) {
      std::string value = line.substr(0, line.find(","));
      line.erase(0, line.find(",") + 1);

      input_row.push_back(std::stoi(value));
    }

    line.erase(0, line.find("-") + 1);

    data.push_back({input_row, line});
  }

  return data;
}

std::vector<std::vector<std::tuple<vector, std::string>>> split_train_test(
    std::vector<std::tuple<vector, std::string>> data, float percentage) {
  std::vector<std::tuple<vector, std::string>> train_set;
  std::vector<std::tuple<vector, std::string>> test_set;

  size_t train_set_size = size_t(data.size() * percentage);

  for (size_t i = 0; i < data.size(); i++) {
    if (i < train_set_size) {
      train_set.push_back(data[i]);
    } else {
      test_set.push_back(data[i]);
    }
  }

  return {train_set, test_set};
}

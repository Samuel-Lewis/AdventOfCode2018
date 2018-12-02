#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <vector>

long solution(std::vector<long> input) {
  long freq = 0;
  std::unordered_set<long> seen = {0};

  while (true) {
    for (auto i : input) {
      freq += i;
      if (seen.count(freq) == 1) {
        return freq;
      } else {
        seen.insert(freq);
      }
    }
  }

  std::cerr << "Did not find duplicate" << std::endl;
  return -1;
}

std::vector<long> getInput() {
  std::vector<long> in;

  long val;
  std::string line;
  while (std::getline(std::cin, line)) {
    std::stringstream ss(line);
    ss >> val;

    in.push_back(val);
  }
  return in;
}

int main() {
  std::vector<long> input = getInput();
  long ans = solution(input);

  std::cout << ans << std::endl;

  return 0;
}

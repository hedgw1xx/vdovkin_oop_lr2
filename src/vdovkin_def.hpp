#ifndef VDOVKIN_DEF_HPP
#define VDOVKIN_DEF_HPP

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <istream>
#include <limits>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

inline void clearTerminal() {
#ifdef _WIN32
  system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix)
  system("clear");
#endif
}

template <typename T> inline bool UserInput(string input) {
  if (input.empty())
    return false;
  try {
    if constexpr (is_same_v<T, int> || is_same_v<T, bool>) {
      int number = stoi(input);
      if constexpr (is_same_v<T, bool>) {
        return number == 0 || number == 1;
      }
      return number >= 0;
    } else if constexpr (is_same_v<T, double>) {
      double number = stod(input);
      return number >= 0.0;
    } else if constexpr (is_same_v<T, string>) {
      return true;
    }
  } catch (...) {
    return false;
  }
  return true;
}

template <typename T>
function<void()> Enter(istream &is, T &varLink, string label) {
  return [&is, &varLink, label]() {
    string raw_input;
    cout << label;
    getline(is, raw_input);

    while (!UserInput<T>(raw_input)) {
      cout << label;
      getline(is, raw_input);
    }

    if constexpr (is_same_v<T, int>) {
      varLink = stoi(raw_input);
    } else if constexpr (is_same_v<T, double>) {
      varLink = stod(raw_input);
    } else if constexpr (is_same_v<T, bool>) {
      varLink = static_cast<bool>(stoi(raw_input));
    } else if constexpr (is_same_v<T, string>) {
      varLink = raw_input;
    }
  };
}

#endif // VDOVKIN_DEF_HPP

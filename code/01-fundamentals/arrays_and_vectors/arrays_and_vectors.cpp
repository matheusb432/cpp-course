#include "cli_app.h";

#include <iostream>
#include <vector>
#include <cctype>
#include "arrays_and_vectors.h"

using namespace std;

// ? Array exercise
vector<int> use_array() {
  const int ARR_LEN = 10;
  int arr[ARR_LEN]{};

  arr[0] = 100;
  arr[ARR_LEN - 1] = 1000;

  vector<int> v(arr, arr + sizeof arr / sizeof arr[0]);
  return v;
}

// ? Vector exercise
vector<int> use_vector() {
  vector<int> vec{ 10, 20, 30, 40, 50 };
  size_t VEC_LEN = vec.size();

  vec.at(0) = 100;
  vec.at(VEC_LEN - 1) = 1000;

  return vec;
}

void display_vec(vector<int> vec, string name) {
  cout << name << ": " << vec.at(0) << ", " << vec.at(1)
       << " | size: " << vec.size() << endl;
}

void section_7_challenge() {
  vector<int> vector1{ 10, 20 };
  vector<int> vector2{ 100, 200 };

  display_vec(vector1, "vector1");
  display_vec(vector2, "vector2");

  vector<vector<int>> vector_2d;

  // NOTE This *copies* the vector, new vectors are created
  vector_2d.push_back(vector1);
  vector_2d.push_back(vector2);

  display_vec(vector_2d.at(0), "vector_2d.at(0)");
  display_vec(vector_2d.at(1), "vector_2d.at(1)");

  // NOTE As the vector was copied, vector_2d.at(0) will NOT be mutated
  vector1.at(0) = 1000;
  cout << "---- MUTATED vector1! ----" << endl;

  display_vec(vector_2d.at(0), "vector_2d.at(0)");
  display_vec(vector_2d.at(1), "vector_2d.at(1)");

  display_vec(vector1, "vector1");
}

int count_divisible() {
  vector<int> vec{ 1,  3,  5,  15, 16, 17,  18,  19,  20,  21,  25,  26, 27,
                   30, 50, 55, 56, 58, 100, 200, 300, 400, 500, 600, 700 };
  int count{};

  for (auto num : vec) {
    // NOTE Equivalent to `num % 3 == 0 || num % 5 == 0 ? 1 : 0` as bools in
    // C++ are 0 or 1
    count += num % 3 == 0 || num % 5 == 0;
  }

  return count;
}

// ? Counts elements before `-99`
int count_numbers(const vector<int> &vec) {
  int count{};
  auto vec_len = vec.size();

  while (count < vec_len) {
    if (vec.at(count) == -99)
      break;
    count++;
  }

  return count;
}

int calculate_pairs(vector<int> vec) {
  int result{};
  auto vec_len = vec.size();

  for (auto i = 0; i < vec_len; i++) {
    for (auto j = i + 1; j < vec_len; j++) {
      result += vec.at(i) * vec.at(j);
    }
  }
  return result;
}
using cli_app::MenuOption;

// ? Also is section 11 challenge
void section_9_challenge() {
  vector<double> numbers{};

  string input{};
  char normalized_input{};

  do {
    cli_app::print_menu();

    cin >> input;
    if (cin.fail() || input.length() != 1) {
      std::cout << "Invalid input! Must be a char" << endl;
      cin.clear();
      continue;
    }

    normalized_input = toupper(input[0]);

    switch (normalized_input) {
      case MenuOption::PRINT_NUMBERS:
        cli_app::print_numbers(numbers);
        break;
      case MenuOption::ADD_NUMBER:
        cli_app::add_number(numbers);
        break;
      case MenuOption::FIND_NUMBER:
        cli_app::find_indexof(numbers);
        break;
      case MenuOption::DISPLAY_MEAN:
        cli_app::display_mean(numbers);
        break;
      case MenuOption::DISPLAY_SMALLEST:
        cli_app::display_largest(numbers);
        break;
      case MenuOption::DISPLAY_LARGEST:
        cli_app::display_largest(numbers);
        break;
      case MenuOption::QUIT:
        std::cout << "Quitting..." << endl;
        break;
      default:
        std::cout << "Unknown selection, please try again." << endl;
    }
  } while (normalized_input != MenuOption::QUIT);
}

int main() {
  /*
  // NOTE array size is inferred as 5, so it's not necessary specify it
  char vowels[]{ 'a', 'e', 'i', 'o', 'u' };
  cout << "The first vowel is: " << vowels[0] << endl;
  cout << "The last vowel is: " << vowels[4] << endl;

  // ! out of bounds, will cause a runtime error
  // cin >> vowels[5];

  // ! Must be initialized with `{}` or else it will contain garbage values
  int test_scores[5]{ 100, 90, 80, 85,
                      70 }; // ? all elements will be initialized to zero

  for (int i = 0; i < 5; i++) {
    cout << "Element at index " << i << ": " << test_scores[i] << endl;
  }

  // ? Mutating array elements
  cin >> test_scores[0] >> test_scores[1] >> test_scores[2] >> test_scores[3]
    >> test_scores[4];

  cout << "Updated test scores: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << "Element at index " << i << ": " << test_scores[i] << endl;
  }

  // ? Value will be  pointer to the first element
  cout << "Value of test_scores: " << test_scores << endl;
  // ? Assuming the address is `1000`, the addresses of the elements would be:
  // 1000, 1004, 1008, 1012, 1016 (assuming 4 bytes per int)

  vector<int> values{ 100, 95, 99, 87, 88 };

  cout << "values.at(0): " << endl;
  cout << values.at(0) << endl;

  // ? Changing the value of the first element
  values.at(0) = 110;

  cout << "values.at(0): " << endl;
  cout << values.at(0) << endl;

  // ? Adding elements to the end of the vector
  values.push_back(1000);
  // ? Getting the size of the vector, `size_t` is an unsigned integer type
  size_t len = values.size();

  cout << "last el: " << endl;
  cout << values.at(len - 1) << endl;

  // ? 2D Vectors
  vector<vector<int>> movie_ratings{ { 1, 2, 3, 4 },
                                     { 5, 2, 4, 4 },
                                     { 3, 3, 4, 5 } };

  cout << "movie_ratings.at(0).at(0): " << endl;
  cout << movie_ratings.at(0).at(0) << endl;

  cout << "movie_ratings.at(1).at(0): " << endl;
  cout << movie_ratings.at(1).at(0) << endl;

  section_7_challenge();
  int scores[]{ 100, 95, 89 };

  cout << "Scores: " << endl;
  // NOTE range-based for loops (C++11)
  for (auto score : scores) {
    cout << score << " ";
  }
  cout << endl;

  cout << "Inline declaration:" << endl;
  for (auto val : { 1, 5, 10 }) {
    cout << val << " ";
  }
  cout << endl;

  vector<double> temps{ 87.2, 77.1, 80.0 };

  double sum{};

  cout << "Temps: " << endl;
  for (auto temp : temps) {
    cout << temp << " ";
    sum += temp;
  }
  cout << endl;

  double avg{ sum / temps.size() };
  cout << "sum: " << sum << endl;
  cout << "avg: " << avg << endl;
  */

  section_9_challenge();
}

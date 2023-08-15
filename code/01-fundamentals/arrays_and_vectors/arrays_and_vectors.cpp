#include <iostream>
#include <vector>
#include <cctype>

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

// ? CLI app to make operations on a vector of numbers
void section_9_challenge() {
  vector<double> numbers{};

  const char PRINT_NUMBERS = 'P';
  const char ADD_NUMBER = 'A';
  const char DISPLAY_MEAN = 'M';
  const char DISPLAY_SMALLEST = 'S';
  const char DISPLAY_LARGEST = 'L';
  const char QUIT = 'Q';

  char input{};
  char normalized_input{};

  // TODO refactor with enums & functions (or similar)
  do {
    std::cout << "\n" << PRINT_NUMBERS << ". Print numbers" << endl;
    std::cout << ADD_NUMBER << ". Add a number" << endl;
    std::cout << DISPLAY_MEAN << ". Display mean of the numbers" << endl;
    std::cout << DISPLAY_SMALLEST << ". Display the smallest number" << endl;
    std::cout << DISPLAY_LARGEST << ". Display the largest number" << endl;
    std::cout << QUIT << ". Quit" << endl;
    std::cout << "Enter your choice: ";

    cin >> input;

    normalized_input = toupper(input);

    // TODO refactor to if-else since it's less verbose?
    switch (normalized_input) {
      case PRINT_NUMBERS: {
        if (numbers.empty()) {
          cout << "[] - The list is empty" << endl;
          break;
        }
        std::cout << "[ ";
        for (auto num : numbers)
          std::cout << num << ", ";
        std::cout << "]" << endl;
        break;
      }
      case ADD_NUMBER: {
        int new_number{};
        std::cout << "Enter the number to add: ";
        while (true) {
          cin >> new_number;

          if (cin.fail()) {
            std::cout << "Invalid input! Must be a double" << endl;
            continue;
          }
          break;
        }
        std::cout << "Added " << new_number << " to the list.";
        numbers.push_back(new_number);
        break;
      }
      case DISPLAY_MEAN: {
        if (numbers.empty()) {
          cout << "Unable to calculate mean - no data" << endl;
          break;
        }

        double sum{};
        for (auto num : numbers)
          sum += num;

        auto mean = sum / numbers.size();
        std::cout << "Mean is " << mean << endl;
        std::cout << "int Mean is " << static_cast<int>(mean) << endl;
        break;
      }
      case DISPLAY_SMALLEST: {
        if (numbers.empty()) {
          cout << "Unable to get smallest - no data" << endl;
          break;
        }

        double smallest{ numbers.at(0) };
        for (auto num : numbers) {
          if (num > smallest)
            continue;
          smallest = num;
        }
        std::cout << "Smallest is " << smallest << endl;
        break;
      }
      case DISPLAY_LARGEST: {
        if (numbers.empty()) {
          cout << "Unable to get largest - no data" << endl;
          break;
        }

        double largest{ numbers.at(0) };
        for (auto num : numbers) {
          if (num < largest)
            continue;
          largest = num;
        }
        std::cout << "Largest is " << largest << endl;
        break;
      }
      case QUIT: {
        std::cout << "Quitting..." << endl;
        break;
      }
      default: {
        std::cout << "Unknown selection, please try again." << endl;
      }
    }
  } while (normalized_input != QUIT);
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

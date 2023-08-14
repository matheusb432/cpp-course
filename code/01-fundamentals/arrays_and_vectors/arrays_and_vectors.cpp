#include <iostream>
#include <vector>

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

  vector<vector<int> > vector_2d;

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

int main() {
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
  vector<vector<int> > movie_ratings{ { 1, 2, 3, 4 },
                                      { 5, 2, 4, 4 },
                                      { 3, 3, 4, 5 } };

  cout << "movie_ratings.at(0).at(0): " << endl;
  cout << movie_ratings.at(0).at(0) << endl;

  cout << "movie_ratings.at(1).at(0): " << endl;
  cout << movie_ratings.at(1).at(0) << endl;

  section_7_challenge();
}

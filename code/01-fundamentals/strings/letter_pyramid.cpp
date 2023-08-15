#include "letter_pyramid.h";

#include <iostream>
#include <string>

using namespace std;

/// NOTE This can probably be optimized further considering each line has a
/// static size after creation, so they could be C-Style strings
// TODO refactor with learned stuff
string letter_pyramid(string word) {
  auto len = word.length();

  if (len == 0)
    return "";

  auto line_len = len * 2 - 1;
  auto line_half_idx = line_len / 2;
  /// NOTE Preallocating the pyramid to (len * (line_len + 1) * sizeof(char))
  /// bytes could potentially be faster?
  string pyramid{};
  string pyramid_line{};
  /// Creating a line with all whitespaces
  const string blank_line(line_len, ' ');

  for (int i = 0; i < len; i++) {
    /// **Copying** (not pointing) the blank line to the pyramid line
    pyramid_line = blank_line;

    auto letters_count = i * 2 + 1;
    auto whitespaces_count = line_len - letters_count;

    int start_idx = whitespaces_count / 2;
    int line_idx = start_idx;
    /// word_idx must be a signed int, otherwise it overflows when decremented
    int word_idx = 0;

    /// Appends letters forward
    while (line_idx <= line_half_idx) {
      pyramid_line.at(line_idx) = word.at(word_idx);

      line_idx++;
      word_idx++;
    }
    word_idx -= 2;
    /// Appends letters in reverse
    while (word_idx >= 0) {
      pyramid_line.at(line_idx) = word.at(word_idx);

      line_idx++;
      word_idx--;
    }

    pyramid += pyramid_line + '\n';
  }

  std::cout << pyramid << endl;
  return pyramid;
}
#include "challenges.h";

#include <iostream>
#include <string>

using namespace std;

// ? Simple encryption algorithm
void section_10_challenge() {
  string alphabet{ "_ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
  string key{ " _XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr" };

  std::cout << "Enter your secret message: ";
  // ? uncomment for simple testing:
  // string input{ "I'll meet you at billy's house at 10AM" };
  string input{};
  getline(cin, input);

  std::cout << "Encrypting message..." << endl;
  string encrypted{};

  for (char c : input) {
    // NOTE `find()` returns the index of the first substring match or `npos`
    size_t position = alphabet.find(c);
    // NOTE `npos` can be used to check if a char was found
    bool did_find = position != string::npos;

    encrypted += did_find ? key.at(position) : c;
  }
  std::cout << "Encrypted message: " << encrypted << endl;

  std::cout << "Decrypting message..." << endl;
  string decrypted{};

  for (char c : encrypted) {
    size_t position = key.find(c);
    bool did_find = position != string::npos;

    decrypted += did_find ? alphabet.at(position) : c;
  }
  std::cout << "Decrypted message: " << decrypted << endl;
}
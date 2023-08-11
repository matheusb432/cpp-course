#include <iostream>
#include <random>
#include <limits>

static const int EASY_DIFFICULTY = 1;
static const int MEDIUM_DIFFICULTY = 2;
static const int HARD_DIFFICULTY = 3;
static const int UNSET_LIVES = -1;
static const int MIN_GUESS = 1;
static const int MAX_GUESS = 100;

void clear_cin() {
  // ? Clearing the input stream
  std::cin.clear();
  // ? Ignoring bad input
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ? Function
bool handled_cin_err() {
  // NOTE handling invalid inputs via std::cin
  bool did_error = std::cin.fail();

  if (!did_error) return did_error;

  std::cout << "Invalid input! It must be an integer" << std::endl;

  clear_cin();

  return did_error;
}

/**
 * Number guessing game with input validation, difficulty selection and
 * tracking of player's lives.
 */
// ? first game made with C++!
// ? I made this to skip over the trivial stuff in the course
int main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(MIN_GUESS, MAX_GUESS);

  std::cout << "Number guessing game! Select a difficulty: " << std::endl;
  std::cout << EASY_DIFFICULTY << " - Easy" << std::endl;
  std::cout << MEDIUM_DIFFICULTY << " - Medium" << std::endl;
  std::cout << HARD_DIFFICULTY << " - Hard" << std::endl;

  int chosen_difficulty;
  int lives = UNSET_LIVES;

  // ? Loops
  while (lives == UNSET_LIVES) {
    // ? Accepting input via cin
    std::cin >> chosen_difficulty;

    if (handled_cin_err()) continue;

    // ? Switch statements
    switch (chosen_difficulty) {
      case EASY_DIFFICULTY:
        lives = 12;
        break;
      case MEDIUM_DIFFICULTY:
        lives = 8;
        break;
      case HARD_DIFFICULTY:
        lives = 5;
        break;
      default:
        std::cout << "Invalid input! Enter a valid difficulty." << std::endl;
    }
  }

  std::cout << "You have " << lives << " lives!\n";

  int favorite_number = distrib(gen);

  std::cout << "Guess my favorite number between " << MIN_GUESS << " and "
            << MAX_GUESS << std::endl
            << " - ";

  int guess;

  while (true) {
    std::cin >> guess;

    if (handled_cin_err()) continue;

    if (guess == favorite_number) {
      std::cout << "You won! it was " << guess << "!\n" << std::endl;
      break;
    }

    if (guess < favorite_number) {
      std::cout << "Your guess is less than the number!\n";
    } else {
      std::cout << "Your guess is more than the number!\n";
    }

    lives--;

    if (lives < 0) {
      std::cout << "Game over!\n" << std::endl;
      break;
    } else {
      std::cout << "You have " << lives << " lives left!";
    }

    std::cout << std::endl << "- ";
  }

  clear_cin();
  std::cin.get();
}

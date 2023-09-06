#include "file_io.h"
#include <fstream>

#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>

namespace file_io {
    void read_file_example() {
        std::ifstream in_file;
        std::string name{};
        int age{};
        double price{};

        in_file.open("./test.txt");
        if (!in_file) {
            std::cerr << "Problem opening ./test.txt file" << std::endl;
            return;
        }

        while (!in_file.eof()) {
            // NOTE Reading from file with extraction operator
            in_file >> name >> age >> price;
            std::cout << std::setw(10) << std::left << name << std::setw(10) << age << std::setw(10) << price <<
                std::endl;
        }
        in_file.close();

        in_file.open("./poem.txt");
        if (!in_file) {
            std::cerr << "Problem opening ./poem.txt file" << std::endl;
            return;
        }

        std::string line{};
        int i = 0;
        // NOTE Reading lines from a file, moves the buffer to the next line
        while (std::getline(in_file, line)) {
            std::cout << ++i << ": " << line << std::endl;
        }
        in_file.close();
    }

    void read_file(const std::string& file_name) {
        std::ifstream in_file;
        in_file.open(file_name);

        if (!in_file) {
            std::cerr << "Error opening file" << std::endl;
            return;
        }

        std::string word{};
        while (in_file >> word) {
            std::cout << word << std::endl;
        }
        in_file.close();
    }

    void write_file_example() {
        const auto file_to_create{"./test_copy.txt"};

        std::ifstream in_file{"./test.txt"};
        std::ofstream out_file{file_to_create};

        if (!in_file) {
            std::cerr << "Error opening input file" << std::endl;
            return;
        }
        if (!out_file) {
            std::cerr << "Error opening output file" << std::endl;
            return;
        }

        std::string line;
        // NOTE Writing to a file with the insertion operator
        out_file << "==== COPY START ====\n\n";
        // NOTE Copying one file to another
        while (std::getline(in_file, line)) {
            out_file << line << '\n';
        }
        out_file << "\n==== COPY END ====";
        in_file.close();
        out_file.close();

        std::cout << "Created '" << file_to_create << "' file" << std::endl;
    }
}

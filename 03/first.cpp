#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cctype>

typedef struct coordinate {
    int x;
    int y;
} coordinate;

class number {
    public:
        bool is_adjecent() { return true;}
};

void add_symbols(std::vector<coordinate>& coordinates, const std::string& line, const int line_number) {
    int i = -1;
    for(const auto character : line) {
        ++i;
        if(character == 46)
            continue;
        else if(character >= 33 && character <= 47 ||
                character >= 58 && character <= 64 ||
                character >= 91 && character <= 96 ||
                character >= 123 && character <= 126) {
            std::cout<<"Found " << character << " at: " << i << "," << line_number << "\n";
            coordinates.push_back(coordinate{i, line_number});
        }
    }
}

void add_numbers(std::vector<number>& numbers, const std::string& line, const int line_number) {
    int i = -1;
    for(auto pos = line.cbegin(); pos < line.cend(); ++pos) {
        ++i;
        if(isdigit(*pos))
            // Iterate forward until there is no more digits
            // Create a number object with the start coordinate + number of digits as parameters
            // Increase the iterator 
            std::cout<<"Found " << *pos << " at: " << i << "," << line_number << "\n";
    }
}


int main() {
    std::ifstream input_file("input");
    std::string line;
    std::vector<coordinate> symbols;
    std::vector<number> numbers;
    int line_number = 0;
    while(std::getline(input_file, line)) {
        // add_symbols(symbols, line, line_number);
        add_numbers(numbers, line, line_number);
        ++line_number;
    }
    return 0;
}
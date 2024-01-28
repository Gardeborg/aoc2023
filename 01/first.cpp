#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

int get_calibration(std::string& line) {
    int first_digit = -1;
    int last_digit = -1;
    // Works
    // std::for_each(line.cbegin(), line.cend(), [&](const char character)
    // {
    //     if(character >= 48 && character < 58) { // ASCII values
    //         if(first_digit == -1) {
    //             first_digit = std::atoi(&character);
    //         }
    //         last_digit = std::atoi(&character); // Always overwriting the last digit
    //     }
    // });

    // Does not work. I don't fully understand. Something about character is in "place" meaning atoi 
    // will continue if there are multiple digits in a row? e.g 17jdkjldas -> first_digit 17, last_digit 77
    // for(const char character : line) {
    //     if(character >= 48 && character < 58) { // ASCII values 0-9
    //         std::cout<<character << "\n";
    //         if(first_digit == -1) {
    //             first_digit = std::atoi(&character);
    //         }
    //         last_digit = std::atoi(&character); // Always overwriting the last digit
    //     }
    // }

    // Works
    for(const char character : line) {
        if(character >= 48 && character < 58) { // ASCII values 0-9
            std::cout<< character << "\n";
            if(first_digit == -1) {
                first_digit = character - 48;
            }
            last_digit = character - 48; // Always overwriting the last digit
        }
    }
    int value = first_digit * 10 + last_digit;
    std::cout<< first_digit << ", " << last_digit << "\t " << value << "\n";
    return value;
}


int main() {
    std::ifstream input_file("input");
    std::string line;
    std::vector<std::string> lines;
    while(getline(input_file, line)) {
        lines.push_back(line);
    }
    int sum = 0;
    for(auto& line: lines)
        sum += get_coordinate(line);
    std::cout<<sum;
    return 0;
}
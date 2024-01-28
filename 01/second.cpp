#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

int get_calibration(std::string& line) {
    short first_number_pos = line.length();
    short first_number_value = -1;
    short last_number_pos = -1;
    short last_number_value = -1;
    std::vector<std::string> numbers_words = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<std::string> numbers_char = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    unsigned short i = 0;
    for(auto number : numbers_words) {
        ++i;
        int pos = line.find(number);
        if(pos == std::string::npos) {
            continue;
        }
        else if(pos < first_number_pos) {
            first_number_pos = pos;
            first_number_value = i;
        }
        int rpos = line.rfind(number);
        if(rpos == std::string::npos) {
            continue;
        }
        if(rpos > last_number_pos) {
            last_number_pos = rpos;
            last_number_value = i;
        }
    }
    i = 0;
    for(auto number : numbers_char) {
        ++i;
        int pos = line.find(number);
        if(pos == std::string::npos) {
            continue;
        }
        else if(pos < first_number_pos) {
            first_number_pos = pos;
            first_number_value = i;
        }
        int rpos = line.rfind(number);
        if(rpos == std::string::npos) {
            continue;
        }
        if(rpos > last_number_pos) {
            last_number_pos = rpos;
            last_number_value = i;
        }
    }
    std::cout<< "Values: " << first_number_value << "," << last_number_value << "\n";
    return first_number_value * 10 + last_number_value;
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
        sum += get_calibration(line);
    std::cout<< sum;
    return 0;
}
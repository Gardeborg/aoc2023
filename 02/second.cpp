#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

const int nr_red_balls = 12;
const int nr_green_balls = 13;
const int nr_blue_balls = 14;

int game_valid(std::string line) { // returns; game_round (valid) | 0 (not_valid)
    int game_round, balls;
    int min_reds = 0;
    int min_greens = 0;
    int min_blues = 0;
    line.erase(std::remove(line.begin(), line.end(), ','), line.end());
    line.erase(std::remove(line.begin(), line.end(), ';'), line.end());
    std::string tmp, color;
    std::stringstream ss(line);
    ss >> tmp >> game_round >> tmp;
    while(ss >> balls >> color) {
        if(color == "red" && balls > min_reds)
            min_reds = balls;
        else if(color == "blue" && balls > min_blues)
            min_blues = balls;
        else if(color == "green" && balls > min_greens)
            min_greens = balls;
    }
    return min_reds * min_blues * min_greens;
}


int main() {
    std::ifstream input_file("input");
    std::string line;
    long sum = 0;
    while(getline(input_file, line)) {
        sum += game_valid(line);
    }
    std::cout<< sum;
    return 0;
}
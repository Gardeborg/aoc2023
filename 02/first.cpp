#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

const int nr_red_balls = 12;
const int nr_green_balls = 13;
const int nr_blue_balls = 14;

int game_valid(std::string line) { // returns; game_nr (valid) | 0 (not_valid)
    int game_round, balls;
    line.erase(std::remove(line.begin(), line.end(), ','), line.end());
    line.erase(std::remove(line.begin(), line.end(), ';'), line.end());
    std::string tmp, color;
    std::stringstream ss(line);
    ss >> tmp >> game_round >> tmp;
    bool game_valid = true;
    while(game_valid && ss >> balls >> color) {
        if(color == "red" && balls > nr_red_balls)
            game_valid = false;
        else if(color == "blue" && balls > nr_blue_balls)
            game_valid = false;
        else if(color == "green" && balls > nr_green_balls)
            game_valid = false;
    }
    if(game_valid)
        std::cout<< game_round << " is valid \n";
    return game_valid ? game_round : 0;
}


int main() {
    std::ifstream input_file("input");
    std::string line;
    int sum = 0;
    while(getline(input_file, line)) {
        sum += game_valid(line);
    }
    std::cout<< sum;
    return 0;
}
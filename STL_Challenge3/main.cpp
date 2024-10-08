#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

// Used for Part1: Display the word and count from the
// std::map<std::string, int>
void display_words(const std::map<std::string, int> &words) {
    std::cout << std::setw(12) << std::left << "\nWord"
                << std::setw(7) << std::right << "Count"<< std::endl;
    std::cout << "===================" << std::endl;
    for (auto pair: words)
        std::cout << std::setw(12) << std::left << pair.first
                       << std::setw(7) << std::right << pair.second << std::endl;
}

// Used for Part2: Display the word and occurrences from the
// std::map<std::string, std::set<int>>
void display_words(const std::map<std::string, std::set<int>> &words)
{
    std::cout << std::setw(12) << std::left << "\nWord"
               << "Occurrences"<< std::endl;
    std::cout << "=====================================================================" << std::endl;
    for (auto pair: words) {
        std::cout << std::setw(12) << std::left << pair.first
                       << std::left << "[ ";
        for (auto i: pair.second)
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in
// a string and returns the clean version
std::string clean_string(const std::string &s) {
    std::string result;
    for (char c: s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

// Part1 process the file and builds a map of words and the number of times they occur in the file
void part1() {
    if (std::ifstream in_file {"../words.txt"}) {
        std::map<std::string, int> words;
        std::string word;
        while (in_file >> word)
        {
            word = clean_string(word);
            words[word]++;
        }

        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

// Part 2 process the file and builds a map of words and a set of line numbers in which the word appears
void part2() {
    if (std::ifstream in_file {"../words.txt"}) {
        std::map<std::string, std::set<int>> words;
        std::string line;
        int line_number {0};

        while(std::getline(in_file, line))
        {
            std::string word;
            line_number++;
            std::stringstream ss(line);
            while(ss >> word)
            {
                word = clean_string(word);
                words[word].insert(line_number);
            }
        }

        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

int main()
{
    // Part 1
    part1();

    // Part 2
    part2();

    return 0;
}

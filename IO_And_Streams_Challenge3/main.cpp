#include <iostream>
#include <fstream>

int main()
{
    std::ifstream my_file;
    my_file.open("../romeoandjuliet.txt");
    if(!my_file)
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string user_word {};
    std::cout << "Enter the substring to search for: ";
    std::cin >> user_word;

    int total_words {0};
    int match_count {0};
    std::string word {};
    while(my_file >> word)
    {
        size_t found = word.find(user_word);
        if (found != std::string::npos)
        {
            match_count++;
        }
        total_words++;
    }

    std::cout << total_words << " words were searched... " << std::endl;
    std::cout << "The substring " << user_word << " was found " << match_count << " times" << std::endl;
}
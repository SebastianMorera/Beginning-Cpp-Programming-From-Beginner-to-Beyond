// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <vector>

void display_results(const std::vector<std::pair<std::string, int>>& students_grades)
{
    constexpr int total_width {30};
    constexpr  int student_field {15};
    constexpr  int score_field {15};

    // Columns
    std::cout << std::setw(student_field) << std::left << "Student"
                << std::setw(score_field) << std::right << "Score"
                << std::endl;

    // Line separator
    std::cout << std::setw(total_width) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' '); // Reset setfill

    // Names and results
    int total {0};
    for(const auto& [name, result]: students_grades)
    {
        total += result;
        std::cout << std::setw(student_field) << std::left << name
                    << std::setw(score_field) << std::right << result
                    << std::endl;
    }

    // Line separator
    std::cout << std::setw(total_width) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' '); // Reset setfill

    // Display average
    constexpr int average_field {15};
    const double average {total/static_cast<double>(students_grades.size())};

    std::cout << std::setw(average_field) << std::left << "Average score"
                << std::setw(score_field) << std::right << average
                << std::endl;
}

int main()
{
    std::ifstream my_file;
    my_file.open("../responses.txt");
    if(!my_file)
    {
        std::cerr << "Problem opening the file" << std::endl;
        return 1;
    }

    // Get the answers key
    std::string answer_key {};
    std::getline(my_file, answer_key);
    std::cout << "The answer key is: " << answer_key << std::endl;

    // Get the names and their answers
    std::vector<std::pair<std::string, std::string>> students_vector {};
    std::string name {};
    std::string answers {};
    while(!my_file.eof())
    {
        my_file >> name >> answers;
        students_vector.emplace_back(name, answers);
    }
    my_file.close();

    // Correct the exam answers for each student
    std::vector<std::pair<std::string, int>> students_grades {};
    for(const auto& [name, answers]: students_vector)
    {
        int result {0};
        for(size_t i {0}; i < answer_key.size(); i++)
        {
            if(answer_key[i] == answers[i])
                result++;
        }
        students_grades.emplace_back(name, result);
    }

    display_results(students_grades);

    return 0;
}

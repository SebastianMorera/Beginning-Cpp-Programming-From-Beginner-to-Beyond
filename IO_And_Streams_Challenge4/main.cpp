#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in_file {"../romeoandjuliet"};
    std::ofstream out_file {"../output.txt"};

    if (!in_file)
    {
        std::cerr << "Input file opening error" << std::endl;
        return 1;
    }
    else if (!out_file)
    {
        std::cerr << "Output file opening error" << std::endl;
        return 1;
    }

    std::string line {};
    int line_count {1};
    while (!in_file.eof())
    {
        std::getline(in_file, line);
        if(line.empty() || line == "\r")
        {
            out_file << std::endl;
        }
        else
        {
            out_file << std::setw(10) << std::left << line_count << line << std::endl;
            line_count++;
        }
    }

    in_file.close();
    out_file.close();
    std::cout << "Copy Completed!" << std::endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

char display_menu()
{
    char choice {};
    cout << "\n" << endl;
    cout << "P - Prints numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << "\n" <<endl;
    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    vector<int> list_numbers {};
    bool program_continue {true};
    char choice {0};
    int number_to_add {0};
    double mean {0};
    int sum {0};

    while (program_continue)
    {
        choice = display_menu();
        switch (toupper(choice))
        {
            case 'P':
                if(!list_numbers.empty())
                {
                    cout << "[";
                    for (auto value: list_numbers)
                        cout << value << " ";
                    cout << "]" << endl;
                } else
                    cout << "[] - the list is empty";
                break;
            case 'A':
                cout << "Enter the number you want to add: ";
                cin >> number_to_add;
                list_numbers.push_back(number_to_add);
                cout << number_to_add << " added" << endl;
                break;
            case 'M':
                if(!list_numbers.empty())
                {
                    for (auto value: list_numbers)
                        sum += value;
                    cout << "The mean value is " << static_cast<double>(sum)/static_cast<double>(list_numbers.size()) << endl;
                } else
                    cout << "Unable to calculate the mean - no data";
                break;
            case 'S':
                if(!list_numbers.empty())
                {
                    auto min_value = min_element(list_numbers.begin(), list_numbers.end());
                    cout << "The smallest number is " << *min_value << endl;
                } else
                    cout << "Unable to determine the smallest number - list is empty";
                break;
            case 'L':
                if(!list_numbers.empty())
                {
                    auto max_value = max_element(list_numbers.begin(), list_numbers.end());
                    cout << "The largest number is " << *max_value << endl;
                } else
                    cout << "Unable to determine the largest number - list is empty";
                break;
            case 'Q':
                program_continue = false;
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Unknown selection, please try again" << endl;
                break;
        }

    }

    return 0;
}

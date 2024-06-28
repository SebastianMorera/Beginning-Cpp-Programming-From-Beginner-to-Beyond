#include <iostream>
#include <vector>

using namespace std;

void display_menu(char &selection);
void option_p(const vector<int> &numbers);
void option_a(vector<int> &numbers);
void option_m(const vector<int> &numbers);
void option_s(const vector<int> &numbers);
void option_l(const vector<int> &numbers);

int main()
{
    vector<int> numbers {};
    char selection {};

    do {
        display_menu(selection);

        switch (selection)
        {
        case 'P':
            option_p(numbers);
            break;
        case 'A':
            option_a(numbers);
            break;
        case 'M':
            option_m(numbers);
            break;
        case 'S':
            option_s(numbers);
            break;
        case 'L':
            option_l(numbers);
            break;
        case 'Q':
            cout << "Goodbye" << endl;
            break;
        default:
            cout << "Unknown selection, please try again" << endl;
        }
    } while (selection != 'Q');

    cout  << endl;
    return 0;
}

void display_menu(char &selection)
{
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number"<< endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
    cin >> selection;

    int uppercase_char = toupper(selection);
    selection = static_cast<char>(uppercase_char);
}

void option_p(const vector<int> &numbers)
{
    if (numbers.empty())
        cout << "[] - the list is empty" << endl;
    else {
        cout << "[ ";
        for (const auto num: numbers)
            cout << num << " ";
        cout << "]" << endl;
    }
}

void option_a(vector<int> &numbers)
{
    int num_to_add {};
    cout << "Enter an integer to add to the list: ";
    cin >> num_to_add;
    numbers.push_back(num_to_add);
    cout << num_to_add << " added" << endl;
}

void option_m(const vector<int> &numbers)
{
    if (numbers.empty())
        cout << "Unable to calculate mean - no data" << endl;
    else {
        int total {};
        for (const auto num: numbers)
            total += num;
        cout << "The mean is : " << static_cast<double>(total)/ static_cast<double>(numbers.size()) << endl;
    }
}

void option_s(const vector<int> &numbers)
{
    if (numbers.empty())
        cout << "Unable to determine the smallest - list is empty" << endl;
    else {
        int smallest = numbers.at(0);
        for (const auto num: numbers)
            if (num < smallest)
                smallest = num;
        cout << "The smallest number is: " << smallest << endl;
    }
}

void option_l(const vector<int> &numbers)
{
    if (numbers.empty())
        cout << "Unable to determine largest - list is empty"<< endl;
    else {
        int largest = numbers.at(0);
        for (const auto num: numbers)
            if (num > largest)
                largest = num;
        cout << "The largest number is: " << largest << endl;
    }
}
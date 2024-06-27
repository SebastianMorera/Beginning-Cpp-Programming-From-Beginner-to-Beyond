#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input {};
    cout << "Enter the letters you want to be displayed in the pyramid: ";
    cin >> input;
    const int length {static_cast<int>(input.length())};

    for (size_t i {1}; i <= length; ++i)
    {
        // Print spaces
        for (size_t j {1}; j <= length - i; j++) {
            cout << " ";
        }

        // Print characters in ascending order
        for (size_t j {1}; j <= i; j++) {
            cout << input[j - 1];
        }

        // Optional: Add space in the middle for even-length strings
        if (length % 2 == 0 && i == length / 2 + 1) {
            cout << " ";
        }

        // Print characters in descending order
        for (size_t j {i - 1}; j >= 1; j--) {
            cout << input[j - 1];
        }

        cout << std::endl;
    }

    return 0;
}

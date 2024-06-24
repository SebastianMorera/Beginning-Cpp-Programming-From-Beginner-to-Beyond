#include <iostream>

using namespace std;

int main()
{
    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;

    int small_rooms {0};
    cout << "How many small rooms would you like cleaned? ";
    cin >> small_rooms;

    int large_rooms {0};
    cout << "How many large rooms would you like cleaned? ";
    cin >> large_rooms;

    constexpr  int small_room_price {25};
    constexpr  int large_room_price {35};
    constexpr  float tax_percentage {0.06};
    constexpr int estimate_expiry {30};

    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << small_rooms << endl;
    cout << "Number of large rooms: " << large_rooms << endl;
    cout << "Price per small room: $" << small_room_price << endl;
    cout << "Price per large room: $" << large_room_price << endl;

    double cost = small_rooms * small_room_price + large_rooms * large_room_price;
    cout << "Cost: $" << cost << endl;
    double tax = cost * tax_percentage;
    cout << "Tax: $" << tax << endl;

    cout << "========================================================================" << endl;
    cout << "Total estimate: $" << cost + tax << endl;
    cout << "This estimate is valid for " << estimate_expiry << " days" << endl;


    return 0;
}

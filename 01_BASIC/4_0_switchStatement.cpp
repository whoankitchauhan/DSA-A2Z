#include <iostream>
using namespace std;
int main()
{

    int day;
    cout << "Enter Number (1 - 7) : ";
    cin >> day;

    switch (day)
    {
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturady";
        break;
    case 7:
        cout << "Sunday";
        break;
    default:
        cout << "Invaild Number";
        break;
    }
    return 0;
}
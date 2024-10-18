#include <iostream>
using namespace std;
int main()
{

    int age;
    cout << "Enter your Age : ";
    cin >> age;
    if (age >= 18)
    {
        cout << "You are Adult";
    }
    else
    {
        cout << "You are Child";
    }
    return 0;
}
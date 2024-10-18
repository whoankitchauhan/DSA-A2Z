#include <iostream>
using namespace std;
int main()
{

    int age;
    cout << "Enter your Age : ";
    cin >> age;

    if (age < 18)
    {
        cout << "Not Eligible for Job";
    }
    // >=18
    else if (age <= 57) // We dont have Write age <=18
    {
        cout << "Eligible for Job";
        if (age >= 54)
        {
            cout << ", but Retirement Soon";
        }
    }
    // else if (age <= 57)
    // {
    //     cout << "Eligible for Job, but Retirement Soon";
    // }
    else
    {
        cout << "Retirement Time";
    }

    return 0;
}
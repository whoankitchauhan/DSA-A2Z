#include <iostream>
using namespace std;
int main()
{

    int marks;
    cout << "Enter your Marks : ";
    cin >> marks;
    if (marks < 25)
    {
        cout << "Grade - F";
    }
    else if (marks >= 25 && marks < 45)
    {
        cout << "Garde - E";
    }
    else if (marks >= 45 && marks < 50)
    {
        cout << "Garde - D";
    }
    else if (marks >= 50 && marks < 60)
    {
        cout << "Garde - C";
    }
    else if (marks >= 60 && marks < 80)
    {
        cout << "Garde - B";
    }
    else if (marks >= 80 && marks <= 100)
    {
        cout << "Garde - A";
    }

    return 0;
}
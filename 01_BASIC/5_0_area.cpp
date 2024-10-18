#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double calculateArea(int shape, const vector<double> &dims)
{
    if (shape == 1) // Circle
        return 3.14159 * dims[0] * dims[0];
    else if (shape == 2) // Rectangle
        return dims[0] * dims[1];

    return 0.0;
}

int main()
{
    int choice;
    cout << "Enter choice (1 for circle, 2 for rectangle): ";
    cin >> choice;

    vector<double> dimensions;

    if (choice == 1)
    {
        double radius;
        cout << "Enter radius: ";
        cin >> radius;
        dimensions.push_back(radius);
    }
    else if (choice == 2)
    {
        double length, breadth;
        cout << "Enter length and breadth: ";
        cin >> length >> breadth;
        dimensions.push_back(length);
        dimensions.push_back(breadth);
    }
    else
    {
        cout << "Invalid choice\n";
        return 1;
    }

    double area = calculateArea(choice, dimensions);
    cout << fixed << setprecision(5) << "Area: " << area << endl;

    return 0;
}

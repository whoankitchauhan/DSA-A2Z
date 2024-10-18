#include <iostream>
#include <string>
using namespace std;

int dataTypes(string type)
{
    if (type == "Integer")
    {
        return 4;
    }
    else if (type == "Long")
    {
        return 8;
    }
    else if (type == "Float")
    {
        return 4;
    }
    else if (type == "Double")
    {
        return 8;
    }
    else if (type == "Character")
    {
        return 1;
    }
    else
    {
        return -1; // Unknown data type
    }
}

int main()
{
    string type;
    cout << "Enter Any Datatype to Know its Size: ";
    cin >> type;
    cout << "Size of " << type << ": " << dataTypes(type) << " bytes" << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern4(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void pattern5(int n)
{

    int col = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << "* ";
        }
        col--;
        cout << endl;
    }
}
void pattern6(int n)
{
    // int col = n;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= col; j++)
    //     {
    //         cout << j << " ";
    //     }
    //     col--;
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern8(int n)
{
    for (int i = 0; i <= n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * n - (2 * i + 1); k++)
        {
            cout << "*";
        }

        cout << endl;
    }
}
void pattern9(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i <= n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * n - (2 * i + 1); k++)
        {
            cout << "*";
        }

        cout << endl;
    }
}
void pattern10(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void apttern11(int n)
{
    int d = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            d = 1;
        else
            d = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << d << " ";
            d = 1 - d;
        }

        cout << endl;
    }
}
void pattern12(int n)
{

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)

            cout << j << " ";

        /*

            i=1 - (n*2)-(2*1)  spaces

            i=2 - (n*2)-(2*2)  spaces

            i=3 - (n*2)-6  spaces

            i=4 - (n*2)-8  spaces

            spaces = (n*2)-(2*i)

        */

        int spaces = (n * 2) - (2 * i);

        // Prints the white spaces

        for (int k = 0; k < spaces; k++)

            cout << " ";

        for (int j = i; j > 0; j--)
        {

            cout << j << " ";
        }

        cout << "\n";
    }
}
void pattern13(int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }

        cout << "\n";
    }
}
void pattern14(int n)
{
    // Write your code here
    for (int i = 0; i < n; i++)
    {
        char a = 'A';
        for (int j = 0; j <= i; j++)
        {
            cout << a << " ";
            a++;
        }
        cout << endl;
    }
}
void pattern15(int n)
{
    // Write your code here.
    for (int i = 1; i <= n; i++)
    {
        char a = 'A';
        for (int j = 0; j <= n - i; j++)
        {
            cout << a << " ";
            a++;
        }
        cout << endl;
    }
}
void pattern16(int n)
{
    char a = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << a << " ";
        }
        cout << endl;
        a++;
    }
}
void pattern17(int n)
{

    for (int i = 1; i <= n; i++)
    {

        for (int s = 1; s <= n - i; s++)
        {
            cout << " ";
        }

        char ch = 'A';
        int bp = (2 * i - 1) / 2;

        for (int j = 1; j <= 2 * i - 1; j++)
        {

            cout << ch << " ";
            if (j <= bp)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }
        cout << endl;
    }
}
void pattern18(int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= i; j++)
        {

            char ch = 'A' + n - 1 - j;
            cout << ch << " ";
        }
        cout << endl;
    }
}
void pattern19(int n)

{

    for (int i = 0; i < n; i++)

    {

        for (int j = 1; j <= n - i; j++)

        {

            cout << "* ";
        }

        for (int j = 0; j < 2 * i; j++)

        {

            cout << " ";
        }

        for (int j = 1; j <= n - i; j++)

        {

            cout << "* ";
        }

        cout << "\n";
    }

    for (int i = 1; i <= n; i++)

    {

        for (int j = 0; j < i; j++)
        {

            cout << "* ";
        }

        for (int j = 0; j < 2 * n - 2 * i; j++)
        {

            cout << " ";
        }

        for (int j = 0; j < i; j++)
        {

            cout << "* ";
        }

        cout << "\n";
    }
}
void pattern20(int n)
{

    int space = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {

        int star = i;
        if (i > n)
        {
            star = 2 * n - i;
        }
        for (int j = 1; j <= star; j++)
        {
            cout << "* ";
        }
        for (int s = 1; s <= space; s++)
        {
            cout << "  ";
        }
        for (int k = 1; k <= star; k++)
        {
            cout << "* ";
        }
        cout << endl;
        if (i < n)
        {
            space -= 2;
        }
        else
        {
            space += 2;
        }
    }
}
void pattern21(int n)
{

    // will run for number of rows

    for (int i = 1; i <= n; i++)
    { // rows starting from 1

        for (int j = 1; j <= n; j++)
        { // columns starting from 1

            if (i == 1 || j == 1 || j == n || i == n)
            { // do some paper work

                cout << "*";
            }
            else
            {

                cout << " ";
            }
        }

        cout << endl; // for the next line
    }
}
void pattern22(int n)
{

    int x = 2 * n - 1;

    int a[x][x], b[x][x], temp = n;

    for (int i = 0; i < x; ++i, temp--)

    {

        for (int j = i; j < x - i; ++j)

        {

            a[i][j] = a[j][i] = a[x - 1 - i][j] = a[j][x - 1 - i] = temp;
        }
    }

    for (int i = 0; i < x; ++i)

    {

        for (int j = 0; j < x; ++j)

        {

            cout << a[i][j];
        }

        cout << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter :";
    cin >> n;
    // pattern1(n);
    // pattern2(n);
    // pattern3(n);
    // pattern4(n);
    // pattern5(n);
    // pattern6(n);
    // pattern7(n);
    // pattern8(n);
    // pattern9(n);
    // pattern10(n);
    // pattern11(n);
    // pattern12(n);
    // pattern13(n);
    // pattern14(n);
    // pattern15(n);
    // pattern16(n);
    // pattern17(n);
    // pattern18(n);
    // pattern19(n);
    // pattern20(n);
    // pattern21(n);
    pattern22(n);
}
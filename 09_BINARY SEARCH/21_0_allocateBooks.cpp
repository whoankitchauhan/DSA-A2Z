

#include <bits/stdc++.h>
using namespace std;

bool canAllocateBooks(vector<int> &books, int students, int maxPages)
{
    int studentsUsed = 1;
    int pagesAllocated = 0;

    for (int pagesInBook : books)
    {
        if (pagesInBook > maxPages)
            return false;

        if (pagesAllocated + pagesInBook > maxPages)
        {
            studentsUsed++;
            pagesAllocated = pagesInBook;

            if (studentsUsed > students)
                return false;
        }
        else
        {
            pagesAllocated += pagesInBook;
        }
    }
    return true;
}

int allocateBooks(vector<int> &books, int students)
{
    int n = books.size();
    if (students > n)
        return -1;

    int maxBook = *max_element(books.begin(), books.end());
    int totalPages = accumulate(books.begin(), books.end(), 0);

    for (int pages = maxBook; pages <= totalPages; ++pages)
    {
        if (canAllocateBooks(books, students, pages))
        {
            return pages;
        }
    }
    return -1;
}

void printVector(const vector<int> &v)
{
    cout << "[";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];
        if (i + 1 < v.size())
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    vector<vector<int>> tests = {
        {12, 34, 67, 90}, // classic
        {10, 20, 30, 40}, // evenly increasing
        {5, 5, 5, 5},     // uniform
        {100},            // single book
        {10, 20}          // students > books
    };

    vector<int> students = {
        2, // expected 113
        2, // expected 60
        2, // expected 10
        1, // expected 100
        3  // expected -1
    };

    vector<int> expected = {
        113, 60, 10, 100, -1};

    for (int i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << i + 1 << "\n";
        cout << "Books = ";
        printVector(tests[i]);
        cout << "\nStudents = " << students[i] << "\n";

        int ans = allocateBooks(tests[i], students[i]);

        cout << "Expected = " << expected[i] << "\n";
        cout << "Actual   = " << ans << "\n\n";
    }

    return 0;
}

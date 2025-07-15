#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int> &height)
{
    int area = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right)
    {
        int currentHeight = min(height[left], height[right]);
        int width = right - left;
        int currentArea = currentHeight * width;
        area = max(currentArea, area);

        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return area;
}

// Driver code for testing
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max Area: " << maxArea(height) << endl;
    return 0;
}

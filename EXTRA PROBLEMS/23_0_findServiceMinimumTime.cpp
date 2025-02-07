#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if a given maxRequestsPerService is feasible
bool isPossible(int maxRequestsPerService, const vector<int> &serviceRequests)
{
    int extraRequests = 0;  // Requests exceeding max limit
    int availableSlots = 0; // Free space in underloaded services

    for (int requests : serviceRequests)
    {
        if (requests > maxRequestsPerService)
        {
            extraRequests += (requests - maxRequestsPerService); // Count excess requests
        }
        else
        {
            availableSlots += (maxRequestsPerService - requests) / 2; // Count free slots
        }
    }

    return availableSlots >= extraRequests; // Can we redistribute requests?
}

// Function to find the minimum time to process all requests
int findMinimumTime(int numServices, vector<int> &requestCache)
{
    vector<int> serviceRequests(numServices, 0);

    // Step 1: Count requests per service
    for (int request : requestCache)
    {
        serviceRequests[request - 1]++;
    }

    // Step 2: Binary search on minimum time
    int low = 1, high = *max_element(serviceRequests.begin(), serviceRequests.end());

    while (low < high)
    {
        int mid = (low + high) / 2;
        if (isPossible(mid, serviceRequests))
        {
            high = mid; // Try a smaller max request limit
        }
        else
        {
            low = mid + 1; // Increase max limit since mid was too small
        }
    }

    return low; // The minimum maxRequestsPerService that balances requests
}

// Driver Code
int main()
{
    int numServices = 3;
    vector<int> requestCache = {1, 2, 2, 3, 3, 3, 3};

    cout << "Minimum time to process all requests: " << findMinimumTime(numServices, requestCache) << endl;
    return 0;
}

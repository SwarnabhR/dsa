//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int findDuplicate(const vector<int> &arr, int k)
    {
        // code here
        unordered_map<int, int> freq; // Map to store frequencies of each element

        // Computing frequencies of all elements
        for (int num : arr)
        {
            freq[num] += 1; // Increment frequency count for each element
        }

        int smallest = -1; // Initialize the smallest element with the desired frequency

        // Finding the smallest element with frequency as k
        for (const auto &pair : freq)
        {
            if (pair.second == k)
            {
                // Update smallest if it is -1 or if the current element is smaller
                if (smallest == -1 || pair.first < smallest)
                {
                    smallest = pair.first;
                }
            }
        }

        // Return the smallest element found or -1 if no such element exists
        return smallest;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--)
    {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore(); // Ignore the newline character after d

        Solution ob;
        cout << ob.findDuplicate(arr, d) << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    // Create a map to store the values of first array and their counts
    map<int, int> mpp;

    // Iterate over the first array and fill the map
    for (int i = 0; i < n; i++)
    {
        // Increment the count of the current element
        mpp[a1[i]]++;
    }

    // Iterate over the second array and check if it's a subset of the first array
    for (int j = 0; j < m; j++)
    {
        // If the current element is present in the map and its count is not zero
        if (mpp.find(a2[j]) != mpp.end() && mpp[a2[j]] != 0)
        {
            // Decrement its count
            mpp[a2[j]]--;
        }
        else
        {
            // If the element is not present or its count is zero, return "No"
            return "No";
        }
    }
    // If we have iterated over the entire second array and didn't find any element that is not present in the first array, return "Yes"
    return "Yes";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;

        cout << "~" << "\n";
    }
    return 0;
}

// } Driver Code Ends

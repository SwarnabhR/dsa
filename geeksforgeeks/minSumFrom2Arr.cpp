//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minSum(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();

        // Finding minimum element in array arr1 and storing its index value
        int minArr1 = arr1[0], indexArr1 = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr1[i] < minArr1)
            {
                minArr1 = arr1[i];
                indexArr1 = i;
            }
        }

        // Finding minimum element in array arr2 and storing its index value
        int minArr2 = arr2[0], indexArr2 = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr2[i] < minArr2)
            {
                minArr2 = arr2[i];
                indexArr2 = i;
            }
        }

        // If indexes of minimum elements are not same, return their sum
        if (indexArr1 != indexArr2)
            return (minArr1 + minArr2);

        // When index of arr1 is not same as previous and value is also less than other
        // minimum Store new minimum and store its index
        int minArr1_2 = INT_MAX, indexArr1_2;
        for (int i = 0; i < n; i++)
        {
            if (i != indexArr1 && arr1[i] < minArr1_2)
            {
                minArr1_2 = arr1[i];
                indexArr1_2 = i;
            }
        }

        // When index of arr2 is not same as previous and value is also less than other
        // minimum Store new minimum and store its index
        int minArr2_2 = INT_MAX, indexArr2_2;
        for (int i = 0; i < n; i++)
        {
            if (i != indexArr2 && arr2[i] < minArr2_2)
            {
                minArr2_2 = arr2[i];
                indexArr2_2 = i;
            }
        }

        // Taking sum of previous minimum of arr1 with new minimum of arr2
        // and also sum of previous minimum of arr2 with new minimum of arr1
        // and return whichever is minimum
        return min(minArr2 + minArr1_2, minArr1 + minArr2_2);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character before getline
    while (t--)
    {
        vector<int> arr1, arr2;
        string line;

        getline(cin, line);
        stringstream ss1(line);
        int num;
        while (ss1 >> num)
        {
            arr1.push_back(num);
        }

        getline(cin, line);
        stringstream ss2(line);
        while (ss2 >> num)
        {
            arr2.push_back(num);
        }

        Solution solution;
        cout << solution.minSum(arr1, arr2) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
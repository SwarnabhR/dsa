//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to count the number of walls that need to be reduced.

/*
Input: arr[] = [5, 3, 2, 6, 8] and k = 5
Output: 2
Explanation: Ishaan can climb a wall with height atmost 5. So he climbs the first 3 walls easily. Now he has to use his power to reduce the height of the 4th wall. After using his power, Now to climb the last wall, he again uses his power.

Input: arr[] = [2, 6, 4, 8, 1, 6] and k = 4
Output: 3
Explanation: Ishaan can climb a wall with height atmost 5. He can't climb the wall with height 6, 8, 6.
*/
class Solution
{
public:
    int reducingWalls(vector<int> &arr, int k)
    {
        // your code here
        int ans = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int x = arr[i];
            if (x > k)
            {
                ans += (arr[i] - 1) / k;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.reducingWalls(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
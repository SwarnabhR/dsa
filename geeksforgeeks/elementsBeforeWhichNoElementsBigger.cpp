//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*
For Input:
10 40 23 35 50 7
Your Code's output is:
5
It's Correct output is:
3
*/

// } Driver Code Ends
class Solution
{
public:
    int countElements(vector<int> &arr)
    {
        // code here
        int result = 1;

        // Store the arr[0] as maximum
        int max_ele = arr[0];

        // Traverse array starting from second element
        for (int i = 1; i < arr.size(); i++)
        {
            // Compare current element with the maximum
            // value if it is true otherwise continue
            if (arr[i] > max_ele)
            {
                // Update the maximum value
                max_ele = arr[i];

                // Increment the result
                result++;
            }
        }

        return result;
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
        vector<int> arr;
        string line;

        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num)
        {
            arr.push_back(num);
        }

        Solution solution;
        cout << solution.countElements(arr) << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
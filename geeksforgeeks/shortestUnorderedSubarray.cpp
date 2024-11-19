//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the length of the shortest unordered subarray
    // in a given array.
    int shortestUnorderedSubarray(vector<int>& arr) {
        int n = arr.size();
        // Initializing minimum length, flag, and answer variables
        long int Min = INT_MAX, flag = -1, ans = 1;

        // Iterating through the array
        for (int i = 1; i < n; i++) {
            // Checking if the array is increasing or decreasing
            if (flag == -1) {
                // If increasing, set flag to 1 and increment the answer
                if (arr[i] > arr[i - 1]) {
                    flag = 1;
                    ans++;
                }
                // If decreasing, set flag to 0 and increment the answer
                else {
                    flag = 0;
                    ans++;
                }
            }
            // If the array is already in increasing or decreasing order
            else {
                // If still increasing, continue to next element
                if (arr[i] > arr[i - 1] && flag == 1)
                    continue;
                // If increasing after decreasing, update flag to 1, increment answer
                // and check if it is the shortest unordered subarray
                else if (arr[i] > arr[i - 1] && flag == 0) {
                    flag = 1;
                    ans++;
                    if (ans >= 3 && Min > ans)
                        Min = ans;
                }
                // If still decreasing, continue to next element
                else if (arr[i] < arr[i - 1] && flag == 0)
                    continue;
                // If decreasing after increasing, increment answer, update flag to 0,
                // and check if it is the shortest unordered subarray
                else if (arr[i] < arr[i - 1] && flag == 1) {
                    ans++;
                    flag = 0;
                    if (ans >= 3 && Min > ans)
                        Min = ans;
                }
            }
        }
        // If no unordered subarray is found, return 0
        if (Min == INT_MAX)
            return 0;
        // Otherwise, return the length of the shortest unordered subarray
        else
            return Min;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.shortestUnorderedSubarray(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
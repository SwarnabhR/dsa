//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxHappiness(vector<int> &arr) {
        // Your code goes here.
        vector<int>v;
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            sum = arr[i] + arr[i+1];
            v.push_back(sum);
        }
        int ans = *max_element(v.begin(),v.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.maxHappiness(arr) << endl;
    }
}

// } Driver Code Ends
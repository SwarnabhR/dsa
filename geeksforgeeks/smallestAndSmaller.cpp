//{ Driver Code Starts
#include <bits/stdc++.h>
#include <limits.h>
#include <random>
#include <sstream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] != arr[i + 1]){
                return {arr[i], arr[i + 1]};
            } else{
                continue;
            }
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.minAnd2ndMin(arr);
        if (ans[0] == -1)
            cout << -1 << endl;
        else
            cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
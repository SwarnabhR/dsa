//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPerfect(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i = 1;
        while (arr[i] > arr[i - 1] && i < n)
        {
            i++;
        }

        while (arr[i] == arr[i - 1] && i < n){
            i++;
        }

        while (arr[i] < arr[i - 1] && i < n) {
            i++;
        }

        return (i == n);
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
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution solution;
        cout << (solution.isPerfect(arr) ? "true" : "false") << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long countOddXorPairs(vector<int>& arr) {
        // code here
        int n = arr.size();
        long long evenCount = 0, oddCount = 0;
        
        // Count even and odd numbers
        for (int num : arr) {
            if (num % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        
        // Calculate odd XOR pairs
        return evenCount * oddCount;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character before getline
    while (t--) {
        vector<int> arr;
        string line;

        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution solution;
        cout << solution.countOddXorPairs(arr) << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
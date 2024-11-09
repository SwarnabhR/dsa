//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Write your code here

class Solution {
  public:
    vector<int> mergeNsort(vector<int>& a, vector<int>& b) {
        // Write your code here
        vector<int> ans;
        for (int i = 0; i < a.size(); i++){
            ans.push_back(a[i]);
        }
        for (int i = 0; i < b.size(); i++){
            ans.push_back(b[i]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr, brr;
        string input1, input2;

        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }

        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }

        Solution ob;
        vector<int> res = ob.mergeNsort(arr, brr);

        for (int x : res) {
            cout << x << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> getMoreAndLess(vector<int> &arr, int x) {
        vector<int> ans;
        int flag1 = 0;
        int flag2 = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= x){
                flag1++;
            }
            if(arr[i] >= x){
                flag2++;
            }
        }
        ans.push_back(flag1);
        ans.push_back(flag2);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        vector<int> ans = ob.getMoreAndLess(arr, x);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> getTriangle(vector<int>& arr) {
        int n = arr.size();
        // Initialize a 2D array to store triangle
        int tri[n][n];
        memset(tri, 0, sizeof(tri));

        // Initialize last row of triangle
        for (int i = 0; i < n; i++)
            tri[n - 1][i] = arr[i];

        // Fill other rows
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                tri[i][j] = (tri[i + 1][j] + tri[i + 1][j + 1]) % 1000000007;

        vector<int> Triangle;
        // Storing the triangle
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                Triangle.push_back(tri[i][j]);

        return Triangle;
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
        vector<int> ans = obj.getTriangle(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends

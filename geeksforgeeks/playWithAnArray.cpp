//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/
class Solution {
  public:
    string formatArray(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int count = 1;
        int cur = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (cur == arr[i]) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    count = 1;
                    cur = arr[i];
                }
            }
        }

        if (count <= 1) {
            return "true";
        } else {
            return "false";
        }
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
        string res = obj.formatArray(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
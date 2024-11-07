//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPerimeter(vector<int> &arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        int max_per=0;

//greatest<=sum of next greater two sides condition
        if(arr[0]<arr[1]+arr[2]){
            max_per=arr[0]+arr[1]+arr[2];
            return max_per;
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

// Driver Program
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
        cout << ob.maxPerimeter(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends
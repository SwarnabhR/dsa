//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the minimum number of moves required.
    int minMoves(vector<int> &arr) {
        int n = arr.size();
        int c{n};
        while ( n-- ) if ( arr[ n ] == c ) c--;
        return c;
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
        cout << ob.minMoves(arr) << endl;
        cout << "~\n";
    }
}
// } Driver Code Ends
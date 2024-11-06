//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findEvenOccurrences(vector<int>& arr) {
        // This function takes an array of integers and returns a new array
        // containing only the numbers that appear an even number of times.
        // The new array will be sorted in ascending order.
        vector<int> v,ans;
        unordered_map<int,int> mpp;
        for(int i:arr){
            mpp[i]++;
        }
        for(auto it:mpp){
            if(it.second%2==0)
            {
                v.push_back(it.first);
            }
        }
        if(v.size()==0) 
        {
            return {-1};
        }
        for(int i:arr){
            for(auto it:v){
                if(i==it){
                    ans.push_back(it);
                    v.erase(remove(v.begin(), v.end(), it), v.end());
                }
            }
        }
        return ans;

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the number of test cases
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        vector<int> result = ob.findEvenOccurrences(arr);
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends

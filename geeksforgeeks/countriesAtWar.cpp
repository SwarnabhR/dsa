//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to determine which country is at war
class Solution {

  public:
    string countryAtWar(vector<int>& arr1, vector<int>& arr2) {
        // code
        int count1 = 0, count2 = 0;
        for (int i = 0; i < arr1.size(); i++)
        {
            if (arr1[i] > arr2[i]){
                count1++;
            } else if (arr1[i] < arr2[i]){
                count2++;
            }
        }
        if (count1 > count2){
            return "A";
        } else if (count2 > count1){
            return "B";
        } else {
            return "DRAW";
        }
    }
};

//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        // Function calling
        // vector<int> v;
        string v = ob.countryAtWar(arr1, arr2);

        // for (int i = 0; i < v.size(); i++)
        //     cout << v[i] << " ";

        cout << v << endl;
        cout << "~" << endl;
        // string tilde;
        // getline(cin, tilde);
    }

    return 0;
}

// } Driver Code Ends
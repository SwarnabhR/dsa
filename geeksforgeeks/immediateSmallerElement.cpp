//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    //  code here
        stack<int>st;
        st.push(-1);
        for (int i=n-1; i>=0; i--){
            int curr= arr[i];
            if(st.top()<curr){
              arr[i]= st.top();
              st.push(curr);
          }
          else{
             arr[i]= -1;
             st.push(curr);
          }
      }
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    // Function to check if elements in the array fall within range A and B
    bool check_elements(int arr[], int n, int A, int B) {
        // Calculate the range of elements
        int range = B - A;

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // Check if the absolute value of the element is within the range
            if ((abs(arr[i])) >= A && (abs(arr[i])) <= B) {
                // Update the value of the element
                int z = abs(arr[i]) - A;
                if (z < n && arr[z] > 0) {
                    arr[z] = arr[z] * -1;
                }
            }
        }

        // Count the number of elements that fall within the range
        int count = 0;
        for (int i = 0; i <= range && i < n; i++) {
            // Check if the element is positive
            if (arr[i] > 0)
                return false;
            else
                count++;
        }

        // Check if the number of elements within the range is equal to the range length
        if (count != (range + 1))
            return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, A, B;
        cin >> n >> A >> B;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        Solution ob;
        if (ob.check_elements(a, n, A, B))
            cout << "True";
        else
            cout << "False";

        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
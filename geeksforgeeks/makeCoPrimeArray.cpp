//{ Driver Code Starts
// CPP program for minimum insertions to
// make a Co-prime Array.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int countCoPrime(const vector<int> &arr)
    {
        // Complete the function
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (gcd(arr[i], arr[i + 1]) == 1)
            {
                ans++;
            }
            else
            {
                continue;
            }
        }
        return ans;
    }

    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
};

//{ Driver Code Starts.

// Driver Function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.countCoPrime(arr, n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
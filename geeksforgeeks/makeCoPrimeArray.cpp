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
    int countCoPrime(int a[], int n)
    {
        // Complete the function
        int c = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (gcd(a[i], a[i + 1]) != 1)
            {
                c++;
            }
        }
        return c;
    }
    static int gcd(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }
        return gcd(b % a, a);
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
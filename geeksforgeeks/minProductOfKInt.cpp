//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int minProduct(vector<int> &arr, int k)
    {
        // Complete the function
        // Store the size of the array
        int n = arr.size();

        // Create a min heap (priority queue)
        priority_queue<int> p;

        // Iterate through the array
        for (int i = 0; i < n; i++)
        {
            // Push each element from the array into the min heap
            p.push(arr[i]);

            // If the size of the min heap exceeds k
            if (p.size() > k)
            {
                // Pop the largest element from the min heap
                p.pop();
            }
        }

        // Initialize product to 1
        long long int product = 1;

        // Iterate through the min heap and multiply each element with the product
        while (!p.empty())
        {
            // Multiply the top of the min heap with the product
            product *= p.top();

            // Calculate the modulo of the product with 1000000007 to prevent overflow
            product %= 1000000007;

            // Pop the top of the min heap
            p.pop();
        }

        // Return the product
        return product;
    }
};

//{ Driver Code Starts.

int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--)
    {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minProduct(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
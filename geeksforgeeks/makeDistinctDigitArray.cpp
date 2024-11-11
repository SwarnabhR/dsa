//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
   	vector<int> common_digits(vector<int>nums){
   	    // Code here
        vector<int> unique;
        int temp = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            temp = nums[i];
            while (temp > 0)
            {
                int rem = temp % 10;
                if (find(unique.begin(), unique.end(), rem) == unique.end())
                {
                    unique.push_back(rem);
                }
                temp /= 10;
            }
        }
        sort(unique.begin(), unique.end());
        return unique;
    }    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < nums.size(); i++)cin >> nums[i];
		Solution ob;
		vector<int> ans = ob.common_digits(nums);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends
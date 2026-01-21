// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int smallest = a[0];
        int ans = a[0];
        
        for (int i = 1; i<a.size(); i++) {
            int opt1 = smallest + a[i];
            int opt2 = a[i];
            smallest = min(opt1, opt2);
            ans = min(ans, smallest);
        }
        
        return ans;
    }
};

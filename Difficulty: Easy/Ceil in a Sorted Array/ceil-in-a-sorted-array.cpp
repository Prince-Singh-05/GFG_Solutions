// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int start = 0;
        int end = arr.size()-1;
        int res_idx = -1;
        int res = INT_MAX;
        
        while (start <= end) {
            int mid = start + (end-start)/2;
            
            if (arr[mid] >= x) {
                if (res >= arr[mid]) {
                    res = arr[mid];
                    res_idx = mid;
                }
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        
        return res_idx;
        
    }
};
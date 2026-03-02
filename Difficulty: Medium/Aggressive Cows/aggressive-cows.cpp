class Solution {
  private:
    bool possible(vector<int>& stalls, int k, int guess) {
        int curr_cow = stalls[0];
        k--;
        
        for (int s = 1; s<stalls.size(); s++) {
            if (k <= 0) return true;
            
            int diff = stalls[s] - curr_cow;
            if (diff >= guess) {
                curr_cow = stalls[s];
                k--;
            }
        }
        
        return k > 0 ? false : true;
    }
    
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        
        sort(stalls.begin(), stalls.end());
        
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        int res = 1;
        
        while (low <= high) {
            int mid = low + (high-low)/2;
            
            if (possible(stalls, k, mid)) {
                res = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return res;
    }
};
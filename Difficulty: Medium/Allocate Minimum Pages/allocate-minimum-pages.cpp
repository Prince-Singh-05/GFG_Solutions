class Solution {
  private:
    bool possible(vector<int>& arr, int k, int guess) {
        int pages = 0;
        int stud = 1;
        
        for (int n: arr) {
            if (pages + n <= guess) {
                pages += n;
            } else {
                stud++;
                pages = n;
                
                if (stud > k) return false;
            }
        }
        
        return true;
    } 
  
  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (n < k) return -1;
        
        int low = INT_MIN;
        int high = 0;
        
        for (int n: arr) {
            low = max(low, n);
            high += n;
        }
        
        int res = -1;
        
        while (low <= high) {
            int mid = low + (high-low)/2;
            
            if (possible(arr, k, mid)) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return res;
    }
};
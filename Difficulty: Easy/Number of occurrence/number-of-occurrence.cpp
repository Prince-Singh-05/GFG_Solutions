class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int idx = -1;
        
        while (s <= e) {
            int m = s + (e-s)/2;
            
            if (arr[m] == target) {
                idx = m;
                e = m-1;
            } else if (arr[m] < target) {
                s = m+1;
            } else {
                e = m-1;
            }
        }
        
        int count = 0;
        
        if (idx != -1) {
            for (int i = idx; i<n; i++) {
                if (arr[i] == target) count++;
            }
        }
        
        return count;
    }
};

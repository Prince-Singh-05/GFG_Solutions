class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        
        int i = 0;
        int j = k-1;
        
        int max_sum = 0;
        
        for (int x = i; x<=j; x++) {
            max_sum += arr[x];
        }
        
        int sum = max_sum;
        
        while (j < arr.size()-1) {
            sum = sum - arr[i++] + arr[++j];
            max_sum = max(max_sum, sum);
        }
        
        return max_sum;
        
    }
};
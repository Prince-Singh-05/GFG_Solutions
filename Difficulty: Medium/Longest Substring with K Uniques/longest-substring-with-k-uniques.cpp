class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> map;
        int max_len = INT_MIN;
        
        while (right < s.size()) {
            map[s[right]] += 1;
            
            while (map.size() > k) {
                map[s[left]]--;
                if (map[s[left]] == 0) map.erase(s[left]);
                left++;
            }
            
            if (map.size() == k) {
                max_len = max(max_len, right-left+1);
            }
            
            right++;
            
        }
        
        return max_len == INT_MIN ? -1 : max_len;
    }
};
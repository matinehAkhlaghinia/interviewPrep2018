class Solution {
public:
    static bool myfunction (vector<int> a,vector<int> b) { return b[1] > a[1]; }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        size_t size = pairs.size();
        int longest = 1;
        sort(pairs.begin(), pairs.end(), myfunction);
        vector<int> dp(size, 1);
        
        for(int i = 1; i < size; i++) {
            for(int j = i - 1; j >=0; j--) {
                if(pairs[j][1] < pairs[i][0]) {
                    longest = max(longest, dp[j]+1);
                }
            }
            dp[i] = longest;
        }
        
        return longest;
        
    }
};
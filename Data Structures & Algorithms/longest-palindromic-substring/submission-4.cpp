class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        int start_idx = -1;
        int end_idx = -1;
      
        for(int i = 0; i < s.size(); ++i) {
            int j = 1;
            while(i + j < s.size() && i - j >= 0 && s[i + j] == s[i - j]) {
                ++j;
            }
            if( 1 + 2 * (j-1) > longest){
                longest = 1 + 2 * (j-1);
                start_idx = i - (j - 1);
                end_idx = i + (j - 1);
            }
            
        }
     
        for(int i = 0; i < s.size() - 1; ++i) {
            if(s[i] == s[i + 1]) {
                int j = 1;
                while(i + 1 + j < s.size() && i - j >= 0 && s[i + 1 + j] == s[i - j]) {
                    ++j;
                }
                // cout<<i<<" "<<j<<endl;
                if( 2 + 2 * (j-1) > longest){
                    longest = 2 + 2 * (j-1);
                    start_idx = i - (j - 1);
                    end_idx = i + 1 + (j - 1);
                }
            }
        }
        
        return string(begin(s) + start_idx, begin(s) + end_idx + 1);
        
    }
};

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char, vector<string>> char_to_str;
        for(int i = 0; i < words.size(); i++) 
            char_to_str[words[i][0]].push_back(words[i]);
        
        int char_ptr = 0;
        int count = 0;
        while(char_ptr < S.length()) {
            if(char_to_str.find(S[char_ptr]) != char_to_str.end()) {
                int size  = char_to_str[S[char_ptr]].size();
                vector<string>* ptr = &char_to_str[S[char_ptr]];
                vector<string>& ref = *ptr;
                for(int i = 0; i < size; i++) {
                    string curr = ref[i];

                    if(curr.empty())continue;
                    curr.erase(curr.begin());

                    if(curr.empty()) 
                        count++;
                    else {
            
                        char_to_str[curr[0]].push_back(curr);
                    }
                }
                
                (ptr)->erase((ptr)->begin(), (ptr)->begin()+size);
            }
            char_ptr++;
        }
        
        return count;
    }
};
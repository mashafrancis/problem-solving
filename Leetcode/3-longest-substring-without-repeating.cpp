class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int startId = 0;
        unordered_map<char, int> lastSeen;
        if (s.size() <= 1) return s.size();
        for (int i = 0; i < s.size(); i++){
            char currChar = s[i];
            if(lastSeen.find(currChar) != lastSeen.end()){
                startId = max(startId, lastSeen[currChar] + 1);
            }
            if(i - startId + 1 > maxLen) maxLen = i - startId + 1;
            lastSeen[currChar] = i;
        }
        return maxLen;
    }
};
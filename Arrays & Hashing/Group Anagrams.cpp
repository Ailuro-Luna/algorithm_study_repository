// see: https://neetcode.io/problems/anagram-groups?list=neetcode150

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> str_map;
        for(string str:strs) {
            string key = str;
            sort(key.begin(),key.end());
            str_map[key].push_back(str);
        }
        for(auto str:str_map) {
            ans.push_back(str.second);
        }
        return ans;
    }

private:
    unordered_map<char, int> str_to_map(string& str) {
        unordered_map<char, int> res;
        
        for(char ch:str) {
            ++res[ch];
        }

        return res;
    }
};

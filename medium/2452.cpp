class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
        unordered_map<int, vector<string>> mp;
        for (auto &d : dictionary) {
            mp[d.size()].push_back(d);
        }

        vector<string> ans;

        for (auto &word : queries) {
            int n = word.size();

            for (auto &d : mp[n]) {
                int edit = 0;

                for (int i = 0; i < n; i++) {
                    if (word[i] != d[i] && ++edit > 2) {
                        break;
                    }
                }

                if (edit <= 2) {
                    ans.push_back(word);
                    break;
                }
            }
        }

        return ans;
    }
};

//myapp:
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,vector<string>& dictionary) {
        vector<string> ans;

        for (string word : queries) {
            int n = word.size();

            for (string d : dictionary) {
                if (d.size() == n) {
                    int edit = 0;

                    for (int i = 0; i < n; i++) {
                        if (word[i] != d[i]) {
                            edit++;
                            if (edit > 2)
                                break;
                        }
                    }

                    if (edit <= 2) {
                        ans.push_back(word);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
//tle
// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord,
//                                        vector<string>& wordList) {
//         vector<vector<string>> res;
//         unordered_set<string> st;
//         for (auto it : wordList)
//             st.insert(it);
//         if (st.find(endWord) == st.end())
//             return res;
//         st.erase(endWord);
//         vector<string> temp;
//         temp.push_back(endWord);
//         queue<vector<string>> q;
//         q.push(temp);
//         string s = endWord;
//         bool f=false;
//         while (!q.empty()) {
//             vector<string> x;
//             int y = q.size();
//             while (y--) {
//                 temp = q.front();
//                 q.pop();
//                 s = temp[temp.size() - 1];
//                 for (int i = 0; i < s.size(); i++) {
//                     string k = s;
//                     for (int j = 0; j < 26; j++) {
//                         k[i] = 'a' + j;
//                         if (k == beginWord) {
//                             f=true;
//                             temp.push_back(k);
//                             vector<string> a = temp;
//                             reverse(a.begin(), a.end());
//                             res.push_back(a);
//                             temp.pop_back();
//                         } else if (st.find(k) != st.end()) {
//                             temp.push_back(k);
//                             q.push(temp);
//                             x.push_back(k);
//                             temp.pop_back();
//                         }
//                     }
//                 }
//             }
//             if(f)break;
//             for (auto it : x)
//                 st.erase(it);
//         }
//         return res;
//     }
// };
//mle
// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord,
//                                        vector<string>& wordList) {
//         vector<vector<string>> res;
//         unordered_set<string> dict(wordList.begin(), wordList.end());
//         if (!dict.count(endWord)) return res;

//         queue<vector<string>> q;
//         q.push({endWord});
//         bool found = false;

//         while (!q.empty()) {
//             int sz = q.size();
//             unordered_set<string> used; 

//             while (sz--) {
//                 auto path = q.front(); q.pop();
//                 string word = path.back();

//                 for (int i = 0; i < word.size(); i++) {
//                     string nxt = word;
//                     for (char c = 'a'; c <= 'z'; c++) {
//                         if (c == word[i]) continue;
//                         nxt[i] = c;

//                         if (nxt == beginWord) {
//                             found = true;
//                             auto newPath = path;
//                             newPath.push_back(nxt);
//                             reverse(newPath.begin(), newPath.end());
//                             res.push_back(newPath);
//                         } 
//                         else if (dict.count(nxt)) {
//                             auto newPath = path;
//                             newPath.push_back(nxt);
//                             q.push(newPath);
//                             used.insert(nxt);
//                         }
//                     }
//                 }
//             }

//             if (found) break; 
//             for (auto &w : used) dict.erase(w);
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (!dict.count(endWord)) return res;
        unordered_map<string, vector<string>> parent; // graph of parent links
        unordered_map<string, int> dist;              // shortest distance
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;
        int L = beginWord.size();
        bool found = false;
        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> levelVisited;
            while (sz--) {
                string word = q.front(); q.pop();
                int d = dist[word];
                string temp = word;
                for (int i = 0; i < L; i++) {
                    char old = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == old) continue;
                        temp[i] = c;
                        if (!dict.count(temp) && temp != endWord) continue;
                        if (!dist.count(temp)) { // first visit
                            dist[temp] = d + 1;
                            q.push(temp);
                            levelVisited.insert(temp);
                        }
                        if (dist[temp] == d + 1) {
                            parent[temp].push_back(word);
                        }
                        if (temp == endWord) found = true;
                    }
                    temp[i] = old;
                }
            }
            for (auto &w : levelVisited) dict.erase(w);
        }
        if (!found) return res;
        // backtrack from endWord to beginWord
        vector<string> path{endWord};
        function<void(string)> dfs = [&](string word) {
            if (word == beginWord) {
                vector<string> seq = path;
                reverse(seq.begin(), seq.end());
                res.push_back(seq);
                return;
            }
            for (string &p : parent[word]) {
                path.push_back(p);
                dfs(p);
                path.pop_back();
            }
        };
        dfs(endWord);
        return res;
    }
};

/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start

const int INF = 1 << 30;

class Solution {
    vector<string> originalWordList;
    int N;
    vector<vector<int>> E;
    string target;
    vector<bool> col;
    vector<int> dp;
    vector<vector<int>> paths;

    bool isPossibleEdge(string w1, string w2) {
        int dif = 0;
        for (int i = w1.length() - 1; i > -1; i--) {
            dif += w1[i] != w2[i];
            if (dif > 1)
                return false;
        }

        return dif == 1;
    }

    void dfs(int u) {
        // cout << '+' << u;
        if (originalWordList[u] == target)
            return;
        

        for (auto v: E[u]) {
            if (dp[v] > dp[u] + 1)
                dp[v] = dp[u] + 1, dfs(v);
            // cout << '-' << v;
        }

        return;
    }

    void storeSoln(int u, vector<int> &path) {
        if (originalWordList[u] == target) {
            paths.push_back(path);
            return;
        }

        // cout << "++++ u: " << u << " " << originalWordList[u] << " " << dp[u] << endl;
        // cout << ">>>>>> v's: {";
        // for (auto v: E[u]) {
        //     cout << v << ' ' << dp[v] <<  ',';
        // }
        // cout << '}' << endl;
        for (auto v: E[u]) {
            // cout << "   ++++ v: " << v << " " << originalWordList[v] << dp[v] << endl;
            if (dp[v] == dp[u] - 1) {
                path.push_back(v);
                storeSoln(v, path);
                path.pop_back();
            }
        }

        return;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int targetIdx = -1;
        for (int i = wordList.size() - 1; i > -1; i--) {
            if (wordList[i] == endWord) {
                targetIdx = i;
                break;
            }
        }
        if (targetIdx == -1)
            return vector<vector<string>>();

        wordList.push_back(beginWord);
        originalWordList = wordList;
        N = wordList.size();
        E = vector<vector<int>>(N, vector<int>());
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (isPossibleEdge(wordList[i], wordList[j])) {
                    E[i].push_back(j);
                    E[j].push_back(i);
                }
            }
        }

        // for (int i = E.size() - 1; i > -1; i--) {
        //     cout << i << ":";
        //     for (auto j: E[i]) {
        //         cout << j << ',';
        //     }
        //     cout << endl;
        // }

        dp = vector<int>(N, INF);
        dp[targetIdx] = 0;
        target = beginWord;
        dfs(targetIdx);

        // for (int i = 0; i < N; i++)
        //     cout << dp[i] << ',';
        // cout << endl;

        // print the slon(s)
        paths.clear();
        vector<int> path = {N - 1};
        target = endWord;
        storeSoln(N - 1, path);

        vector<vector<string>> res;
        for (auto path: paths) {
            vector<string> soln;
            for (auto u: path) {
                soln.push_back(wordList[u]);
            }
            res.push_back(soln);
        }

        return res;
    }
};
// @lc code=end


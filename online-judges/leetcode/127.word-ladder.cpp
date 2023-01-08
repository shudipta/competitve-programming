/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
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

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int targetIdx = -1;
        for (int i = wordList.size() - 1; i > -1; i--) {
            if (wordList[i] == endWord) {
                targetIdx = i;
                break;
            }
        }
        if (targetIdx == -1)
            return 0;

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

        dp = vector<int>(N, INF);
        dp[targetIdx] = 1;
        target = beginWord;
        dfs(targetIdx);

        return dp[N - 1] != INF ? dp[N - 1] : 0;
    }
};
// @lc code=end


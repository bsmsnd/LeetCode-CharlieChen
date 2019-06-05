/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
class Solution {
public:
    int wordLength;
    bool adjacentCheck(string a, string b)
    {        
        bool diff = false;
        for(int i = 0; i < wordLength;i++)
            if (a[i]!=b[i])
                if (!diff)
                    diff = true;
                else
                    return false;
        return diff;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        const int N = wordList.size();
        wordLength = wordList[0].size();        
        int visit[N];        
        int goal = -1;
        queue<int> q;
        for(int i = 0;i<N;i++)
        {
            if (adjacentCheck(beginWord, wordList[i]))
            {
                q.push(i);
                visit[i] = 2;
            }
            else
            {
                visit[i] = -1;
            }
            
            if (wordList[i] == endWord)
                goal = i;
        }
        if (goal == -1)
            return 0;

        int cur;
        while(!q.empty())
        {
            cur = q.front();
            q.pop();            
            for(int i = 0; i < N;i++)
                if (visit[i]==-1 && adjacentCheck(wordList[cur], wordList[i]))
                {
                    visit[i] = visit[cur] + 1;
                    q.push(i);
                }
            if (visit[goal] != -1)
                return visit[goal];
        }
        return 0;
    }
};

// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> dict(wordList.begin(), wordList.end());
//         queue<string> todo;
//         todo.push(beginWord);
//         int ladder = 1;
//         while (!todo.empty()) {
//             int n = todo.size();
//             for (int i = 0; i < n; i++) {
//                 string word = todo.front();
//                 todo.pop();
//                 if (word == endWord) {
//                     return ladder;
//                 }
//                 dict.erase(word);
//                 for (int j = 0; j < word.size(); j++) {
//                     char c = word[j];
//                     for (int k = 0; k < 26; k++) {
//                         word[j] = 'a' + k;
//                         if (dict.find(word) != dict.end()) {
//                             todo.push(word);
//                         }
//                      }
//                     word[j] = c;
//                 }
//             }
//             ladder++;
//         }
//         return 0;
//     }
// };


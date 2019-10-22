/*
 * @lc app=leetcode id=843 lang=cpp
 *
 * [843] Guess the Word
 */

// @lc code=start
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        const int N = wordlist.size();
        int used_word[N];
        int common[N][N];
        const int K = wordlist[0].length();
        memset(used_word, 0, sizeof(used_word));

        for (int i=0; i < N; i++)
        for (int j=i+1; j < N; j++)
        {
            common[i][j] = 0;
            for (int k = 0;k < K; k++)
                common[i][j] += (wordlist[i][k] == wordlist[j][k]);
            common[j][i] = common[i][j];
        }
        
        int cnt[N];
        // only 10 times!
        for (int t = 0;t < 10; t++)
        {
            memset(cnt, 0, sizeof(cnt));
            int choose = -1;
            for (int i = 0;i < N; i++)
            if (!used_word[i])
            {
                for (int j = i+1;j < N; j++)
                if (!used_word[j])
                {
                    cnt[i] += (common[i][j] == 0);
                    cnt[j] += (common[i][j] == 0);
                }
                if (choose == -1 || cnt[choose] > cnt[i])
                    choose = i;  // choose the smallest one!                
            }
            cout << choose << " " << cnt[choose] << " " << wordlist[choose] << endl;
            // guess that word!
            int result = master.guess(wordlist[choose]);
            if (result == K) return;
            // analyze the result
            used_word[choose] = 1;
            for (int i = 0;i < N;i++)
                if (!used_word[i])
                    if (common[choose][i] != result)
                        used_word[i] = 1; // no longer available                        
        }
    }
};
// @lc code=end


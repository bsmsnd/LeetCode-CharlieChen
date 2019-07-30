/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */
#define MAX_PLAYER 1
#define MIN_PLAYER 2

class Solution {
public:
    int states[101][101];  // pile, M; states[i][j] = max. score from i to the end with M = j given first move is by Alex
    int prefix[101];
    int N;
    int DFS(int pile, int M, int player)
    {
        int remaining = prefix[N - 1] - ((pile == 0) ? 0 : prefix[pile - 1]);
        if (states[pile][M] != -1)
            return (player == MAX_PLAYER) ? states[pile][M] : remaining - states[pile][M];
        if (player == MAX_PLAYER)
        {
            if (N - pile <= 2 * M) // take all!
                states[pile][M] = remaining;
            else
            {
                int best_ans = -1;
                for (int i = 1;i <= 2 * M; ++i)
                {
                    int this_round = prefix[i + pile - 1] - ((pile == 0) ? 0 : prefix[pile - 1]);
                    int tmp = this_round + DFS(pile + i, max(i, M), 3 - player);
                    if (tmp > best_ans)
                    best_ans = tmp;
                }
                states[pile][M] = best_ans;
            }
            return states[pile][M];
        }
        else
        {
            if (N - pile <= 2 * M) // take all!
            {
                states[pile][M] = remaining;
                return 0;
            }
            else
            {
                int best_ans = INT_MAX;
                for (int i = 1;i <= 2 * M; ++i)
                {
                    int tmp = DFS(pile+i, max(i,M), 3 - player);
                    if (tmp < best_ans)
                    best_ans = tmp;
                }
                states[pile][M] = remaining - best_ans;
                return best_ans;
            }
        }
    }

    int stoneGameII(vector<int>& piles) {
        N = piles.size();
        for (int i = 0;i < N; ++i)
        for (int j = 1; j<= 100; ++j)
        states[i][j] = -1;
        prefix[0] = piles[0];
        for (int i = 1;i < N;++i)
        prefix[i] = prefix[i-1] + piles[i];
        return DFS(0, 1, MAX_PLAYER);
    }
};


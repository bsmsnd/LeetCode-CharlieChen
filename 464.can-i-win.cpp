/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */
#define MAX_PLAYER 1
#define MIN_PLAYER -1

#define WIN 1
#define LOSE -1
class Solution {
public:
    unordered_map<int, int> states;
    int N;
    int target;

    int minimax(int state, int depth, int player, int total, int alpha, int beta)
    {
        auto it = states.find(state);
        if (it!=states.end())
            return it->second;
        int value;
        if (player == MAX_PLAYER)
        {
            // first check if the player can win directly
            for (int i = N-1; i>=0; --i)
                if ((state & (1 << i)) == 0 && total + (i+1) >= target)
                {
                    states[state] = WIN;
                    return WIN;
                }

            // then DFS to see if the player can win
            value = -2;
            for (int i = 0;i < N; ++i)
            if ((state & (1 << i)) == 0) // number i has not used
            {
                int tmp = minimax(state | (1 << i), depth+1, MIN_PLAYER, total + (i+1), alpha, beta);
                value = max(tmp, value);
                alpha = max(tmp, alpha);
                if (value == WIN)break;  
                if (alpha >= beta) break;
            }
        }
        else // player == MIN_PLAYER
        {
            // first check if the player can win directly
            for (int i = N-1; i>=0; --i)
                if ((state & (1 << i)) == 0 && total + (i+1) >= target)
                {
                    states[state] = LOSE;
                    return LOSE;
                }
            
            value = 2;
            for (int i = 0;i < N;++i)
            if ((state & (1 << i)) == 0)
            {
                int tmp = minimax(state | (1 << i), depth+1, MAX_PLAYER, total + (i+1), alpha, beta);
                value = min(tmp, value);
                beta = min(tmp, beta);
                if (value == LOSE)break;  
                if (alpha >= beta) break;
            }
        }
        states[state] = value;
        return value;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) /2 < desiredTotal)
            return false;
        if (desiredTotal <= 0)
            return true;
        N = maxChoosableInteger;
        target = desiredTotal;
        int result = minimax(0, 0, MAX_PLAYER, 0, -2, 2);
        return (result == 1);
    }
};


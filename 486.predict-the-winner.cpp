/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */
// #include <vector>
// #include <unordered_map>
// using namespace std;

#define MAX_PLAYER 1
#define MIN_PLAYER -1

class Solution {
public:
    vector<int> numbers;
    int minimax(pair<int, int> state, int player, int total, int alpha, int beta)
    {        
        int value;
        if (player == MAX_PLAYER)
        {
            // then DFS to see if the player can win
            value = INT_MIN;
            if (state.first!=state.second)
            {
                // choose left
                int tmp = minimax(make_pair(state.first+1, state.second), MIN_PLAYER, total + numbers[state.first], alpha, beta);
                value = max(value, tmp);
                alpha = max(alpha, tmp);
                if (alpha>beta) return value;
                tmp = minimax(make_pair(state.first, state.second-1), MIN_PLAYER, total + numbers[state.second], alpha, beta);
                value = max(value, tmp);
                alpha = max(alpha, tmp);
            }
            if (state.first == state.second)
                return total + numbers[state.first];
        }
        else // player == MIN_PLAYER
        {    
            // then DFS to see if the player can win
            value = INT_MAX;
            if (state.first!=state.second)
            {
                // choose left
                int tmp = minimax(make_pair(state.first+1, state.second), MAX_PLAYER, total, alpha, beta);
                value = min(value, tmp);
                beta = min(beta, tmp);
                if (alpha>beta) return value;
                tmp = minimax(make_pair(state.first, state.second-1), MAX_PLAYER, total, alpha, beta);
                value = min(value, tmp);
                beta = min(beta, tmp);
            }
            if (state.first == state.second)
                return total;  
        }    

        return value;
    }


    bool PredictTheWinner(vector<int>& nums) {
        int all_total = 0;
        numbers = nums;
        for (int i = 0;i < nums.size();i++)
            all_total += nums[i];
        int best_score = minimax(make_pair(0, nums.size()-1), MAX_PLAYER, 0, INT_MIN, INT_MAX);
        return best_score >= all_total - best_score;
    }
};


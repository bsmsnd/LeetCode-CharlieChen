#include <unordered_map>
using namespace std;
#define MAX_PLAYER 1
#define MIN_PLAYER -1


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
        // then DFS to see if the player can win
        value = -2;
        for (int i = 0;i < N; ++i)
        if ((state & (1 << i)) == 0) // number i has not used
        {
            int tmp = minimax(state | (1 << i), depth+1, MIN_PLAYER, total + (i+1), alpha, beta);
            value = max(tmp, value);
            alpha = max(tmp, alpha);
            if (alpha > beta) break;
        }
    }
    else // player == MIN_PLAYER
    {    
        value = 2;
        for (int i = 0;i < N;++i)
        if ((state & (1 << i)) == 0)
        {
            int tmp = minimax(state | (1 << i), depth+1, MAX_PLAYER, total + (i+1), alpha, beta);
            value = min(tmp, value);
            beta = min(tmp, beta);
            if (alpha > beta) break; 
        }
    }
    states[state] = value;
    return value;
}



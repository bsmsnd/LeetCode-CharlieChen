/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
const int MOVE_X[4] = {1,0,-1,0};
const int MOVE_Y[4] = {0,-1,0,1};

class Solution {
public:    
    vector<vector<char>> b;
    string w;
    int N, M;
    vector<vector<bool>> visited;
    
    bool h(int x, int y, int t)
    {
        if (t >= w.size())
            return true;
        int cx, cy;
        for (int i = 0; i < 4;i++)
        {
            cx = x + MOVE_X[i];
            cy = y + MOVE_Y[i];
            if (cx >= 0 && cx < N && cy >=0 && cy < M && !visited[cx][cy] && b[cx][cy] == w[t])
            {
                visited[cx][cy] = 1;
                if (h(cx, cy, t+1))
                    return true;
                visited[cx][cy] = 0;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> v;
        b = board;
        w = word;
        N = board.size();
        M = board[0].size();
        
        visited.resize(N);
        for (int i = 0;i < N;i++)
            visited[i].resize(M, false);
        
        for (int i = 0;i < N; i++)
            for (int j = 0;j < M;j++)
                if (board[i][j] == word[0])
                    v.push_back({i,j});
        
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            visited[v[i].first][v[i].second] = 1;
            if (h(v[i].first, v[i].second, 1))
                return true;
            visited[v[i].first][v[i].second] = 0;
        }
        return false;
    };
    
};


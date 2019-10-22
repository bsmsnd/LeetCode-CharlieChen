/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

struct TrieNode
{
    bool isWord = false;
    TrieNode* children[26] = {nullptr}; 
    int child_cnt = 0;
};

const int MX[4] = {1,0,-1,0};
const int MY[4] = {0,-1,0,1};

class Solution {
public:
    TrieNode* head;
    void addWord(string w)
    {
        int n = w.size();
        TrieNode *cur = head;
        for (int i = 0; i < n; i++)
        {
            if (!(cur->children[w[i]-'a']))
            {
                cur->children[w[i]-'a'] = new TrieNode;
                if (i != n-1)
                    cur->child_cnt++;
            }
            cur = cur->children[w[i] - 'a'];
            if (i == n-1)
                cur->isWord = true;
        }
    }

    bool backtrack(int x, int y, TrieNode *cur)
    {
        if(!cur)return false;
        if (cur->isWord)
        {
            ans.push_back(cur_word);
            cur->isWord = false;
        }        
        int nx, ny;                
        for (int k = 0;k < 4; k++)
        if (cur->child_cnt > 0)
        {
            nx = x + MX[k]; ny = y + MY[k]; 
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visit[nx][ny])
                if (cur->children[b[nx][ny] - 'a'])
                {
                    cur_word.push_back(b[nx][ny]);
                    visit[nx][ny] = 1;
                    if (backtrack(nx, ny, cur->children[b[nx][ny] - 'a']))
                    {
                        cur->child_cnt--;
                        delete cur->children[b[nx][ny]];
                        cur->children[b[nx][ny]] = nullptr;
                    }
                    visit[nx][ny] = 0;
                    cur_word.pop_back();
                }
        }
        if (!cur->isWord && cur->child_cnt <= 0)
            return true;
        return false;
    }

    string cur_word;
    vector<string> ans;
    vector<vector<bool>> visit;
    vector<vector<char>> b;
    int N, M;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        b = board;
        for (int i = 0; i < words.size(); i++)
            addWord(words[i]);
        N = board.size(); M = board[0].size();
        visit.resize(N);
        for (int i = 0;i < N; i++)
            visit[i].resize(M, false);
        
        for (int i = 0;i < N; i++)
        for (int j = 0;j < M; j++)
        if (head->children[board[i][j]-'a'])
        {
            visit[i][j] = 1;
            cur_word = board[i][j];
            if (backtrack(i,j,head->children[board[i][j]-'a']))
            {
                head->child_cnt--;
                delete head->children[board[i][j]-'a'];
                head->children[board[i][j]-'a'] = nullptr;
            }
        }
        return ans;
    }
};
// @lc code=end


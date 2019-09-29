/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence
 */
#include <string> 
#include <vector>
using namespace std;

class Solution {
public:
    char add[1001][1001];
    pair<int, int> next[1001][1001];
    bool visited[1001][1001];
    int len[1001][1001];
    int N, M;
    string s1, s2;
    int func(int p1, int p2)
    {
        if (p1 >= N && p2 >= M)return 0;
        if (visited[p1][p2])return len[p1][p2];
        if (p1 >= N)
            if (p2 != M-1)
            {
                add[p1][p2] = s2[p2];
                len[p1][p2] = 1 + func(p1, p2+1);
                next[p1][p2] = {p1, p2+1};
                visited[p1][p2] = 1;
                return len[p1][p2];
            }
            else
            {
                add[p1][p2] = s2[p2];
                len[p1][p2] = 1;
                next[p1][p2] = {-1, -1};
                visited[p1][p2] = 1;
                return len[p1][p2];
            }

        if (p2 >= M)
            if (p1 != N-1)
            {
                add[p1][p2] = s1[p1];
                len[p1][p2] = 1 + func(p1+1, p2);
                next[p1][p2] = {p1+1, p2};
                visited[p1][p2] = 1;
                return len[p1][p2];
            }
            else
            {
                add[p1][p2] = s1[p1];
                len[p1][p2] = 1;
                next[p1][p2] = {-1, -1};
                visited[p1][p2] = 1;
                return len[p1][p2];
            }
        
        // p1 < N, p2 < M
        int cur_ans = 2002;
        pair<int, int> cur_next = {-1, -1};
        char cur_add;
        if (s1[p1] == s2[p2])
        {
            cur_add = s1[p1];
            cur_next = {p1+1, p2+1};
            cur_ans = 1 + func(p1+1, p2+1);
        }
        // #1
        int tmp_ans = 1 + func(p1, p2+1);
        if (tmp_ans < cur_ans)
        {
            cur_add = s2[p2];
            cur_next = {p1, p2+1};
            cur_ans = tmp_ans;
        }
        // #2
        tmp_ans = 1 + func(p1+1, p2);
        if (tmp_ans < cur_ans)
        {
            cur_add = s1[p1];
            cur_next = {p1+1, p2};
            cur_ans = tmp_ans;
        }
        
        visited[p1][p2] = 1;
        next[p1][p2] = cur_next;
        add[p1][p2] = cur_add;
        len[p1][p2] = cur_ans;
        return len[p1][p2];
        
    }
    string shortestCommonSupersequence(string str1, string str2) {
        N = str1.length(); M = str2.length();
        s1 = str1; s2 = str2;
        func(0,0);
        pair<int,int> cur={0,0};
        string ans;
        while(cur!=make_pair(-1,-1) && cur.first < N && cur.second < M)
        {
            ans += add[cur.first][cur.second];
            cur = next[cur.first][cur.second];
        }
        return ans;
    }
};


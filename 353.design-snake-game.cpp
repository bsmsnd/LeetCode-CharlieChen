/*
 * @lc app=leetcode id=353 lang=cpp
 *
 * [353] Design Snake Game
 */

// @lc code=start
const int mx[] = {0,-1,0,1};
const int my[] = {1,0,-1,0};

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) : w(width), h(height), f(food){
        q.push_back(make_pair(0,0));
        points = 0;
        pre = make_pair(0,0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int dir = 0;
        if (direction == "R") dir = 0;
        if (direction == "U") dir = 1;
        if (direction == "L") dir = 2;
        if (direction == "D") dir = 3;
                
        
        int nx = pre.first + mx[dir];
        int ny = pre.second + my[dir];        
        // q.push_front();
        if (points < f.size() && (nx == f[points][0]) && (ny == f[points][1])){                
            points++;                
        }
        else{
            cout << q.size() << endl;
            q.pop_front();
        }
        
        // printf("%d %d %d %d\n", nx, ny, w, h);
        if (nx < 0 || nx >= h || ny < 0 || ny >= w)
            return -1;
        // check collision
        for (auto it = q.begin(); it != q.end(); it++){
            if (nx == it->first && ny == it->second)
                return -1;
        }
        
        pre = make_pair(nx, ny);
        q.push_back(pre);
        // q.push_front(make_pair(nx, ny));        
        return points;
    }

    int len(){
        return points + 1;
    }
private:
    int w;
    int h;
    int points;
    deque<pair<int, int>> q;
    vector<vector<int>> f;
    pair<int, int> pre;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
// @lc code=end


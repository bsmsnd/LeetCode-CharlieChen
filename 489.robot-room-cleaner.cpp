/*
 * @lc app=leetcode id=489 lang=cpp
 *
 * [489] Robot Room Cleaner
 */

// @lc code=start
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
#include <vector>
#include <set>
using namespace std;

// class Robot {
// public:
//       // Returns true if the cell in front is open and robot moves into the cell.
//       // Returns false if the cell in front is blocked and robot stays in the current cell.
//       bool move();
 
//       // Robot will stay in the same cell after calling turnLeft/turnRight.
//       // Each turn will be 90 degrees.
//       void turnLeft();
//       void turnRight();
 
//       // Clean the current cell.
//       void clean();
// };

#define BLOCKED 1
#define EMPTY 0

// directions
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
const int MX[4] = {-1, 0, 1, 0};
const int MY[4] = {0, 1, 0, -1};

class Solution {
public:    
    set<pair<int, int>> room;  
    int x = 0;
    int y = 0;
    int direction = 0;

    void oneStepMoveTo(Robot& robot, int dx, int dy)
    {
        int toDirection;
        if (x == dx)
        {
            if (dy - y == 1)
                toDirection = RIGHT;
            else
                toDirection = LEFT;            
        }
        else
        {
            if (dx - x == 1)
                toDirection = DOWN;
            else
                toDirection = UP;
        }
        rotate(robot, toDirection);
        robot.move();
        x = dx;
        y = dy;
    }

    void rotate(Robot& robot, int newDirection)
    {
        int diff = newDirection - direction;
        if (diff < 0)diff+=4;
        
        if (diff == 0)
            return;
        else if (diff == 1)        
            robot.turnRight();
        else if (diff == 2)
        {
            robot.turnLeft();
            robot.turnLeft();
        }
        else if (diff == 3)
            robot.turnLeft();

        direction = newDirection;        
    }

    void cleanRoom(Robot& robot) {
        int tx = x, ty = y;
        room.insert({tx,ty});        
        robot.clean();
        // explore all 4 directions
        for (int d = 0;d < 4; d++)
        {
            int nx = tx + MX[d];
            int ny = ty + MY[d];
            if (room.find({nx, ny}) != room.end())continue;
            rotate(robot, d);
            if (robot.move())
            {
                // move to that space
                x = nx; 
                y = ny;
                cleanRoom(robot); // DFS
                // come back, assuming robot is at (nx, ny)
                oneStepMoveTo(robot, tx, ty);
            }  
            else
                room.insert(make_pair(nx, ny));
        }
    }
};
// @lc code=end


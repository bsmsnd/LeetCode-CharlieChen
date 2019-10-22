/*
 * @lc app=leetcode id=736 lang=cpp
 *
 * [736] Parse Lisp Expression
 */

// @lc code=start
#include <iostream>
#include <string> 
#include <unordered_map>
using namespace std;

// #define DEBUG

class Solution {
public:
    int pointer;
    string expr;
    int N;    
    unordered_map<string, int> vars;

    // this function will skip the space, 
    // but will keep the position of closing parenthesis
    string extractString()
    {
        int left_pos = pointer;
        while(pointer < N && expr[pointer]!= ' ' && expr[pointer] != ')')
            pointer++;
        
        int right_position = pointer;
        skipSpace();
        #ifdef DEBUG
        cout << "pointer at " << pointer << ", word = " << expr.substr(left_pos, pointer - left_pos)<<endl;
        #endif
        return expr.substr(left_pos, right_position - left_pos);        
    }

    void skipSpace()
    {
        if (pointer < N && expr[pointer] == ' ')
            pointer++; // skip the space
    }

    int compute()
    {
        if (expr[pointer] == '(')pointer++;  // skip the opening parenthesis
        // step 1: get action        
        string action = extractString();                
        if (action == "let")
        {
            #ifdef DEBUG
            printf("let:\n");
            #endif

            unordered_map<string, int> local_vars;
            unordered_map<string, int> outer_vars;
            
            string expr1, expr2;
            int right_value;
            while(pointer < N && expr[pointer] != ')')
            {
                // () handler
                if (expr[pointer] == '(')
                {
                    int return_value = compute();
                    for (auto it = local_vars.begin(); it != local_vars.end(); it++)
                        vars.erase(it->first);
                    for (auto it = outer_vars.begin(); it != outer_vars.end(); it++)
                        vars[it->first] = it->second;
                    
                    pointer++; // cover the closing parenthesis
                    return return_value;
                }
                
                string cur_str = extractString();                                
                if (expr[pointer] == ')')   // evaluate this value
                {                    
                    int return_value;
                    if (cur_str[0] >= '0' && cur_str[0] <= '9' || cur_str[0] == '-')
                    {
                        return_value = stoi(cur_str);
                    }
                    else
                    {
                        return_value = vars[cur_str];
                    }
                    // remove local variables
                    for (auto it = local_vars.begin(); it != local_vars.end(); it++)
                        vars.erase(it->first);
                    for (auto it = outer_vars.begin(); it != outer_vars.end(); it++)
                        vars[it->first] = it->second;
                    
                    pointer++; // cover the closing parenthesis
                    return return_value;
                }

                expr1 = cur_str;

                // obtain the right value
                skipSpace();
                
                if (expr[pointer] == '(') // opening parenthesis
                    right_value = compute();
                else
                {
                    expr2 = extractString();
                    if (expr2[0] >= '0' && expr2[0] <= '9' || expr2[0] == '-')
                        right_value = stoi(expr2);
                    else
                        right_value = vars[expr2];
                }

                // assign value
                if (local_vars.find(expr1) == local_vars.end())
                {
                    if (vars.find(expr1) == vars.end())
                        local_vars[expr1] = vars[expr1] = right_value;
                    else
                    {
                        outer_vars[expr1] = vars[expr1];
                        local_vars[expr1] = vars[expr1] = right_value;
                    }                    
                }
                else
                {
                    local_vars[expr1] = vars[expr1] = right_value;
                }
                skipSpace();                                
            }
            return -1; // placeholder
        }
        else if (action == "add" || action == "mult" )
        {
            #ifdef DEBUG
            cout<<action<<":"<<endl;
            #endif
            int left_value, right_value;
            string e;
            if (expr[pointer] == '(')
                left_value = compute();
            else
            {
                e = extractString();
                if (e[0] >= '0' && e[0] <= '9' || e[0] == '-')
                {
                    left_value = stoi(e);
                }
                else
                {
                    left_value = vars[e];
                }
            }

            skipSpace();

            if (expr[pointer] == '(')
                right_value = compute();
            else
            {
                e = extractString();
                if (e[0] >= '0' && e[0] <= '9' || e[0] == '-')
                {
                    right_value = stoi(e);
                }
                else
                {
                    right_value = vars[e];
                }
            }
            
            if (expr[pointer] == ')')pointer++; // cover the closing parenthesis
            if (action == "add")
                return left_value + right_value;
            else
                return left_value * right_value;

        }        
        else  // single value
        {            
            if (expr[pointer] == ')')pointer++; // cover the closing parenthesis

            if (action[0] >= '0' && action[0] <= '9' || action[0] == '-')
            {
                return stoi(action);
            }
            else
            {
                return vars[action];
            }
        }
        return -1; // placeholder
    }

    int evaluate(string expression) {
        expr = expression;
        N = expression.size();
        pointer = 0;
        if (expr[pointer] == '(')
            return compute();
        else
            return stoi(expr);
    }
};
// @lc code=end


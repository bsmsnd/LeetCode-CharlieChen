/*
 * @lc app=leetcode id=1452 lang=cpp
 *
 * [1452] People Whose List of Favorite Companies Is Not a Subset of Another List
 */

// @lc code=start
class Solution {
public:
    // bool subset(set<int>& a, set<int>& b){ // a < b                
    //     for (auto k : a)
    //         if (b.find(k) == b.end()){
    //             return false;
    //         }
        
    //     return true;        
    // }

    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        map<string, int> m;
        int companyCount = 0;
        vector<set<int>> v;
        const int nPeople = favoriteCompanies.size();
        v.resize(nPeople);

        for (int i = 0; i < nPeople; i++)
            for (string& company : favoriteCompanies[i]){
                int code;
                if (m.find(company) == m.end()){
                    m[company] = companyCount;
                    code = companyCount++;                    
                }
                else
                    code = m[company];
                
                v[i].insert(code);
            }
        
        vector<int> ans;
        for (int i = 0; i < nPeople; i++){
            bool flag = true;
            for (int j = 0; j < nPeople; j++)            
                if (i != j && includes(v[j].begin(), v[j].end(), v[i].begin(), v[i].end())){
                    flag = false;
                    break;
                }
            if (flag)
                ans.push_back(i);
        }
        return ans;                
    }
};
// @lc code=end


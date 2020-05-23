// Time complexity :- O(n + m)
// Space complexity :- O(1)
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int n = A.size();
        int m = B.size();
        
        //  [x y]  [a b]
        // not intersect -> y < a or b < x
        int i = 0, j = 0;
        vector<vector<int> >ans;
        while(i < n && j < m)
        {
            int x = A[i][0], y = A[i][1];
            int a = B[j][0], b = B[j][1];
            
            if(y < a || b < x)
            {
                if(y < a)   i++;
                else    j++;
            }
            else
            {
                vector<int>temp;
                temp.push_back(max(x,a));
                temp.push_back(min(y,b));
                ans.push_back(temp);
                
                if(y > b)   j++;
                else    i++;
            }
        }
        
        return ans;
    }
};
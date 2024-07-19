class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; ++i){
            int minNumInRow = matrix[i][0]; 
            int colIndex = 0;
            int j = 1;
            while(j < n){
                if(matrix[i][j] < minNumInRow){
                    minNumInRow = matrix[i][j];
                    colIndex = j;
                }
                j++;
            }
            // cout << minNumInRow << endl;
            //check whether matrix[i][colIndex] is the max of the colIndex column
            for(j = 0; j < m; ++j){
                if(matrix[j][colIndex] > minNumInRow){
                    colIndex = -1;
                    break;
                }
            }
            if(colIndex>=0){
                ans.push_back(minNumInRow);
            }
        }
        return ans;
    }
};
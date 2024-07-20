class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // Greedy
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> mat(m,vector<int>(n,0));
        int curRowSum = 0;
        vector<int> curColSum(n,0);
        for(int i=0; i<m; ++i){
            curRowSum = 0;
            for(int j=0; j<n; ++j){
                mat[i][j] = min(rowSum[i] - curRowSum, colSum[j] - curColSum[j]);
                curRowSum += mat[i][j];
                curColSum[j] += mat[i][j];
            }
        }
        return mat;
    }
};
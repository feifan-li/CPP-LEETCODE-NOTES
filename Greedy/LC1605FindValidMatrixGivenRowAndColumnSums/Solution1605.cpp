#include<iostream>
#include<vector>

using namespace std;

class Solution1605 {
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

int main(int argc, char* argv[]){
  Solution1605 s;
  vector<int> rowSum = {5, 7, 10};
  vector<int> colSum = {8, 6, 8};
  vector<vector<int>> ans = s.restoreMatrix(rowSum, colSum);
  for(int i=0; i<ans.size(); ++i){
    for(int j=0; j<ans[0].size(); ++j){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
#include<iostream>
#include<vector>
#include<deque>

using namespace std;

class Solution2392 {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, 
                                        vector<vector<int>>& colConditions) {
        //topological sort: O(m+n)
        vector<int> rowTopoOrder = topoSort(k, rowConditions);
        if(rowTopoOrder.empty() || rowTopoOrder.size() == 0){
            return {};
        }
        vector<int> colTopoOrder = topoSort(k, colConditions);
        if(colTopoOrder.empty() || colTopoOrder.size() == 0){
            return {};
        }
        //merge: O(k)
        vector<vector<int>> ans(k, vector<int>(k,0));
        vector<int> valToRowIndex(k+1);
        vector<int> valToColIndex(k+1);
        for(int index = 0; index < k; ++index){
            valToRowIndex[rowTopoOrder[index]] = index;
            valToColIndex[colTopoOrder[index]] = index;
        }
        for(int val = 1; val <= k; ++val){
            ans[valToRowIndex[val]][valToColIndex[val]] = val;
        }
        // for(int i = 0; i < k; ++i){
        //     for(int j = 0; j < k; ++j){
        //         if(rowTopoOrder[i] == colTopoOrder[j]){
        //             ans[i][j] = rowTopoOrder[i];
        //         }
        //     }
        // }
        return ans;
    }
    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        // Create an adjacency list to store the edges.
        vector<vector<int>> G(n+1);
        vector<int> inDegree(n+1);
        vector<int> ans;
        for(auto e: edges){
            G[e[0]].push_back(e[1]);
            inDegree[e[1]]++;
        }
        deque<int> q;
        for(int i = 1; i <= n; ++i){
            if(inDegree[i] == 0){
                q.push_back(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop_front();
            ans.push_back(u);
            for(int v: G[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push_back(v);
                }
            }
        }
        if(ans.size() < n){
            return {};
        }
        return ans;
    }
};

int main(int argc, char** argv){
  Solution2392 s;
  vector<vector<int>> rowConditions = {{1,2},{3,2}};
  vector<vector<int>> colConditions = {{2,1},{3,2}};
  vector<vector<int>> ans = s.buildMatrix(3, rowConditions, colConditions);
  for(auto row: ans){
    for(auto x: row){
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
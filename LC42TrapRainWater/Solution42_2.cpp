#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
// dp:
class Solution {
public:
    int trap(vector<int>& height) {
      int n = height.size();
      vector<int> l_max(n);
      vector<int> r_max(n);
      l_max[0] = height[0];
      r_max[n-1] = height[n-1];

      for(int i=1;i<n;++i){
        l_max[i] = max(l_max[i-1],height[i]);
      }
      for(int i=n-2; i>=0;--i){
        r_max[i] = max(r_max[i+1],height[i]);
      }
      int ans = 0;
      for(int i=0;i<n;i++){
        ans+=min(l_max[i],r_max[i])-height[i];
      }
      return ans;
    }
};
int main(){
  Solution solution;
  vector<int> height1{0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int> height2{4,2,0,3,2,5};

  cout << solution.trap(height1) << endl;
  cout << solution.trap(height2) << endl;

  return 0;
}
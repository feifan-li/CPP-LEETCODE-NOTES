#include<iostream>
#include<vector>
using namespace std;
// 双指针法：
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int n = height.size();
        int left = 0, right = n-1;

        int l_max = height[0], r_max = height[n-1];
        int ans = 0;
        while(left<=right){
            l_max = max(l_max,height[left]);
            r_max = max(r_max,height[right]);
            if(l_max<r_max){
                ans+=l_max-height[left];
                ++left;
            }else{
                ans+=r_max-height[right];
                --right;
            }
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
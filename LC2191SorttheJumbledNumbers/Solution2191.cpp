#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution2191 {
public:
    vector<int> myPows = {1, 10, 100, 1000, 10000, 
            100000, 1000000, 10000000, 100000000};
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> shuffleMap;
        unordered_map<int, int> orderMap;
        for(int i = 0; i < nums.size(); ++i){
            if(shuffleMap.find(nums[i])==shuffleMap.end()){
                shuffleMap[nums[i]] = getMappedValue(mapping, nums[i]);
            }
            orderMap[nums[i]] = i;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b){
            return (shuffleMap[a]==shuffleMap[b])?(orderMap[a]<orderMap[b]):(shuffleMap[a]<shuffleMap[b]);
        });
        return nums;
    }
    int getMappedValue(vector<int>& map, int x){
        if(x >= 0 && x <= 9){
            return map[x];
        }
        int mappedVal = 0, significance = 0;
        while(x > 0){
            mappedVal += map[x % 10]*myPows[significance];
            significance ++;
            x = x / 10;
        }
        return mappedVal;
    }
};

int main(){
  Solution2191 s;
  vector<int> mapping1 = {9,8,7,6,5,4,3,2,1,0};
  vector<int> nums1 = {0,1,2,3,4,5,6,7,8,9};
  vector<int> mapping2 = {8,9,4,0,2,1,3,5,7,6};
  vector<int> nums2 = {991,338,38};
  vector<int> mapping3 = {0,1,2,3,4,5,6,7,8,9};
  vector<int> nums3 = {789,456,123};
  s.sortJumbled(mapping1, nums1);
  for(int num : nums1){
    cout << num << " ";
  }
  cout << endl;
  s.sortJumbled(mapping2, nums2);
  for(int num : nums2){
    cout << num << " ";
  }
  cout << endl;
  s.sortJumbled(mapping3, nums3);
  for(int num : nums3){
    cout << num << " ";
  }
  cout << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution1636 {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> freq(201,0);
        for(int num : nums){
            freq[num+100]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b){
            return freq[a+100]==freq[b+100]?b<a:freq[a+100]<freq[b+100];
        });
        return nums;
    }
};
int main(int argc, char** argv){
  Solution1636 s;
  vector<int> nums1 = {1,1,2,2,2,3};
  vector<int> nums2 = {2,3,1,3,2};
  vector<int> nums3 = {-1,1,-6,4,5,-6,1,4,1};
  s.frequencySort(nums1);
  s.frequencySort(nums2);
  s.frequencySort(nums3);
  for(int num : nums1){
    cout << num << " ";
  }
  cout << endl;
    for(int num : nums2){
    cout << num << " ";
  }
  cout << endl;
    for(int num : nums3){
    cout << num << " ";
  }
  cout << endl;
}
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        if(n <= 4){
            return 0;
        }
        sort(nums.begin(),nums.end());
        //choice 1:
        int c1 = nums.at(n-1)-nums.at(3);
        ans = (c1<ans)?c1:ans;
        //choice 2:
        c1 = nums.at(n-2) - nums.at(2);
        ans = (c1<ans)?c1:ans;
        //choice 3:
        c1 = nums.at(n-3) - nums.at(1);
        ans = (c1<ans)?c1:ans;
        //choice 4:
        c1 = nums.at(n-4) - nums.at(0);
        ans = (c1<ans)?c1:ans; 
        return ans;
    }
};
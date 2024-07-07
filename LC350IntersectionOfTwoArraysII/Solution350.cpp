class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int cnt1[1001] = {0};
        int cnt2[1001] = {0};
        for(int x:nums1){
            cnt1[x]++;
        }
        for(int x:nums2){
            cnt2[x]++;
        }
        for(int i=0;i<=1000;++i){
            if(cnt1[i]==0 || cnt2[i]==0){
                continue;
            }
            int cnt = cnt1[i]<=cnt2[i]?cnt1[i]:cnt2[i];
            while(cnt>0){
                ans.push_back(i);
                cnt--;
            }
        }
        return ans;
    }
};
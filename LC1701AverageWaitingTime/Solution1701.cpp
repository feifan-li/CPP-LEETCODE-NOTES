class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int cur_order_finish_time = 0;
        double ans = 0.0;
        int n = customers.size();
        for(int i=0; i<n; ++i){
            if(cur_order_finish_time <= customers[i][0]){
                cur_order_finish_time = customers[i][0] + customers[i][1];
            }else{
                cur_order_finish_time += customers[i][1];
            }
            ans = (ans*i + cur_order_finish_time - customers[i][0])/(i+1);
        }
        return ans;
    }
};
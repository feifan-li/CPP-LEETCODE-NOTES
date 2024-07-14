class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ids(n);
        for(int i = 0; i < n; ++i){
            ids[i] = i;
        }
        sort(ids.begin(), ids.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });
        // all robots are now sorted by their positions in ascending order
        deque<int> stack; // stack of robots' ids
        vector<int> survivals;  // survivals' ids
        for(int i : ids){
            if(directions[i]=='R'){
                stack.push_back(i);
                continue;
            }
            if(stack.empty()){
                survivals.push_back(i);
                continue;
            }
            int rightMoving = stack.back();
            stack.pop_back();
            if(healths[rightMoving] > healths[i]){
                healths[rightMoving]--;
                if(healths[rightMoving] > 0){
                    stack.push_back(rightMoving);
                }
            }else if(healths[rightMoving] == healths[i]){
                continue;
            }else{
                healths[i] --;
                while(!stack.empty() && healths[i]>0){
                    rightMoving = stack.back();
                    stack.pop_back();
                    if(healths[rightMoving] > healths[i]){
                        healths[i] = 0;
                        healths[rightMoving]--;
                        if(healths[rightMoving] > 0){
                            stack.push_back(rightMoving);
                        }
                    }else if(healths[rightMoving] == healths[i]){
                        healths[i] = 0;
                    }else{
                        healths[i] --;
                    }
                }
                if(healths[i]>0 && stack.empty()){
                    survivals.push_back(i);
                }
            }
        }
        while(!stack.empty()){
            survivals.push_back(stack.back());
            stack.pop_back();
        }
        //sort all the survivals by their ids
        sort(survivals.begin(), survivals.end());
        vector<int> ans(survivals.size());
        for(int i=0;i<survivals.size();++i){
            ans[i] = healths[survivals[i]];
        }
        return ans;
    }
};
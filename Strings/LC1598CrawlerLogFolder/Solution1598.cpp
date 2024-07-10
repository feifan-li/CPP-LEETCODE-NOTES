class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for(string log: logs){
            if(log.find("../")==0){
                level = (level-1>=0)?(level-1):0;
            }else if(log.find("./")==0){
                continue;
            }else{
                //the child folder is guaranteed to always exist
                level ++;
            }
        }
        return level;
    }
};
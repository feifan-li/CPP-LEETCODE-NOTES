class Solution {
public:
    int maximumGain(string s, int x, int y) {
        //remove more valueble type of strings first
        //then remove the other type of strings
        int ans = 0;
        if(x <= y){
            string s1 = removeBA(s);
            ans += y*(s.size()-s1.size())/2;
            string s2 = removeAB(s1);
            ans += x*(s1.size()-s2.size())/2;
        }else{
            string s1 = removeAB(s);
            ans += x*(s.size()-s1.size())/2;
            string s2 = removeBA(s1);
            ans += y*(s1.size()-s2.size())/2;
        }
        return ans;
    }
private:
    string removeAB(string s){
        deque<char> stack;
        for(int i=0;i<s.size();++i){
            if(!stack.empty() && stack.back()=='a' && s.at(i)=='b'){
                stack.pop_back();
                continue;
            }else{
                stack.push_back(s.at(i));
            }
        }
        string ans(stack.begin(),stack.end());
        return ans;
    }
    string removeBA(string s){
        deque<char> stack;
        for(int i=0;i<s.size();++i){
            if(!stack.empty() && stack.back()=='b' && s.at(i)=='a'){
                stack.pop_back();
                continue;
            }else{
                stack.push_back(s.at(i));
            }
        }
        string ans(stack.begin(),stack.end());
        return ans;
    }
};
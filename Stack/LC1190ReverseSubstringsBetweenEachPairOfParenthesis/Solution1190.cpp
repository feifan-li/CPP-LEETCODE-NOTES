class Solution {
public:
    string reverseParentheses(string s) {
        s.insert(0,"(");
        s.append(")");
        string ans = reverseBracketedParentheses(s);
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    string reverseBracketedParentheses(string s){
        deque<char> stack;
        queue<char> queue;
        int i = 0, n = s.size();
        while(i<n){
            if(s.at(i)!=')'){
                stack.push_back(s.at(i));
            }else{
                while(stack.size()>0 && stack.back()!='('){
                    char c = stack.back();
                    stack.pop_back();
                    queue.push(c);
                }
                stack.pop_back();
                while(queue.size()>0){
                    char c = queue.front();
                    queue.pop();
                    stack.push_back(c);
                }
            }
            i++;
        }
        // string ans = "";
        // while(stack.size()>0){
        //     char c = stack.front();
        //     stack.pop_front();
        //     ans.append(string(1,c));
        // }
        string ans(stack.begin(), stack.end());
        stack.clear();
        return ans;
    }
};
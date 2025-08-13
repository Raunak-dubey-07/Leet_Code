class Solution {

public:
    bool checkValidString(string s) {
         int n = s.size();
        stack<int>st1;
        stack<int>st2;

        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == '(')
            st1.push(i);

            else if(s[i] == ')')
            {
                if(st1.empty() && st2.empty())
                return false;

                if(!st1.empty())
                st1.pop();

                else if(!st2.empty())
                st2.pop();
            }
            else st2.push(i);
        }
        while(!st1.empty() && !st2.empty())
        {
            if(st2.top() < st1.top())
            return false;

            st1.pop();
            st2.pop();
        }

        return st1.empty();
    }
};
class Solution {
public:
    bool parseBoolExpr(string expre) {
        stack<int>s;
        stack<char>sy;
        for(int i=0;i<expre.size();i++)
        {
            if(expre[i]=='f')
            s.push(0);
            else if(expre[i]=='t')
            s.push(1);
            else if(expre[i]=='&'||expre[i]=='|'||expre[i]=='!')
            sy.push(expre[i]);
            else if(expre[i]=='(')
            s.push(2);
            else if(expre[i]==')')
            {
                if(sy.top()=='&')
                {
                    int k=s.top();
                    s.pop();
                    while(!s.empty()&&s.top()!=2)
                    {
                        k=k&s.top();
                        s.pop();
                    }
                    if(!s.empty()&&s.top()==2)
                    s.pop();
                    s.push(k);
                }
                else if(sy.top()=='|'){
                    int k=s.top();
                    s.pop();
                    while(!s.empty()&&s.top()!=2)
                    {
                        k=k|s.top();
                        s.pop();
                    }if(!s.empty()&&s.top()==2)
                    s.pop();
                    s.push(k);
                }
                else{
                    int k=s.top();
                    s.pop();
                    k=k?0:1;
                    if (!s.empty() && s.top() == 2)
                        s.pop();
                    s.push(k);
                }
                sy.pop();
            }
        }
        return s.top()?true:false;
    }
};
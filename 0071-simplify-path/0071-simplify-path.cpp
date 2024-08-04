class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st; // Stack to keep track of directory names
        string res; // Resultant simplified path
        
        for(int i = 0;  i < path.size(); ++i) {
            if(path[i] == '/')    
                continue; // Skip multiple slashes
            
            string temp; // Temporary string to store the current directory name
            while(i < path.size() && path[i] != '/') {
                temp += path[i];
                ++i;
            }
            
            if(temp == ".") {
                // Current directory, so do nothing
                continue;
            } else if(temp == "..") {
                // Parent directory, so pop from the stack if not empty
                if(!st.empty())
                    st.pop();
            } else {
                // Regular directory name, push it onto the stack
                st.push(temp);
            }
        }
        
        // Construct the simplified path from the stack
        while(!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        // If the resultant path is empty, it means the root directory
        if(res.empty())
            return "/";
        
        return res;
    }
};

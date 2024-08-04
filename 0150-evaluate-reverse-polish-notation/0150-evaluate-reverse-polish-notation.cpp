static unordered_set<string> operations({"+", "-", "*", "/"});

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        
        for (auto t : tokens) {
            if (operations.find(t) == operations.end()) {
                // If the token is not an operation, convert it to an integer and push it onto the stack
                stack.push(stoi(t));
            } else {
                // If the token is an operation, pop the top two elements from the stack
                int b = stack.top(); 
                stack.pop();
                int a = stack.top(); 
                stack.pop();                
                // Perform the operation and push the result back onto the stack
                if (t == "+") stack.push(a + b);
                else if (t == "-") stack.push(a - b);
                else if (t == "*") stack.push(a * b);
                else stack.push(a / b);
            }
        }     
        // The result of the expression is the only element left in the stack
        return stack.top();
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int i = 0;
        int n = tokens.size();
        unordered_map<std::string, int> mp = {{"/", 1}, {"+", 1}, {"-", 1}, 
        {"*", 1}};

        while(i < n){
            string temp = tokens[i];
            if (mp.find(temp) == mp.end()){
                st.push(stoi(temp));
            }else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (temp == "+") st.push(a + b);
                if (temp == "-") st.push(b-a);
                if (temp == "/") st.push(b/a);
                if (temp == "*") st.push(a*b);
            }
            i++;
        }
        return st.top();
    }
};
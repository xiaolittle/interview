class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        int n = tokens.size();
        int i = 0;
        while(i < n) {
            if(tokens[i].size() != 1 || (tokens[i][0] != '+' && tokens[i][0] != '-' &&
                tokens[i][0] != '*' && tokens[i][0] != '/')) {
                    int m = tokens[i].size();
                    int res = 0;
                    int flag = 1;
                    int j = 0;
                    if(tokens[i][0] == '-') {
                        flag = -1;
                        ++j;
                    }
                    for(; j < m; ++j) {
                        res *= 10;
                        res += tokens[i][j] - '0';
                    }
                    st.push(flag * res);
                } else {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    switch(tokens[i][0]) {
                        case '+':
                        st.push(a + b);
                        break;
                        case '-':
                        st.push(a - b);
                        break;
                        case '*':
                        st.push(a * b);
                        break;
                        case '/':
                        st.push(a / b);
                        break;
                    }
                }
                ++i;
        }
        return st.top();
    }
};

const int N = 4;
const char STARTCHAR = '0';
const char ENDCHAR = '9';
const string STARTKEY(N,STARTCHAR);
const string ENDKEY(N,ENDCHAR);

void addOne(string &digits) 
{
    int size = digits.size();
    if(digits[size-1] != ENDCHAR)
        digits[size-1]++;
    else
    {
        int current = size-1;
        while(true)
        {
            if(digits[current] == ENDCHAR)
            {
                digits[current] = STARTCHAR;
                current --;
            }
            else
            {
                digits[current]++;
                break;
            }
            if(current == -1)
            {
                auto it = digits.begin();
                char temp = STARTCHAR + 1;
                digits = temp + digits;
                break;
            }
        }
    }
}

string good()
{
    string s = STARTKEY;
    string i = STARTKEY;
    string end = ENDKEY;
    addOne(i);
    for(; i != ENDKEY; addOne(i))
    {
        if(s.find(i) != -1)
            continue;
        int len = s.length();
        for(int j=N-1; j>=0; j--)
        {
            if(i.find(s.substr(len-j)) == 0)
            {
                s.append(i.substr(j));
                break;
            }
        }
    }
    string temp = end.substr(N-1);
    s.insert(s.find_last_of(end),temp);
    s.shrink_to_fit();
    return s;
}

int main()
{
    good();
    return 0;
}

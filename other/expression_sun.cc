clude <stack>
using namespace std;
int calc(const char * exp)
{
  int ret = 0;
  stack<char> opstack;
  stack<int> numstack;
  for (int ii=0; ii<strlen(exp); ++ii)
  {
    if (exp[ii] == '*' || exp[ii] == '+')
    {
      opstack.push(exp[ii]);
    }
    else 
    {
      int num = exp[ii] - '0';
      if (opstack.empty())
      {
        numstack.push(num);
      }
      else
      {
        if (opstack.top() == '*')
        {
          numstack.top() *= num;
          opstack.pop();
        }
        else
        {
          numstack.push(num);
        }
      }
    }
  }
  while (!numstack.empty())
  {
    ret += numstack.top();
    numstack.pop();
  }
  return  ret;
}


int _tmain(int argc, _TCHAR* argv[])
{
  const char * exp = "5+4*5+5*1+9";
  cout << calc(exp) << endl;
    return 0;
}

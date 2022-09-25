#include <iostream>
#include <string>
using namespace std;

int calculate(string s,int left,int right)
{
    int L = left, R = right;
    while(L>=0&&R<s.length()&&s[L]==s[R])
    {
        //计算以left和rigth为中心的回文串长度
        L--;
        R++;
    }
    return R-L-1;
}
int main() {
    string s;
    cin>>s;
    int n = s.length();
    if(n<1)
        cout<<s;
    int start = 0, end =0;
    for(int i=0;i<n;i++)
    {
        int lengths1 = calculate(s ,i,i);
        int lengths2 = calculate(s,i,i+1);
        int len = max(lengths1,lengths2);
        if(len > end -start)
        {
            start = i - (len -1)/2;
            end = i + len /2;
        }
    }
    cout << s.substr(start,end-start+1);
    return 0;
}

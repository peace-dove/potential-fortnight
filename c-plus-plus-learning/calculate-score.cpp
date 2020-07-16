#include <bits/stdc++.h>

using namespace std;
stack<int> s;
int main()
{
    char input[10],ch;
    int m=0;
    while((ch=getchar())!='\n')
    {
        if(ch!=' ')
            input[m++]=ch;
    }
    for(int i=0; i<m; i++)
    {
        if(input[i]>='0'&&input[i]<='9')
            s.push(input[i]-'0');
        else if(input[i]=='+')
        {
            int top=s.top();
            s.pop();
            int sum=top+s.top();
            s.push(top);

            s.push(sum);
        }
        else if(input[i]=='D')
        {
            int sum=0;
            sum=2*s.top();
            s.push(sum);
        }
        else
            s.pop();
    }
    int sum=0;
    while(!s.empty())
    {
        sum+=s.top();
        s.pop();
    }
    printf("The score is %d.\n",sum);
    return 0;
}

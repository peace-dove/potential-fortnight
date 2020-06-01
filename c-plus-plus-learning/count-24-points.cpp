//input 4 numbers like 2 3 4 5 and is this can be counted to 24 point it will output Yes
//if not it will output No
//to end the procedure just input 0 0 0 0
#include<iostream>
#include<cmath>
#include<string.h>
#define EPS 1e-6
using namespace std;

double a[5];

bool iszero(double x)
{
    return fabs(x)<=EPS;
}
bool count24(double a[],int n)
{
    if(n==1)
        if(iszero(a[0]-24))
            return true;
        else
            return false;
    else
    {
        double b[5]= {0};
        for(int i=0; i<n-1; ++i)
            for(int j=i+1; j<n; ++j)
            {
                int m=0;
                for(int k=0; k<n; ++k)
                {
                    if((k!=i)&&(k!=j))
                        b[m++]=a[k];
                }
                b[m]=a[i]+a[j];
                if(count24(b,n-1))
                    return true;

                b[m]=a[i]-a[j];
                if(count24(b,n-1))
                    return true;

                b[m]=a[j]-a[i];
                if(count24(b,n-1))
                    return true;

                b[m]=a[i]*a[j];
                if(count24(b,n-1))
                    return true;

                if(a[j]!=0)
                {
                    b[m]=a[i]/a[j];
                    if(count24(b,n-1))
                        return true;
                }

                if(a[i]!=0)
                {
                    b[m]=a[j]/a[i];
                    if(count24(b,n-1))
                        return true;
                }
            }
    }
    return false;
}
bool judge(double a[],int n)
{
    int cnt=0;
    for(int i=0; i<n; ++i)
        if(iszero(a[i]))
            cnt++;
    if(cnt==n)
        return false;
    else
        return true;
}
/*int main()
{
    for(int i=0; i<4; ++i)
        cin>>a[i];
    while(judge(a,4))
    {
        if(count24(a,4))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
      for(int i=0; i<4; ++i)
        cin>>a[i];
    }

    return 0;
}*/
int main()
{
    while(true)
    {
        bool isend=true;
        for(int i=0; i<4; ++i)
        {
            cin>>a[i];
            if(!iszero(a[i]))
                isend=false;
        }
        if(isend)
            break;
        if(count24(a,4))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    return 0;
}

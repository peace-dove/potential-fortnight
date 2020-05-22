/*#include <bits/stdc++.h>

using namespace std;
int cols,rows,kx,ky,hx,hy;
int minsteps=10000000;
char chess[152][152];
bool visited[152][152];
bool cango[152][152];
int steps[152][152];

int dir[8][2]=
{
    {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}
};

struct node
{
    int x,y;
};

bool check(int i,int j)
{
    if(i>=1&&i<=cols&&j>=1&&j<=rows&&cango[i][j]&&!visited[i][j])
        return true;
    return false;
}

int bfs()
{
    queue<node> q;
    node start,next,target;
    start.x=kx,start.y=ky;
    target.x=hx,target.y=hy;


    steps[start.x][start.y]=0;

    q.push(start);
    while(!q.empty())
    {
        start=q.front();
        q.pop();

        for(int i=0; i<8; i++)
        {
            next.x=start.x+dir[i][0];
            next.y=start.y+dir[i][1];


            if(check(next.x,next.y))
            {
                /*if(next.x==target.x&&next.y==target.y)
                {
                    steps[next.x][next.y]=steps[start.x][start.y]+1;
                    minsteps=min(minsteps,steps[next.x][next.y]);
                    //continue;
                    cout<<minsteps<<endl;
                }
                else**
                {
                    visited[next.x][next.y]=true;

                    steps[next.x][next.y]=steps[start.x][start.y]+1;
                    //cout<<steps[next.x][next.y]<<' '<<next.x<<' '<<next.y<<endl;
                    q.push(next);

                    if(next.x==target.x&&next.y==target.y)
                    {
                        return steps[next.x][next.y];
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
    cin>>cols>>rows;
    for(int j=rows; j>=1; j--)
        for(int i=1; i<=cols; i++)
        {
            cin>>chess[i][j];
            if(chess[i][j]=='K')
            {
                kx=i;
                ky=j;
                visited[i][j]=true;
                cango[i][j]=false;
            }
            if(chess[i][j]=='H')
            {
                hx=i;
                hy=j;
                cango[i][j]=true;
            }
            if(chess[i][j]=='.')
                cango[i][j]=true;
            if(chess[i][j]=='*')
                cango[i][j]=false;
        }
    int res=bfs();
    cout<<res<<endl;
    return 0;
}
*/



#include <bits/stdc++.h>

using namespace std;
int cols,rows,kx,ky,hx,hy;
int minsteps=10000000;
char chess[152][152];
bool visited[152][152];
bool cango[152][152];
int steps[152][152];

int dir[8][2]=
{
    {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}
};

struct node
{
    int x,y;
};

bool check(int i,int j)
{
    if(i>=1&&i<=cols&&j>=1&&j<=rows&&cango[i][j]&&!visited[i][j])
        return true;
    return false;
}

int bfs()
{
    queue<node> q;
    node start,next,target;
    start.x=kx,start.y=ky;
    target.x=hx,target.y=hy;


    steps[start.x][start.y]=0;

    q.push(start);
    while(!q.empty())
    {
        start=q.front();
        q.pop();

        for(int i=0; i<8; i++)
        {
            next.x=start.x+dir[i][0];
            next.y=start.y+dir[i][1];


            if(check(next.x,next.y))
            {
                if(next.x==target.x&&next.y==target.y)
                {
                    steps[next.x][next.y]=steps[start.x][start.y]+1;
                    minsteps=min(minsteps,steps[next.x][next.y]);
                    //continue;
                    return minsteps;
                }
                else
                {
                    visited[next.x][next.y]=true;

                    steps[next.x][next.y]=steps[start.x][start.y]+1;
                    //cout<<steps[next.x][next.y]<<' '<<next.x<<' '<<next.y<<endl;
                    q.push(next);

                }
            }
        }
    }
    return 0;
}
int main()
{
    cin>>cols>>rows;
    for(int j=rows; j>=1; j--)
        for(int i=1; i<=cols; i++)
        {
            cin>>chess[i][j];
            if(chess[i][j]=='K')
            {
                kx=i;
                ky=j;
                visited[i][j]=true;
                cango[i][j]=false;
            }
            if(chess[i][j]=='H')
            {
                hx=i;
                hy=j;
                cango[i][j]=true;
            }
            if(chess[i][j]=='.')
                cango[i][j]=true;
            if(chess[i][j]=='*')
                cango[i][j]=false;
        }
    int res=bfs();
    cout<<res<<endl;
    return 0;
}


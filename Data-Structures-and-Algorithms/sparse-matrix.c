//wait for a moment
#include <stdio.h>
#include <stdlib.h>

#define maxsize 100
#define maxrc 30
typedef struct
{
    int i,j;
    int e;
} Triple;

typedef struct matrix
{
    Triple data[maxsize+1];
    int rpos[maxrc+1];
    int mu,nu,tu;
} TSMatrix;

void creat(TSMatrix *M)
{
    for(int i=0; i<maxrc; i++)
        M->rpos[i]=0;

    scanf("%d %d %d",&M->mu,&M->nu,&M->tu);

    for(int i=1; i<=M->tu; i++)
        scanf("%d %d %d",&M->data[i].i,&M->data[i].j,&M->data[i].e);
    for(int i=1,j=1; i<=M->mu; i++)
    {
        M->rpos[i]=j;
        while(M->data[j].i<=i&&j<=M->tu)
            j++;
    }
}
int comp(int a,int b)
{
    if(a<b)
        return 1;
    else if(a==b)
        return 0;
    else
        return 1;
}
TSMatrix add(TSMatrix M,TSMatrix N)
{
    TSMatrix Q;
    for(int i=0; i<maxrc; i++)
        Q.rpos[i]=0;
    if(M.mu!=N.mu||M.nu!=N.nu)
        return Q;

    Q.mu=M.mu;
    Q.nu=M.nu;
    Q.tu=0;

    int m=1,n=1,q=0;
    while(m<=M.tu&&n<=N.tu)
    {
        switch(comp(M.data[m].i,N.data[n].i))
        {
        case -1:
        {
            q++;
            Q.data[q].i=M.data[m].i;
            Q.data[q].j=M.data[m].j;
            Q.data[q].e=M.data[m].e;
            m++;
            break;
        }
        case 0:
        {
            switch(comp(M.data[m].j,N.data[n].j))
            {
            case -1:
            {
                q++;
                Q.data[q].i=M.data[m].i;
                Q.data[q].j=M.data[m].j;
                Q.data[q].e=M.data[m].e;
                m++;
                break;
            }
            case 1:
            {
                q++;
                Q.data[q].i=N.data[n].i;
                Q.data[q].j=N.data[n].j;
                Q.data[q].e=N.data[n].e;
                n++;
                break;
            }
            case 0:
                if(M.data[m].e+N.data[n].e)
                {
                    q++;
                    Q.data[q].e=M.data[m].e+N.data[n].e;
                    Q.data[q].i=M.data[m].i;
                    Q.data[q].j=M.data[m].j;
                }
                m++,n++;
                break;
            }
            break;
        }
        case 1:
        {
            q++;
            Q.data[q].i=N.data[n].i;
            Q.data[q].j=N.data[n].j;
            Q.data[q].e=N.data[n].e;
            n++;
            break;
        }
        }
    }
    while(m<=M.tu)
    {
        q++;
        Q.data[q].i=M.data[m].i;
        Q.data[q].j=M.data[m].j;
        Q.data[q].e=M.data[m].e;
        m++;
    }
    while(n<=N.tu)
    {
        q++;
        Q.data[q].i=N.data[n].i;
        Q.data[q].j=N.data[n].j;
        Q.data[q].e=N.data[n].e;
        n++;
    }
    Q.tu=q;
    return Q;
}
TSMatrix sub(TSMatrix M,TSMatrix N)
{
    TSMatrix Q;
    for(int i=1; i<=N.tu; i++)
    {
        N.data[i].e*=(-1);
    }
    Q=add(M,N);
    return Q;
}
TSMatrix mul(TSMatrix M,TSMatrix N)
{
    TSMatrix Q;
    if(M.nu!=N.mu)
        return Q;
    Q.mu=M.mu;
    Q.nu=N.nu;
    Q.tu=0;

    if(M.tu*N.tu)
    {
        int arow,ccol,tp,brow,p,q,t;
        int ctemp[21];
        for(arow=1; arow<=M.mu; arow++)
        {
            for(ccol=1; ccol<=N.nu; ccol++)
                ctemp[ccol]=0;

            Q.rpos[arow]=Q.tu+1;

            if(arow<M.mu)
                tp=M.rpos[arow+1];
            else
                tp=M.tu+1;

            for(p=M.rpos[arow]; p<tp; p++)
            {
                brow=M.data[p].j;
                if(brow<N.mu)
                    t=N.rpos[brow+1];
                else
                    t=N.tu+1;

                for(q=N.rpos[brow]; q<t; q++)
                {
                    ccol=N.data[q].j;
                    ctemp[ccol]+=M.data[p].e*N.data[q].e;
                }

            }
            for(ccol=1; ccol<=Q.nu; ccol++)
            {
                if(ctemp[ccol])
                {
                    Q.tu++;
                    if(Q.tu>maxsize)
                        return Q;
                    Q.data[Q.tu].i=arow;
                    Q.data[Q.tu].j=ccol;
                    Q.data[Q.tu].e=ctemp[ccol];
                }
            }

        }
    }
    return Q;
}
void print(TSMatrix M)
{
    int k=1;

    for(int i=1; i<=M.mu; i++)
    {
        for(int j=1; j<=M.nu; j++)
            if(k<=M.tu&&M.data[k].i==i&&M.data[k].j==j)
            {
                printf("%d ",M.data[k].e);
                k++;
            }
            else
                printf("0 ");
        printf("\n");
    }
    return;
}
int main()
{
    TSMatrix a,b,c,d,e;
    creat(&a);
    creat(&b);
    printf("\n");
    print(a);
    printf("\n");
    print(b);
    printf("\n");

    //c=add(a,b);
    //d=sub(a,b);
    e=mul(a,b);

    printf("\n");
    //print(c);
    printf("\n");
    //print(d);
    printf("\n");
    print(e);
    return 0;
}

/*test 1
3 3 3
1 1 1
2 2 1
3 2 1
3 3 3
1 1 1
2 2 1
3 2 1
*/

/*test 2
3 4 4
1 1 3
1 4 5
2 2 -1
3 1 2
4 2 4
1 2 2
2 1 1
3 1 -2
3 2 4
*/

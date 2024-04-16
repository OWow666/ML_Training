#include<iostream>
using namespace std;

const double alpha=0.01;

double x[1000],y[1000];
int m;

int main()
{
    cin>>m;
    for(int i=1;i<=m;i++) cin>>x[i]>>y[i];

    double w=0,b=0; // start from (0,0)
    for(int iter=1;iter<=1000;iter++)
    {
        // Gradient Descent
        double tmpw=0,tmpb=0;
        for(int i=1;i<=m;i++)
        {
            double error=w*x[i]+b-y[i];
            tmpw+=error*x[i];
            tmpb+=error;
        }
        tmpw/=m;
        tmpb/=m;
        w-=alpha*tmpw;
        b-=alpha*tmpb;

        if(iter%100==0) cout<<"Iteration:"<<iter<<' '<<"w:"<<w<<' '<<"b:"<<b<<endl;
    }

    return 0;
}
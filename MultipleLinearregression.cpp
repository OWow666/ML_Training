#include<iostream>
#include<fstream>
using namespace std;

const double alpha = 0.01;
const int total_num = 100;

double x1[105],x2[105],y[105];
int m;
int main()
{
    ifstream fin("MLG_data.txt");
    double A,B,C;
    int cnt = 0;
    while(fin>>A>>B>>C)
    {
        if(cnt>=total_num)
        {
            cout<<"Finish reading."<<endl;
            break;
        }
        x1[++cnt] = A;
        x2[cnt] = B;
        y[cnt] = C;
    }
    fin.close();

    double w1=0,w2=0,b=0; // Start from (0,0,0)

    for(int iter=1;iter<=1000;iter++)
    {
        // Gradient Descent
        double tmpw1=0,tmpw2=0,tmpb=0;
        for(int i=1;i<=total_num;i++)
        {
            double error = w1*x1[i]+w2*x2[i]+b-y[i];
            tmpw1 += error*x1[i];
            tmpw2 += error*x2[i];
            tmpb += error;
        }
        tmpw1 /= total_num;
        tmpw2 /= total_num;
        tmpb /= total_num;

        w1 -= alpha*tmpw1;
        w2 -= alpha*tmpw2;
        b -= alpha*tmpb;

        if(iter%100==0) cout<<"Iteration:"<<iter<<' '<<"w1:"<<w1<<' '<<"w2:"<<w2<<' '<<"b:"<<b<<endl;
    }

    return 0;
}
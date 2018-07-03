#include <bits/stdc++.h>
#define MAX 2000001
using namespace std;
int lpf[MAX];
void lowest_prime_factor()
{
    for(int i=0;i<MAX;i++)
        lpf[i]=i;
    for(int i=2;i<MAX;i++)
    {
        if(lpf[i]==i)
        {
            for(int j=2*i;j<MAX;j+=i)
            {
                if(lpf[j]==j)
                    lpf[j]=i;
            }
        }
    }
/*     for(int i=0;i<MAX;i++)
 *         cout<<lpf[i]<<endl;
 */
}
int solve(int n)
{
    bool arr[n+1];
    for(int i=1;i<n+1;i++)
        arr[i]=false;
    int k=n;
    vector<int> v;


    while(k)
    {   int temp=k;
        int l=0;
        if(arr[k]==false)
        {   while(temp!=1)
            {int t=k;
            int m=lpf[temp];
            while(t>0)
            {   if(arr[t]!=true)
                {arr[t]=true;
                v.push_back(t);
                l++;}
                t=t-m;}
            while(temp%m==0)
            {
                temp=temp/m;
            }
            }
            sort(v.end()-l,v.end(),greater<int>());



        }
        k--;
    }
    if(arr[1]!=true)
        v.push_back(1);
    for(auto i=v.begin();i!=v.end();i++)
        cout<<*i<<" ";

}
int main()
{
    lowest_prime_factor();
    int n;
    cin>>n;
    solve(n);
}

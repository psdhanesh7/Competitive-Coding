#include <bits/stdc++.h>

using namespace std;
int nodigits(int n)
{
    int count=0;
    while(n>0)
    {
        count++;
        n/=10;
    }
    return count;
}

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    int present=0,dig,nod;
    long int sq,l,r,poften;
    for(long int i=p;i<=q;i++)
    {
        sq=i*i;
        nod=nodigits(i);
        //cout<<nod<<endl;
        poften=pow(10,nod);
        //cout<<poften<<endl;
        r=sq%poften;
        //cout<<r<<endl;
        l=sq/poften;
       // cout<<l<<"\n"<<r<<"\n"<<endl;
        if(l+r==i){
            cout<<i<<" ";
            present=1;
        }
    }
    if(!present)
        cout<<"INVALID RANGE";


}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int fibb(int n){
    //base case two bse cases here
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    //Induction hypothesis here also two
    int ans1 = fibb(n-1);         //time complexity is O(2^n)
    int ans2 = fibb(n-2);
    //induction step
    return ans1 + ans2;
}
int power(int x,int n) //not the best solution
{   //base case
    if(n == 0)
        return 1;           //time complexity is t(n)=n*k ie t(n)=o(n)
                                // space coplexity is o(n)*o(1)
    //induction hypothesis
    int ans = power(x,n-1);
//induction step
    return x*ans;
}
//best solutio for fining power
int power2(int x,int n){        //time complexity is O(log n)
                                //space cocmplexity is O(1)*O(n)=O(n)
    if(n==0)
        return 1;
    int smallAns=power(x,n/2);
    int ans;
    if(n%2==0)
        ans=smallAns*smallAns;
    else
    {
        ans=x*smallAns*smallAns;
    }
    return ans;
    
}
int subsequences(string str,string* output){
    //base case is empty string
    if(str.length()==0){
        output[0]="";
        return 1;//it has one subset which is an empty string
    }
    //induction hypothesis
    int smallsize=subsequences(str.substr(1),output);
    for(int i=0;i<smallsize;i++)
        output[smallsize+i]=str[0]+output[1];
    return 2*smallsize;
}
int fibbdp(int n,int* dp){    //this solution  is memoizastion solution
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int ans1,ans2;
    if(dp[n-1]==-1) /*We are storing all the results in an array and before calling the funcn we are checking if we have already found the ans earlier This is what dynamic programming does */
    {
        ans1=fibbdp(n-1,dp);
        dp[n-1]=ans1;
    }
    else
    {
        ans1=dp[n-1];

    }
    
    if (dp[n-2]==-1)//we have initialised all the elememnts with -1,because -1 will never be a fibonnacci num
    {
        ans2=fibb(n-2,dp);
        dp[n-2]=ans2;
    }
    else
    {
        ans2=dp[n-2];
    }
    
    
}
int fibbi(int n){             //best solution because, in recursion there is a stack that is being developed.and only a maximum of 10000 stacks can be stored at a time.
//this is the best solution for competitive coding
    int* dp=new int[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int minstepsto1(int n){  //there are overlapping subproblems here
    if(n==1)
        return 0;
    int ans1=minstepsto1(n-1)
    int ans2=MAX_VALUE;
    if(n%2==0)
    {
        ans2=minstepsto1(n/2);
    }
    int ans3=MAX_VALUE;
    if(n%3==0)
    {
        ans3=minstepsto1(n/3);
    }
    int ans=1+min(ans1,min(ans2,ans3));
    return ans;

}
int minstepsto1dp(int n,int* dp);
{
    int ans1;
    if(dp[n-1]==-1)
    {
        ans1=minstepsto1dp(n-1,dp);
        dp[n-1]=ans1;
    }
    else
        ans1=dp[n-1];
    int ans2=MAX_VALUE;
    if(dp[n-1]==-1)
    {
        ans2=minstepsto1dp(n/2,dp);
        dp[n-1]=ans2;
    }
    else
        ans2=dp[n-1];
    int 
    
}
int minsqtorepn(int n){
    
    if(n==0)
        return 0;
    int minimum=MAX_VALUE;
    for(int i=1;i*i<=n;i++)
    {
        int ans=minsqtorepn(n-i*i);
        if(minimum<ans)            /*minimum=min(minimum,ans) */
            minimum=ans;
    }
    return 1+minimum;
}
int minsqtorepndp(int n,int* dp)
{
    if(n==0)
        return 0;
    int minimum=n;
    int ans;
    for(int i=1;i*i<=n;i++)               //there are n unique calls;each call has root n operations .so time complexity is n*sqrt(n)
    {
        if(dp[n-i*i]==-1)
        {
            ans=minsqtorepndp(n-i*i,dp);
            dp[n-i*i]=ans;
        }
        else
        {
            ans=dp[n-i*i];
        }
        minimum=min(minimum,ans);
        
    }
    return minimum+1;
}
int lis(int* arr,int n){    //longest increasing subsequences


    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
                maximum=max(maximum,1+dp[j]);
        }   
    }
    dp[i]=maximum;
    //now goto each element of the array and compute the maximum in it
}
//length of longest  bitonic subseqeunce
//fpr that find the longest increasing subsequence as well as longest decreasing subseqence;
//for each index add these two and subtract 1 because that index will be added twice

int main()
{
 //   int fib=power2(2,4);
   // cout<<fib<<endl;
  /*  string str="abc";
   int outputsize=power(2,str.length());
   string* output=new string[outputsize];
   int size=subsequences(str,output);
   //print them
   for(int i=0;i<size;i++)
    cout<<output[i]<<endl;
   delete[] output;*/
   int* dp=new int[5];//n+1
   for(int i=0;i<=n;i++)
        dp[i]=-1;
    cout<<fibbdp(4,dp)<<endl;
   return 0;

}
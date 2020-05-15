#include<iostream>
#include<cstring>
using namespace std;

unsigned long long mod = 1000000007;

void multiply(unsigned long long A[2][2], unsigned long long M[2][2]) {

	// unsigned long long fValue = A[0][0]*M[0][0] + A[0][1]*M[1][0];
	// unsigned long long sValue = A[0][0]*M[0][1] + A[0][1]*M[1][1];
	// unsigned long long tValue = A[1][0]*M[0][0] + A[1][1]*M[1][0];
	// unsigned long long lValue = A[1][0]*M[0][1] + A[1][1]*M[1][1];

	unsigned long long fValue = (A[0][0]*M[0][0] + A[0][1]*M[1][0])%mod;
	unsigned long long sValue = (A[0][0]*M[0][1] + A[0][1]*M[1][1])%mod;
	unsigned long long tValue = (A[1][0]*M[0][0] + A[1][1]*M[1][0])%mod;
	unsigned long long lValue = (A[1][0]*M[0][1] + A[1][1]*M[1][1])%mod;

	A[0][0] = fValue;
	A[0][1] = sValue;
	A[1][0] = tValue;
	A[1][1] = lValue;
}

void power(unsigned long long A[2][2], unsigned long long n) {

	if(n == 0 || n == 1) {
		return ;
	}

	power(A, n/2);

	// multiply A^n/2 with A^n/2
	multiply(A, A);

	if(n%2 == 1) {
		unsigned long long M[2][2] = {{1, 1}, {1, 0}};
		multiply(A, M);
	}
}

long long fib(unsigned long long n) {

	unsigned long long A[2][2] = {{1, 1}, {1, 0}};

	if(n == 0) {
		return 0;
	}

	power(A, n-1);
	return A[0][0]%mod;
}

unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
	// Write your code here
	unsigned long long sm = fib(m+1) - 1;
	unsigned long long sn = fib(n+2) - 1;

	return sn - sm;
}

int main()
{
    unsigned long long m,n;
    cin>>m>>n;
	cout<<fiboSum(m,n);
    return 0;
}
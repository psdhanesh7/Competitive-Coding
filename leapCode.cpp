#include<bits/stdc++.h>
using namespace std;

bool isLeapCode(long n) {
    // cout << n << endl;
    if(n/10 == 0) {
        return true;
    }
    
    bool leapCode = true;
    int last = n%10;
    n /= 10;
    while(n > 0) {
        int d = n%10;
        if((last - d) == 1 || (d - last) == 1) {
            last = d;
            n /= 10;
            continue;
        }
        else {
            leapCode = false;
            break;
        }

        

    }
    return leapCode;
    
}

void printLeapCodes(long n) {

    for(long i = 0; i <= n; i++) {
        // cout << "*" << endl;
        if(isLeapCode(i)) {
            cout << i << " " ;
        }
    }
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        long n;
        cin >> n;

        printLeapCodes(n);
        cout << endl;
    }

    return 0;
}
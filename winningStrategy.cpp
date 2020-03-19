#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n;
    cin >> n;
    bool possible = true;
    int minSwaps = 0;
    
    int *pos = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> pos[i];
    }

    for(int i = 0; i < n; i++)
    {
        pos[i] = pos[i] - (i+1);
        if(pos[i] < -2 || pos[i] > 2)
        {
            possible = false;
            break;
        }
        if(pos[i] > 0)
        {
            minSwaps += pos[i];
        }
    }
    
    if(possible)
    {
        cout << "YES" << endl;
        cout << minSwaps << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    delete [] pos;
    return 0;
}
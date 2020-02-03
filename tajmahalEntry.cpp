#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    
    int *people = new int[n];
    for(int i = 0; i < n; i++){
        cin >> people[i];
    }

    int *times = new int[n];
    for(int i = 0; i < n; i++){

    	int v = (people[i] - i)/n;

    	if((people[i] - i) % n != 0){
    		times[i] = v + 1;
    	}
    	else{
    		times[i] = v;
    	}
    }

    int minTime = INT_MAX;
    int minPos = 0;

    for(int i = 0; i < n; i++){
    	if(times[i] < minTime){
    		minTime = times[i];
    		minPos = i;
    	}
    }

    cout << minPos + 1 << endl;

    delete [] times;
    delete [] people;

	return 0;
}

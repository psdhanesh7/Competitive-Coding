#include<bits/stdc++.h>
using namespace std;

long merge(int *a, int start, int mid, int end){

	int i = start, j = mid, k = 0;
	long sum = 0;

	int *temp = new int[end - start + 1];

	while(i < mid && j <= end){

		if(a[i] < a[j]){

			temp[k++] = a[i++];
			sum += (end - j + 1) * a[i];
		}
		else{
			temp[k++] = a[j++];
		}
	}

	while(i < mid){
		temp[k++] = a[i++];
	}
	while(j <= end){
		temp[k++] = a[j++];
	}

	for(int i = start, k = 0; i <= end; i++, k++){
		a[i] = temp[k];
	}

	delete [] temp;

	return sum;
}

long mergeSort(int *a, int start, int end){

	long sum = 0;
	if(start < end){

		int mid = (start + end)/2;

		long leftAns = mergeSort(a, start, mid);
		long rightAns = mergeSort(a, mid+1, end);
		long currentAns = merge(a, start, mid+1, end);

		cout << leftAns << " " << rightAns << " " << currentAns << endl;

		sum = leftAns + rightAns + currentAns;
	}

	return sum;
}

int main(){

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		int *arr = new int[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		long ans = mergeSort(arr, 0, n-1);

		cout << ans << endl;

		delete [] arr;
	}

	return 0;
}
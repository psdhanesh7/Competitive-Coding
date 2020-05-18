#include<iostream>
using namespace std;

// void sort(int *ar, int n) {

// 	int forward = 0;
// 	int backward = n-1;

// 	while(forward < backward) {
// 		if(ar[forward] == 1) {
// 			int temp = ar[forward];
// 			ar[forward] = ar[backward];
// 			ar[backward] = ar[forward];
// 			backward--;
// 		}
// 		else {
// 			forward++;
// 		}
// 	}
// }

void sort(int *arr, int n) {

	int forward = 0;
	int backward = n-1;

	for(int i = 0; i < n; i++) {
		if(arr[forward] == 1 && )
	}
}

int main() {

	int n;
	cin >> n;

	int arr[] = new int[n];
	for(int i = 0; i < n; i++)  {
		cin >> arr[i];
	}

	sort(arr, n);

	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}
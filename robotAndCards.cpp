#include<bits/stdc++.h>
using namespace std;

#define cards 13

int main() {

	string s;
	cin >> s;

	bool deck1[cards];
	bool deck2[cards];
	bool deck3[cards];
	bool deck4[cards];


	for(int i = 0; i < cards; i++) {
		deck1[i] = false;
		deck2[i] = false;
		deck3[i] = false;
		deck4[i] = false;
	}

	int no;
	int a = true;
	for(int i = 0; i < s.length() && a; i++) {
		switch(s[i]) {
			case 'P' : 	no = (s[i+1] - '0') * 10 + (s[i+2] - '0');
						if(deck1[no-1] == true) {
							cout << "ERROR" << endl;
							a = false;
							break;
							
						}
						else {
							deck1[no-1] = true;
							break;
						}
			case 'K' : 	no = (s[i+1] - '0') * 10 + (s[i+2] - '0');
						if(deck2[no-1] == true) {
							cout << "ERROR" << endl;
			
							a = false;
							break;
						}
						else {
							deck2[no-1] = true;
							break;
						}
			case 'H' : 	no = (s[i+1] - '0') * 10 + (s[i+2] - '0');
						if(deck3[no-1] == true) {
							cout << "ERROR" << endl;
							
							a = false;
							break;
						}
						else {
							deck3[no-1] = true;
							break;
						}
			case 'T' : 	no = (s[i+1] - '0') * 10 + (s[i+2] - '0');
						if(deck4[no-1] == true) {
							cout << "ERROR" << endl;
							
							a = false;
							break;
						}
						else {
							deck4[no-1] = true;
							break;
						}
		}
	}

	if(a) {
		int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
		for(int i = 0; i < cards; i++) {
			if(deck1[i] == false) {
				count1++;
			}
			if(deck2[i] == false) {
				count2++;
			}
			if(deck3[i] == false) {
				count3++;
			}
			if(deck4[i] == false) {
				count4++;
			}
		}

		cout << count1 << " " << count2 << " " << count3 << " " << count4 << endl;
	}

	
}

// P01K02H03H04

#include<bits/stdc++.h>
using namespace std;

#define n 10

bool isValidVertical(char crossword[][n], string word, int row, int col){

	int i;
	for(i = 0; i < word.length() && row < n; i++){

		if(crossword[row][col] == '-' || crossword[row][col] == word[i]){
			row++;
			continue;
		}
		else{
			return false;
		}

	}

	if(i < word.length()){
		return false;
	}
	return true;
}

bool isValidHorizontal(char crossword[][n], string word, int row, int col){

	int i;
	for(i = 0; i < word.length() && col < n; i++){
		if(crossword[row][col] == '-' || crossword[row][col] == word[i])
		{
			col++;
			continue;
		}
		else{
			return false;
		}
	}
	if(i < word.length()){
		return false;
	}
	return true;
}

void setVertical(char crossword[][n], string word, int row, int col, bool *helper){

	for(int i = 0; i < word.length(); i++){

		if(crossword[row][col] == '-'){
			crossword[row][col] = word[i];
			helper[i] = true;
		}
		else{
			helper[i] = false;
		}

		row++;
	}
}

void setHorizontal(char crossword[][n], string word, int row, int col, bool *helper){

	for(int i = 0; i < word.length(); i++){

		if(crossword[row][col] == '-'){
			crossword[row][col] = word[i];
			helper[i] = true;
		}
		else{
			helper[i] = false;
		}

		col++;
	}
}

void resetVertical(char crossword[][n], string word, int row, int col, bool *helper){
	
	for(int i = 0; i < word.length(); i++){
		if(helper[i]){
			crossword[row][col] = '-';
			helper[i] = false;
		}
		row++;
	}
}

void resetHorizontal(char crossword[][n], string word, int row, int col, bool *helper){

	for(int i = 0; i < word.length(); i++){

		if(helper[i]){
			crossword[row][col] = '-';
			helper[i] = false;
		}
		col++;
	}
}

bool solveCrossword(char crossword[][n], vector<string> words, int index){

	if(index == words.size()){
		return true;
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{

			if(crossword[i][j] == '-' || crossword[i][j] == words[index][0]){

				if(isValidVertical(crossword, words[index], i, j))
				{
					bool *helper = new bool[words[index].length()];
					setVertical(crossword, words[index], i, j, helper);

					if(solveCrossword(crossword, words, index+1)){
						return true;
					}
					else{
						resetVertical(crossword, words[index], i, j, helper);
					}

					delete [] helper;
				}
				
				if(isValidHorizontal(crossword, words[index], i, j))
				{
					bool *helper = new bool[words[index].length()];
					setHorizontal(crossword, words[index], i, j, helper);

					if(solveCrossword(crossword, words, index+1)){
						return true;
					}
					else{
						resetHorizontal(crossword, words[index], i, j, helper);
					}

					delete [] helper;
				}

			}
		}
	}

	return false;
}

int main(){

	char crossword[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> crossword[i][j];
		}
	}

	string ws;
	cin >> ws;
    vector<string> words;
    string option = "";
    
    for(int i = 0; i < ws.length(); i++)
    {

        if(ws[i] == ';')
        {
            words.push_back(option);
            option = "";
        }
        else{
            option += ws[i];
        }
    }
    words.push_back(option);

    bool solved = solveCrossword(crossword, words, 0);

    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < n; j++){
    		cout << crossword[i][j];
    	}
    	cout << endl;
    }

    return 0;
}

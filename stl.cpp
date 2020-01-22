#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */

	//Vectors

	vector<int> v(5);  //creates a vector of five elements

	//We can traverse through a vector just like a n array if we know the size of the vector

	for (int i = 0; i < 5; ++i)
	{
		/* code */
		v[i] = i+1;
	}

	/*to know the current size of the array we can use the method size() */

	for( int i = 0; i < v.size(); i++)
		cout << v[i] << '\t';

	cout << endl;

	/*Suppose we dont know the initial size of the vector to declare it the way we did above.But I still want to insert elements into the vector.In that case we can use the push_back() function*/

	for(int i = 0; i < 5; i++)
		v.push_back(i+6);

	/*Note if we print the vector at this point the output will be all the numbers from 1 to 10, because in the above statement vector elements are not replaced but instead all the five elements 
	are pushed to the end of the vector*/

	/*Iterator is a pointer to elements within range of elements. We use an iterator to iterate throough any data structure. When we need to get the value ponted by iterator we simply 
	use value at operator*/

	// to declare an iterator on a vector we use the following syntax

	vector<int>::iterator itr;

	//vector has a functionality which gives us the poiter to the first element of the vector 
	//we use vectorName.begin() for this purpose

	//when we need to iterate through a vector we can initialise the iterator with vectorName.begin()

	//Then there is a functionlity called end() which gives a pointer pointing to the next position of last element of the vector, 
	//ie if we reach vectorName.end(), that means we have  already completed the vector
	//syntax is vectorName.end()

	for(itr = v.begin(); itr != v.end(); itr++)
		cout << *itr << "\t";

	cout << endl;

	//To remove an element from the vector we can use the erase method
	//usage is as follows
	// vectorName.erase(itr);
	//where itr is the name of the itr of the element to be deleted
	//we can also use the same method to delete multiple elements

	itr = v.begin();

	v.erase(itr);

	for(itr = v.begin(); itr != v.end(); itr++)
		cout << *itr << "\t";

	cout << endl;

	//deletes the first element from the vector

	//syntax is 
	//vectorName.erase(startingPosition, endingPosition);

	itr = v.begin();	

	v.erase(itr, itr + 3);

	//deletes the first three elements from the vector

	for(itr = v.begin(); itr != v.end(); itr++)
		cout << *itr << "\t";

	cout << endl;

	//to delete the last element, we can give position as v.end()-1

	itr = v.end();

	v.erase(itr - 1);

	for(itr = v.begin(); itr != v.end(); itr++)
		cout << *itr << "\t";

	cout << endl;

	//we can check if a vector is empty or not by using the method empty()
	//syntax is 
	// vectorName.empty();
	//It returns a boolean value;

	cout << v.empty() << endl;


	//String class


	//In C++ we have string library to help us do all the string operations.The STL required for this  is string
	//we can use this stl instead of using character array 

	string s = "Dhanesh";

	//If I want to declare a separate string with the same value  I can do it in the following way

	string s1(s);

	//Here the string s1 will be initialised with "Dhanesh"

	//Suppose I give the following statement

	string s2(s, 2, 4);

	//In this case ,it takes the 4 charecters starting from index 2, and initialises s2 with it.
	//ie, s2 will be initialised with "anes"

	cout << s << '\n' << s1 << '\n' << s2 << endl;

	//string stl also provides us with a method called substr() which can be used to obtain the substring of a string
	//the syntax is as follows

	// variable = stringName.substr(startingIndex, numberOfCharacters)

	//This function returns a substring


	s2 = s1.substr(1,4);

	// This imiplies that a ubstring of s1, starting from index 1 and then the next 4 charecters
	//the second argument is not compulsary
	//If we dont give the second argument, that means , it means that , in this case from 1 onwards until the end of the array

	cout  << s2 << endl;

	//To compare two strings, we have the method compare()
	//syntax is as follows
	// int variable = s1.compare(s2);

	//the fuction returns 0 if s1 and s2 are the same

	if(s1.compare(s2) == 0)
		cout << "Both strings are same" << endl;
	else
		cout << "Strings are different" << endl;

	//if we use cin to take a string input, input will be terminated with a space, ie ,even if we enter "this is awesome" , it will only take "this"
	//to overcome this difficulty, ie to take strings containing spaces as input we can use getline() funtion
	//getline() function has two arguments which are cin, from which it is taking the input and a string valriable in which it is storing  the input

	getline(cin, s);

	cout << s << endl;

	//Also we can treat string just like an array 
	//Example s[0] will give you the first character of the string
	//I can also change the first character alone

	s[0] = 'a'; //this is a completely valid statement for string type also

	//I can also use the + operator for appending strings in case of string type 

	cout << s + s2 << endl;

	//to find the size of the string we can use size() method or length method 

	cout << s.length() << endl;
	cout << s.size() << endl;

	//we can also use the find() function with the string
	//we can check if a substring is present in a string 
	// if a substring is present, then it returns the starting index
	//if the substring occurs twice, then it returns the index of the first occurence

	cout << s.find("def") << endl;

	//Pair class

	//Now we will see what a pair class is 

	// Example we can have  a vector of pairs of heigth and weight.We can have a pair of anything 
	//For pair class we have header name <utility> which is the class name

	// We can declare a pair in the following way
	// pair<datatype1, datatype2> pairName;

	pair<char, int> p;

	//Now if I want to give data to the pair p, ie make a pair, then I can use the method make_pair(first,second);

	p = make_pair('a', 1);


	
	//Or I can do something like this 

	pair<int, char> p1(1, 'a');

	//this will initialise my pair with 1, 'a'

	//to access the elemnts of a pair, syntax is :
	// to access the first element , pairName.first
	//to access the second element , pairName.second

	cout << p.first << " " << p.second << endl;
	cout << p1.first << '\t' << p1.second << endl;

	return 0;
}
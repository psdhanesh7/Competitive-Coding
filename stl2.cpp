#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	
	//SET

	//Set contains all unique values
	//To use a set in c++ we need to include the header file <set>

	//syntax for declaring a set 
	// set<datatype> name;

	set<int> s;

	//To insert an element in to a set we have the method insert(value)

	//suppose we store some values in an array	 

	int arr[] = {1, 2, 3, 2, 5, 4, 5, 6, 5};

	for(int i = 0; i < 8; i++)
		s.insert(arr[i]);

	set<int> :: iterator it;

	for( it = s.begin(); it != s.end(); it++)
		cout << *it << endl;

	//to find an element in a set we have the method find()

	//usage is as follows

	//the functin returns an iterator pointing towards that elemnt.If the element is not found then the iterator points to the next element after the last element, ie s.end()

	if(s.find(6) == s.end()){

		cout << "Element not found" << endl ;
	}
	else
	{
		cout << "Element found" << endl ;
	}

	//Generally set is implemented in c++ using a balanced binary search tree
	//So the time complexity of the find function is log n , insertion is also log n

	//MAP

	//In set we stored all the elements once. Suppose I want to store the frequency of these numbers as well
	//ie we have a key value pair 
	//Map stores key value pairs

	//to use maps we need to include the header file <map>

	//the following is the declaration of a map 


	map<int, int> m;
	//here the first int represents the data type of the key and second int represents the data type of the value

	//int arr[] = {1, 2, 3, 2, 5, 4, 5, 6, 5};

	for(int i = 0; i < 8; i++)
	{
		m[arr[i]] = m[arr[i]] + 1;
	}
	//the above for loop finds and stores the frequency of each element in the array 

	//now we want to print the elements of the map, we need to use the iterator

	map<int, int> :: iterator itr;

	//here itr is pointing to the element of the map
	//element of the map contains a key as well as a value
	//if you want to access the key, itr->first will give you the key
	//and to access the value, u can use itr->second

	for( itr = m.begin(); itr != m.end(); itr++)
	{
		cout << itr->first << " : " << itr->second << endl;
	}
	
	//map has also got the find() method which returns the iterator to that element of the map

	//Now to remove an element from the map, we can use the erase method

	cout << endl;

	m.erase(1);

	for( itr = m.begin(); itr != m.end(); itr++)
	{
		cout << itr->first << " : " << itr->second << endl;
	}

	cout << endl;

	//In c++ , map is also implemented using binary search tree
	//so time complexity for insertion, deletion and finding is O(logn)

	//There is also  a map called unodered_map which is implemented using hash tables
	//for insertion, deletion and find , it takes O(1) in average case, and in the worst case, it takes O(n).
	//But worst case occurs only in a very few scenarios

	//so we generally use unordered_map
	//It has all the funtionalaties same as that of map

	unordered_map<int, int> m1;

	//int arr[] = {1, 2, 3, 2, 5, 4, 5, 6, 5};

	for(int i = 0; i < 8; i++)
	{
		m1[arr[i]] = m1[arr[i]] + 1;
	}

	unordered_map<int, int> :: iterator itr1;

	for( itr1 = m1.begin(); itr1 != m1.end(); itr1++)
	{
		cout << itr1->first << " : " << itr1->second << endl;
	}
	
	cout << endl;

	//We can also use the insert() method to insert a key value pair into an unordered map
	//following is the syntax
	//unordered_map_name.insert({key, element})

	m.insert({1,1});

	for( itr1 = m1.begin(); itr1 != m1.end(); itr1++)
	{
		cout << itr1->first << " : " << itr1->second << endl;
	}
	
	cout << endl;

	m1.erase(1);

	//Note: for a doubly linked list we use the stl list
	//There are other stls like stack, queue, priority_queue
	
	return 0;
}
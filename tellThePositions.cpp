// Tell the positions

// In a class there are ‘n’ number of students. They have three different subjects: Data Structures, Algorithm Design & Analysis and Operating Systems. Marks for each subject of all the students are provided to you. You have to tell the position of each student in the class. Print the names of each student according to their position in class. Tie is broken on the basis of their roll numbers. Between two students having same marks, the one with less roll number will have higher rank. The input is provided in order of roll number.

// Input Format:
// First line will have a single integer ‘n’, denoting the number of students in the class.
// Next ‘n’ lines each will have one string denoting the name of student and three space separated integers m1, m2, m3 denoting the marks in three subjects.

// Output Format:
// Print ‘n’ lines having two values: First, the position of student in the class and second his name.

// Constraints:
// 1 <= n <= 10^5
// 0 <= m1, m2, m3 <= 100

// Sample Input:

// 3
// Mohit 94 85 97
// Shubham 93 91 94
// Rishabh 95 81 99

// Sample Output:

// 1 Shubham
// 2 Mohit
// 3 Rishabh

#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.second != p2.second)
    {
        return p1.second > p2.second;
    }
    else
    {
        return p1.first < p2.first;
    }
}
int main()
{
    int n; 
    int m1, m2, m3;
    string name;
    vector<pair<int, int>> students;
    map<int, string> rollno;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> name;
        cin >> m1 >> m2 >> m3;
        students.push_back(pair<int, int>(i+1, m1+m2+m3));
        rollno.insert(pair<int, string>(i+1, name));
    }
    
    sort(students.begin(), students.end(), compare);
    vector<pair<int, int>>::iterator it;
    
    int i = 0;
    for(it = students.begin(); it != students.end(); it++)
    {
        cout << ++i << " " << rollno[it->first] << endl;
    }
	return 0;
}




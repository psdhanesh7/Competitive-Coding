// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;


// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
//     int h,u,d,f,rheight,fatigue,climbing;
//     while(1)
//     {
//     cin>>h>>u>>d>>f;
//     if(h==0 && u==0 && d==0 && f==0)
//         break;
//     rheight=h;
//     climbing=u;
//     fatigue=u*(f/100);
//     while(climbing>0)
//     {
//         rheight-=climbing;
//         if(rheight<0)
//         {
//             cout<<"Yes"<<endl;
//             goto label;
//         }   
//         else
//         {
//             rheight+=d;
//             climbing=climbing-fatigue;
//         }
//     }
//     cout<<"No"<<endl;
//     label: ;
//     }
    
    
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

// int findNode(BinaryTreeNode<int>* root, int k) {
// 		// Write your code here
    
//     stack<BinaryTreeNode<int>*> s;
//     BinaryTreeNode<int> *ptr, *minimum;
//     int count = 0;
    
//     s.push(root);
    
//     while(!s.empty())
//     {
//         while(ptr != NULL)
//         {
//             ptr = ptr->left;
//             if(ptr != NULL)
//             {
//                 s.push(ptr);
//             }
//         }
        
//         minimum = s.top();
//         s.pop();
//         count++;
        
//         if(count ==  k)
//             return minimum->data;
        
//         ptr = minimum->right;
        
        
//     }
    
//     return INT_MIN;

// }




BinaryTreeNode<int>* getMinimum(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    
    if(root->left == NULL)
    {
        return root;
    }
    
    BinaryTreeNode<int> *minimum = getMinimum(root->left);
    
    return minimum;
    
}

BinaryTreeNode<int>* removeNode(BinaryTreeNode<int> *root, int X){
    /* Don't write main().
    * Don't read input, they are passed as function arguments.
    * Return output and don't print it.
    * Taking input and printing output is handled automatically.
    */
    
    if(root == NULL)
    {
        return root;
    }
    
    if(X < root->data)
    {
        root->left = removeNode(root->left, X);
    }
    else if(X > root->data)
    {
        root->right = removeNode(root->right, X);
    }
    else
    {
        BinaryTreeNode<int> *temp;
        
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;            
        }
        else if(root->left == NULL)
        {
            temp = root->right;
            delete root;
            root = temp;
        }
        else if(root->right == NULL)
        {
            temp = root->left;
            delete root;
            root = temp;
        }
        else
        {
            BinaryTreeNode<int> *minimum = getMinimum(root->right);
            int tempData = minimum->data;
            minimum->data = root->data;
            root->data = tempData;
            root->right = removeNode(root->right, minimum->data);
        }
    }
    
    return root;

}


int main()
{
	return 0;
}
//The given problem is to find out the diameter of a tree. Diameter of a tree  is defined as the number of egdes between the farthest two elements of the tree

#include<iostream>
using namespace std;

struct node{

	int data;
	node *leftChild, *rightChild;
};

node* getNewNode(int value)
{
	node *ptr = new node;

	ptr->data = value;
	ptr->rightChild = NULL;
	ptr->leftChild = NULL;

	return ptr;
}

node* insert(node *root, int value)
{
	if(root == NULL)
	{
		root = getNewNode(value);
		return root;
	}

	if(value <= root->data)
	{
		root->leftChild = insert(root->leftChild, value);
	}
	else
	{
		root->rightChild = insert(root->rightChild, value);
	}

	return root;
}

int height(node *root)
{
	if(root == NULL)
	{
		return -1;
	}

	int leftHeight = height(root->leftChild);
	int rightHeight = height(root->rightChild);

	return 1 + max(leftHeight, rightHeight);
}

int diameter(node *root)                        //In this case the time complexity is O(n*h), where h is the height of the treeDiameter
{												//if the tree is balanced then time complexity is O(nlogn) else in the worst case time complexity becomes O(n^2)
	if(root == NULL)
	{
		return 0;
	}

	int option1 = diameter(root->leftChild);
	int option2 = diameter(root->rightChild);
	int option3 = 2 + height(root->leftChild) + height(root->rightChild);

	return max(option1, max(option2, option3));
}

void deleteTree(node *root)
{
	if(root == NULL)
	{
		return;
	}

	deleteTree(root->leftChild);
	deleteTree(root->rightChild);
	delete root;
}

// void traversal(node *root)
// {
// 	if(root == NULL)
// 	{
// 		return;
// 	}

// 	traversal(root->leftChild);
// 	cout << root->data << "\t" ;
// 	traversal(root->rightChild);
// }

int main()
{
	int n, value;
	node *root = NULL;

	cout << "Enter the number of nodes of the binary search tree : " ;
	cin >> n;

	cout << "Enter the nodes of the binary search tree : " << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> value;
		root = insert(root, value);
	}

	int treeHeight = height(root);
	int treeDiameter = diameter(root);

	cout << "Height of tree is : " << treeHeight << endl;
	cout << "Diameter of tree is : " << treeDiameter << endl;

	// traversal(root);
	// cout << endl;

	deleteTree(root);
	return 0;
}
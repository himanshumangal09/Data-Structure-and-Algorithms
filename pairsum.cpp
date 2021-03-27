/**********************************************************
	Following is the Binary Tree Node class structure

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

***********************************************************/

#include <iostream>
#include <queue>
using namespace std;
template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

//This file is created by Himanshu Mangal
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

vector<int> *getarray(BinaryTreeNode<int> *root, vector<int> *vp)
{
    if (root == NULL)
    {
        return NULL;
    }
    vp->push_back(root->data);
    getarray(root->left, vp);
    getarray(root->right, vp);
    return vp;
}
void pairSum(BinaryTreeNode<int> *root, int sum)
{
    vector<int> *vp = new vector<int>();
    vp = getarray(root, vp);

    sort(vp->begin(), vp->end());

    int i = 0;
    int j = vp->size() - 1;
    while (j > i)
    {
        if (vp->at(i) + vp->at(j) > sum)
        {
            j--;
        }
        if (vp->at(i) + vp->at(j) < sum)
        {
            i++;
        }
        if (vp->at(i) + vp->at(j) == sum)
        {
            // cout << vp->at(i) << " " << vp->at(j)<<endl;
            j--;
            i++;
        }
    }
}

// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 15
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}
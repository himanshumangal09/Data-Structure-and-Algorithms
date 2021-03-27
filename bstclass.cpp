#include <iostream>
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

/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/

class BST
{
    // Define the data members
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
        // Implement the Constructor
    }

    /*----------------- Public Functions of BST -----------------*/

    void remove(int data)
    {
        // Implement the remove() function
    }

private:
    void printBST(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data;
        printBST(node->left);
        printBST(node->right);
    }

public:
    void print()
    {
        printBST(root);
        // Implement the print() function
    }

private:
    BinaryTreeNode<int> *insertBST(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
            // root->left = NULL;
            // root->right = NULL;
            return root;
        }
        if (node->data >= data)
        {
            BinaryTreeNode<int> *leftroot = insertBST(data, node->left);
            node->left = leftroot;
        }
        if (node->data < data)
        {
            BinaryTreeNode<int> *rightroot = insertBST(data, node->right);
            node->right = rightroot;
        }
        return node;
    }

public:
    void insert(int data)
    {
        // Implement the insert() function
        BinaryTreeNode<int> *root = insertBST(data, root);
    }

private:
    bool isBST(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (node->data == data)
        {
            return true;
        }
        if (node->data > data)
        {
            bool leftout = isBST(data, node->left);
            return leftout;
        }
        else if (node->data < data)
        {
            bool rightout = isBST(data, node->right);
            return rightout;
        }
        else
        {
            return NULL;
        }
    }

public:
    bool search(int data)
    {
        // Implement the search() function
        return isBST(data, root);
    }
};

int main()
{
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            tree->insert(input);
            break;
        case 2:
            cin >> input;
            tree->remove(input);
            break;
        case 3:
            cin >> input;
            cout << ((tree->search(input)) ? "true\n" : "false\n");
            break;
        default:
            tree->print();
            break;
        }
    }
}
#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int tData) {
		data = tData;
		left = right = NULL;
	}
};

class binaryTree {
public:
	Node* root;

	binaryTree() {
		root = NULL;
	}

	Node* createNode(int data) {
		Node* node = new Node(data);
		return node;
	}

	// recursive method to insert in Binary-Search-Tree
	Node* insert(Node* root, int data) {
		if (root == NULL) {
			root = createNode(data);
		}

		else if (data >= root->data) {
			root->right = insert(root->right, data);
		}
		else if (data < root->data) {
			root->left = insert(root->left, data);
		}

		return root;
	}

	// iterative method to insert in Binary-Search-Tree
	void insertion() {
		int value = 0;
		cout << "Enter the Value: ";
		cin >> value;
		Node* current = root;

		if (root == nullptr) {
			root = new Node(value);
			return;
		}

		Node* parent = nullptr;
		while (current != nullptr) {
			parent = current;

			if (value < current->data) 
				current = current->left;
			else 
				current = current->right;

		}
		

		if (value > parent->data)
			parent->right = new Node(value);
		else
			parent->left = new Node(value);
	}

	//function to search the value (key) in the BST
	void search() {
		int key = 0;
		bool flag = false;
		cout << "Enter the Key to Search: ";
		cin >> key;

		Node* current = root;
		Node* parent = nullptr;

		while (current != nullptr && current->data != key) {
			parent = current;
			if (key < current->data)
				current = current->left;
			else
				current = current->right;
		}

		if (current == nullptr) {
			cout << "Key [" << key << "] not found.\n";
			return;
		}

		if (parent == nullptr) {
			cout << "The key [" << key << "] node is the Root Node.\n";
		}
		else if (key < parent->data) {
			cout << "The key [" << key << "] is the left node of the Node with key [" << parent->data << "].\n";
		}
		else if (key > parent->data) {
			cout << "The key [" << key << "] is the right node of the Node with key [" << parent->data << "].\n";
		}
	}

	//function to find the maximum value from the binary search tree 
	int maximum(Node* root)
	{
		if (root == NULL)
			return -1;

		int root_max = root->data;
		int left_max = maximum(root->left);
		int rres = maximum(root->right);
		if (left_max > root_max)
			root_max = left_max;
		if (rres > root_max)
			root_max = rres;
		return root_max;
	}

	//function to find the minimum value from the binary search tree 
	int minimum(Node* root)
	{
		if (root == NULL)
		{
			return INT_MAX;
		}
		int min = root->data;
		int left = minimum(root->left);
		int right = minimum(root->right);
		if (left < min)
		{
			min = left;
		}
		if (right < min)
		{
			min = right;
		}
		return min;
	}

	Node* findMaximumKey(Node* node) {
		while (node->right != nullptr)
			node = node->right;
		return node;
	}
	// function to delete a certain node in the BST
	void remove(Node* &root, int key) {
		if (root == nullptr)
			return;

		if (key < root->data)
			remove(root->left, key);
		else if (key > root->data)
			remove(root->right, key);

		else {
			//if the node has no children
			if (root->left == nullptr && root->right == nullptr) {
				delete root;
				root = nullptr;
			}

			//if the node has two children
			else if (root->left && root->right)
			{
				Node* predecessor = findMaximumKey(root->left);

				root->data = predecessor->data;

				remove(root->left, predecessor->data);
			}

			// if the node has only one children
			else {
				Node* child = (root->left) ? root->left : root->right;
				Node* curr = root;

				root = child;

				delete curr;
			}
		}
			

	}

	// display functions
	void inOrder(Node* root) {
		if (root == NULL) {
			return;
		}

		inOrder(root->left);
		cout << root->data << "  ";
		inOrder(root->right);
	}

	void preOrder(Node* root) {
		if (root == NULL) {
			return;
		}

		cout << root->data << "  ";
		preOrder(root->left);
		preOrder(root->right);
	}

	void postOrder(Node* root) {
		if (root == NULL) {
			return;
		}
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << "  ";
	}
};


void menu() {
	cout << "1. Insert" << endl;
	cout << "2. Search" << endl;
	cout << "3. Maximum" << endl;
	cout << "4. Minimum" << endl;
	cout << "5. Delete" << endl;
	cout << "6. Display" << endl;
	cout << "7. Quit Program" << endl;
}

int main() {
	binaryTree tree;
	int choice = 0, key = 0;
	char rep = ' ';
	do
	{
		menu();
		cout << "Enter the operation: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the No. of Values: ";
			cin >> choice;
			for (int i = 0; i < choice; i++) {
				tree.insertion();
			}
			break;
		case 2:
			tree.search();
			break;
		case 3:
			if (tree.maximum(tree.root) == -1)
				cout << "Tree is Empty.\n";
			else
				cout << tree.maximum(tree.root) << " is maximum value.\n";
			break;
		case 4:
			cout << tree.minimum(tree.root) << " is minimum value.\n";
			break;
		case 5:
			cout << "Enter the Value to Remove: ";
			cin >> key;
			tree.remove(tree.root, key);
			break;
		case 6:
			cout << "1. In-order\n2. Pre-Order\n3. Post-Order\n";
			cout << "Enter the Operation: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				tree.inOrder(tree.root);
				cout << endl;
				break;
			case 2:
				tree.preOrder(tree.root);
				cout << endl;
				break;
			case 3:
				tree.postOrder(tree.root);
				cout << endl;
				break;
			default:
				cout << "Invaid Operation.\n";
				break;
			}
			break;
		case 7:
			cout << "*********PROGRAM   ENDED************\n";
			return 0;
		default:
			cout << "Invalid operation.\n";
			break;
		}
		cout << "Enter Y to Repeat: ";
		cin >> rep;
	} while (rep == 'y' || rep == 'Y');
	
	return 0;
}
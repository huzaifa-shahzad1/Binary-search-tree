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

int main() {
	binaryTree tree;
	
	tree.insertion();
	tree.insertion();
	tree.insertion();
	tree.insertion();
	tree.insertion();
	tree.insertion();


	tree.search();
	cout << endl;
	tree.inOrder(tree.root);
	cout << endl;
	tree.preOrder(tree.root);
	cout << endl;
	tree.postOrder(tree.root);
	cout << endl;
}
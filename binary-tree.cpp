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
	Node* leaf;

	binaryTree() {
		root = leaf = NULL;

	}

	bool isEmpty() {
		return(root == NULL);
	}

	Node* createNode(int data) {
		Node* node = new Node(data);
		return node;
	}

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

	tree.inOrder(tree.root);
	cout << endl;
	tree.preOrder(tree.root);
	cout << endl;
	tree.postOrder(tree.root);
	cout << endl;
}
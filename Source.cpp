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

	// display functions
	void inOrder(Node* root) {
		if (root==NULL) {
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
	tree.root = tree.insert(tree.root, 51);
	tree.root = tree.insert(tree.root, 13);
	tree.root = tree.insert(tree.root, 87);
	tree.root = tree.insert(tree.root, 31);
	tree.root = tree.insert(tree.root, 42);
	tree.root = tree.insert(tree.root, 90);
	tree.root = tree.insert(tree.root, 98);

	tree.inOrder(tree.root);
	cout << endl;
	tree.preOrder(tree.root);
	cout << endl;
	tree.postOrder(tree.root);
	cout << endl;
}
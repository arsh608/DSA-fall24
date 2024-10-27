#include<iostream>
#include<stack>
using namespace std;
class Node{
	int data;
	Node* left;
	Node* right;
public:
	Node(int d = -1, Node* l = NULL, Node* r = NULL):data(d),left(l),right(r){}
	friend class BST;
};

class BST{
public:
	Node* Insert(Node* root, int value){
    	if (!root)
        	return new Node(value);    
    	if (value > root->data)
        	root->right = Insert(root->right, value);    
   		else
        	root->left = Insert(root->left, value);    
    	return root;
	}	
	
	// Function to find the minimum value node (inorder successor)
	Node* minValueNode(Node* node) {
	    Node* current = node;
	
	    // Loop to find the leftmost leaf
	    while (current != nullptr && current->left != nullptr) {
	        current = current->left;
	    }
	
	    return current;
	}
	
	// Function to delete a node in the BST
	Node* deleteNode(Node* root, int key) {
	    // Base case: if the tree is empty
	    if (root == nullptr) {
	        return root;
	    }
	
	    // If the key to be deleted is smaller than the root's key,
	    // it lies in the left subtree
	    if (key < root->data) {
	        root->left = deleteNode(root->left, key);
	    }
	    // If the key to be deleted is greater than the root's key,
	    // it lies in the right subtree
	    else if (key > root->data) {
	        root->right = deleteNode(root->right, key);
	    }
	    // If the key is equal to the root's key, delete this node
	    else {
	        // Node with only one child or no child
	        if (root->left == nullptr) {
	            Node* temp = root->right;
	            delete root; // Free memory
	            return temp;
	        } else if (root->right == nullptr) {
	            Node* temp = root->left;
	            delete root; // Free memory
	            return temp;
	        }
	
	        // Node with two children:
	        // Get the inorder successor (smallest in the right subtree)
	        Node* temp = minValueNode(root->right);
	
	        // Copy the inorder successor's content to this node
	        root->data = temp->data;
	
	        // Delete the inorder successor
	        root->right = deleteNode(root->right, temp->data);
	    }
	    return root;
	}
	    
	
	void InOrder(Node* root){
		if (root==NULL)
			return;
		InOrder(root->left);
		cout << root->data << " ";
		InOrder(root->right);
	}
};

int main(){
	BST b;
	Node *root = NULL;
    root = b.Insert(root, 15);
    b.Insert(root, 10);
    b.Insert(root, 20);
    b.Insert(root, 8);
    b.Insert(root, 12);
    b.Insert(root, 16);
    b.Insert(root, 25);
    b.Insert(root, 32);
    b.Insert(root, 6);
    b.Insert(root, 35);
    cout << "InOrder" << endl;
    b.InOrder(root);
    cout << "Deleting Node 15" << endl;
    root = b.deleteNode(root, 15);
    cout << "\nInOrder" << endl;
    b.InOrder(root);
	return 0;
}

	
	

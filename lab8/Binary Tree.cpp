#include <iostream>
#include <queue>
using namespace std;
static int index = -1;
class Node {
	int data;
	Node* left;
	Node* right;
	
	public:
		Node(int d){
			this->data = d;
			left = NULL;
			right = NULL;
		}
	friend class BinaryTree;
};

class BinaryTree {
	public:
		Node* root;
		BinaryTree():root(NULL){  }
		
		void addNode (int d){
			Node* newNode = new Node(d);
			if (root == NULL)
				root = newNode;
			else {
				queue<Node*> q;
				q.push(root);
				
				while(!q.empty()){
					Node* current = q.front();
					q.pop();
					
					if (current->left == NULL){
						current->left = newNode;
						return;
					}
					else
						q.push(current->left);
						
					if (current->right == NULL){
						current->right = newNode;
						return;	
					}
					else
						q.push(current->right);							
				}	
			}
		}
		
		
		
		void inOrder(Node* root){
			if (root==NULL)
				return;
			inOrder(root->left);
			cout << root->data << " ";
			inOrder(root->right);
		}
		
		// Function to delete the deepest node in the binary tree
		void deleteDeepest(Node* root, Node* d_node) {
		    queue<Node*> q;
		    q.push(root);
		
		    while (!q.empty()) {
		        Node* temp = q.front();
		        q.pop();
		
		        if (temp == d_node) {
		            temp = nullptr;
		            delete d_node;
		            return;
		        }
		
		        if (temp->left) {
		            if (temp->left == d_node) {
		                temp->left = nullptr;
		                delete d_node;
		                return;
		            } else {
		                q.push(temp->left);
		            }
		        }
		
		        if (temp->right) {
		            if (temp->right == d_node) {
		                temp->right = nullptr;
		                delete d_node;
		                return;
		            } else {
		                q.push(temp->right);
		            }
		        }
		    }
		}
		
		// Function to delete a node in the binary tree
		Node* deleteNode(Node* root, int key) {
		    if (root == nullptr) {
		        return nullptr;
		    }
		
		    if (root->left == nullptr && root->right == nullptr) {
		        if (root->data == key) {
		            delete root;
		            return nullptr;
		        } else {
		            return root;
		        }
		    }
		
		    queue<Node*> q;
		    q.push(root);
		
		    Node* key_node = nullptr;
		    Node* temp;
		
		    // Find the node to delete and the deepest node
		    while (!q.empty()) {
		        temp = q.front();
		        q.pop();
		
		        if (temp->data == key) {
		            key_node = temp;
		        }
		
		        if (temp->left) {
		            q.push(temp->left);
		        }
		
		        if (temp->right) {
		            q.push(temp->right);
		        }
		    }
		
		    // If the node to delete is found, replace it with the deepest node's data
		    if (key_node != nullptr) {
		        int x = temp->data;
		        deleteDeepest(root, temp);
		        key_node->data = x;
		    }		
		    return root;
		}
};

int main(){
	
//	int values[] = {1, 2, 4, -1, -1, 5, -2, -1, 3, -1, 6, -1, -1};
	BinaryTree bt;
	bt.addNode(10);
	bt.addNode(20);
	bt.addNode(30);
	bt.addNode(40);
	bt.addNode(50);
	bt.addNode(60);
	bt.addNode(70);
	bt.inOrder(bt.root);
	
	cout << "\nAfter Deleting Node with Key 30" << endl;
	bt.deleteNode(bt.root, 30);
	bt.inOrder(bt.root);
	return 0;
}
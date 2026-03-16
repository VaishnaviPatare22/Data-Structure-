#include <iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* LC;
    Node* RC;

    Node(int Data) {
        data = Data;
        LC = NULL;
        RC = NULL;
    }
};

class BinaryTree {
public:
    int index = -1;

    Node* BuildTree(int nodes[]) {
        index++;

        if (nodes[index] == -1) {
            return NULL;
        }

        Node* newNode = new Node(nodes[index]);
        newNode->LC = BuildTree(nodes);
        newNode->RC = BuildTree(nodes);

        return newNode;
    }
	
	void preorder(Node* root){
		if(root==NULL){
			return;
		}
		cout<<root->data<<" ";
		preorder(root->LC);
		preorder(root->RC);
	}
	
	void inorder(Node* root){
		if(root==NULL){
			return;
		}
		
		inorder(root->LC);
		cout<<root->data<<" ";
		inorder(root->RC);
	}
	
	void postOrder(Node* root){
		if(root==NULL){
			return;
		}
		
		postOrder(root->LC);
		postOrder(root->RC);
		cout<<root->data<<" ";
	}
	
	void levelOrder(Node* root) {
		if (root == NULL) {
			return;
		}

		queue<Node*> q;
		q.push(root);
		q.push(NULL);

		while (!q.empty()) {
			Node* curNode = q.front();
			q.pop();

			if (curNode == NULL) {
				cout << endl;
				if (q.empty()) {
					break;
				} else {
					q.push(NULL);
				}
			} else {
				cout << curNode->data << " ";

				if (curNode->LC != NULL) {
					q.push(curNode->LC);
				}
				if (curNode->RC != NULL) {
					q.push(curNode->RC);
				}
			}
		}
	}
	
	//Count of Nodes
	int countOfNodes(Node* root){
		if (root == NULL) {
			return 0;
		}
		
		int LeftNodes = countOfNodes(root->LC);
		int RightNodes = countOfNodes(root->RC);
		
		return LeftNodes + RightNodes + 1;
		
	}
	
	//Sum of Nodes
	int sumOfNodes(Node* root){
		if (root == NULL) {
			return 0;
		}
		
		int leftSum = sumOfNodes(root->LC);
		int RightSum = sumOfNodes(root->RC);
		
		return leftSum + RightSum + root->data;
		
	}
	
	//Height of Tree
	int height(Node* root){
		if(root == NULL){
			return 0;
		}
		int leftHeight = height(root->LC);
		int rightHeight = height(root->RC);
		
		int myHeight = max(leftHeight,rightHeight) + 1;
		
		return myHeight;
	}
	
	//Diameter of a Tree
	int diameter(Node* root){
		if(root == NULL){
			return 0;
		}
		
		int Diam1 = diameter(root->LC);
		int Diam2 = diameter(root->RC);
		int Diam3 = height(root->LC) + height(root->RC) + 1;
		
		return max(Diam3,max(Diam1,Diam2));
	}
};

int main() {
    int nodes[] = {1, 2, 3, -1, -1, 4, -1, -1, 6, 5, -1, -1, 7, -1, -1};

    BinaryTree b;
    Node* root = b.BuildTree(nodes);

    cout << "Root Data : " << root->data << endl;
	//b.preorder(root);
	b.levelOrder(root);
	cout<<"\nCount of Nodes : "<<b.countOfNodes(root);
	
	cout<<"\nSum of Nodes : "<<b.sumOfNodes(root);
	
	cout<<"\nHeight of Tree : "<<b.height(root);
	
	cout<<"\nDiameter of Tree : "<<b.diameter(root);
    return 0;
}

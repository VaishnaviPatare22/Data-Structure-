#include<iostream>
#include<ios>
#include<limits> 
#include <cstring>
#define MAX 20
using namespace std;

typedef struct Node{
	struct Node *LC;
	string word;
	string meaning;
	struct Node *RC;
}NODE;

class Stack{
   NODE *stk[MAX];
   int top;
   
   public:
	Stack(){
	   top=-1;
	}
   
   void push(NODE * val){
		if(!isFull())
			stk[++top]=val;
		else
			cout<<"\nStack Full!";
   }
	NODE* pop(){
		if(!isEmpty())
			return stk[top--];
		else
			cout<<"\nStack Empty!";
		return NULL;
	}
	
    bool isFull(){
		return (top==MAX-1);
	}
	
	bool isEmpty(){
		return (top==-1);
	}
};

class BST{
	private:
		NODE *root;
		Stack S;
	public:
		BST(){
			root=NULL;
		}
	
		void addNode(string word, string meaning){
			NODE *p;
			p=new NODE;
			p->LC=NULL;
			p->word=word;
			p->meaning=meaning;
			p->RC=NULL;
			
			if(root==NULL){
				root=p;
			}
			else{
				NODE *cur,*f;
				cur=root;
				
				while(cur){
					f=cur;
					if(word == cur->word){
						cout<<"\nDuplicate node!!";
						return;
					}
					else if(word > cur->word)
						cur=cur->RC;
					else
						cur=cur->LC;
				}
				if(word > f->word)
					f->RC=p;
				else
					f->LC=p;
			}
				
		}
		
		void deleteNode(string key){
			NODE *parent,*cur,*p,*q,*t;
			bool found=false;
			if(root==NULL)
				cout<<"\nTree Empty!!";
			else{
				cur=root;

				while(cur){
					cout<<"\n I am in while with "<<cur->word<<" node\n";
					if(key==cur->word){
						cout<<cur->word<<" : "<<cur->meaning<<" will be deleted!";
						found=true;
						if(cur == root){
							cout<<"\nNode "<<cur->word<<" is root node!";
							if(cur->LC ==NULL && cur->RC == NULL){
								root=NULL;
								delete cur;
							}
							else
							if(cur->LC !=NULL && cur->RC == NULL){
								root=root->LC;
								delete cur;
							}
							else
							if(cur->RC != NULL){
								if((cur->RC)->LC == NULL){
									p=cur->RC;
									cur->word=p->word;
									cur->RC=p->RC;
									delete p;
								}
								else{
									p=t=cur->RC;
									while(t){
										q=p;
										p=t;
										t=t->LC;
									}
									cur->word=p->word;
									q->LC=NULL;
									delete p;
								}
							}
						}else
						if(cur->LC == NULL && cur->RC == NULL){
							cout<<"\nLeaf Node of "<<parent->word;
							if((parent->LC)->word==key){
								cout<<"\nLeft Child!!";
								parent->LC=NULL;
							}
							else{
								cout<<"\nRight Child!!";
								parent->RC=NULL;
							}
							delete cur;
						}
						else
						if((parent->LC)->word==key){
							cout<<"\nLeft child Node of "<<parent->word;
							if(cur->LC != NULL && cur->RC == NULL)
								parent->LC=cur->LC;
							else if(cur->LC == NULL && cur->RC != NULL)
								parent->LC=cur->RC;
							
							delete cur;
						}
						else
						if((parent->LC)->word==key){
							cout<<"\nRight child Node of "<<parent->word;
							if(cur->LC != NULL && cur->RC == NULL)
								parent->RC=cur->LC;
							else if(cur->LC == NULL && cur->RC != NULL)
								parent->RC=cur->RC;
							
							delete cur;
						}
						else
						if(cur->LC != NULL && cur->RC != NULL){
							cout<<"\nNode "<<cur->word<<" has both left & right child!";
							if((cur->RC)->LC ==NULL){
								p=cur->RC;
								cur->word=p->word;
								cur->RC=p->RC;
								delete p;
							}
							else{
								p=t=cur->RC;
								while(t)
								{
									q=p;
									p=t;
									t=t->LC;
								}
								cur->word=p->word;
								q->LC=NULL;
								delete p;
							}
						}
						
						return;
					}
					if(key<cur->word){
						parent=cur;
						cur=cur->LC;
					}
					else{
						parent=cur;
						cur=cur->RC;
					}
				}
				cout<<"\nNode with "<<key<<" not found!!";
			}	
		}
		
		void updateNode(string word){
			
			if(root==NULL){
				cout<<"\nTree Empty!!";
						return;
			}
			else{
				NODE *cur;
				cur=root;
				
				while(cur){
					if(word == cur->word){
						cout<<"\nEnter new meaning::";
						cin>>cur->meaning;
						break;
					}
					else if(word > cur->word)
						cur=cur->RC;
					else
						cur=cur->LC;
				}	
			}
		}
		
		
		void displayAscBST(NODE *t){
			if(t){
				displayAscBST(t->LC);
				cout<<"["<<t->word<<"|"<<t->meaning<<"]  ";
				displayAscBST(t->RC);
			}
		}
	
		void INORDBST(NODE *t){
			if(t){
				INORDBST(t->LC);
				S.push(t);
				INORDBST(t->RC);
			}
		}
		
		void displayDscBST(){
			INORDBST(returnroot());
				NODE* t=S.pop();
				cout<<"["<<t->word<<"|"<<t->meaning<<"]  ";
			
		}
	
		
		void searchNode(string key){
			int count=0;
			if(root==NULL){
				cout<<"\nTree Empty!!";
						return;
			}
			else{
				NODE *cur;
				cur=root;
				
				while(cur){
					count++;
					if(key == cur->word){
						cout<<"\nWord found!";
						cout<<"\nThe number of comparisons are::"<<count;
						return;
					}
					else if(key > cur->word)
						cur=cur->RC;
					else
						cur=cur->LC;
				}	
			}
			cout<<"\nNode not found";
			
		}
		
		NODE* returnroot(){
			return root;
		}

};

int main(){
	BST P;
	int choice=0;
	string word, meaning;

	while(choice != 6){
		cout<<"\n****************BST Operations**************";
		cout<<"\n1. Add Node";
		cout<<"\n2. Display BST";
		cout<<"\n3. Delete Node";
		cout<<"\n4. Update Node";
		cout<<"\n5. Search Node";
		cout<<"\n6. Exit";
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
		cout<<"\nWhat operation you want::";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"\nEnter word::";
				cin>>word;
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
				cout<<"\nEnter meaning::";
				cin>>meaning;
				P.addNode(word,meaning);
				break;
			case 2:
				cout<<"\nPrint words in ascending:\n";
				P.displayAscBST(P.returnroot());
				
				cout<<"\n\nPrint words in descending:\n";
				P.displayDscBST();
				break;
			case 3:
				cout<<"\nEnter woderd to be deleted::";
				cin>>word;
				P.deleteNode(word);
				
				break;
			case 4:
				//cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
				cout<<"\nEnter word::";
				cin>>word;
				P.updateNode(word);
				
				break;
			case 5:
				cout<<"\nEnter word to be searched::";
				cin>>word;
				P.searchNode(word);
				
				break;
			case 6:
				cout<<"\nThanks for using application!!";
				break;
			default:
				cout<<"\nWrong Choice!!";
		}
	}
	return 0;
}


/*A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
deleting keywords, updating values of any entry. Provide facility to display whole data sorted in
ascending/ Descending order. Also find how many maximum comparisons may require for
finding any keyword.
Use Height balance tree (AVL tree) and find the complexity for finding a keyword.

input : A word and its meaning

Output : BST of dictionary words*/

#include<iostream>
#include<ios>
#include<limits>
#include<cstring>
using namespace std;

//Dictionary of word
typedef struct Keyword{
	string key;
	string meaning;
}WORD;

//Dictionary of Node
typedef struct Node{
	struct Node *LC;//left child link
	WORD data;
	struct Node *RC;//right child link
}NODE;

class AVL{
	private:
		NODE *root;
		int count;
	public :
		AVL(){
			root=NULL;
			count=0;
		}
		NODE* getroot(){
			return root;
		}
		
		int height(NODE *T){
			int lh,rh;
			if(T==NULL)
				return 0;
			if(T->LC ==NULL && T->RC==NULL)//if leaf node then retrun height '0'
				return 0;
			lh=height(T->LC);//travel left recursively
			rh=height(T->RC);//travel right recursively
			if(lh>rh)//For every node see left height is greater than right 
				return lh+1;//return left height 
			else
				return rh+1;//return right height
		}
		
		//Function to calculate balance factor
		int difference(NODE* T){
			int l_height = height(T->LC);//calculate a left height of a node
			int r_height = height(T->RC);//calculate a right height of a node
			int b_factor = l_height - r_height;// Find the difference of Left and rigth height to get balance factor
			return b_factor;//return banance factor	
		}
		
		NODE *llRotation(NODE *Pptr){
			NODE *Aptr;
			Aptr=Pptr->LC;
			Pptr->LC = Aptr->RC;
			Aptr->RC = Pptr;
			cout<<"\nLeft-Left Rotation ";
			return Aptr;
		}
		
		NODE *rrRotation(NODE *Pptr){
			NODE *Aptr;
			Aptr=Pptr->RC;
			Pptr->RC = Aptr->LC;
			Aptr->LC = Pptr;
			cout<<"\nRight-Right Rotation ";
			return Aptr;
		}
		
		NODE *lrRotation(NODE *Pptr){
			NODE *Aptr;
			Aptr=Pptr->LC;
			Pptr->LC=rrRotation(Aptr);
			cout<<"\nLeft=Right Rotation ";
			return llRotation(Pptr);
		}
		
		NODE *rlRotation(NODE *Pptr){
			NODE *Aptr;
			Aptr=Pptr->RC;
			Pptr->RC=llRotation(Aptr);
			cout<<"\nLeft=Right Rotation ";
			return rrRotation(Pptr);
		}
		
		NODE* balance(NODE* T){
			int bal_factor = difference(T);
			if (bal_factor > 1) {                                                                 
				if (difference(T->LC) > 0)
					T = llRotation(T);
				else
					T = lrRotation(T);
			} else if (bal_factor < -1) {
				if (difference(T->RC) > 0)
					T = rlRotation(T);
				else
					T = rrRotation(T);
			}
			return T;	
		}
		
		NODE* insert(NODE* T,WORD w){
			if (T == NULL) {
				T = new NODE;
				T->data = w;
				T->LC = NULL;
				T->RC = NULL;
				root=T;
				return T;
			} else if(w.key<T->data.key) {
					T->LC = insert(T->LC, w);
					T = balance(T);
			} else if (w.key>T->data.key) {
					T->RC = insert(T->RC, w);
					T = balance(T);
			} 
			
			root=T;//update root after rotations
			return T;
		}

		//INORDER Traversal of tree
		void displayIN(NODE *T){
			if(T)
			{
				displayIN(T->LC);
				cout<<"["<<T->data.key<<":"<<T->data.meaning<<"]->";
				displayIN(T->RC);
			}
		}
};

int main(){
	AVL B;
	int val,ch,n;
	WORD w;
	NODE* r;
	string key;
	ch=0;
	while(ch!= 3){
	cout<<"\n********DICTIONARY STORAGE using AVL*********";
     	cout<<"\n1. ADD WORD";
     	cout<<"\n2. DISPLAY DICTIONARY";
     	cout<<"\n3. EXIT";
     	cout<<"\nEnter your choice : ";
    	cin>>ch;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
     	
		switch(ch){
			case 1:
				cout<<"\nEnter keyword:";
				cin>>w.key;   

				cin.ignore();

				cout<<"\nEnter meaning of the word: ";
				getline(cin,w.meaning); // CHANGED: allows multi-word meaning
				r=B.insert(B.getroot(),w);
				break;
			case 2:
				B.displayIN(B.getroot());
				break;
			case 3:
				cout<<"\nProgram Exits!!";
				break;
			default:
				cout<<"\nWrong choice!";
		}
   }

   return 0;
}
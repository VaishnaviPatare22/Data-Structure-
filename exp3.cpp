/*Use the map of the area around the college as the graph. 
Identify the prominent land marks as nodes.
Represent a given graph using adjacency matrix/list 
to perform DFS and using adjacency list to perform BFS.*/

#include<iostream>
#include<ios>
#include<limits>

using namespace std;

class GraphMap{
	private :
		int GAM[10][10];
		int n;
		
	public :
		GraphMap(){
			for(int i=0; i<10; i++)
				for(int j=0; j<10; j++)
					GAM[i][j]=0;
		}
		
		void generateGraph(){
			bool flag = true;
			int s,d;
			
			cout<<"\nEnter the number of nodes in Graph :: ";
			cin>>n;
						
			while(flag){
				cout<<"Enter the source : ";
				cin>>s;
				
				cout<<"Enter the Destination : ";
				cin>>d;
				
				GAM[s][d]=1;
				
				cout<<"\nDo you want to add more edges Yes=1/No=0::";
				cin>>flag;	
			}
		}
		
		void displayMatrix() {
			cout<<"\nAdjacency Matrix:\n\n";

			cout<<"    ";
			for(int i = 1; i <= n; i++) {
				cout<<i<<" ";
			}
			cout<<endl;

			for(int i = 1; i <= n; i++){
				cout<<i<<"   ";
				for(int j = 1; j <= n; j++){
					cout<<GAM[i][j]<<" ";
				}
				cout<<endl;
			}
		}
};

int main(){
	GraphMap G;
	int choice=0;
	while(choice!=6){
		cout<<"\n1. Create Graph .";
		cout<<"\n2. Display Graph Adjancee Matrix.";
		cout<<"\n3. Display Graph Adjancee List..";
		cout<<"\n4. Traverse BSF.";
		cout<<"\n5. Traverse DFS.";
		cout<<"\n6. Exit";
		//cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"\nWhat operation you want :: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				G.generateGraph();
				break;
			case 2:
				G.displayMatrix();
				break;
			case 3:				
				break;		
			case 4:				
				break;
			case 5:
				break;			
			case 6:
				cout<<"\nThanks for using BST.";
				break;	
			default:
				cout<<"Wrong Choice!!";
		}
	}
	
	return 0;
	
}
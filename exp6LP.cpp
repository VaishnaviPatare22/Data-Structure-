#include<iostream>
#include<ios>
#include<limits>
#include <cstring>
#define BSIZE 5
using namespace std;

typedef struct Client{
	long int telephoneNo;
	string name;
}CLIENT;

class TelephoneDirectory{
	private:
		CLIENT LPHashTable[BSIZE];
		CLIENT cObj;
	public:
		TelephoneDirectory(){
			for(int i=0;i<BSIZE;i++){
				LPHashTable[i].telephoneNo=-1;
			}
		}
		void init(){
			for(int i=0;i<BSIZE;i++){
				LPHashTable[i].telephoneNo=-1;
			}
		}
		
		void readData();
		void printData();
		void insertRecordLP();
		void displayRecordsLP();
		void searchRecordLP(long int);
};

void TelephoneDirectory::readData(){
	long int telephone;
	string name;
	cout<<"\nEnter client telephone No.::";
	cin>>cObj.telephoneNo;
	
	cout<<"\nEnter client name::";
	cin>>cObj.name;
}

void TelephoneDirectory::printData(){
	cout<<"\nThe client telephone No.::"<<cObj.telephoneNo;
	cout<<"\nThe client name::"<<cObj.name;
}

void TelephoneDirectory::insertRecordLP(){
	int hi,noc,i;
	readData();
	hi=cObj.telephoneNo%BSIZE;
	if(LPHashTable[hi].telephoneNo == -1)
		LPHashTable[hi]=cObj;
	else{
		 i=(hi+1)%BSIZE;
		 while(i != hi){
			if(LPHashTable[i].telephoneNo==-1){
				LPHashTable[i]=cObj;
				break;
			}
			i=(i+1)%BSIZE;
		 }
		if(i==hi)
			cout<<"\nHash Table Full!!";
	}
}

void TelephoneDirectory::searchRecordLP(long int telephoneNo){
	int hi,noc,i;
	hi=telephoneNo%BSIZE;
	noc=0;
	if(LPHashTable[hi].telephoneNo == telephoneNo){
		noc++;
		cout<<"\nRecord found after "<<noc<<" comparisons!";
	}
	else{
		 i=(hi+1)%BSIZE;
		 while(i != hi){
			noc++;
			if(LPHashTable[i].telephoneNo==telephoneNo){
				cout<<"\nRecord found after "<<noc<<" comparisons!";
				break;
			}
			i=(i+1)%BSIZE;
		 }
		if(i==hi)
			cout<<"\nRecord NOT found even after "<<noc<<" comparisons!";
	}
}

void TelephoneDirectory::displayRecordsLP(){
	cout<<"\nTelephone No."<<"\t"<<"Name  ";
	for (int i=0;i<BSIZE;i++)
		cout<<"\n"<<LPHashTable[i].telephoneNo<<"\t\t"<<LPHashTable[i].name;
}

int main(){
	TelephoneDirectory t1;
	string name;
	int ch=0,ch1,telephoneNo;
	
	while(ch!=6)
	{
		cout<<"\n*******  HASH TABLE - LINEAR PROBING********** \n\n";
		cout<<"\n1.INSERT RECORD\n2.DISPLAY All RECORD\n3.SEARCH RECORD\n4.EXIT.";
		cout<<"\nWhat operations:";
		cin >> ch;
		switch(ch)
		{
		case 1:
			t1.insertRecordLP();
			break;
		case 2:
			t1.displayRecordsLP();
			break;
		case 3:
			cout<<"\nEnter the telephone number to be searched::";
			cin>>telephoneNo;
			t1.searchRecordLP(telephoneNo);
			break;
		case 4:
			exit(0);
			break;
		
		default:
			cout<<"\nWrong Choice!!";
		}
	}
	return 0;
}
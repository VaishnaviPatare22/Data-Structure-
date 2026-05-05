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
		CLIENT QPHashTable[BSIZE];
		CLIENT cObj;
	public:
		TelephoneDirectory(){
			for(int i=0;i<BSIZE;i++){
				QPHashTable[i].telephoneNo=-1;
			}
		}
		void init(){
			for(int i=0;i<BSIZE;i++){
				QPHashTable[i].telephoneNo=-1;
			}
		}
		
		void readData();
		void printData();
		void insertRecordQP();
		void displayRecordsQP();
		void searchRecordQP(long int);
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

void TelephoneDirectory::insertRecordQP(){
    int hi, newHI;
    readData();

    hi = cObj.telephoneNo % BSIZE;

    for(int i=0;i<BSIZE;i++){
        newHI = (hi + i*i) % BSIZE;

        if(QPHashTable[newHI].telephoneNo == -1){
            QPHashTable[newHI] = cObj;
            cout<<"\nRecord inserted!";
            return;
        }
    }
    cout<<"\nRecord could not be stored!!";
}

void TelephoneDirectory::searchRecordQP(long int telephoneNo){
	int hi,noc=0;
	int newHI;//new hash index
	hi=telephoneNo%BSIZE;
	for (int i=0;i<BSIZE;i++){
		newHI=(hi+i*i)%BSIZE;
		noc++;
		if(QPHashTable[newHI].telephoneNo==telephoneNo){
			cout<<"\nRecord found after "<<noc<<" comparisons!";
			cout<<"\nName: "<<QPHashTable[newHI].name;
            return; 
		}
	}
	cout<<"\nRecord NOT found even after "<<noc<<" comparisons!";	
}

void TelephoneDirectory::displayRecordsQP(){
	cout<<"\nTelephone No."<<"\t"<<"   Name  ";
	for (int i=0;i<BSIZE;i++)
		cout<<"\n"<<QPHashTable[i].telephoneNo<<"\t"<<QPHashTable[i].name;
}
int main(){
	TelephoneDirectory t1;
	string name;
	int ch=0;
	long int telephoneNo;
	
	while(ch!=6){
		cout<<"\n*******  HASH TABLE - QUADRATIC PROBING********** \n\n";
		cout<<"\n1.INSERT RECORD\n2.DISPLAY All RECORD\n3.SEARCH RECORD\n4.EXIT.";
		cout<<"\nWhat operations:";
		cin >> ch;
		switch(ch)
		{
		case 1:
			t1.insertRecordQP();
			break;
		case 2:
			t1.displayRecordsQP();
			break;
		case 3:
			cout<<"\nEnter the telephone number to be searched::";
			cin>>telephoneNo;
			t1.searchRecordQP(telephoneNo);
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
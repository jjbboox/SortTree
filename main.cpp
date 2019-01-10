#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#include <sys/types.h>
#include "SortTree.h"

using namespace std;
#define defInputNum	3

#define iData_CNT		10000000
#define iData_MAX		10000000

int *iData;

void printTree(SortLeaf *leaf, char end_c);

long long getSystemTime()
{
	struct timeb t;
	ftime(&t);
	return 1000*t.time + t.millitm;
}

int main(int argc, char **argv)
{
	int inputNum = iData_CNT;
	// float fnum;
	
	// Convert parameter 1 to input number if there is a command line argument
	if(argc > 1){
		inputNum = atoi(argv[1]);
	}
	
	// If the command line parameter is not specified, or specified parameter value of 0
	//if(inputNum == 0) {
		//cout << "The number of values specified on the command line is 0." << endl;
	//}
	
	//while(inputNum <= 0) {
		//cout<< "Please enter the number of values to be sorted (greater than 0):";
		//cin >> inputNum;
	//}
	
	SortLeaf* root = NULL;
	
	//for(int i = 0;i < inputNum; i++) {
		//cout<<"Please enter the number " << (i + 1) << "Values:";
		//cin>>fnum;
		//if(root == NULL) {
			//root = new SortLeaf(fnum);
		//}
		//else {
			//root->append(fnum);
		//}
	//}
	//cout<<"End of input"<<endl;

	cout << "Start generating " << inputNum << " random numbers" << endl;
	iData = new int[inputNum];

	for(int i  = 0; i < inputNum; i++ ) {
		iData[i] = rand()%iData_MAX;
		cout << iData[i] << ((i+1)%10==0?'\n':'\t');
	}
	cout << endl << "Random number generation completed" << endl;

	time_t start_time = time(NULL);
	long long start_ms = getSystemTime();
	cout << "Sort start time:" << start_time << endl;

	for(int i = 0; i < inputNum; i++) {
		if(root == NULL) {
			root = new SortLeaf(iData[i]);
		}
		else {
			root->append(iData[i]);
		}
	}
	delete iData;
	
	cout << endl << "Sort job completed" << endl;
	long long end_ms = getSystemTime();
	time_t end_time = time(NULL);

	// cout << endl << "Output sort result" << endl;
	// printTree(root, '\t');
	
	cout << "Sorted timestamps:" << end_time << endl;
	cout << "Sort time:" << (end_ms - start_ms) / 1000.0 << "s" << endl;
	// Delete object, free memory
	if(root != NULL) {
		delete root;
		cout << endl << "The sort tree object was deleted successfully." << endl;
	}

	// cout << "Press any key...";
	// char a;
	// a = getchar();
	return 1;
}

// Recursive function, print sorted series
void printTree(SortLeaf *leaf, char end_c='\n') {
	if(leaf->getSmallLeaf() != NULL) {
		printTree(leaf->getSmallLeaf(), end_c);
	}
  if(leaf != NULL) {
		cout << leaf->getValue() << end_c;
  }
	if(leaf->getBigLeaf() != NULL) {
		printTree(leaf->getBigLeaf(), end_c);
	}
}
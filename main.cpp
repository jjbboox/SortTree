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

#define iData_CNT		10000
#define iData_MAX		10000000

int *iData;

void printTree(SortLeaf *leaf, char end_c);
void printTreeReverse(SortLeaf *leaf, char end_c);

long long getSystemTime()
{
	struct timeb t;
	ftime(&t);
	return 1000*t.time + t.millitm;
}

int main(int argc, char **argv)
{
	int inputNum = iData_CNT;
	
	// Convert parameter 1 to input number if there is a command line argument
	if(argc > 1){
		inputNum = atoi(argv[1]);
	}
	
	SortLeaf* root = NULL;
	
	cout << "Start generating " << inputNum << " random numbers" << endl;
	iData = new int[inputNum];

	for(int i  = 0; i < inputNum; i++ ) {
		iData[i] = rand()%iData_MAX;
		//cout << iData[i] << ((i+1)%10==0?'\n':'\t');
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

	// 以下代码为树状排序结果的输出，在无需输出的情况下可以注释掉
	// cout << endl << "Output sort result" << endl;
	// 从小到大输出
	// printTree(root, '\t');
	// 从大到小输出
	// printTreeReverse(root, '\t');
	// cout << endl;
	
	cout << "Sorted timestamps:" << end_time << endl;
	cout << "Sort time:" << (end_ms - start_ms) / 1000.0 << "s" << endl;
	// Delete object, free memory
	if(root != NULL) {
		delete root;
		cout << "二叉树状链表对象删除成功。" << endl;
	}

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

// 从大到小输出排序结果
void printTreeReverse(SortLeaf *leaf, char end_c='\n') {
	if(leaf->getBigLeaf() != NULL) {
		printTreeReverse(leaf->getBigLeaf(), end_c);
	}
	if(leaf != NULL) {
		cout << leaf->getValue() << end_c;
	}
	if(leaf->getSmallLeaf() != NULL) {
		printTreeReverse(leaf->getSmallLeaf(), end_c);
	}
}

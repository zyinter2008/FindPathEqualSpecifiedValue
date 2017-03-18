#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

struct BSTreeNode {
	int m_nValue; // value of node
	BSTreeNode *m_pLeft; // left child of node
	BSTreeNode *m_pRight; // right child of node
};

void addValue2BsTree(BSTreeNode **current, int value);
void findPathNode(BSTreeNode *s, int expectSum, vector<int> & path,
		int &currentSum);

int main() {
	BSTreeNode *tree = NULL;
	addValue2BsTree(&tree, 10);
	addValue2BsTree(&tree, 5);
	addValue2BsTree(&tree, 12);
	addValue2BsTree(&tree, 4);
	addValue2BsTree(&tree, 7);
	vector<int> path;
	int currentSum = 0;
	findPathNode(tree, 22, path, currentSum);

	return 0;
}

void addValue2BsTree(BSTreeNode **current, int value) {
	if (*current == NULL) {
		BSTreeNode* pTree = new BSTreeNode();
		pTree->m_nValue = value;
		pTree->m_pLeft = NULL;
		pTree->m_pRight = NULL;
		*current = pTree;
	} else if ((*current)->m_nValue > value) {
		addValue2BsTree(&(*current)->m_pLeft, value);
	} else if ((*current)->m_nValue < value) {
		addValue2BsTree(&(*current)->m_pRight, value);
	} else {
		cout << "Equal value" << endl;
	}
}

void findPathNode(BSTreeNode *s, int expectSum, vector<int> & path,
		int &currentSum) {
	if (s == NULL) {
		return;
	}

	currentSum += s->m_nValue;
	path.push_back(s->m_nValue);

	if (s->m_pLeft == NULL && s->m_pRight == NULL && currentSum == expectSum) {
		for (vector<int>::const_iterator it = path.begin(); it != path.end();
				it++) {
			cout << "Equal expect sum, path value:" << *it << endl;
		}
	}

	if (s->m_pLeft != NULL) {
		findPathNode(s->m_pLeft, expectSum, path, currentSum);
	}

	if (s->m_pRight != NULL) {
		findPathNode(s->m_pRight, expectSum, path, currentSum);
	}

	currentSum -= s->m_nValue;
	path.pop_back();
}

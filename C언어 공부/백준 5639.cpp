#include <iostream>

using namespace std;

Node* root;
Node* nodePtr;
int arr[10001];

struct Node {
	bool visit;
	int key;
	Node* parent;
	Node* left;
	Node* right;

	Node(int _key) {
		visit = false;
		key = _key;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};

void Init() {
	int input;
	int idx = 0;

	while (1) {
		cin >> input;

		if (cin.eof() == true)
			break;

		arr[idx++] = input;
	}

	root = new Node(arr[0]);
	nodePtr = root;
	
}

Node* SearchParent(Node* _curNodePtr, int __arrIdx) {
	if (_curNodePtr->key < arr[__arrIdx]) {
		if (_curNodePtr = root) {
			nodePtr = root;
			return root;
		}
		else {
			return SearchParent(_curNodePtr->parent, __arrIdx);
		}
	}
	else if (_curNodePtr->key > arr[__arrIdx]) {
		return _curNodePtr;
	}
}

void Fill(int _arrIdx) {
	if (nodePtr->key > arr[_arrIdx]) {
		nodePtr->left = new Node(arr[_arrIdx]);
		nodePtr->left->parent = nodePtr;
		nodePtr = nodePtr->left;
	}
	else if (nodePtr->key < arr[_arrIdx]) {
		nodePtr = SearchParent(nodePtr, _arrIdx);
		nodePtr->right = new Node(arr[_arrIdx]);
		nodePtr->right->parent = nodePtr;
		nodePtr = nodePtr->right;
	}
	Fill(_arrIdx + 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Init();

	return 0;
}


//#include <iostream>
//
//using namespace std;
//
//int tree[10001];
//int visit[10001];
//int arr[10001];
//
//void SearchLeft(int);
//void SearchRight(int);
//void Visit(int);
//void LRV(int);
//
//void Init() {
//	int input;
//	int idx = 0;
//
//	while (1) {
//		cin >> input;
//
//		if (cin.eof() == true)
//			break;
//
//		arr[idx++] = input;
//	}
//
//	tree[0] = arr[0];
//}
//
//int SearchParentsNode(int __arrIdx, int __curIdx) {
//	if (tree[__curIdx] < arr[__arrIdx]) {
//		if (__curIdx == 0) {
//			return 0;
//		}
//		else {
//			return SearchParentsNode(__arrIdx, (__curIdx - 1) / 2);
//		}
//	}
//	else if (tree[__curIdx] > arr[__arrIdx])
//		return __curIdx  * 2 + 1;
//
//	cout << "SearchParentsNode(" << __arrIdx << ", " << __curIdx << ") Error\n";
//	return 0;
//}
//
//void Fill(int _arrIdx, int _curIdx) {
//	if (tree[_curIdx] > arr[_arrIdx]) {
//		tree[_curIdx * 2 + 1] = arr[_arrIdx];
//		Fill(_arrIdx + 1, _curIdx * 2 + 1);
//	}
//	else if(tree[_curIdx] < arr[_arrIdx]) {
//		int targetNodeIdx;
//
//		if (_curIdx != 0)
//			targetNodeIdx = SearchParentsNode(_arrIdx, (_curIdx - 1) / 2);
//		else if(_curIdx == 0)
//			targetNodeIdx = 0;
//
//		tree[targetNodeIdx * 2 + 2] = arr[_arrIdx];
//		Fill(_arrIdx + 1, targetNodeIdx * 2 + 2);
//	}
//}
//
//void Print() {
//	for (int i = 0; i < 10001; i++) {
//		cout << tree[i] << ' ';
//	}
//}
//
//void SearchLeft(int _curIdx) {
//	if (tree[_curIdx] == 0 || visit[_curIdx] == true)
//		return;
//
//	visit[_curIdx] = true;
//	LRV(_curIdx);
//	cout << tree[_curIdx] << '\n';
//}
//
//void SearchRight(int _curIdx) {
//	if (tree[_curIdx] == 0 || visit[_curIdx] == true)
//		return;
//
//	visit[_curIdx] = true;
//	LRV(_curIdx);
//	cout << tree[_curIdx] << '\n';
//}
//
//void Visit(int _curIdx) {
//	if (tree[_curIdx] == 0 || visit[_curIdx] == true)
//		return;
//
//	visit[_curIdx] = true;
//	LRV(_curIdx);
//	cout << tree[_curIdx] << '\n';
//}
//
//void LRV(int _curIdx) {
//	SearchLeft(_curIdx * 2 + 1);
//	SearchRight(_curIdx * 2 + 2);
//	Visit(_curIdx);
//}
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	Init();
//	Fill(1, 0);
//	LRV(0);
//
//	return 0;
//}
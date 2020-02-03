#include <string>
#include <vector>
using namespace std;
#define  MAX_ELEMENT	1000000

class HeapNode
{
	int			key;
public:
	HeapNode(int key = 0) : key(key) { }
	~HeapNode(void) { }

	void 	setKey(int k) { key = k; }
	int	 getKey() { return key; }
	void 	display() { printf("\t%d", key); }
};

class MinHeap
{
	HeapNode 	node[MAX_ELEMENT];
	int		 size;
public:
	MinHeap() : size(0) { }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode&	getParent(int i) { return node[i / 2]; }
	HeapNode&	getLeft(int i) { return node[i * 2]; }
	HeapNode&	getRight(int i) { return node[i * 2 + 1]; }

	void insert(int key) {
		if (isFull()) return;

		int i = ++size;

		while (i != 1 && key < getParent(i).getKey()) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key);
	}

	HeapNode remove() {
		if (isEmpty()) return NULL;

		HeapNode root = node[1];
		HeapNode last = node[size--];

		int parent = 1;
		int child = 2;

		while (child <= size) {
			if (child < size && getLeft(parent).getKey() > getRight(parent).getKey())
				child++;
			if (last.getKey() <= node[child].getKey()) break;

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return root;
	}

	HeapNode find() { return node[1]; }
};

int solution(vector<int> scoville, int K) {
	MinHeap heap;
	for (int i = 0; i < scoville.size(); i++)
		heap.insert(scoville.at(i));
	int count = 0;
	while (heap.find().getKey() < K) {
		int first = heap.remove().getKey();
		int second = heap.remove().getKey();
		heap.insert(first + second * 2);
		count++;
		if (count >= scoville.size()) {
			count = -1;
			break;
		}
	}
	return count;
}
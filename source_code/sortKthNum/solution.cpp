#include <string>
#include <vector>
#define SWAP(x,y,t) ((t)=(x), (x)= (y), (y)=(t))
using namespace std;

vector<int> editArray(vector<int>array, int min, int max) {
	vector<int> editted;
	for (int i = min; i <= max; i++)
		editted.push_back(array.at(i));
	return editted;
}

vector<int> sorting(vector<int> array) {
	int tmp;
	for (int i = 0; i < array.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < array.size(); j++)
			if (array.at(min) > array.at(j))
				min = j;
		SWAP(array.at(i), array.at(min), tmp);
	}


	printf("sorted array : ");
	for (int i = 0; i < array.size(); i++)
		printf("%d ", array.at(i));
	printf("\n");

	return array;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	int i, j, k;
	for (int m = 0; m < commands.size(); m++) {
		vector<int> tmp;
		i = commands[m].at(0) - 1;
		j = commands[m].at(1) - 1;
		k = commands[m].at(2) - 1;
		printf(" i: %d, j: %d, k: %d\n", i+1, j+1, k+1);
		tmp = editArray(array, i, j);
		tmp = sorting(tmp);
		printf("tmp : ");
		for (int i = 0; i < tmp.size(); i++)
			printf("%d ", tmp.at(i));
		printf("\n");
		printf(" k: %d answer : %d\n", k,  tmp.at(k));
		answer.push_back(tmp.at(k));
	}
	return answer;
}


int main() {
	vector<int> array;
	array.push_back(1);
	array.push_back(5);
	array.push_back(2);
	array.push_back(6);
	array.push_back(3);
	array.push_back(7);
	array.push_back(4);

	vector<vector<int>> commands;
	vector<int> a;
	a.push_back(2);
	a.push_back(5);
	a.push_back(3);
	vector<int> b;
	b.push_back(4);
	b.push_back(4);
	b.push_back(1);
	vector<int> c;
	c.push_back(1);
	c.push_back(7);
	c.push_back(3);

	commands.push_back(a);
	commands.push_back(b);
	commands.push_back(c);

	vector<int> answer;
	answer = solution(array, commands);
	printf("[ ");
	for (int i = 0; i < answer.size(); ++i)
		printf("%d ", answer.at(i));
	printf("]\n");

	system("pause");

}
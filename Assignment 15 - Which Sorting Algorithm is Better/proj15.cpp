// Skeleton codes for Assign15.cpp
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <iterator>
#include <iomanip>
#include "Timer.h"
#include "RandomInt.h"
//#include "Algorithms.h"
#define ALGORITHM(Class , Func) struct Class : AlgorithmTest {Class(string _name, vector<int> _input) : AlgorithmTest(_name, _input){}; void run(){Func(input);}}
using namespace std;

//Test Sorted:
template<class T>
bool isSorted(vector<T>& input) {
	for (int i = 0; i < input.size() - 1; i++) {
		if (input[i] > input[i + 1]) {
			return false;
		}
	}
	return true;
}

struct AlgorithmTest {
public:
	AlgorithmTest(string, vector<int>);
	virtual void run();
	void test();
	Timer timer;
	string name;
	double runtime;
	vector<int> input;
};


AlgorithmTest::AlgorithmTest(string _name, vector<int> _input) {
	name = _name;
	input = _input;
}

void AlgorithmTest::run() {}

void AlgorithmTest::test() {
	timer.Start();
	run();
	timer.Stop();
	runtime = timer.Seconds();
	if (!isSorted(input)) {
		cout << name << " is not sorted" << endl;
	}
}

// STL Sort:
template<class T>
void sTLSort(vector<T>& input) {
	sort(input.begin(), input.end());
}

// Bubble Sort:
template<class T>
void bubbleSort(vector<T>& input) {
	int n = (int)input.size();
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (input[j - 1] > input[j]) {
				swap(input[j - 1], input[j]);							// Invariant: the i largest elements are in the correct locations.
			}
		}
	}
}

// Selection Sort:
template<class T>
void selectionSort(vector<T>& input) {
	int min = 0;
	for (int i = 0; i < (int)input.size() - 1; i++) {
		min = i;
		for (int j = i + 1; j < (int)input.size(); j++) {
			if (input[j] < input[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap(input[min], input[i]);
		}
	}
}

// Insertion Sort:
template<class T>
void insertionSort(vector<T>& input) {
	for (int i = 0; i < 100; i++) {
	}
	int pos, j;
	for (int i = 0; i < input.size(); i++) {
		pos = i;
		for (j = i - 1; j >= 0 && input[j] > input[pos]; j--) {
			input[j + 1] = input[j];
		}
		input[j + 1] = input[pos];
	}
}

// Quick Sort:
template <class T>
int split(vector<T>& input, int first, int last) {
	T pivot = input[first];												// pick the first as pivot element
	int left = first,													// index for left search
		right = last;													// index for right search
	while (left < right) {
		while (pivot < input[right]) {									// Search from right for element <= pivot
			right--;
		}
		while (left < right && (input[left] <= pivot)) {				// Search from left for element > pivot
			left++;
		}
		if (left < right) {												// If searches haven't met
			swap(input[left], input[right]);							// interchange elements
		}
	}
	swap(input[first], input[left]);
	return left;
}

template<class T>
void quickHelper(vector<T>& input, int first, int last) {
	if (first < last) {
		int pi = split(input, first, last);
		quickHelper(input, first, pi - 1);
		quickHelper(input, pi + 1, last);
	}
}

template<class T>
void quickSort(vector<T>& input) {
	quickHelper(input, 0, input.size() - 1);
}

// Merge Sort:
template<class T>
void merge(vector<T>& input, int low, int mid, int high) {
	int left = low; int right = mid + 1;
	int* tempArray = new int[high - low + 1];							// need extra n space, where n is the size of the data set.
	for (int i = 0; i <= high - low; i++) {
		if (right == high + 1) {
			tempArray[i] = input[left];
			left++;
		}
		else if (left > mid) {
			tempArray[i] = input[right];
			right++;
		}
		else if (input[left] < input[right]) {
			tempArray[i] = input[left];
			left++;
		}
		else {
			tempArray[i] = input[right];
			right++;
		}
	}
	for (int j = 0; j <= high - low; j++) {
		input[low + j] = tempArray[j];
	}
}

template<class T>
void mergeHelper(vector<T>& input, int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergeHelper(input, low, mid);
		mergeHelper(input, mid + 1, high);
		merge(input, low, mid, high);
	}
}

template<class T>
void mergeSort(vector<T>& input) {
	mergeHelper(input, 0, input.size() - 1);
}

ALGORITHM(STLSort, sTLSort);
ALGORITHM(BubbleSort, bubbleSort);
ALGORITHM(SelectionSort, selectionSort);
ALGORITHM(InsertionSort, insertionSort);
ALGORITHM(QuickSort, quickSort);
ALGORITHM(MergeSort, mergeSort);

bool compare(AlgorithmTest* a, AlgorithmTest* b) {
	return a->runtime < b->runtime;
}

void report(vector<AlgorithmTest*> tests) {
	string colors[3] = { "\033[1;32m", "\033[1;33m", "\033[1;31m" };
	int c = 0;
	sort(tests.begin(), tests.end(), compare);
	for (int i = 0; i < tests.size(); i++) {
		cout << i + 1 << ": " << setw(15) << left << tests[i]->name << " sort took" << right;
		if (!((i == 0) || (tests[i]->runtime < (tests[i-1]->runtime * 2)))) {
			c += c < 2;
		}
		cout << colors[c];
		cout << setw(20) << tests[i]->runtime << "\033[0m" << " seconds." << endl;
	}
}


int main() {
	vector<int> temp = { 27, 19, 31, 64, 8, 25, 53, 14, 85, 3, 40 };
	RandomInt r;
	vector<int> input;
	int numValues;
	cout << "Sorting array of random integers (0-100000)" << endl;
	cout << "Input the number of random values to be sorted: ";
	cin >> numValues;
	for (int i = 1; i < numValues; ++i) {
		r.Generate(0, 1000000);
		input.push_back(r);
	}
	vector<AlgorithmTest*> tests = {
		new STLSort("STL algorithm", input),
		new BubbleSort("Bubble", input),
		new SelectionSort("Selection", input),
		new InsertionSort("Insertion", input),
		new QuickSort("Quick", input),
		new MergeSort("Merge", input)
	};

	for (AlgorithmTest* test : tests) {
		test->test();
	}
	// rank and print the six sorting algorithms based on the times from the shortest to longest :
	report(tests);
	return 0;
}
/*
Post your sample run:

Sorting array of random integers (0-100000)
Input the number of random values to be sorted: 100000
1: Insertion       sort took               0.039 seconds.
2: Quick           sort took               0.244 seconds.
3: Merge           sort took               0.341 seconds.
4: STL algorithm   sort took               0.351 seconds.
5: Selection       sort took             596.174 seconds.
6: Bubble          sort took             917.739 seconds.
*/


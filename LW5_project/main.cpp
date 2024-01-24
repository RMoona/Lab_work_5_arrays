#include <iostream>
#include <random>

using namespace std;

int main() {

	int taskNr, studentCode, taskVarCount;

	cout << "Enter your student code: ";
	cin >> studentCode;

	cout << "Enter task count: ";
	cin >> taskVarCount;

	taskNr = studentCode % taskVarCount;
	if (taskNr == 0) {
		taskNr = taskVarCount;
	}
	cout << "Your task number is: " << taskNr << endl << "----------------------" << endl;


	int nRows;
	int mColumns;
	cout << "Enter array row count: ";
	cin >> nRows;
	cout << "Enter array column count: ";
	cin >> mColumns;

	char choice;

	int** arr = new int* [nRows];
	for (int i = 0; i < nRows; ++i) {
		arr[i] = new int[mColumns];
	}

	while (true) {
		cout << "Enter 'a' for automatic array filling or 'm' for manual filling : ";
		cin >> choice;

		switch (choice) {
		case 'a': {
			int fromRange, toRange;
			random_device randDev;
			mt19937 generator(randDev());

			cout << "Enter the minimal range: ";
			cin >> fromRange;
			cout << "Enter the maximal range: ";
			cin >> toRange;
			uniform_int_distribution<int> distr(fromRange, toRange);

			for (int i = 0; i < nRows; i++) {
				for (int j = 0; j < mColumns; j++) {
					arr[i][j] = distr(generator);
				}
			}
			break;
		}
		case 'm':
			int number;
			cout << "Enter array elements: " << endl;
			for (int i = 0; i < nRows; i++) {
				for (int j = 0; j < mColumns; j++) {
					cin >> number;
					arr[i][j] = number;
				}
			}
			break;

		default:
			cout << "Wrong value." << endl;
			continue;
		}
		break;
	}

	cout << "The values of the array:" << endl;
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < mColumns; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}


	bool negativeRow = false;
	int posRowSum = 0;

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < mColumns; j++) {

			if (arr[i][j] > 0) {
				posRowSum = posRowSum + arr[i][j];
			}

			if (arr[i][j] < 0) {
				negativeRow = true;
			}

		}
		if (negativeRow) {
			cout << "The sum of positive elements in row that has any negative elements (row No." << i + 1 << ") is: " << posRowSum << endl;
		}
		negativeRow = false;
		posRowSum = 0;

	}

	for (int i = 0; i < nRows; ++i) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;

}
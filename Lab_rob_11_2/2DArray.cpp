#include "2DArray.h"

bool IsNullPtr(const int** arr) {
	if (!arr) {
		cout << "����� �� ��������� ��������." << endl;
		return true;
	}
	return false;
}

void Num(int& num) {
	
	do {
		cin >> num;

		if (num <= 0)
			cout << "����i�� ������ �� ���������." << endl;

	} while (num <= 0);
}

int** create(int &r, int &c) {

	cout << "������ �������� ������� ��� ����� �� ��������: "; Num(r); Num(c);

	int** arr = new int* [r];

	for (int i = 0; i < r; i++)
		*(arr + i) = new int[c];

	return arr;

}

void inic(int** arr, int r, int c) {
	int ans;

	if (IsNullPtr(arr))return;

	cout << "�����i�� ����i� ���������� ������ (0 - ������, i��� �������� - rand): " << endl;
	cin >> ans;

	if (!ans)
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> arr[i][j];
	else {
		srand(time(nullptr));

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				arr[i][j] = rand() % 21 - 10;

	}

}

void show(const int** arr, int r, int c) {

	if (IsNullPtr(arr)) return;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << *(*(arr + i) + j) << " ";;

		cout << endl;
	}

}

void clear(int**& arr, int r) {

	if (IsNullPtr(arr)) return;

	for (int i = 0; i < r; i++)
		delete[] arr[i];

	delete[] arr;

	arr = nullptr;

}

int min(const int** arr, int r, int c) {

	if (IsNullPtr(arr)) return 0;

	int min = **arr;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (min > *(*(arr + i) + j))
				min = *(*(arr + i) + j);

	return min;

}

int max(const int** arr, int r, int c) {
	
	if (IsNullPtr(arr)) return 0;

	int max = arr[0][0];

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (max < arr[i][j])
				max = arr[i][j];

	return max;

}

double average(const int** arr, int r, int c) {

	if (IsNullPtr(arr)) return 0;

	double s = 0;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			s += *(*(arr + i) + j);

	return s / (r * c);

}

int* arrNew(const int** arr, int r, int c) {

	if (IsNullPtr(arr)) return nullptr;

	int k = 0;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (arr[i][j] < 0)
				k++;

	if (!k) {
		cout << "�i�'���i �������� � �������i �i�����i." << endl;
		return nullptr;
	}

	int* arrN = new int[k];
	k = 0;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (arr[i][j] < 0)
				arrN[k++] = arr[i][j];

	return arrN;

}

void showJArr(const int** arr, int c, int* ind) {
	
	cout << setw(10) << "��������" << setw(15) << "���������� �����" << endl;

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < ind[i]; j+=2) 
			cout << setw(10) << arr[i][j] << setw(15) << arr[i][j + 1] + 1;
		
		cout << endl;
	}
}

int** Dod(const int** arr, int r, int c) {
	int** arrD = new int* [c];
	int* cInColumn = new int[c];
	int cnt = 0;

	for (int j = 0; j < c; j++) {
		int a = 0;
		*(cInColumn + j) = 0;
		
		for (int i = 0; i < r; i++) 
			if (*(*(arr + i) + j) > 0) {
				*(cInColumn + j) += 2;
				cnt++;
			}

		*(arrD + j) = new int[*(cInColumn + j)];

		for (int i = 0; i < r; i++)
			if (*(*(arr + i) + j) > 0) {
				*(*(arrD + j) + a++) = *(*(arr + i) + j);
				*(*(arrD + j) + a++) = i;
			}
	}
	if (!cnt) {
		cout << "������i �������� �i�����i � �������i." << endl;
		return nullptr;
	}

	cout << "��i�� ������i����� ������: " << endl;

	showJArr(arrD, c, cInColumn);

	return arrD;

}
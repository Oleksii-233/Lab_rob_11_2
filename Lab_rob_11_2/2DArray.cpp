#include "2DArray.h"

bool IsNullPtr(int** arr) {
	if (!arr) {
		cout << "����� �� ��������� ��������." << endl;
		return true;
	}
	return false;
}

bool IsNullPtr(int* arr) {
	if (!arr)
	
		return true;

	return false;

}

void Num(int& num) {
	
	do {
		cin >> num;

		if (num <= 0)
			cout << "����i�� ������ �� ���������." << endl;

	} while (num <= 0);
}




int** create(int r, int c) {

	int** arr = new int* [r];

	for (int i = 0; i < r; i++)
		*(arr + i) = new int[c];

	return arr;

}

void inic(int** arr, int r, int c) {
	int ans;

	if (IsNullPtr(arr));

	cout << "�����i�� ����i� ���������� ������ (0 - ������, i��� �������� - rand): " << endl;
	cin >> ans;

	if (!ans)
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> arr[i][j];
	else {

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				arr[i][j] = rand() % 21 - 10;

	}

}

void show(int** arr, int r, int c) {

	if (IsNullPtr(arr)) return;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << setw(5) << *(*(arr + i) + j) << " ";

		cout << endl;
	}


}

void show(int* arr, int r) {

	if (IsNullPtr(arr))return;

	for (int i = 0; i < r; i++) 
			cout << setw(5) << *(arr + i) << " ";;

	cout << endl;

}

void clear(int**& arr, int r) {

	for (int i = 0; i < r; i++)
		delete[] arr[i];

	delete[] arr;

	arr = nullptr;

}

void clear(int*& arr) {

	delete[] arr;

	arr = nullptr;

}

void clearArrays(int**& arr, int r, int*& arrN, int**& arrD, int c, int* arrInd) {

	if (arr) {
		clear(arr, r);
		cout << "���'��� ��i������ i� ��������������� ������." << endl;

	}
	if (arrN) {
		clear(arrN);
		cout << "���'��� ��i������ i� ������ ���������� �������i�." << endl;

	}
	if (arrD) {
		clear(arrD, c);
		cout << "���'��� ��i������ i� ������ ������i� �������i� � ������i" << endl;

	}
	if (arrInd) {
		clear(arrInd);
		cout << "���'��� ��i������ �� ������ ��� ���������� �������" << endl;

	}

}




int Min(int** arr, int r, int c) {

	if (IsNullPtr(arr)) return 0;

	int min = **arr;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (min > *(*(arr + i) + j))
				min = *(*(arr + i) + j);

	return min;

}

int Max(int** arr, int r, int c) {
	
	if (IsNullPtr(arr)) return 0;

	int max = arr[0][0];

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (max < arr[i][j])
				max = arr[i][j];

	return max;

}

double average(int** arr, int r, int c) {

	if (IsNullPtr(arr)) return 0;

	double s = 0;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			s += *(*(arr + i) + j);

	return s / (r * c);

}




int* arrNew(int** arr, int r, int c, int& k) {

	if (IsNullPtr(arr)) return nullptr;

	k = 0;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (arr[i][j] < 0)
				k++;

	if (!k) 
		return nullptr;

	int* arrN = new int[k];
	k = 0;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (arr[i][j] < 0)
				arrN[k++] = arr[i][j];

	return arrN;

}

void showJArr(int** arr, int c, int* ind) {
	int k = 0;

	for (int i = 0; i < c; i++) {
		cout << "��������i �������� � " << i + 1 << " ������i �� �� ��������i ������: ";
		for (int j = 0; j < ind[i]; j += 2) {
			cout << setw(3) << arr[i][j] << "(" << arr[i][j] + 1 << ")" << " ";
			k++;
		}
		if (!k)
			cout << "���������i.";
		cout << endl;
	}
}

int** Dod(int** arr, int r, int c, int* cInColumn) {

	if (IsNullPtr(arr)) return nullptr;

	int** arrD = new int* [c];
	cInColumn = new int[c];

	for (int j = 0; j < c; j++) {

		int a = 0;
		*(cInColumn + j) = 0;
		
		for (int i = 0; i < r; i++) 
			if (*(*(arr + i) + j) > 0) 
				*(cInColumn + j) += 2; 
		
				
		*(arrD + j) = new int[*(cInColumn + j)];

		for (int i = 0; i < r; i++)
			if (*(*(arr + i) + j) > 0) {
				*(*(arrD + j) + a++) = *(*(arr + i) + j);
				*(*(arrD + j) + a++) = i;
			}
	}

	return arrD;

}


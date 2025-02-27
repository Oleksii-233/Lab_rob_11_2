#include "2DArray.h"

bool IsNullPtr(int** arr) {
	if (!arr) {
		cout << "Масив не правильно передано." << endl;
		return true;
	}
	return false;
}

bool IsNullPtr(const int* arr) {
	if (!arr)
	
		return true;

	return false;

}

void Num(int& num) {
	
	do {
		cin >> num;

		if (num <= 0)
			cout << "Розмiри задано не правельно." << endl;

	} while (num <= 0);
}

int** create(int &r, int &c) {

	cout << "Введiть значення кiлькостi для рядкiв та стовпцiв: "; Num(r); Num(c);

	int** arr = new int* [r];

	for (int i = 0; i < r; i++)
		*(arr + i) = new int[c];

	return arr;

}

void inic(int** arr, int r, int c) {
	int ans;

	if (IsNullPtr(arr));

	cout << "Виберiть спосiб заповнення масиву (0 - вручну, iнше значення - rand): " << endl;
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

void show(int** arr, int r, int c) {

	if (IsNullPtr(arr)) return;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << setw(5) << *(*(arr + i) + j) << " ";;

		cout << endl;
	}


}

void show(int* arr, int r) {

	if (IsNullPtr(arr))return;

	for (int i = 0; i < r; i++) 
			cout << setw(5) << *(arr + i) << " ";;

	cout << endl;

}

void showNumInd(int** arr, int r, int c) {

	if (!r) {
		cout << "Елементи вiдсутнi." << endl;
		return;
	}

	cout << "Додатнi елементи масиву: " << endl;
	cout << setw(10) << "Значення " << setw(10) << "Рядок" << setw(10) << "Стовпець" << endl;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < 3; j++)
			cout << setw(10) << arr[i][j];
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

void clear(int*& arr) {

	if (IsNullPtr(arr)) return;

	delete[] arr;

	arr = nullptr;

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

	if (!k) {
		cout << "Вiд'ємнi елементи у масивовi вiдстунi." << endl;
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

int** Dod(int** arr, int r, int c, int& row) {
	row = 0;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (*(*(arr + i) + j) > 0)
				row++;

	if (!row) return nullptr;

	int** dod = new int* [row];

	for (int i = 0; i < row; i++)
		*(dod + i) = new int[3];

	int a = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			if (*(*(arr + i) + j) > 0) {
				int b = 0;
				*(*(dod + a) + b++) = *(*(arr + i) + j);
				*(*(dod + a) + b++) = i;
				*(*(dod + a) + b) = j;
				a++;
			}

	}

	return dod;
}

void clearArrays(int**& arr, int r, int*& arrN, int**& arrD, int c) {

	if (arr) {
		clear(arr, r);
		cout << "Пам'ять звiльнена iз користувацького масиву." << endl;

	}
	if (arrN) {
		clear(arrN);
		cout << "Пам'ять звiльнена iз масиву негативних елементiв." << endl;

	}
	if (arrD) {
		clear(arrD, c);
		cout << "Пам'ять звiльнена iз масиву додатнiх елементiв у ствопцi" << endl;

	}

}
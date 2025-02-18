#include "2DArray.h"

int main() {
	setlocale(0, "UKR");
	int** arr = nullptr, * arrN = nullptr, ** arrD = nullptr, r = 0, c = 0, ans;

	do {
		cout << "Виберіть, що бажаєте зробити:\n0 - створення та заповнення двовимiрного динамiчного масиву." << endl;
		cout << "1 - виведення двовимірного масиву." << endl;
		cout << "2 - мінімальне значення масиву." << endl;
		cout << "3 - максимальне значення масиву." << endl;
		cout << "4 - середє арифметичне значення елементів масиву." << endl;
		
		cout << "5 - створення нового динамічного масиву із від'ємних елементів початкового." << endl;
		cout << "6 - формування та виведення нового двовимiрного масиву iз додатнiх елементiв стовпцiв та їх початкових номерiв." << endl;
		cout << "7 - звiльнення динамiчної пам'ятi." << endl;
		cout << "Будь - яке iнше значення для виходу." << endl;

		cin >> ans;

		switch (ans) {
		case 0: {
			arr = create(r, c);
			inic(arr, r, c);
		}break;
		case 1: {
			show(arr, r, c);
		}break;
		case 2: {
			cout << "Мiнiмальне значення елементiв масиву: " << Min(arr, r, c) << endl;
		}break;
		case 3: {
			cout << "Максимальне значення серед елементів масиву: " << Max(arr, r, c) << endl;
		}break;
		case 4: {
			cout << "Середнє значення елементiв масиву: " << average(arr, r, c) << endl;
		}break;
		case 5: {
			arrN = arrNew(arr, r, c);
		}break;
		case 6: {
			arrD = Dod(arr, r, c);
		}break;
		case 7: {
			if (arr)
				clear(arr, r);
			if (arrN)
				clear(arr);
			if (arrD)
				clear(arrD, c);
		}
		default: return;
		}
		
	} while (true);


}
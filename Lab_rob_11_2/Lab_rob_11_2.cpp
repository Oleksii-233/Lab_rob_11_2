#include "2DArray.h"

int main() {
	setlocale(0, "UKR");
	int** arr = nullptr, * arrN = nullptr, ** arrD = nullptr, *arrInd = nullptr, r = 0, c = 0, ans, k = 0;

	srand(time(nullptr));

	do {
		cout << "Виберiть, що бажаєте зробити:\n0 - створення та заповнення двовимiрного динамiчного масиву." << endl;
		cout << "1 - виведення масиву" << endl;
		cout << "2 - мiнiмальне значення масиву." << endl;
		cout << "3 - максимальне значення масиву." << endl;
		cout << "4 - середє арифметичне значення елементiв масиву." << endl;
		
		cout << "5 - створення нового динамiчного масиву iз вiд'ємних елементiв початковогo" << endl;
		cout << "6 - формування та виведення нового двовимiрного масиву iз додатнiх елементiв стовпцiв та їх початкових номерiв." << endl;
		cout << "7 - звiльнення динамiчної пам'ятi." << endl;
		cout << "Будь - яке iнше значення для виходу." << endl;

		cin >> ans;

		switch (ans) {

		case 0: {
			cout << "Введiть значення кiлькостi для рядкiв та стовпцiв: "; Num(r); Num(c);
			arr = create(r, c);
			inic(arr, r, c);
		}break;

		case 1: {
			cout << "Виберiть який масив вивести: 0 - користувацький, 1 - масив вi'ємних елементiв, iнше значення - масив, що мiстить додатнi елементи кожного стовпця." << endl;
			cin >> ans;
			if (!ans)
				show(arr, r, c);
			else if (ans == 1)
				show(arrN, k);
			else
				showJArr(arrD, c, arrInd);
		}break;
		case 2: {
			cout << "Мiнiмальне значення елементiв масиву: " << Min(arr, r, c) << endl;
		}break;
		case 3: {
			cout << "Максимальне значення серед елементiв масиву: " << Max(arr, r, c) << endl;
		}break;
		case 4: {
			cout << setprecision(3) << "Середнє значення елементiв масиву: " << average(arr, r, c) << endl;
		}break;
		case 5: {
			arrN = arrNew(arr, r, c, k); // k - кількість від'ємних елементів для виведення в головній програмі
		}break;
		case 6: {
			arrD = Dod(arr, r, c,arrInd);
		}break;
		case 7: {
			clearArrays(arr, r, arrN, arrD, c,arrInd);
		}break;

		default: return 0 ;
		}
		system("pause");

	} while (true);


}
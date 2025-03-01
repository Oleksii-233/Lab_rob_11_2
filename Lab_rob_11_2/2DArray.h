#pragma once

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

bool IsNullPtr(int** arr); // Перевірка на те чи порожній масив:

bool IsNullPtr(int* arr);

void Num(int& num); // Забезпечує правельне введення розміру масиву




int** create(int r, int c); // Створення нового двовимірного масиву

void inic(int** arr, int r, int c); // Ініціалізація двовимірного масиву

void show(int** arr, int r, int c); // Виведення для двовимірного масиву

void show(int* arr, int r); // Виведення для одновимірного масиву




int Min(int** arr, int r, int c); // Мінімальне значення серед елементів масиву

int Max(int** arr, int r, int c); // Максимальне значення серед елементів масиву

double average(int** arr, int r, int c); // Середня значення елементів масиву



int* arrNew(int** arr, int r, int c, int &k); // Створення нового одновимірного масиву, що буде містити від'ємні елементи користувацького

int** Dod(int** arr, int r, int c, int* cInColumn); // Створення масиву, що буде містити додатні елементи у стовпці

void showJArr(int** arr, int c, int* ind); // Виведення для додатніх елементів у стовпці


void clear(int*& arr); // Вивільнення для одновимірного масиву

void clear(int**& arr, int r); // Вивільнення для двовимірного масиву

void clearArrays(int**& arr,  int r, int*& arrN, int**& arrD, int c, int* arrInd); // Вивільнення для всіх масивів


#endif 
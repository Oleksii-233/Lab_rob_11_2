#pragma once

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int** create(int &r, int &c);

void inic(int** arr, int r, int c);

void show(int** arr, int r, int c);

void show(int* arr, int r);

int Min(int** arr, int r, int c);

int Max(int** arr, int r, int c);

double average(int** arr, int r, int c);

int* arrNew(int** arr, int r, int c, int &k);

int** Vid(int** arr, int r, int c);

void clearArrays(int**& arr,  int r, int*& arrN, int**& arrD, int c);

#endif 
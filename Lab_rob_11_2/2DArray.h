#pragma once

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <ctime>;

using namespace std;

int** create(int r, int c);

void inic(int** arr, int r, int c);

void show(const int** arr, int r, int c);

void clear(int** arr, int r);

int min(const int** arr, int r, int c);

int max(const int** arr, int r, int c);

double average(const int** arr, int r, int c);

int* arrNew(const int** arr, int r, int c);

int** Dod(const int** arr, int r, int c);

#endif 
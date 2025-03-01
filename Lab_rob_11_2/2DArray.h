#pragma once

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

bool IsNullPtr(int** arr); // �������� �� �� �� ������� �����:

bool IsNullPtr(int* arr);

void Num(int& num); // ��������� ��������� �������� ������ ������




int** create(int r, int c); // ��������� ������ ����������� ������

void inic(int** arr, int r, int c); // ����������� ����������� ������

void show(int** arr, int r, int c); // ��������� ��� ����������� ������

void show(int* arr, int r); // ��������� ��� ������������ ������




int Min(int** arr, int r, int c); // ̳������� �������� ����� �������� ������

int Max(int** arr, int r, int c); // ����������� �������� ����� �������� ������

double average(int** arr, int r, int c); // ������� �������� �������� ������



int* arrNew(int** arr, int r, int c, int &k); // ��������� ������ ������������ ������, �� ���� ������ ��'��� �������� ���������������

int** Dod(int** arr, int r, int c, int* cInColumn); // ��������� ������, �� ���� ������ ������ �������� � �������

void showJArr(int** arr, int c, int* ind); // ��������� ��� ������� �������� � �������


void clear(int*& arr); // ���������� ��� ������������ ������

void clear(int**& arr, int r); // ���������� ��� ����������� ������

void clearArrays(int**& arr,  int r, int*& arrN, int**& arrD, int c, int* arrInd); // ���������� ��� ��� ������


#endif 
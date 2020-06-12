#pragma once
#include<iostream>
#include<fstream>
#include <stdio.h>

using namespace std;

const string fileName = "Array.txt";
class Array
{
	int* arr;
	int size;

	inline bool IsValidPosition(int pos);

public:
	Array();

	Array(int size);

	~Array();

	Array(const Array& other);

	void FillArr();

	void AddElement(int value);

	void DeleteElement(int pos);

	int GetMaxElement();

	void SortArr();

	void Print() const;



	Array& operator++();	

	Array& operator--();	

	Array& operator++(int k);	

	Array& operator--(int k);
	
	Array operator-();	

	Array& operator=(const Array& other);	

	operator long();	

	void SaveArr() const;

	operator char* (); 

	int& operator[](int k);

	void operator()(int num);
	
	

};







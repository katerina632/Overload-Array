#include "Array.h"

inline bool Array::IsValidPosition(int pos)
{
	return pos >= 0 && pos < size;
}

Array::Array()
{
	arr = nullptr;
	size = 0;
}

Array::Array(int size)
{
	this->size = size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

Array::~Array()
{
	cout << "!" << endl;
	if (arr != nullptr) {
		delete[] arr;
	}
}

Array::Array(const Array& other)
{
	this->size = other.size;
	this->arr = new int[size];
	for (int i = 0; i < this->size; i++) {
		this->arr[i] = other.arr[i];
	}
}

void Array::FillArr()
{
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 21;
	}
}

void Array::AddElement(int value)
{
	int* newArr = new int[size + 1];

	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	newArr[size] = value;

	delete[] arr;
	arr = newArr;
	++size;
}

void Array::DeleteElement(int pos)
{
	if (IsValidPosition(pos) == 1 && arr != nullptr) {

		--size;
		int* newArr = new int[size];
		for (int i = 0; i < size; i++) {
			if (i < pos - 1)
				newArr[i] = arr[i];
			else
				newArr[i] = arr[i + 1];
		}
		delete[] arr;
		arr = newArr;
	}
	else {
		cout << "Enter correct number!" << endl;
	}
}

int Array::GetMaxElement()
{
	int maxElement = 0;
	if (arr != nullptr) {
		maxElement = arr[0];
		for (int i = 0; i < size; i++) {
			if (arr[i] > maxElement) {
				maxElement = arr[i];
			}
		}
		return maxElement;
	}
	else
	{
		return 0;
	}
}

void Array::SortArr()
{
	if (arr != nullptr) {
		for (int i = 0; i < size - 1; i++)
			for (int j = 0; j < size - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
	}
}

void Array::Print() const
{
	cout << "Array (size=" << size << "): ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

Array& Array::operator++()
{
	for (int i = 0; i < this->size; i++) {
		this->arr[i]++;
	}
	return *this;
}

Array& Array::operator--()
{
	for (int i = 0; i < this->size; i++) {
		this->arr[i]--;
	}
	return *this; 
}

Array& Array::operator++(int k)
{
	Array temp = *this;
	for (int i = 0; i < this->size; i++) {
		this->arr[i]++;
	}
	return temp;
}

Array& Array::operator--(int k)
{
	Array temp = *this;
	for (int i = 0; i < this->size; i++) {
		this->arr[i]--;
	}
	return temp;
}

Array Array::operator-()
{
	for (int i = 0; i < this->size; i++) {
		this->arr[i] *= -1;;
	}
	return *this;
}

Array& Array::operator=(const Array& other)
{
	if (this == &other)
		return *this;

	if (arr != nullptr)
		delete[] arr;

	this->size = other.size;
	this->arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}

Array::operator long()
{
	long sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

void Array::SaveArr() const
{
	ofstream fs;
	fs.open(fileName);
	bool isOpen = fs.is_open();
	if (isOpen == true) {

		for (int i = 0; i < size; i++) {
			fs << arr[i];
		}
	}
	else {
		cout << "Error!" << endl;
	}
	fs.close();
}

Array::operator char* () //ne po programists'ki, ale vse shcho zmogla))))
{
	char* res = nullptr;

	SaveArr();

	ifstream fs;
	fs.open(fileName);
	bool isOpen = fs.is_open();
	if (isOpen == true) {

		char line[100];
		fs.getline(line, 100);
		int lenght = strlen(line) + 1;
		res = new char[lenght];
		strcpy_s(res, lenght, line);
	}
	else {
		cout << "Error!" << endl;
	}
	fs.close();

	return res;
}

int& Array::operator[](int k)
{
	static int InCorrect = INT_MIN;
	if (IsValidPosition(k) == 1 && arr != nullptr) {
		return arr[k];
	}
	else
	{
		cout << "Enter correct index!" ;		
		return InCorrect;
	}
	
}

void Array::operator()(int num)
{
	for (int i = 0; i < size; i++) {
		arr[i] += num;
	}	
}

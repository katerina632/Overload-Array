#include<iostream>
#include "Array.h"


using namespace std;

int main() {

	Array arr1(3);
	arr1.FillArr();
	arr1.Print();
	
	//-arr1;
	arr1.Print();

	//++arr1;
	//arr1--;
	//--arr1;
	//arr1++;
	-arr1;

	arr1.Print();

	Array arr2;
	arr2 = arr1;
	arr2.Print();

	cout << long(arr1) << endl;	

	int i = 97;
	char a =i;
	cout << (int)a << endl;
	
	cout << (char*)arr1 << endl;	
	
	cout << arr1[6] << endl;
	cout << arr1[1] << endl;

	arr1(2);
	arr1.Print();

	system("pause");
	return 0;
}
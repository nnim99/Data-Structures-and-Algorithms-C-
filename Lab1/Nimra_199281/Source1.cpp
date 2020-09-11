#include <iostream>
using namespace std;
void main()
{
	int a, *pa; // Statement 1
	pa = &a; // Statement 2
	cout << "pa = &a --> pa = " << pa << endl << endl;
	pa = pa + 1; // Statement 3
	cout << "pa = pa + 1 --> pa = " << pa << endl << endl;
	pa = pa + 3; // Statement 4
	cout << "pa = pa + 3 --> pa = " << pa << endl << endl;
	pa = pa - 1; // Statement 5
	cout << "pa = pa - 1 --> pa = " << pa << endl << endl;
	pa = pa *4; // Statement 6
	cout << "pa = pa * 4> pa = " << pa << endl << endl;
}
/*
1) Why the memory address stored in pointer “pa” vary by 4 ?
Answer: Because it's integer type. Memory allocated to integer type is 4 bytes.
2) Will the address still vary by 4 if I change the data type of the above mentioned code
from “int” to “long”? Explain your answer.
Answer: Yes, beacuse long type is also allocated memory of 4 bytes.
3) If we try to multiply the address pointed to by “pa” then what will happen? Is this
logically or programmatically correct? Attach screen shot of the output you get when you
try this multiplication.
Answer: No there is a logical error /arthimetic error. it is shown in screenshot.

*/

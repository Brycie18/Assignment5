#include <cstdlib>
#include <iostream>
#include "myArray.h"

using namespace std;



int main (int argc, char **argv)
{ 
	cout << "**************Testing Default Constructor*****************" << endl;   
	myArray A1;
	cout << "A1: ";
	A1.print();

	cout << "**************Testing Alt Constructor 1*****************" << endl;	
	myArray A2(5,0);
	cout << "A2: "; 
	A2.print();
	
	cout << "**************Testing init*****************" << endl;	
	A2.init();
	cout << "A2 after init: "; 
	A2.print();
	
	int size = 5;	
	double *temp = new double[size];
	for(int i = 0; i < size; i++)
	{
		temp[i] = i;
	}
	
	cout << "**************Testing Alt Constructor 2*****************" << endl;	
	myArray A3(temp, size); 
	cout << "A3: "; 
	A3.print();
	
	delete [] temp;
	
	/*cout << "**************Testing get*****************" << endl;
	cout << "The element at index 0 is : " << A3.get(0) << endl;
	cout << "The element at index 10 is : " << A3.get(10) << endl;
	
	cout << "**************Testing insert*****************" << endl; 
	A3.insert(5,7.5);
	cout << "A3 after insert: " << endl;
	A3.print();
	
	cout << "**************Testing remove*****************" << endl; 
	A3.remove(1);
	cout << "A3 after remove: " << endl;
	A3.print();
	
	cout << "**************Testing find*****************" << endl; 
	cout << "7.5 was found at index " << A3.find(7.5) << endl;
	
	cout << "**************Testing equals*****************" << endl; 
	bool ans = A2.equals(A3);
	if(ans)
	{
		cout << "A2 equals A3." << endl;
	}
	else
	{
		cout << "A2 does not equal A3." << endl;
	}
	
	ans = A2.equals(A2); 
	if(ans)
	{
		cout << "A2 equals A2." << endl;
	}
	else
	{
		cout << "A2 does not equal A2." << endl;
	}
	
	cout << "**************Testing clear*****************" << endl; 
	A3.clear();
	cout << "A3 after clear: " << endl;
	A3.print();
	
	A2.clear();
	cout << "A2 after clear: " << endl;
	A2.print();*/
	
	cout << "***************Testing operator= non cascade*************" << endl;
	
	cout << "Before equals " << endl;
	cout << "A1 : ";
	A1.print(); 
	cout << "A2 : ";
	A2.print(); 
	
	A1 = A2; 
	
	cout << "After equals " << endl;
	cout << "A1 : ";
	A1.print(); 
	cout << "A2 : ";
	A2.print(); 
	
	cout << "***************Testing operator= cascade*************" << endl;
	
	cout << "Before equals " << endl;
	cout << "A1 : ";
	A1.print(); 
	cout << "A2 : ";
	A2.print(); 
	cout << "A3 : ";
	A3.print(); 
	
	A1 = A2 = A3; 
	
	cout << "After equals " << endl;
	cout << "A1 : ";
	A1.print(); 
	cout << "A2 : ";
	A2.print(); 
	cout << "A3 : ";
	A3.print(); 
	
	cout << "***************Testing operator== *************" << endl;
	cout << "A1 : ";
	A1.print(); 
	cout << "A2 : ";
	A2.print(); 
	
	if(A1 == A2)
	{
		cout << "A1 equals A2" << endl;
	}
	else
	{
		cout << "A1 does not equal A2" << endl;
	}
	
	myArray A4(5,1);
	cout << "A1 : ";
	A1.print(); 
	cout << "A4 : ";
	A4.print(); 
	if(A1 == A4)
	{
		cout << "A1 equals A4" << endl;
	}
	else
	{
		cout << "A1 does not equal A4" << endl;
	}
	
	cout << "***************Testing operator!= *************" << endl;
	cout << "A1 : ";
	A1.print(); 
	cout << "A2 : ";
	A2.print(); 
	
	if(A1 != A2)
	{
		cout << "A1 does not equal A2" << endl;
	}
	else
	{
		cout << "A1 equals A2" << endl;
	}
	
	cout << "A1 : ";
	A1.print(); 
	cout << "A4 : ";
	A4.print(); 
	if(A1 != A4)
	{
		cout << "A1 does not equal A4" << endl;
	}
	else
	{
		cout << "A1 eqauls A4" << endl;
	}
	
	cout << "***************Testing operator+ non-cascading*************" << endl;
	cout << "A1 : ";
	A1.print(); 
	cout << "A4 : ";
	A4.print(); 
	myArray A5;
	A5 = (A1 + A4);
	
	cout << "A5 : ";
	A5.print(); 
	
	cout << "***************Testing operator+ cascading*************" << endl;
	cout << "A1 : ";
	A1.print(); 
	cout << "A4 : ";
	A4.print(); 
	cout << "A2 : ";
	A2.print(); 
	
	A5 = (A1 + A4 + A2);
	
	cout << "A5 : ";
	A5.print();
	
	cout << "***************Testing operator- *************" << endl; 
	cout << "Before negation:" << endl; 
	cout << "A5 : ";
	A5.print();
	A5 = -A5;
	cout << "After negation:" << endl; 
	cout << "A5 : ";
	A5.print();
	
	cout << "***************Testing operator++ (post) *************" << endl; 
	
	cout << "Before ++:" << endl; 
	cout << "A5 : ";
	A5.print();
	cout << "A4 : ";
	A4.print();
	
	A5 = A4++;
	
	cout << "After ++:" << endl; 
	cout << "A5 : ";
	A5.print();
	cout << "A4 : ";
	A4.print();
	
	cout << "***************Testing operator++ (pre) *************" << endl; 
	
	cout << "Before ++:" << endl; 
	cout << "A5 : ";
	A5.print();
	cout << "A4 : ";
	A4.print();
	
	A5 = ++A4;
	
	cout << "After ++:" << endl; 
	cout << "A5 : ";
	A5.print();
	cout << "A4 : ";
	A4.print();
	
	cout << "***************Testing operator[] *******************" << endl; 
	cout << "The value of A5 at 0 is: " << A5[0] << endl;
	cout << "The value of A5 at 100 is: " << A5[100] << endl;
	
	/*cout << "***************Testing operator() *******************" << endl;
	cout << "A5 : ";
	A5.print();
	
	A5(0,100);
	
	cout << "A5 : ";
	A5.print();
	
	A5(100,100);*/
	
	cout << "***************Testing operator<< (non cascade) *********" << endl;
	
	cout << "A5: " << endl;
	cout << A5;
	
	cout << "***************Testing operator<< (cascade) *********" << endl;
	
	cout << "A5: " << A5 << endl;
	
	cout << "***************Testing operator >> (non cascade) *********" << endl;
	
	cin >> A5;
	cout << "A5: " << endl;
	cout << A5;
	
	cout << "***************Testing operator >> (cascade) *********" << endl;
	cout << "A4: " << endl;
	cout << A4;	
	
	cout << "A3: " << endl;
	cout << A3;	
	
	cin >> A4 >> A3;
	
	cout << "A4: " << endl;
	cout << A4;	
	
	cout << "A3: " << endl;
	cout << A3;	
	
    return 0;
}

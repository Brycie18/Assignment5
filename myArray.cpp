/*
 * Bryce Tant
 * October 1st, 5:30pm
 * Function: Create and test an Array object using previous code
 * Input: None
 * Output: Arrays
*/

#include "myArray.h"
#include <iostream>

myArray::myArray() {
    size = 0;
    arr = new double[size];
    for(int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

myArray::myArray(int _size, double num) {
    size = _size;
    arr = new double[size];
    for(int i = 0; i < size; i++) { //sets all elements to num
        arr[i] = num;
    }
}

myArray::myArray(double *_arr, int _size) {
    size = _size;
    arr = new double[size];
    for(int i = 0; i < size; i++) {
        arr[i] = _arr[i];
    }
}

myArray::myArray(const myArray& orig) {
    setSize(orig.getSize());
    arr = new double [getSize()];
    for (int i = 0; i < getSize(); i++) {
        setArr(i, orig.getArr(i));
    }
}

myArray::~myArray() {
    delete [] arr;
}

void myArray::insert(int index, double num) { //Inserts an element at the specified index

	double *localArray = new double[size + 1];

    for(int i = 0; i < size; i++) {
        localArray[i] = arr[i];
    }

    localArray[size] = size;
    delete [] arr;
    setSize(size + 1);
    arr = localArray;
    arr[index] = num;
}

void myArray::remove(int index) { //removes the element at the specified index
	
	if(index > size)
	cout << "Index is not within the bounds of 0..n" << endl;	

    else {
	for(int i = index; i < size; i++) {
    arr[i] = arr[i+1];
	}
	size--;
	}
}

double myArray::getArr(int index) const {
    if ((index >= 0) && (index < size)) {
        return arr[index];
    } else {
        return arr[size - 1];
    }
}

void myArray::clear() { //deletes all elements 

    for(int i = 0; i < size; i++) {
        arr[i] = 0;
    }
	size = 0;
}

int myArray::find(double num) { //checks if a specified element is in the array

	for(int i = 0; i < size; i++) {

	if(arr[i] == num)
	return i;

	}
	return -1;
}

bool myArray::equals(const myArray& rhs) const {
    bool result(true);

    if (getSize() != rhs.getSize()) {
        result = false;
    } else {
        for (int i = 0; i < getSize(); i++) {
            if (getArr(i) != rhs.getArr(i)) {
                result = false;
            }
        }
    }
    return result;
}

void myArray::print() const {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void myArray::init() { //populates the array
	cout << "Please enter " << size << " elements to populate the array" << 	endl;

	for(int i = 0; i < size; i++) {
	cin >> arr[i];
	}
}

int myArray::getSize() const {
    return size;
}

void myArray::setSize(int value) {
    if (value > 0) {
        size = value;
    }
}

void myArray::setArr(int index, double value) {
    if ((index >= 0) && (index < size)) {
        arr[index] = value;
    } else {
        cout << "NO!" << endl;
    }
}

myArray& myArray::operator=(const myArray& rhs) {

    if(this != &rhs) {  
        delete [] arr;
        setSize(rhs.getSize());
        arr = new double [getSize()];
        for (int i = 0; i < size; i++) {
            arr[i] = rhs[i];
        }
    }
    return *this;
}

bool myArray::operator==(const myArray& rhs) const {
    bool result(true);

    if (getSize() != rhs.getSize()) {
        result = false;
    } else {
        for (int i = 0; i < getSize(); i++) {
            if (getArr(i) != rhs.getArr(i)) {
                result = false;
            }
        }
    }
    return result;
}

bool myArray::operator!=(const myArray& rhs) const {
    bool result(false);

    if (getSize() != rhs.getSize()) {
        result = true;
    } else {

        for (int i = 0; i < getSize(); i++) {
            if (arr[i] != rhs[i]) {
                result = true;
            }
        }
    }
    return result;
}

const myArray myArray::operator+(const myArray& rhs) const {
    myArray Cookies(rhs);
    if (getSize() != rhs.getSize()) {
        cout << "Exception" << endl;
    } else {
        for (int i = 0; i < getSize(); i++) {
            Cookies.setArr(i, rhs[i] + arr[i]);
        }
    }
    return Cookies;
}

const myArray myArray::operator-() const {

    for(int i = 0; i < getSize(); i++) {
        arr[i] = -arr[i];
    }
    return *this;
}

const myArray myArray::operator++() {
    for(int i=0; i < getSize(); i++) {
        arr[i]++;
    }
    return *this;
}

const myArray myArray::operator++(int dummy) {
    myArray temp(*this);
    
    for(int i=0; i < getSize(); i++) {
        arr[i]++;
    }
    return temp;
}

double myArray::operator[](int index) const {
    if ((index >= 0) && (index < size)) {
        return arr[index];
    } else {
        return arr[size - 1];
    }
}


ostream & operator<<(ostream &lhs, const myArray &rhs) {
    for (int i = 0; i < rhs.getSize(); i++) {
        lhs << rhs[i] << " ";
    }
    cout << endl;
    return lhs;
}

istream & operator>>(istream &lhs, myArray &rhs) {
    double temp;
    for (int i = 0; i < rhs.getSize(); i++) {
        lhs >> temp;
        rhs.setArr(i, temp);
    }
    return lhs;
}

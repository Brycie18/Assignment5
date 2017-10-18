/*
 * Bryce Tant
 * October 1st, 5:30pm
 * Function: Create and test an Array object using previous code
 * Input: None
 * Output: Arrays
*/

#include <iostream>
using namespace std;
 
class myArray
{

    friend ostream & operator<<(ostream &lhs, const myArray &rhs);
    friend istream & operator>>(istream &lhs, myArray &rhs);    

	public: 
		myArray();
		myArray(int, double); 
		myArray(double*, int);
        myArray(const myArray& orig);
		~myArray();
		
		void insert(int, double);
		void remove(int);
		double getArr(int index) const;
		void clear();
		int find(double);
        bool equals(const myArray& rhs) const;
		void print() const;
		void init();
        int getSize() const;
        void setArr(int, double);

        myArray & operator=(const myArray& rhs);
        bool operator==(const myArray& rhs) const;
        bool operator!=(const myArray& rhs) const; 
        const myArray operator+(const myArray & rhs) const;
        const myArray operator-() const;
        const myArray operator++();
        const myArray operator++(int);
        double operator[](int index) const;
		
		
	private: 
		int size; 
		double *arr;
        void setSize(int);
};

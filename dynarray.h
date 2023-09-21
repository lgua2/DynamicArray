#pragma once
#include <iostream>
#include <string>

class DynArray {
public:
DynArray(int arrSize ); // constructor initializer
DynArray( const DynArray &otherArr ); // cop constructor
void set(int val, int i ); // set member function
int getValueAt(int i ) const; //get member function
void operator=(const DynArray &otherArr);
~DynArray( );
void loopSet(int &value, int &addy, DynArray &arr1);
void print(int size, const DynArray &arr1);
void QNA(int &value, int &addy, DynArray &arr1);
private:
int* arr ;
int size ;
};
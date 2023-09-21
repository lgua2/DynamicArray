#include <iostream>
#include <string>
#include <cstdlib>
#include "dynarray.h"

using namespace std;

int main(){

int yourSize;
cout << "Please enter your dynamic array size: " << endl;
cin >> yourSize;

DynArray yourArray(yourSize);

int val;
int place;

cout << "Please enter a numerical value followed by the location in the array you would like to place it. Type 999 after the first use to stop." << endl;

cin >> val;
cin >> place;

yourArray.loopSet(val,place,yourArray);


}
DynArray::DynArray(int arrSize )
// Constructor.
// PRE: arrSize is assigned
// POST: IF arrSize >= 1 && enough memory THEN
// Array of size arrSize is created with
// all elements == 0 ELSE error message.
{
int i;
if ( arrSize < 1 ) {
cerr << "DynArray constructor - invalid size: " << arrSize << endl;
exit(1);
}
arr = new int[arrSize] ; // allocate memory
size = arrSize;
for (i = 0; i < size; i++)
arr[i] = 0;
}
void DynArray::set (int val, int i)
// PRE: val and i are assigned
// POST: IF 0 <= i < size of this array THEN
// arr[i] == val
// ELSE error message.
{
if ( i < 0 || i >= size ) {
cerr << "set - invalid index : " << i << endl;
exit(1) ;
}
arr[i] = val ;
}
int DynArray:: getValueAt(int i) const {
if ( i < 0 || i >= size ) {
cerr << "getValueAt - invalid index : " << i << endl;
exit(1) ;
}
return arr[i];
}
void DynArray::operator=(const DynArray &otherArr)
// programmer-defined assignment operator 
//POST: Array pointed to by arr@entry deallocated
// && IF room on free set
// THEN new array is created on free set
// && arr == its base address
// && size == otherArr.size
// && arr[0..size-1] == otherArr[0..size-1]
// ELSE halts with error message.
{
int i ;
delete [ ] arr ; // delete current array
size = otherArr.size ;
arr = new int [size] ; // allocate new array
for ( i = 0; i< size ; i++ ) // deep copy array
arr[i] = otherArr.arr[i] ;
}
DynArray::DynArray(const DynArray &otherArr)
// Copy constructor
// Implicitly called for deep copy in initializations.
// POST: If room on free set THEN
// new array of size otherArr.size is created
// on free set && arr == its base address
// && size == otherArr.size
// && arr[0..size-1] == otherArr.arr[0..size-1]
// ELSE error message.
{
int i ;
size = otherArr.size ;
arr = new int[size] ; // allocate memory for copy
for ( i = 0; i< size ; i++ )
arr[i] = otherArr.arr[i] ; // copies array
}
DynArray::~DynArray(){
cout << "destructor" << endl; 
delete [ ] arr;
}
void DynArray::print(int size, const DynArray &arr1){
    int addy = 0;
    for (addy = 0; addy < arr1.size; addy++){
    cout << "The value at location " << addy << " is " << arr1.getValueAt(addy) << endl;
}
}
void DynArray::loopSet(int &value, int &addy, DynArray &arr1){

string key1 = "999STOP";
int key2 = stoi(key1);



while (value != key2 && addy != key2){
    arr1.set(value,addy);
    cin >> value;
    if (value == key2){
    arr1.print(size,arr1);
    arr1.QNA(value,addy,arr1);
    }
    cin >> addy;
    if (addy == key2){
    arr1.print(size,arr1);
    arr1.QNA(value,addy,arr1);
    }
    else if (value == key2 && addy == key2){
        cout << "Thanks for trying my program!" << endl;
    }
    
}

}
void DynArray::QNA(int &value, int &addy, DynArray &arr1){
cout << "Would you like to make another array? Please type Y for yes or N for no." << endl;
char qna;
cin >> qna;

if (qna == 'N'){
    cout << "Thanks for trying my program!" << endl;
}
else if (qna == 'Y'){
int size;
cout << "Please enter your dynamic array size: " << endl;
cin >> size;

DynArray arr1(size);

cout << "Please enter a numerical value followed by the location in the array you would like to place it. Type 999 to stop." << endl;
cin >> value;
cin >> addy;

arr1.loopSet(value,addy,arr1);
arr1.print(size, arr1);
}
else if (qna != 'N' || qna != 'Y'){
cerr << "Invalid answer ur a bot" << endl;
}
}


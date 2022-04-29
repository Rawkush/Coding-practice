# include<iostream>
using namespace std;

/*

    Stack stores all variables made by program, stack size is determined at the start of program so it
    have limited storage, so dynamic allocation can cause problem if a big size is needed.

    Heap have big storage so use this for dynamic allocation

    OR

    use vectors


    NOTE:

     static memeory is released automatically but dynamic needed to be done manually
*/

int main(){

    int a=1; // static memory allocation

    /*


    */
    int n;
    cout<<"enter size of array ";
    cin>>n;
    int a1[n]; // dynamic memory allocation but it is done in stack, if c big this wall cause error

    /*
        new int;

        this makes storage for vaiable in heap;
        so to access it use pointers;
        this pointer is made in stack memory

    */

    int* p= new int;
    *p=10;


    // for array

    int *pa= new int[n]; // this array is stored in heap so size is not an issue now
    // pa is pointer  to access the array and is stored in stack
    pa[2]=10;
    //or
    *(pa+2)=15;
    cout<<"p[2] "<<pa[2]<<endl;
    cout<<"*(p+2) "<<*(pa+2);

    delete [] pa; // freeing dynamically alloted memory
    delete p;
}




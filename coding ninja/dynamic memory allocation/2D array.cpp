#include<iostream>
using namespace std;

/*
    we cant make @D array in heap with simple syntax like
    new int[][]

    THIS IS NO ALLOWED

    make mutliple 1D array and store their address in another !Darray


*/

int main(){

    int *row1 = new int[20];
    int *row2 = new int[20];
    int *row3= new int[20];
    int *row4= new int[20];

    // storing rows in another 1d array to make @D ayyar

 /*
    new int*[4] because we want to store pointers in the array
    and sinwe want to save address of pointers we need double pointer


 */
    int **p=new int*[4];
    p[0]=row1;
    p[1]=row2;
    p[2]=row3;
    p[3]=row4;
/*
    we can simply access the data as we acces in normal 2D array
    i.e.. p[1][1]

*/
    p[0][0]=10;
    cout<<p[0][0]<<endl;

    /*
        to free the storage you have to delete each row individually

    */

    for(int i=0;i<4;i++)
        delete [] p[i];

}

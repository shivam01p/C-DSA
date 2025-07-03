#include <iostream>
#include <climits>
using namespace std;

//todo: Function for swapping max and min num of an array

void sMaxMin(int arr[], int sz){

    int smallest = arr[0];
    int largest = arr[0];
    int sm_index;
    int lg_index;

    for(int i = 0; i < sz; i++){

        if(arr[i] < smallest){

            smallest = arr[i]; 
            sm_index = i;
        }

        if(arr[i] > largest){

            largest = arr[i];
            lg_index = i;
        }

    }
    
    cout << "smalest= " << smallest << endl;
    cout << "largest= " << largest << endl;
    
    swap (smallest, largest);
    cout << "After swapping" << endl;
    
    cout << "smalest= " << smallest << endl;
    cout << "largest= " << largest << endl;

    swap(arr[sm_index], arr[lg_index]);

}

//todo: Function to print unique value of an array

void unqVal(float arr[], int sz){

    float unqVal;
    bool unq;
    bool flag = false;
    for(int i=0; i<sz; i++){
        
        unq = true;
        for(int j=0; j<sz; j++){

            if(i != j && arr[i] == arr[j]){
                
            unq = false;
            break;
            
            }
            
        }

        if(unq == true){
            unqVal = arr[i];
            cout << unqVal << " ";
            flag = true;
        }

    }

    if(flag == false){
        cout << "There is no unq value";
    }

}

//todo: Function for finding intersection of two array

void insArray(int a[], int sza, int b[], int szb){

    bool flag = false;
    for(int i=0; i<sza; i++){

        for(int j=0; j<szb; j++){

            if(a[i] == b[j]){
                
                flag = true;
                cout << a[i] ;

            }

        }

    }

    if(flag == false){
        cout << "Ther is no common numbers";
    }

}

int main(){

    // int a[] = {30, 20, 40, 10, 50, 60};
    // int sz = sizeof(a) / sizeof(int);

    // sMaxMin(a, 6);
    // for(int i=0; i<6; i++){

    //     cout << a[i] << " ";
    // }
    
    // float a[] = {(float)1.89, (float)2.9, (float)1.89, (float)3.20, (float)2.78, (float)3.20};
    // float sz = sizeof(a) / sizeof(float);
    // unqVal(a, sz);

    // int a[] = {10, 45, 30};
    // int b[] = {90, 5, 24, 7, 43};
    // int sza = sizeof(a) / sizeof(int);
    // int szb = sizeof(b) / sizeof(int);

    // insArray(a, sza, b, szb);

    return 0;
}
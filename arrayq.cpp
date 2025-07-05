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
                cout << a[i] << "\n";

            }

        }

    }

    if(flag == false){
        cout << "Ther is no common numbers";
    }

}

//todo: Maximum subarray sum (Time complexity is O(n^3))

int mSS1(int a[], int sz){

    int maxSum = INT_MIN;

    for(int st=0; st<sz; st++){

        for(int end=st; end<sz; end++){

            int cursum = 0;
            for(int k=st; k<=end; k++){

                cursum += a[k];
            }
            maxSum = max(maxSum, cursum);
        }
    }
    return maxSum;
}

//? Another way to print Maximum subarray sub (the easiest way is in the vector.cpp file)

int mSS2(int a[], int sz){

    int maxSum = INT_MIN;

    for(int st=0; st<sz; st++){

        int curSum = 0;
        for(int end=st; end<sz; end++){

            curSum += a[end];                           //? Here we don't have to do sum of those num which is already done 
            maxSum = max(maxSum, curSum);
        }
    }
    return maxSum;
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

//todo: Subarray (kadane's algorithm)

    // int n = 5;
    // int a[] = {1, 2, 3, 4, 5};

    // for(int st = 0; st < n; st++){

    //     for(int end = st; end < n; end++){

    //         for(int i = st; i <= end; i++){
    //             cout << a[i];
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

//todo: Maximum subarray sum

    int ar[] = {3, 2, -6, 9, 1, -2, 5};
    int sz = sizeof(ar) / sizeof(int);
    cout << mSS1(ar, sz) << "\n";
    cout << mSS2(ar, sz);

    return 0;
}
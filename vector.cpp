#include <iostream>
#include <climits>
#include <vector>

using namespace std;
 
//todo: Function for linear search 

int linearS(vector<int> vc,int target){

    for(int i=0; i<vc.size(); i++){

        if(vc[i] == target){
            return i;
        }
    }
    return -1;
}

//todo: Reverse an vector

void reverseVc(vector<int> &vc){                                  //? Here if we didn't write "&" then vector in main function will be remain same

    int end = vc.size()-1;
    for(int start=0; start<end ; start++){

        swap(vc[start], vc[end]);
        end--;
    }

    for(int i: vc){
        cout << i << " ";
    }
    cout << endl;
}

//todo: Kadane's algorithm to find maximum subarray sum

int kMSS(vector<int> &vc){

    int curSum = 0, maxSum = INT_MIN;
    for(int val: vc){

        curSum += val;
        maxSum = max(maxSum, curSum);
        
        if(curSum < 0){
            curSum = 0;
        }
    }
    return maxSum;
}

//todo: Pair sum

vector<int> pairS(vector<int> vc, int target){

    vector<int> ans;
    int sz = vc.size();
    for(int i=0; i<sz; i++){

        for(int j=i+1; j<sz; j++){

            if(vc[i] + vc[j] == target){
                
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

int main(){

    // std::cout << __cplusplus << std::endl;                      //? to print std of the c++
    // vector<int> vect;                                           //? Initializtion of vector
    // vector<int> vec(3,2);
    // vector<int> vc = {3, 5, 2};
     
    // cout << "size = " << vc.size() << endl;                     //? It gives the size of vector
    // vc.push_back(7);                                            //? push(add) the value at the back side(last digit)(last position)
    // vc.pop_back();                                              //? pop(remove) the value at the end of vector
    // cout << vc.at(2) << "\n";                                   //? print the specific value at given idex
    
    // //for each loop
    // for(int i : vc){
    //     cout << i << " ";                                       //? Here i will print the value at any i idnex of vc
    // }

    // vector<int> vc = {3, 54, 23, 67, 32, 5};
    // int target = 23;;
    // cout << linearS(vc, target);

    // vector<int> vc = {1, 2, 3, 4, 5};
    // reverseVc(vc);

    // for(int i : vc){
    //     cout << i << " ";
    // }

    vector<int> vc = {3, 2, -6, 9, 1, -2, 5};
    // cout << kMSS(vc);

    vector<int> ans =  pairS(vc, 10);
    cout << "indices are = " << ans[0] << " & " << ans[1];

    return 0;
}
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

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

//? another method

vector<int> ps(vector<int> vc, int target){

    int sz = vc.size();
    vector<int> ans;
    int i = 0, j = sz-1;

    while(i<j){

        int pairSum = vc[i] + vc[j];

        if(pairSum < target){

            i++;

        }else if(pairSum > target){

            j--;

        }else{

            ans.push_back(i);
            ans.push_back(j);
            return ans;
            
        }
    } 
    return ans;
}

//todo: Function for majority element (brute force method) [Here we are assuming that element is always exist which is (>n/2)]

int majE1(vector<int> nums){

    int n = nums.size();
    int ans;
    for(int val : nums){                                //? Point to the first element

        int freq = 0;
        for(int el : nums){                             //? Traverse whole vector and check how many time val is present by increasing freq
           
            if(el == val){
                freq++;
            }
        }

        if(freq > n/2){
            ans = val;
            return ans;
        }
    }
    return ans;
}

//? Using sorting

int majE2(vector<int> vc){

    int ans = vc[0];
    int freq = 1;
    int sz = vc.size();
    sort(vc.begin(), vc.end());

    for(int i = 1; i < sz; i++){

        if(vc[i] == vc[i-1]){
            freq++;
        }else{
            freq = 1;
            ans = vc[i];
        }

        if(freq > sz/2){
            return ans;
        }
    }
    return -1;
}

//todo:  moore's voting algorithm

int majE3(vector<int> vc){

    int freq = 0;
    int ans = 0;

    for(int i = 0; i<vc.size(); i++){

        if(freq == 0){
            ans = vc[i];
        }
        if(vc[i] == ans){
            freq++;
        }else{
            freq--;
        }
    }
    return ans;
}

int main(){

    // cout << __cplusplus << endl;                                //? to print std of the c++
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

    // vector<int> vc = {3, 2, -6, 9, 1, -2, 5};
    // cout << kMSS(vc);

    // vector<int> ans =  pairS(vc, 10);
    // cout << "indices are = " << ans[0] << " & " << ans[1];

    vector<int> a = {2, 2, 1, 3, 5, 7, 2, 2, 2, 2};
    cout << majE3(a);

    return 0;
}
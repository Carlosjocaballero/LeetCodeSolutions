/**
 * @file PlusOne.cpp
 * @author Carlos Caballero (carlosjocaballero@gmail.com)
 * @brief given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
 *        This program will increment the large integer by one and return the resulting array of digits.
 * @version 0.1
 * @date 2022-04-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>
#include <iostream>
using namespace std;

vector<int> plusOne(vector<int>& digits){
    int lastDigit = digits[digits.size() - 1];
    int position = -1;
    if(lastDigit == 9){
        for(int i = digits.size() ; i > 0; --i){
            if(digits[i-1] != 9){
                position = i-1;
                break;
            }
        }

        if(position != -1){
            int numInPosition = digits[position];
            fill(digits.begin() + position, digits.end(), 0);
            digits[position]= numInPosition + 1; 
        }
        else{
            digits.push_back(0);
            fill(digits.begin(), digits.end(), 0);
            digits[0] = 1;
        }

    }
    else{
        digits[digits.size() - 1] += 1;
    }
    return digits;
}


int main() {
    vector<int> digits = {9,9,9,9};
    vector<int> result = plusOne(digits);

    cout << "[";
    for(int i = 0; i < result.size(); ++i){
        if(i == result.size() - 1)
            cout << result[i] << "]\n";
        else cout << result[i] << ", ";
    }
}
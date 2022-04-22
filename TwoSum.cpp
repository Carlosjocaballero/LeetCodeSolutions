/**
 * @file TwoSum.cpp
 * @author Carlos Caballero (carlosjocaballero@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

vector<int> TwoSum(vector<int>& nums, int target){
    vector<int> solution;
    for(int i=0; i<nums.size(); ++i){
        for(int j=i+1; j < nums.size(); ++j){
            if(nums[i] + nums[j] == target){
                solution.push_back(i);
                solution.push_back(j);
                return solution;
            }
        }
    }
    return solution;
}

int main(){
    
    // Gets the value as a string and will convert later to make push it in vector
    string value; 
    vector<int> numbers;

    string file = "nums.txt";


    // number of lines
    int lines=0;

    ifstream file_(file);

    if(file_.is_open()){
        // While the end of the line is NOT reached
        while(!file_.eof()){
            getline(file_, value, ' ');

            /**
             * stoi casts a string to an integer
             */
            numbers.push_back(stoi(value));
        }
    }
    file_.close();
    for(int i =0;i<numbers.size(); ++i)
        cout << numbers[i] << " ";
    cout << endl;
    
    int target = 6;

    vector<int> solution = TwoSum(numbers, target);
    cout << "Output: [";
    for(int i = 0; i < solution.size(); ++i){
        if(i == solution.size() - 1){
            cout << solution[i] << "]" << endl;
        }
        else cout << solution[i] << ", ";
    }
}
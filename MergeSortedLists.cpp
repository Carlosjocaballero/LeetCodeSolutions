/**
 * @file MergeSortedLists.cpp
 * @author Carlos Caballero (carlosjocaballero@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;

    if(list1->val <= list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else{
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}


int main(){
    int arr1[] = {1,2,4};
    int arr2[] = {1,3,4};

    ListNode* list1;
    list1 = new ListNode(arr1[0]);
    cout << list1->val << endl;
    
}


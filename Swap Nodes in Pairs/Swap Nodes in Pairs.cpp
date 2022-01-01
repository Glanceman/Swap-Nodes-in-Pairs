// Swap Nodes in Pairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

ListNode* swapNode(ListNode* head, ListNode* tail) {
    ListNode* temp = head->next;
    head->next = tail;
    temp->next = head;
    return temp;
}

ListNode* swapPairs(ListNode* head) {
    ListNode* node = head;
    ListNode* root = head;
    int counter = 0;
    while (node != nullptr && node->next != nullptr) {
        if (counter == 0) {
            root = swapNode(node, node->next->next);
            node = root;
            node = node->next;
        }
        else {
            if (node->next->next == nullptr) { break; }
            node->next = swapNode(node->next, node->next->next->next);
            node = node->next->next;
        }
        counter++;
        
    }
    return root;
}

void printList(ListNode* root) {
    while (root != nullptr) {
        cout << root->val;
        root=root->next;
    }
}

int main()
{
    ListNode* root = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    root->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    printList(root);
    cout << endl;
    root = swapPairs(root);
    printList(root);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

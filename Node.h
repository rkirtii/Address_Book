#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
    string input_name;
    string input_address;
    string input_phone;
    int input_year = 0;
    Node *next;
    Node(string input_name1, string input_address1, int input_year1, string input_phone1)
    {
        input_name = input_name1;
        input_address = input_address1;
        input_phone = input_phone1;
        input_year = input_year1;
        next = NULL;
    }
};
#endif
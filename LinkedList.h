#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include<string>
#include "Node.h"
using namespace std;

class Node;
class LinkedList
{
public:
    LinkedList();
    Node *head;
    void add(string, string, int, string);
    void print(string);
    void print_all();
    void Delete(string );
    void reverse(Node *);
    void modify(string , string , int , string );
    bool modify1(string );
    void write_file();
};

#endif
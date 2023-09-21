#include <iostream>
#include <string>
#include<fstream>
// #include "Node.h"
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
}

void LinkedList::add(string input_name, string input_address, int input_year, string input_phone)
{
    Node *temp = new Node(input_name, input_address, input_year, input_phone);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = temp;
    cout << "--------------------\n";
    cout << "Record has been added.\n";
    cout << "--------------------\n";
}

void LinkedList::print(string input_name1)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->input_name == input_name1)
        {
            cout << "Name : " << temp->input_name << endl;
            cout << "Address : " << temp->input_address << endl;
            cout << "Birth year : " << temp->input_year << endl;
            cout << "Telephone : " << temp->input_phone << endl;
        }
        temp = temp->next;
    }
    cout << endl;
}

void LinkedList::print_all()
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "The database is empty " << endl;
        return;
    }
    int count = 0;
    while (temp != NULL)
    {
        count++;
        cout << "Name : " << temp->input_name << endl;
        cout << "Address : " << temp->input_address << endl;
        cout << "Birth year : " << temp->input_year << endl;
        cout << "Telephone : " << temp->input_phone << endl;
        cout << "---------------" << endl;
        temp = temp->next;
    }
    cout << count << " Records Printed\n";
    return;
}

void LinkedList::Delete(string input_name1)
{

    Node *temp = head;
    Node *prev = NULL;
    if (temp == NULL)
    {
        cout << "The Database is empty  \n";
        return;
    }
    if (temp->next == NULL)
    {
        head = NULL;
        return;
    }
    if (temp->input_name == input_name1)
    {
        head = temp->next;
        return;
    }
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;

        if (temp->input_name == input_name1)
        {
            prev->next = temp->next;
            return;
        }
    }

    if (temp == NULL)
    {
        cout << input_name1 << " not found in the database \n";
    }

    return;
}

void LinkedList::reverse(Node *current)
{
    if(current==NULL)
    {
        cout<<"The database is empty\n\n";
        return;
    }
    if (current->next == NULL)
    {
        head = current;
        return;
    }
    reverse(current->next);
    Node *p = current->next;
    p->next = current;
    current->next = NULL;
}

void LinkedList::modify(string input_name1, string input_address1, int input_year1, string input_phone1)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->input_name == input_name1)
        {
            temp->input_address = input_address1;
            temp->input_phone = input_phone1;
            temp->input_year = input_year1;
            return;
        }
        else
        {
            cout << "No matching name in the database\n\n";
            return;
        }
        temp = temp->next;
    }
}

bool LinkedList::modify1(string input_name1)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->input_name == input_name1)
        {
            return true;
        }
    }
    cout<<"No matching name found in database\n\n";
    return false;
}

void LinkedList::write_file()
{
    ofstream file("data.txt");
    Node* temp=head;
    while(temp!=NULL)
    {
        file<<"Name : "<<temp->input_name<<endl;
        file<<"Address : "<<temp->input_address<<endl;
        file<<"Birth Year : "<<temp->input_year<<endl;
        file<<"Telephone Number : "<<temp->input_phone<<endl;
        file<<"-----------------\n";

        temp=temp->next;
    }
}

#include <iostream>
#include <string>
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

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    void add(string input_name, string input_address, int input_year, string input_phone)
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

    void print(string input_name1)
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

    void print_all()
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

    void Delete(string input_name1)
    {

        Node *temp = head;
        Node *prev = NULL;
        if (temp == NULL)
        {
            cout << "The Database is empty  "<<endl;
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

    void reverse(Node *current)
    {

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

    void modify(string input_name1, string input_address1, int input_year1, string input_phone1)
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
            temp = temp->next;
        }
    }
};

void display_commands()
{
    cout << endl;
    cout << "Usage:" << endl;
    cout << "1: Add a new record into the database." << endl;
    cout << "2: Print information about a record using the name as the key." << endl;
    cout << "3: Modify a record in the database using the name as the key." << endl;
    cout << "4: Print all information in the database." << endl;
    cout << "5: Delete an existing record from the database." << endl;
    cout << "6: Reverse the order of all existing records from the database." << endl;
    cout << "7: Quit the program." << endl;
    cout << "What would you like to do?" << endl;
}

void run_program()
{
    LinkedList LL;
    string input_name;
    string input_address;
    string input_phone;
    int input_year = 0;
    int menu = 0;

    display_commands();
    do
    {
        cin >> menu;
        switch (menu)
        {
        case 1: // Add new record
            cout << "Add a new Record " << endl;

            cout << "Please enter the Person's name : \n";
            cin.ignore();
            getline(cin, input_name);

            cout << "Please enter the Person's address : \n";
            getline(cin, input_address);

            cout << "Please enter the Person's birth year : \n";
            cin >> input_year;

            cout << "Please enter the Person's Telephone number : \n";
            cin.ignore();
            getline(cin, input_phone);

            LL.add(input_name, input_address, input_year, input_phone);
            break;

        case 2: // Print record with same name
            cout << "Print Record with same name : " << endl;
            cout << "Enter the name : ";
            cin.ignore();
            getline(cin, input_name);
            LL.print(input_name);
            break;

        case 3: // Modify a record in the database
            cout << "Enter the name : ";
            cin.ignore();
            getline(cin, input_name);

            cout << "Enter the address : ";
            getline(cin, input_address);

            cout << "Enter the Birth Year : ";
            cin >> input_year;
            cin.ignore();

            cout << "Enter the Telephone : ";
            getline(cin, input_phone);

            LL.modify(input_name, input_address, input_year, input_phone);
            break;

        case 4: // Print all records
            cout << "--------------------\n";
            cout << "Printing Records...\n";
            LL.print_all();
            break;

        case 5: // Delete record with same name
            cout << "--------------------\n";
            cout << "Delete Record(s) with the same name\n";
            cout << "Please enter the Person's name : ";
            cin.ignore();
            getline(cin, input_name);
            LL.Delete(input_name);
            break;

        case 6: // Reverse the list
            cout << "--------------------\n";
            cout << "Reversing the list \n";
            LL.reverse(LL.head);
        }
        if (menu != 7)
        {
            display_commands();
        }
    } while (menu != 7);
    return;
}
int main()
{
    cout << "********************\n";
    cout << "Welcome User!\n";
    cout << "--------------------\n";
    run_program();
    cout << "--------------------\n";
    cout << "App terminated\n";
    cout << "********************\n";
}

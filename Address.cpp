#include <iostream>
#include <string>
#include "LinkedList.h"
// #include "Node.h"
using namespace std;

void display_commands();
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
            cout << endl;
            cout << "Add a new Record \n";
            cout << "Please enter the Person's name : ";
            cin.ignore();
            getline(cin, input_name);

            cout << "Please enter the Person's address : ";
            getline(cin, input_address);

            cout << "Please enter the Person's birth year : ";
            cin >> input_year;

            cout << "Please enter the Person's Telephone number : ";
            cin.ignore();
            getline(cin, input_phone);

            LL.add(input_name, input_address, input_year, input_phone);
            break;

        case 2: // Print record with same name
            cout << "Print Record with same name  \n\n";
            cout << "Enter the name : ";
            cin.ignore();
            getline(cin, input_name);
            LL.print(input_name);
            break;

        case 3: // Modify a record in the database
            cout << "Enter the name : ";
            cin.ignore();
            getline(cin, input_name);
            bool check;
            check = LL.modify1(input_name);

            if (check)
            {
                cout << "Enter the address : ";
                getline(cin, input_address);

                cout << "Enter the Birth Year : ";
                cin >> input_year;
                cin.ignore();

                cout << "Enter the Telephone : ";
                getline(cin, input_phone);

                LL.modify(input_name, input_address, input_year, input_phone);
            }

            break;

        case 4: // Print all records
            cout << "--------------------\n";
            cout << "Printing Records...\n\n";
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
    LL.write_file();
    return;
}

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

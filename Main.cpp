#include <iostream>
#include "Phone.h"
#include <string>

using namespace std;

int main() {
    setlocale(0, "");
    system("chcp 1251");

    char temp[100];
    char choice = 0;
    bool hasWorkers = false;
    int amount = 0;
    int amountDelete = 0;
    int foundSubscriber = 0;

    char* firstName;
    char* lastName;
    char* Patronymic;

    PhoneBook* subscribers = nullptr;


    while (true) {
        if (!hasWorkers) {
            cout << "1. Add abonent (Enter the number of abonent first)" << endl;
        }
        else {
            cout << "Μενώ: " << endl;
            cout << "1. Add abonents" << endl;
            cout << "2. add abonent" << endl;
            cout << "3. Search for a subscriber by full name" << endl;
            cout << "4. Show all abonents" << endl;
            cout << "5. Delete abonent" << endl;
            cout << "6. Save abonents to file" << endl;
            cout << "7. Load abonents from file" << endl;
            cout << "8. Exit" << endl;
        }
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();
        cout << endl;

        if (!hasWorkers && choice != '1') {
            cout << "The number of abonents is not specified, first press 1 to enter the number." << endl;
            continue;
        }


        if (isdigit(choice) && choice >= '1' && choice <= '8') {
            switch (choice) {
            case '1':
                cout << "Enter the number of abonents: ";
                cin >> amount;

                subscribers = new PhoneBook[amount];

                for (int i = 0; i < amount; i++) {
                    subscribers[i].Input();
                    cout << endl;
                }
                hasWorkers = true;

                break;
            case '2':
                amount = subscribers->ResizeArray(subscribers, amount);
                for (int i = amount - 1; i < amount; i++) {
                    subscribers[i].Input();
                    cout << endl;
                }
                break;
            case '3':
            {

                while (true) {
                    char subChoice;
                    cout << "D. Return to main menu, S. Continue searching: ";
                    cin >> subChoice;
                    cin.ignore();

                    if (subChoice == 'D' || subChoice == 'd') {
                        break;
                    }
                    else if (subChoice == 'S' || subChoice == 's') {
                        cout << "Search by fullname: " << endl;
                        cout << "input last name: ";
                        cin >> temp;
                        lastName = new char[strlen(temp) + 1];
                        strcpy_s(lastName, strlen(temp) + 1, temp);

                        cout << "input name: ";
                        cin >> temp;
                        firstName = new char[strlen(temp) + 1];
                        strcpy_s(firstName, strlen(temp) + 1, temp);

                        cout << "input Patronymic: ";
                        cin >> temp;
                        Patronymic = new char[strlen(temp) + 1];
                        strcpy_s(Patronymic, strlen(temp) + 1, temp);

                        if (foundSubscriber == subscribers->SearchByFullname(subscribers, amount, firstName, lastName, Patronymic)) {
                            cout << "Subscriber found:" << endl << endl;
                            subscribers[foundSubscriber].Print();
                        }
                        else {
                            cout << "Subscriber not found." << endl;
                        }
                    }
                    else {
                        cout << "Wrong choice. Please select 'D' or 'S'" << endl;
                    }
                }
            }
            break;

            case '4':
            {
                char subChoice;
                cout << "D. Back to main menu, S. Continue to search: ";
                cin >> subChoice;
                cin.ignore();

                if (subChoice == 'D' || subChoice == 'd') {
                    break;
                }
                else if (subChoice == 'S' || subChoice == 's') {
                    if (amount == 0) {
                        cout << "No abonents for print!" << endl << endl;
                    }
                    else {
                        for (int i = 0; i < amount; i++) {
                            subscribers[i].Print();
                            cout << endl;
                        }
                    }
                }
                else {
                    cout << "Wrong choice. Please select 'D' or 'S'" << endl;
                }
            }
            break;
            case '5':
            {
                char subChoice;
                cout << "D. Return to main menu, S. Continue: ";
                cin >> subChoice;
                cin.ignore();

                if (subChoice == 'D' || subChoice == 'd') {
                    break;
                }
                else if (subChoice == 'S' || subChoice == 's') {
                    cout << "Index list worker:" << endl;
                    subscribers->printEmployeeList(subscribers, amount);

                    cout << endl << "Delete worker for index:" << endl;
                    cin >> amountDelete;
                    if (amountDelete > amount || amountDelete <= -1)
                    {
                        cout << "You entered an invalid range!" << endl << endl;
                    }
                    else
                    {
                        amount = subscribers->DelateSubscriber(subscribers, amount, amountDelete);
                        cout << "The abonents has been deleted!" << endl << endl;
                    }
                }
                else {
                    cout << "Wrong choice. Please select 'D' or 'S'" << endl;
                }
            }
            break;
            case '6':
                subscribers->saveDataToFile(subscribers, amount);

                break;
            case '7':
                subscribers->readFile();
                break;
            case '8':

                cout << "Exit from the program." << endl;
                return 0;
            default:
                cout << "Wrong choice, try again." << endl;
            }
        }
        else {
            cout << "Wrong choice, try again." << endl;
        }
    }



    return 0;
}
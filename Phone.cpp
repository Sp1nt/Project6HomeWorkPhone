#include "Phone.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

PhoneBook::PhoneBook() {
    firstName = nullptr;
    lastName = nullptr;
    Patronymic = nullptr;

    homePhone = nullptr;
    workPhone = nullptr;
}
PhoneBook::PhoneBook(const char* fn, const char* ln, const char* sn, const char* hp, const char* wp) {

    firstName = new char[strlen(fn) + 1];
    strcpy_s(firstName, strlen(fn) + 1, fn);

    lastName = new char[strlen(ln) + 1];
    strcpy_s(lastName, strlen(ln) + 1, ln);

    Patronymic = new char[strlen(sn) + 1];
    strcpy_s(Patronymic, strlen(sn) + 1, sn);

    homePhone = new char[strlen(hp) + 1];
    strcpy_s(homePhone, strlen(hp) + 1, hp);

    workPhone = new char[strlen(wp) + 1];
    strcpy_s(workPhone, strlen(wp) + 1, wp);
}
PhoneBook::~PhoneBook() {

    delete[] lastName;
    delete[] firstName;
    delete[] Patronymic;

    delete[] homePhone;
    delete[] workPhone;
}


void PhoneBook::Input() {
    char buff[100];

    cout << "name: ";
    cin >> buff;

    if (firstName != nullptr) {
        cout << "Delete firstName -> " << firstName << endl << endl;
        delete[] firstName;
    }

    firstName = new char[strlen(buff) + 1];
    strcpy_s(firstName, strlen(buff) + 1, buff);


    cout << "Lastname: ";
    cin >> buff;

    if (lastName != nullptr) {
        cout << "Delete lastName -> " << lastName << endl << endl;
        delete[] lastName;
    }

    lastName = new char[strlen(buff) + 1];
    strcpy_s(lastName, strlen(buff) + 1, buff);


    cout << "Patronymic: ";
    cin >> buff;

    if (Patronymic != nullptr) {
        cout << "Delete Patronymic -> " << Patronymic << endl << endl;
        delete[] Patronymic;
    }

    Patronymic = new char[strlen(buff) + 1];
    strcpy_s(Patronymic, strlen(buff) + 1, buff);



    cout << "HomePhone: ";
    cin >> buff;

    if (homePhone != nullptr) {
        cout << "Delete homePhone -> " << homePhone << endl << endl;
        delete[] homePhone;
    }

    homePhone = new char[strlen(buff) + 1];
    strcpy_s(homePhone, strlen(buff) + 1, buff);


    cout << "WorkPhone: ";
    cin >> buff;

    if (workPhone != nullptr) {
        cout << "Delete workPhone -> " << workPhone << endl << endl;
        delete[] workPhone;
    }

    workPhone = new char[strlen(buff) + 1];
    strcpy_s(workPhone, strlen(buff) + 1, buff);
}
void PhoneBook::Print() {
    cout << "LastName: " << lastName << endl;
    cout << "name: " << firstName << endl;
    cout << "Patronymic: " << Patronymic << endl;

    cout << "HomePhone.: " << homePhone << endl;
    cout << "workPhone: " << workPhone << endl;
}
int PhoneBook::NewAbonent(PhoneBook*& array, int oldSize) {
    int newSize = oldSize + 1;
    PhoneBook* newArray = new PhoneBook[newSize];

    for (int i = 0; i < oldSize; i++)
        newArray[i] = array[i];

    array = newArray;

    return newSize;
}
int PhoneBook::DeleteAbonent(PhoneBook*& array, int oldSize, int numberDelate) {
    int newSize = oldSize - 1;
    PhoneBook* newArray = new PhoneBook[newSize];

    for (int i = 0, j = 0; i < oldSize; i++) {
        if (i != numberDelate) {
            newArray[j] = array[i];
            j++;
        }
    }

    array = newArray;
    oldSize = newSize;

    return newSize;
}
int PhoneBook::SearchByFullname(PhoneBook* array, int size, const char* fn, const char* ln, const char* sn) {
    cout << "Input FullName: " << endl<< endl;
    cout << "lastname: " << ln << endl;
    cout << "name: " << fn << endl;
    cout << "Patronymic: " << sn << endl;

    for (int i = 0; i < size; i++) {

        if (strcmp(array[i].lastName, ln) == 0 &&
            strcmp(array[i].firstName, fn) == 0 &&
            strcmp(array[i].Patronymic, sn) == 0) {
            return i;
        }
    }

    return -1;
}

void PhoneBook::printEmployeeList(PhoneBook*& array, int size) {
    for (int i = 0; i < size; i++) {
        cout << "index: " << i << endl;
        array[i].Print();
        cout << endl;
    }
}


char* PhoneBook::GetFistName() {
    return this->firstName;
}
char* PhoneBook::GetLastName() {
    return this->lastName;
}
char* PhoneBook::GetPatronymic() {
    return this->Patronymic;
}
char* PhoneBook::GetHomePhone() {
    return this->homePhone;
}
char* PhoneBook::GetWorkPhone() {
    return this->workPhone;
}


void PhoneBook::SetFistName(const char* fn) {
    if (firstName != nullptr) {
        cout << "Delate firstName -> " << this->firstName << endl;
    }

    firstName = new char[strlen(fn) + 1];
    strcpy_s(firstName, strlen(fn) + 1, fn);
}
void PhoneBook::SetLastName(const char* ln) {
    if (lastName != nullptr) {
        cout << "Delate lastName -> " << this->lastName << endl;
    }

    lastName = new char[strlen(ln) + 1];
    strcpy_s(lastName, strlen(ln) + 1, ln);
}
void PhoneBook::SetPatronymic(const char* sn) {
    if (Patronymic != nullptr) {
        cout << "Delate Patronymic -> " << this->Patronymic << endl;
    }

    Patronymic = new char[strlen(sn) + 1];
    strcpy_s(Patronymic, strlen(sn) + 1, sn);
}
void PhoneBook::SetHomePhone(const char* hp) {
    if (homePhone != nullptr) {
        cout << "Delate homePhone -> " << this->homePhone << endl;
    }

    homePhone = new char[strlen(hp) + 1];
    strcpy_s(homePhone, strlen(hp) + 1, hp);
}
void PhoneBook::SetWorkPhone(const char* wp) {
    if (workPhone != nullptr) {
        cout << "Delate workPhone -> " << this->workPhone << endl;
    }

    workPhone = new char[strlen(wp) + 1];
    strcpy_s(workPhone, strlen(wp) + 1, wp);
}

void PhoneBook::saveDataToFile(PhoneBook* array, int size) {
    ofstream outFile("data.txt");

    if (!outFile) {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        outFile << "Name: " << array[i].firstName << endl;
        outFile << "lastName: " << array[i].lastName << endl;
        outFile << "Patronymic: " << array[i].Patronymic << endl;
        outFile << "HomePhone: " << array[i].homePhone << endl;
        outFile << "WorkPhone: " << array[i].workPhone << endl;
        outFile << endl;
    }

    outFile.close();
    cout << "Data received successfully." << endl << endl;
}

void PhoneBook::readFile()
{
    ifstream textFile("data.txt");

    if (!textFile) {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    cout << textFile.rdbuf();

    textFile.close();

}

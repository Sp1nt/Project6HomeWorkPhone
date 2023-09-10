#pragma once
class PhoneBook {
    char* firstName;
    char* lastName;
    char* surName;

    char* homePhone;
    char* workPhone;

public:
    PhoneBook();
    PhoneBook(const char* fn, const char* ln, const char* sn, const char* hp, const char* wp);
    ~PhoneBook();

    void Input();
    void Print();
    int ResizeArray(PhoneBook*&, int);
    int DelateSubscriber(PhoneBook*&, int, int);
    int SearchByFullname(PhoneBook* array, int size, const char* fn, const char* ln, const char* sn);

    void saveDataToFile(PhoneBook*, int);

    void readFile();

    void printEmployeeList(PhoneBook*&, int);
    char* GetFistName();
    char* GetLastName();
    char* GetSurName();

    char* GetHomePhone();
    char* GetWorkPhone();

    void SetFistName(const char*);
    void SetLastName(const char*);
    void SetSurName(const char*);

    void SetHomePhone(const char*);
    void SetWorkPhone(const char*);


};

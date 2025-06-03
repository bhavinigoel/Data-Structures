#include <iostream>
#include <string>
using namespace std;
struct Address
{
    string homeNo;
    string streetName;
    string city;
    string state;
    string country;
};
struct StudentRecord
{
    int rollNo;
    string name;
    string fatherName;
    string motherName;
    string className;
    string semester;
    string branch;
    Address address;
};
const int MAX_RECORDS = 100;

void addRecord(StudentRecord records[], int &number)
{
    if (number == MAX_RECORDS)
    {
        cout << "Maximum limit of records reached." << endl;
        return;
    }
    StudentRecord newRecord;
    cout << "Enter Roll No: ";
    cin >> newRecord.rollNo;
    cout << "Enter Student Name: ";
    cin >> newRecord.name;
    cout << "Enter Father's Name: ";
    cin >> newRecord.fatherName;
    cout << "Enter Mother's Name: ";
    cin >> newRecord.motherName;
    cout << "Enter Class: ";
    cin >> newRecord.className;
    cout << "Enter Semester: ";
    cin >> newRecord.semester;
    cout << "Enter Branch: ";
    cin >> newRecord.branch;
    cout << "Enter Home/House No: ";
    cin >> newRecord.address.homeNo;
    cout << "Enter Street Name: ";
    cin >> newRecord.address.streetName;
    cout << "Enter City: ";
    cin >> newRecord.address.city;
    cout << "Enter State: ";
    cin >> newRecord.address.state;
    cout << "Enter Country: ";
    cin >> newRecord.address.country;

    records[number++] = newRecord;
    cout << "Record added successfully." << endl;
}
void deleteRecord(StudentRecord records[], int &number)
{
    int rollNo;
    cout << "Enter the Roll No of the record to be deleted: ";
    cin >> rollNo;

    for (int i = 0; i < number; i++)
    {
        if (records[i].rollNo == rollNo)
        {
            for (int j = i; j < number - 1; j++)
            {
                records[j] = records[j + 1];
            }
            number--;
            cout << "Record with Roll No " << rollNo << " deleted successfully." << endl;
            return;
        }
    }
}
void searchByrollno(StudentRecord records[], int number, int numm)
{
    for (int i = 0; i < number; i++)
    {
        if (records[i].rollNo == numm)
        {
            cout << "Roll No: " << records[i].rollNo << ", Name: " << records[i].name << endl;
        }
    }
}
void searchByState(StudentRecord records[], int number, string state)
{
    for (int i = 0; i < number; i++)
    {
        if (records[i].address.state == state)
        {
            cout << "Roll No: " << records[i].rollNo << ", Name: " << records[i].name << endl;
        }
    }
}
void searchByCity(StudentRecord records[], int number, string City)
{
    for (int i = 0; i < number; i++)
    {
        if (records[i].address.city == City)
        {
            cout << "Roll No: " << records[i].rollNo << ", Name: " << records[i].name << endl;
        }
    }
}
void DisplayByCity(StudentRecord records[], int number, string city)
{

    for (int i = 0; i < number; i++)
    {
        if (records[i].address.city == city)
        {
            cout << "Roll No: " << records[i].rollNo << "\n"
                 << ", Name: " << records[i].name << endl;
            cout << "Father's Name: " << records[i].fatherName << endl;
            cout << "Mother's Name: " << records[i].motherName << endl;
            cout << "Class: " << records[i].className << endl;
            cout << "Semester: " << records[i].semester << endl;
            cout << "Branch: " << records[i].branch << endl;
            cout << "Address: " << records[i].address.homeNo << ", " << records[i].address.streetName << ", " << records[i].address.city << ", " << records[i].address.state << ", " << records[i].address.country << endl;
            cout << "----------------------------------------\n";
        }
    }
}
void DisplayByState(StudentRecord records[], int number, string state)
{
    for (int i = 0; i < number; i++)
    {
        if (records[i].address.state == state)
        {
            cout << "Roll No: " << records[i].rollNo << ", Name: " << records[i].name << endl;
            cout << "Father's Name: " << records[i].fatherName << endl;
            cout << "Mother's Name: " << records[i].motherName << endl;
            cout << "Class: " << records[i].className << endl;
            cout << "Semester: " << records[i].semester << endl;
            cout << "Branch: " << records[i].branch << endl;
            cout << "Address: " << records[i].address.homeNo << ", " << records[i].address.streetName << ", " << records[i].address.city << ", " << records[i].address.state << ", " << records[i].address.country << endl;
            cout << "----------------------------------------\n";
        }
    }
}

int main()
{
    StudentRecord records[MAX_RECORDS];
    int number;
    int choice;

    cout << " Enter the data of students" << endl;
    cout << " Enter number of students u want" << endl;
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cout << "Enter Roll No: ";
        cin >> records[i].rollNo;
        cout << "Enter Student Name: ";
        cin >> records[i].name;
        cout << "Enter Father's Name: "<<endl;
        cin >> records[i].fatherName;
        cout << "Enter Mother's Name: "<<endl;
        cin >> records[i].motherName;
        cout << "Enter Class: ";
        cin >> records[i].className;
        cout << "Enter Semester: ";
        cin >> records[i].semester;
        cout << "Enter Branch: ";
        cin >> records[i].branch;
        cout << "Enter Home/House No: ";
        cin >> records[i].address.homeNo;
        cout << "Enter Street Name: ";
        cin >> records[i].address.streetName;
        cout << "Enter City: ";
        cin >> records[i].address.city;
        cout << "Enter State: ";
        cin >> records[i].address.state;
        cout << "Enter Country: ";
        cin >> records[i].address.country;
    }
    cout << " Do you want to add a record?" << endl;

    string reply;
    cin >> reply;
    if (reply == "yes")
    {
        addRecord(records, number);
    }

    cout << "Do you want to delete a record? " << endl;
    cin >> reply;
    if (reply == "yes")
    {
        deleteRecord(records, number);
    }
    cout << "  Do you want to search a record?" << endl;
    cin >> reply;
    if (reply == "yes")
    {
        cout << " Press 1 , if you want to search by rollno." << endl;
        cout << " Press 2 , if you want to search by state" << endl;
        cout << " press 3, if want to search by city " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << " Enter the roll no." << endl;
            int numm;
            cin >> numm;
            searchByrollno(records, number, numm);
            break;
        }
        case 2:
        {
            cout << " Enter the state" << endl;
            string state;
            cin >> state;
            searchByState(records, number, state);
            break;
        }
        case 3:
        {
            cout << " enter the city" << endl;
            string city;
            cin >> city;
            searchByCity(records, number, city);
            break;
        }
        }
    }

    cout << " Do you want to display whole record?" << endl;

    cin >> reply;
    if (reply == "yes")
    {
        cout << " Press 1 , if you want to display by city" << endl;
        cout << " Press 2 , if you want to display by state" << endl;

        cin >> choice;

        switch (choice)
        {
        case 2:
        {
            cout << " Enter the state" << endl;
            string state;
            cin >> state;
            DisplayByState(records, number, state);
            break;
        }
        case 1:
        {
            cout << " enter the city" << endl;
            string city;
            cin >> city;
            DisplayByCity(records, number, city);
            break;
        }
        }
    }
}

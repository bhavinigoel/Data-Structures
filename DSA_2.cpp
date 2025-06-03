#include <iostream>
#include<string.h>
using namespace std;
struct CitizenRecord
{
    long long int  Aadharcard;
    char name[100];
    char Father_name[100];
    char Mother_name[100];
    char Rank_Position[100];
    char Department_of_workplace[100];
    int house_number;
    char city[100];
    char state[100];
    char country[100];
    char street_name[100];
    long int pin;

   
    CitizenRecord *Next;
}  *head ;


struct Citizen* head = NULL;

void insert(long long int aadhar,char *name,char *fname,char *Mname, char *rank,char *department, int *houseno, char *street, char *city, char *state, char *country, long int *pin){

CitizenRecord *citizen = new CitizenRecord;
citizen->Aadharcard = aadhar;


strcpy(citizen->name, name);
strcpy(citizen->Father_name, fname);
strcpy(citizen->Mother_name, Mname);
strcpy(citizen->Rank_Position, rank);
strcpy(citizen->Department_of_workplace, department);

citizen->house_number=houseno;
strcpy(citizen->street_name,street);
strcpy(citizen->city,city );
strcpy( citizen->state,state);
strcpy( citizen->country,country);
citizen->pin = pin;

citizen->Next = NULL;

    return citizen ;


}


struct Date
    {
        int day;
        int month;
        int year;
    }date;

int check_Date(int day, int month, int year)
{
    if (month > 12 || month < 1)
        cout << " Invalid Month" << endl;
    if (year < 1 || year > 2023)
        cout << " Invalid year" << endl;
        int actual_days;
        switch(month){
            case 2:{
                 if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            actual_days = 29;
            } else {
                actual_days = 28;
            }
            break;

            }
            case 4:
            case 6:
            case 9:
            case 11:
            actual_days=30;
            break;
            default:{
            actual_days=31;
            break;}

        }
        if(day>actual_days || day<1)
        cout<<" Invalid Date!"<<endl;
}

int main()
{ 
  
    cout<<" Enter Date of joining"<<endl;
    cin>>date.day>>date.month>>date.year;
    int a=date.day;
    int b= date.month;
    int c=date.year;

    check_Date(a,b,c);
    cout<<" Choose from the menu"<<endl;
    cout<<" press 1 for inseting a record"<<endl;
    cout<<" press 2 for deleting a record"<<endl;
     cout<<" Choose from the menu"<<endl;
      cout<<" Choose from the menu"<<endl;
       cout<<" Choose from the menu"<<endl;
        cout<<" Choose from the menu"<<endl;
         cout<<" Choose from the menu"<<endl;
          cout<<" Choose from the menu"<<endl;
    




}

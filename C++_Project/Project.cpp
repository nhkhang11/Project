#include <iostream>
#include <string>
#include <iterator>
#include <map>
using namespace std;

class People
{
private:
    string FirstName;
    string LastName;
public:
    People()
    {
        FirstName = "";
        LastName = "";
    }
    void insert()
    {
        cout << "First Name: ";
        cin >> FirstName;
        if (FirstName[0] >= 97 && FirstName[0] <= 122)
            FirstName[0] = FirstName[0] - 32;
        cout << "Last Name: ";
        cin >> LastName;
        if (LastName[0] >= 97 && LastName[0] <= 122)
            LastName[0] = LastName[0] - 32;
    }
    void print()
    {
        cout << FirstName << " " << LastName;
    }
    People& operator=(const People& A)
    {
        this->FirstName = A.FirstName;
        this->LastName = A.LastName;
        return *this;
    }
    bool operator<(const People &A) const
    {
        if (FirstName < A.FirstName)
            return true;
        if (FirstName == A.FirstName && LastName < A.LastName)
            return true;
        else
            return false;
    }
    bool operator==(const People& A) const
    {
        return FirstName == A.FirstName && LastName == A.LastName;
    }
};

void ADD(map <People, string>& Pref,map<People, string>::iterator p);
void REMOVE(map <People, string>& Pref,map<People, string>::iterator p);
void SEARCH(map <People, string>& Pref, map<People, string>::iterator p);
void EDIT(map <People, string>& Pref, map<People, string>::iterator p);

void ADD(map <People, string>& Pref,map<People, string>::iterator p)
{
    string email;
    People* CreateNew = new People;
    CreateNew->insert();
    p = Pref.find(*CreateNew);
    if (p != Pref.end())
        cout << "People is existed!" << endl<<endl;
    else
    {
        cout << "Email: ";
        cin >> email;
        Pref.insert({ *CreateNew, email });
        cout << endl << "Information has been added!" << endl << endl;
    }
    delete CreateNew;
    return;
}

void REMOVE(map <People, string>& Pref,map<People, string>::iterator p)
{
    People* FindItem = new People;
    FindItem->insert();
    p = Pref.find(*FindItem);
    if (p == Pref.end())
        cout << endl << "No people found!" << endl<<endl;    
    else
    {
        Pref.erase(p);
        cout << endl << "Data has been removed!" << endl<<endl;
    }
    delete FindItem;
}

void SEARCH(map <People, string>& Pref,map<People, string>::iterator p)
{
    People* SearchItem = new People;
    // Input information of people need to find
    SearchItem->insert();
    p= Pref.find(*SearchItem);
    if (p == Pref.end())
        cout <<endl << "No people found!"<<endl;
    else
    {
        cout << endl;
        *SearchItem = p->first;
        SearchItem->print();
        cout <<" " << p->second << endl <<endl;
    }
    delete SearchItem;
}

void EDIT(map <People, string>& Pref,map<People, string>::iterator p)
{
    People* EditItem = new People;
    EditItem->insert();
    p = Pref.find(*EditItem);
    if (p == Pref.end())
        cout << endl << "No people found!" << endl << endl;
    else
    {
        *EditItem = p->first;
        cout << endl;
        EditItem->print();
        cout << " " << p->second << endl<<"New email: ";
        cin >> Pref[p->first];
        //print out the data again
        *EditItem = p->first;
        cout << endl;
        EditItem->print();
        cout << " " << p->second << endl;
    }
    delete EditItem;
}

int main()
{
    int x = 0,choice=0,num=0;
    map < People, string > Info;
    map<People, string>::iterator p;
    while (x == 0)
    {
        cout <<"*** EMAIL ADRESS BOOK ***"<<endl<<"Numbers of contacts: "<<Info.size() << endl << "1.SEARCH" << endl << "2.ADD";
        cout << endl << "3.REMOVE" << endl << "4.EDIT" <<endl<<"5.END"<<endl <<"Your choice is: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout <<endl<< "SEARCHING PROFILE"<<endl;
                SEARCH(Info,p);
                break;
            case 2:
                cout << endl << "ADDING NEW PROFILE!" << endl;
                ADD(Info,p);
                break;
            case 3:
                cout << endl << "REMOVING A PROFILE!" << endl;
                REMOVE(Info,p);
                break;
            case 4:
                cout << endl << "EDITING A PROFILE!" << endl;
                EDIT(Info,p);
                break;
            case 5:
                x = 1;
                cout << "End of the program!";
                break;
        }
    }
    return 0;
}


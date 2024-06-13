/*
Creating Lists by using concepts of OOP
*/

#include<iostream>
#include<vector>

using namespace std;

class student {
public:
    student() {
        Year = 0;
        Campus = ' ';
        ID = 0;
        CGPA = 0;
    }
    friend ostream& operator <<(ostream& os, student& S) {
        os << "Student ID : " << S.ID << endl;
        os << "Year : " << S.Year << endl;
        os << "Campus : " << S.Campus << endl;
        os << "CGPA : " << S.CGPA << endl;
        return os;
    }

    friend istream& operator >>(istream& is, student& S) {
        cout << "Enter ID : ";
        is >> S.ID;
        cout << "Enter Year : ";
        is >> S.Year;
        cout << "Enter Campus : ";
        is >> S.Campus;
        cout << "Enter CGPA : ";
        is >> S.CGPA;
        cout << endl;
        return is;
    }
    bool operator ==(student obj)
    {
        if (this->Year == obj.Year && this->Campus == obj.Campus
            && this->ID == obj.ID && this->CGPA == obj.CGPA)
            return true;
        else
            return false;
    }

private:
    int Year;
    char Campus;
    int ID;
    double CGPA;
};

template<class T>
class listNode {
public:
    bool operator < (listNode<T>& Obj) {
        return ((*this.Data) < Obj.Data);
    }
    bool operator <= (listNode<T>& Obj) {
        return ((*this.Data) <= Obj.Data);
    }
    bool operator > (listNode<T>& Obj) {
        return ((*this.Data) > Obj.Data);
    }
    bool operator >= (listNode<T>& Obj) {
        return ((*this.Data) >= Obj.Data);
    }
    bool operator == (listNode<T> Obj) {
        return ((*this.Data) == Obj.Data);
    }

    T Data;
    listNode<T>* next;
};

template<class U>
class D_List {
public:
    D_List() {
        Start = NULL;
        totalRecords = 0;
    }
    ~D_List() {
        while (Start) {
            listNode<U>* temp = Start;
            Start = Start->next;
            delete temp;
        }
    }

    void showList() {
        if (!Start) {
            cout << "List is empty." << endl;
            return;
        }
        cout << "List contents :- " << endl;
        listNode<U>* current;
        current = Start;
        while (current != nullptr) {
            cout << current->Data << endl;
            current = current->next;
        }
        cout << "\n";
    }

    void insertSorted(listNode<U>& node) {
        listNode<U>* newnode = new listNode<U>;
        newnode->Data = node.Data;

        newnode->next = Start;
        Start = newnode;
        totalRecords++;
    }
    bool deleteNode(listNode<U>& node) {
        listNode<U>* present = Start;
        listNode<U>* last = nullptr;

        if (present->Data == node.Data) {
            Start = present->next;
            delete present;
            totalRecords--;
            return true;
        }
        while (present != nullptr) {
            if (present->Data == node.Data) {

                last->next = present->next;
                delete present;
                totalRecords--;
                return true;
            }
            last = present;
            present = present->next;

        }
    }
private:
    listNode<U>* Start;
    int totalRecords;
};

int main() {
    D_List<student> DL;
    D_List<int>D1;

    char c;
    cout << "Enter 'i' for integers list and 's' for students list : ";
    cin >> c;
    if (c == 'i' || c == 'I')
    {
        int choice;
        do {
            do {
                cout << "1: Insert" << endl
                    << "2: Delete" << endl
                    << "3: Show List" << endl
                    << "4: Exit" << endl << endl
                    << "Enter Your Choice : ";

                cin >> choice;
            } while (1 > choice || choice > 4);

            if (choice == 1) {
                int x;
                cout << "Enter number : ";
                cin >> x;
                listNode<int> I1;
                I1.Data = x;
                D1.insertSorted(I1);
            }
            else if (choice == 2) {
                int x;
                cout << "Enter number : ";
                cin >> x;
                listNode<int> I1;
                I1.Data = x;
                D1.deleteNode(I1);
            }
            else if (choice == 3) {
                D1.showList();
            }

        } while (choice != 4);
    }
    if (c == 's' || c == 'S')
    {
        int choice;
        do {
            do {
                cout << "1: Insert" << endl
                    << "2: Delete" << endl
                    << "3: Show List" << endl
                    << "4: Exit" << endl << endl
                    << "Enter Your Choice : ";

                cin >> choice;
            } while (1 > choice || choice > 4);

            if (choice == 1) {
                student s1;
                cout << "Enter record of student :- " << endl;
                cin >> s1;
                listNode<student> St;
                St.Data = s1;
                DL.insertSorted(St);

            }
            else if (choice == 2) {
                student s1;
                cout << "Enter record of student :- " << endl;
                cin >> s1;
                listNode<student> St;
                St.Data = s1;
                DL.deleteNode(St);
            }
            else if (choice == 3) {
                DL.showList();
            }

        } while (choice != 4);
    }
    return 0;
}
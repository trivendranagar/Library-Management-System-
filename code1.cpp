#include <iostream>
#include <string.h>
using namespace std;

class Library
{
public:
    char name[30];
    char book[50];
    char author[50];
    int id2;
    int pages;

    char book2[50];
    int id;

    void input()
    {
        cin.ignore();
        cout << "Enter student name : ";
        cin.getline(name, 30);

        cout << "Enter book name : ";
        cin.getline(book, 50);

        cout << "Enter book author name : ";
        cin.getline(author, 50);

        cout << "Enter book id : ";
        cin >> id2;

        cout << "Enter book pages : ";
        cin >> pages;

        cout << "\nRecord inserted.....\n";
    }

    void add()
    {
        cin.ignore();
        cout << "\nEnter book name : ";
        cin.getline(book2, 50);

        cout << "Enter book id : ";
        cin >> id;

        cout << "\nBook added.....\n";
    }

    void displayBook()
    {
        cout << "\nBook Name : " << book2
             << "\nBook ID   : " << id << endl;
    }

    void displayStudent()
    {
        cout << "\nStudent Name : " << name
             << "\nBook Name    : " << book
             << "\nAuthor Name  : " << author
             << "\nBook ID      : " << id2
             << "\nPages        : " << pages << endl;
    }
};

void removeBook(Library* books[], int &bookIndex, int bookId)
{
    int pos = -1;

    for (int i = 0; i < bookIndex; i++)
    {
        if (books[i]->id == bookId)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        for (int i = pos; i < bookIndex - 1; i++)
            books[i] = books[i + 1];

        bookIndex--;
        cout << "\nBook removed from library stock.\n";
    }
    else
    {
        cout << "\nBook not found in library.\n";
    }
}

int main()
{
    Library *students[100], *books[100];
    int studentIndex = 0, bookIndex = 0;
    int choice, password;

    cout << "===== LIBRARY MANAGEMENT SYSTEM =====\n";
    cout << "Enter password to unlock: ";
    cin >> password;

    if (password != 8877)
    {
        cout << "Wrong Password!\n";
        return 0;
    }

    while (true)
    {
        cout<<"<-----MAIN MENU------>";
        cout << "\n1. Add new book";
        cout << "\n2. Issue book";
        cout << "\n3. Display issued books";
        cout << "\n4. Search student";
        cout << "\n5. Display library books";
        cout << "\n6. Search book";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            books[bookIndex] = new Library();
            books[bookIndex]->add();
            bookIndex++;
            break;

        case 2:
            students[studentIndex] = new Library();
            students[studentIndex]->input();
            removeBook(books, bookIndex, students[studentIndex]->id2);
            studentIndex++;
            break;

        case 3:
            if (studentIndex == 0)
                cout << "\nNo issued records found.\n";
            else
                for (int i = 0; i < studentIndex; i++)
                    students[i]->displayStudent();
            break;

        case 4:
        {
            char search[30];
            cin.ignore();
            cout << "Enter student name: ";
            cin.getline(search, 30);

            int found = -1;
            for (int i = 0; i < studentIndex; i++)
            {
                if (strcmp(search, students[i]->name) == 0)
                {
                    found = i;
                    break;
                }
            }

            if (found == -1)
                cout << "\nStudent not found.\n";
            else
                students[found]->displayStudent();
            break;
        }

        case 5:
            if (bookIndex == 0)
                cout << "\nNo books in library.\n";
            else
                for (int i = 0; i < bookIndex; i++)
                    books[i]->displayBook();
            break;

        case 6:
        {
            char searchBook[50];
            cin.ignore();
            cout << "Enter book name: ";
            cin.getline(searchBook, 50);

            int found = -1;
            for (int i = 0; i < bookIndex; i++)
            {
                if (strcmp(searchBook, books[i]->book2) == 0)
                {
                    found = i;
                    break;
                }
            }

            if (found == -1){
                cout << "\nBook not found.\n";
            }
            else{
                cout<<"Book Found.....";
                books[found]->displayBook();
           }
         break;
        }

        case 7:
            cout << "\nThank you! Program exited successfully.\n";
            return 0;

        default:
            cout << "\nInvalid choice!\n";
        }
    }
}

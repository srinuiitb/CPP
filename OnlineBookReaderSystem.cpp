/*
    Online Book Reader System
    Author : Srinu Kolukuluri
    Date : 09/12/2017

*/
#include <map>
#include <iostream>
#include <conio.h>
using namespace std;

class Book {
    int id;
    string name;
    string author;
public:
    Book(){
       // cout << "Created a empty book object " << endl;
    }
    Book(int id,string name,string author) {
        this->id = id;
        this->name = name;
        this->author = author;
        cout << "Created book called " << this->name << endl;
    }
    int getID() {
        return id;
    }
    string getName() {
        return name;
    }
    string getAuthorName() {
        return author;
    }

    bool setBookID(int id) {
        this->id = id;
    }
    bool setBookName(string name) {
        this->name = name;
    }
    bool setAuthorName(string author) {
        this->author = author;
    }

};

class Library {
public:
    static int bookCount;
    Library(){
        //cout << "Created empty Library " << endl;
    }
    Library(map<int, Book> books) {
        this->books = books;
        cout << "Created Library " << endl;
    }
    Book findBook(int id) {
        it =  books.find(id);
        return it->second;
    }
    bool removeBook(Book book) {
        it = books.find(book.getID());
        books.erase(it);
    }
    bool addBook(Book book) {
        books[book.getID()] = book;
    }
    bool addBook(string name, string author) {
        Book book;
        book.setBookID(bookCount++);
        book.setAuthorName(author);
        book.setBookName(name);
        books[book.getID()] = book;
        cout << "Total Books = " << books.size() << endl;
        cout << "Added new book to Library, Book id : " << book.getID() << ", Book name = " << book.getName() << ", Book author = " << book.getAuthorName() << endl;

    }
    bool removeBoook(int id) {
        it = books.find(id);
        books.erase(it);
    }
    map<int, Book> getBooksList() {
        return books;
    }
    bool init(map<int,Book> books) {
        this->books = books;
    }

    int TotalBooks() {
        return books.size();
    }

private:
    map<int, Book> books;
    map<int, Book>::iterator it;
};
int Library::bookCount = 1;

class User {
    int userId;
    string AccountType;
    string userName;
    public:
        static int userCount;
        User(){
           // cout << "Created User " << endl;
        }
        User(int userId, string AccountType, string userName) {
            this->userId = userId;
            this->AccountType = AccountType;
            this->userName = userName;
            cout << "Created User : " << userName << endl;
        }
        int getID() {
            return userId;
        }
        string getAccountType() {
            return AccountType;
        }
        string getUserName() {
            return userName;
        }
        bool setId(int id) {
            userId = id;
        }
        bool setAccountType(string acctype) {
            AccountType = acctype;
        }
        bool setUserName(string user) {
            userName = user;
        }
};

class UserManagement {
    static int userCount;
    map<int, User> users;
    map<int, User>::iterator it;
public:
    UserManagement(){
        //cout << "User Management System initialized " << endl;
    }
    UserManagement(map<int, User> usrs) {
        this->users = usrs;
        cout << "UserManagement System initialized " << endl;
    }
    bool addUser(string name, string acctype) {
        User usr;
        usr.setUserName(name);
        usr.setAccountType(acctype);
        usr.setId(userCount++);
        users[usr.getID()] = usr;
        cout << "Added new user, UserName = " << usr.getUserName() << ", Account Type = " << usr.getAccountType() << endl;
    }

    bool addUser(User usr) {
        users[usr.getID()] = usr;
    }

    bool removeUser(User usr) {
        it = users.find(usr.getID());
        users.erase(it);
    }
    bool removeUser(int id) {
        it = users.find(id);
        users.erase(it);
    }
    User findUser(int id) {
        it = users.find(id);
        return it->second;
    }
    bool init(map<int, User> users) {
        this->users = users;
    }
    int TotalUsers() {
        return users.size();
    }

};
int UserManagement::userCount = 1;
class Display{
    Book activeBook;
    User activeUser;
    int pageNumber;
public:
    bool setBook(Book book) {
        activeBook =  book;
    }

    bool setUser(User usr) {
        activeUser = usr;
    }
    bool setPageNumer(int n) {
        pageNumber = n;
        cout << "Reading page " << pageNumber << endl;
    }
    Display(){
        //cout << "Created dummy Display" << endl;
    }
    Display(Book activeBook, User activeUser, int pageNumber) {
        this->activeBook = activeBook;
        this->activeUser = activeUser;
        this->pageNumber = pageNumber ;
        cout << "Displaying book : " << activeBook.getName() << " for user : " << activeUser.getUserName() << endl;
        cout << "Reading page " << pageNumber << endl;
    }
    User ShowActiveUser() {
        return activeUser;
    }
    Book ShowActiveBook() {
        return activeBook;
    }
    int getCurrPage() {
        cout << "Current display page number : " << pageNumber << endl;
        return pageNumber;
    }
    bool NextPageForward() {
        pageNumber++;
        cout << "Reading page " << pageNumber << endl;
    }
    bool NextPageBackward() {
        pageNumber--;
        cout << "Reading page " << pageNumber << endl;
    }
    bool doneReading() {
        cout << "Done reading the book " << activeBook.getName() << endl;
    }
};

class OnlineBookReaderSystem {
private:
    static bool IsInstanceCreated;
    static OnlineBookReaderSystem* obrs;
    OnlineBookReaderSystem() {}
    Library lbr;
    UserManagement usrMA;
    Display dsp;
public:
    static OnlineBookReaderSystem* getInstance();
    ~OnlineBookReaderSystem() {
        IsInstanceCreated = false;
    }
    OnlineBookReaderSystem(Library lbr,UserManagement usrMA,Display dsp) {
        this->dsp = dsp;
        this->usrMA;
        this->lbr = lbr;
        cout << "Created Online Book Reader System with all modules initialized " << endl;
    }
    bool createLibrary() {
        map<int, Book> books;
        Library lbr(books);
        this->lbr = lbr;
    }
    bool createUserManagement() {
        map<int, User> users;
        UserManagement um(users);
        this->usrMA = um;
        return true;
    }
    bool createDisplay() {
        Display dsp;
        this->dsp = dsp;
        return true;
    }

    Display getDisplay() {
        return dsp;
    }
    UserManagement getUserManagementSystem() {
        return usrMA;
    }
    Library getLibrarySystem() {
        return lbr;
    }
    bool addLibrary(Library lbr){
        this->lbr = lbr;
    }
    bool addUserManagement(UserManagement um) {
        this->usrMA = um;
    }
    bool addDisplay(Display dsp) {
        this->dsp;
    }
};
bool OnlineBookReaderSystem::IsInstanceCreated = false;
OnlineBookReaderSystem* OnlineBookReaderSystem::obrs = nullptr;
OnlineBookReaderSystem* OnlineBookReaderSystem::getInstance() {
    if(!IsInstanceCreated) {
        obrs = new OnlineBookReaderSystem();
        IsInstanceCreated = true;
        return obrs;
    }
}


int main() {
    cout << "****************************************************************" << endl;
    cout << "         Welcome to Online Book Reader System        " << endl;
    cout << "****************************************************************" << endl;
    cout << endl;

    //Creating some books
    Book Aptitude(1,"Aptitude","Vanaja");
    Book Maths(2,"Maths","Srinu");
    Book Cpp(3,"CPP - Programming","Srinu");
    Book Reasoning(4,"Reasoning","Vanaja");

    Library lbr;
    lbr.addBook(Aptitude);
    lbr.addBook(Maths);
    lbr.addBook(Cpp);
    lbr.addBook(Reasoning);

    cout << " Total number of books in library = " << lbr.TotalBooks() << endl;
    //Creating users
    User Srinu(1,"GOLD","Srinu");
    User Vanaja(2,"PLATINUM","Vanaja");

    UserManagement um;
    um.addUser(Srinu);
    um.addUser(Vanaja);
    cout << "Number of users = " << um.TotalUsers() << endl;

    Display dsp;
    OnlineBookReaderSystem *obrs = OnlineBookReaderSystem::getInstance();
    obrs->addLibrary(lbr);
    obrs->addUserManagement(um);
    obrs->addDisplay(dsp);
    return 0;
}




/*
int main() {
    cout << "****************************************************************" << endl;
    cout << "         Welcome to Online Book Reader System        " << endl;
    cout << "****************************************************************" << endl;
    cout << endl;
    //cout << "_________________________________________________________________" << endl;
    map<int,Book> books;
    map<int,User> users;
    OnlineBookReaderSystem obrs;
    obrs.getLibrarySystem().init(books);
    obrs.getUserManagementSystem().init(users);
    //cout << "_________________________________________________________________" << endl;
    while(true) {
        int n;
        cout << endl;
        cout << "******************************************************" << endl;
        cout << " Please enter proper value from the following menu" << endl;
        cout << "**************  Main Menu ****************************" << endl;
        cout << " 1. Go to Library " << endl;
        cout << " 2. Go to User Management System " << endl;
        cout << " 3. Display a book for a registered user " << endl;
        cout << " 4. exit " << endl;
        cout << "************************************************" << endl;
        cout << endl;
        cin>>n;
        switch(n) {
            case 1:
            {
                int tt = 1;
                while(tt) {
                    int m;
                    cout << "   ************************************************" << endl;
                    cout << "   Please enter proper value from the following menu  : " << endl;
                    cout << "   *************** Library Menu *******************" << endl;
                    cout << "   1. Add a new book " << endl;
                    cout << "   2. Remove a book " << endl;
                    cout << "   3. Search a book " << endl;
                    cout << "   4. Display available books " << endl;
                    cout << "   5. Goto Main Menu " << endl;
                    cout << "   ************************************************" << endl;
                    cout << endl;
                    cin>>m;
                    switch(m) {
                        case 1:
                        {
                            string name, author;
                            cout << "Please enter Book name " << endl;
                            cin>>name;
                            cout << "Please enter author name " << endl;
                            cin>>author;
                            cout << endl;
                            obrs.getLibrarySystem().addBook(name,author);
                            cout << endl;
                            break;
                        }
                        case 2:
                        {
                            int removeId;
                            cout << " Enter book id to remove from the following list " << endl;
                            map<int, Book> Bookslist = obrs.getLibrarySystem().getBooksList();
                            map<int, Book>::iterator it;
                            cout << " #BOOK_ID  #BOOK_NAME  #BOOK_AUTHOR     " << endl;
                            for(it = Bookslist.begin();it!=Bookslist.end();++it) {
                                 cout << it->second.getID() << "    "<< it->second.getName() << "   "<< it->second.getAuthorName() << endl;
                            }
                            break;
                        }
                        case 3:
                        {
                            cout << " Enter book name to search " << endl;
                            break;
                        }
                        case 4:
                        {
                            cout << " Displaying current book list "<< endl;
                            map<int, Book> Bookslist = obrs.getLibrarySystem().getBooksList();
                            if(Bookslist.size() <=0) {
                                cout << " No books are available in Library " << endl;
                                break;
                            }
                            map<int, Book>::iterator it;
                            cout << " #BOOK_ID  #BOOK_NAME  #BOOK_AUTHOR     " << endl;
                            for(it = Bookslist.begin();it!=Bookslist.end();++it) {
                                 cout << it->second.getID() << "    "<< it->second.getName() << "   "<< it->second.getAuthorName() << endl;
                            }
                                break;
                        }
                        case 5:
                        {
                            tt = 0;
                            break;
                        }
                        default:
                            break;
                    }
                }
                break;
            }
            case 2:
            {
                int tt = 1;
                while(tt) {
                    int m;
                    cout << "   ************************************************" << endl;
                    cout << "   Please enter proper value from the following menu  : " << endl;
                    cout << "   *************** User Management Menu ***********" << endl;
                    cout << "   1. Add a new user " << endl;
                    cout << "   2. Remove a user " << endl;
                    cout << "   3. Search a user " << endl;
                    cout << "   4. Display available users " << endl;
                    cout << "   5. Goto Main Menu " << endl;
                    cout << "   ************************************************" << endl;
                    cout << endl;
                    cin>>m;

                    switch(m) {
                        case 1:
                        {

                            break;
                        }
                        case 2:
                        {

                            break;
                        }
                        case 3:
                        {

                            break;
                        }
                        case 4:
                        {

                            break;
                        }
                        case 5:
                        {
                            tt = 0;
                            break;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                cout << " Displaying a book for a  registered user " << endl;
                break;
            }
            case 4:
                exit(1);
            default:
                break;
        }
    }
    cout << "_________________________________________________________" << endl;
    getch();
    return 0;
}
*/

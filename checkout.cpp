// Suhrab Yeawary	
// Section 2
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.cpp"
#include "book.cpp"

using namespace std;
//Person *findPerson(vector <Person*> cardID) {
	//for()
//}
void readBooks(vector<Book*> myBook) {
	string title;
	string author;
	string num;
	string category;
	int bookID;
	Book *bookPtr = nullptr;

	/*string   title;
string   author;
string   category;
int      bookID;
Person * personPtr = nullptr;
int id, string bookName, string auth, string cat
*/
	ifstream book;
	book.open("books.txt");
	while (book>>bookID) {
		book >> title >> author >> category >> bookID;
		getline(book, num);
		getline(book, title);
		getline(book, author);
		getline(book, category);
		cout << bookID << num << title << author << category << endl;
	bookPtr = new Book(bookID, title,author, category);
	myBook.push_back(bookPtr);
}
	book.close();
	return;
}
int readPersons(vector<Person*> & Cardholder) {
	
	string firstName;
	string lastName;
	int cardID;
	bool active;
	Person *person = NULL;
	ifstream Personfile;
	Personfile .open("Person.txt");
	while (Personfile.eof()) {
		Personfile >>cardID>> firstName >> lastName>>active;
		//cout << cardID << " " << firstName << " " << lastName << " " << endl;
		Cardholder.push_back(person = new Person(cardID, active, firstName, lastName));
		Personfile.close();

	}
	
}
void readRentals(vector<Book*>&book, vector<Person*> &cardholders) {
	vector<int> bookR,cardid;
	int bookr;
	int card;
	ifstream rental;
	rental.open("rentals.txt");
	while (rental.eof())
	{
		rental >> bookr;
		bookR.push_back(bookr);
		rental >> card;
		cardid.push_back(card);
	}
	rental.close();
}
void openCard(vector<Person *> & cardholders, int ID) {
	string firstName;
	string lastName;
	bool act;
	for (int i = 0; i < cardholders.size(); i++) {
		if (cardholders.at(i)->getFirstName() == firstName && cardholders.at(i)->getLastName() == lastName)
		{
			cout << " Card ID" << cardholders.at(i)->getId() << "is Active" << endl;
			cardholders.at(i)->setActive(1);
			cout << "Cardholder" << cardholders.at(i)->fullName() << endl;
			cout << " Enter your fisrt name and last name: " << endl;
			cin >> firstName>> lastName;
		


		}
		else if(i == cardholders.size()) {
			Person *Pptr = NULL;
			cardholders.push_back(Pptr = new Person(ID, 1, firstName, lastName));
			cout << " ID " << cardholders.at(i)->getId() << "is Active: " << endl;
			cout << " Cardholder: " << cardholders.at(i)->getFirstName() << "" << cardholders.at(i)->getLastName() << endl;
			
		}
	}

}
void searchBook(vector<Book *> myBooks, int id) {
	int x;
	for (int i = 0; i < myBooks.size(); i++) {
		if (myBooks.at(i)->getId() == NULL) {
			cout << "ID: " << myBooks.at(i)->getId() << " title: " << myBooks.at(i)->getTitle() << endl;
			cout << "Author: " << myBooks.at(i)->getAuthor() << " Category: " << myBooks.at(i)->getCategory << endl;
			x++;
		}

	}
	if (x == -1) {
		cout << " Error:" << endl;
	}
	
}
void bookcheckout(vector<Person*>&cardholder, vector<Book*>&book) {
	//int cardID;
	//int BID;

}
void Bookreturn(vector<Book*> &book) {
	int bookID;
	Person *personptr = nullptr;
	//if it is valid
	cout << " Please Enter your ID: " << endl;
	cin >> bookID;
	for (int j = 0; j < book.size(); j++) {
		if (bookID == book.at(j)->getId()) {
			cout << "title: " << book.at(j)->getTitle() << endl;
			book.at(j)->setPersonPtr(nullptr);
			cout << "returned: ";
			break;

			
   }
	}

	//if
	/*for (int i = 0; i < book.size(); i++)
	{
		if (book[i]->getId() == bookID) {
			book[i]->setPersonPtr(nullptr);
		}
	}
	cout << "Please Enter the book id to return: ";
	cin >> bookID;
	*/
}
void AvaBooks(vector<Book*> &book) {
	for (int i = 0; i < book.size(); i++) {
		if (book.at(i)->getPersonPtr() == nullptr) {
			cout << book.at(i)->getId() << book.at(i)->getTitle() << book.at(i)->getAuthor() << book.at(i)->getCategory() << endl;

		}
	}

}
void outstandrental(vector<Book*> &book) {
	int x = 0;
	for (int i = 0; i < book.size(); i++) {
		if (book[i]->getPersonPtr() != nullptr) {
			cout << " book Id: " << book[i]->getId() << endl;
			cout << book.at(i)->getTitle() << "Title: " << endl;
			cout << book.at(i)->getAuthor() << " Author: " << endl;
			cout<< book.at(i)->getCategory() <<" Category: "<< endl;
			cout << "Cardholder: " << book.at(i)->getPersonPtr()->fullName() << endl;
			cout << "ID: " << book.at(i)->getPersonPtr()->getId() << endl;
			x++;
		}		
		
	
	}
	 if (x == 0) {
		 cout << " !!! Not outstanding" << endl;


}
}
void Outcardholder(vector<Book*> &book, vector<Person*> &card) {


}

void closecard() {

}
void printMenu() {
	cout << "----------Library Book Rental System----------" << endl;
	cout << "1.  Book checkout" << endl;
	cout << "2.  Book return" << endl;
	cout << "3.  View all available books" << endl;
	cout << "4.  View all outstanding rentals" << endl;
	cout << "5.  View outstanding rentals for a cardholder" << endl;
	cout << "6.  Open new library card" << endl;
	cout << "7.  Close library card" << endl;
	cout << "8.  Exit system" << endl;
	cout << "Please enter a choice: ";
}
int main()
{
	int index;
	vector<Book *> books;
	vector<Person *> cardholders;
	readBooks(books);
	readRentals(books, cardholders);
	index=readPersons(cardholders);
	int choice;
	do
	{
		// If you use cin anywhere, don't forget that you have to handle the <ENTER> key that 
		// the user pressed when entering a menu option. This is still in the input stream.
		printMenu();

		cin >> choice;
		switch (choice)
		{
		case 1:
			bookcheckout(cardholders, books);
			break;

		case 2:
			Bookreturn(books);
			break;
		case 3:
			AvaBooks(books);
			break;

		case 4:
			outstandrental(books);
			break;

		case 5:
		Outcardholder(book,cardholer);
			break;

		case 6:
			// Open new library card
			break;

		case 7:
			// Close library card
			break;

		case 8:
			// Must update records in files here before exiting the program
			break;

		default:
			cout << "Invalid entry" << endl;
			break;
		}
		cout << endl;
	} while (choice != 8);
	return 0;
}

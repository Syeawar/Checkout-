#include "book.h"

Book::Book(int id, string bookName, string auth, string cat) {
	bookID = id;
	title = bookName;
	category = cat;
	author = auth;
}
//int id, string bookName, string auth, string cat
/*string   title;
string   author;
string   category;
int      bookID;
Person * personPtr = nullptr;
*/
string Book::getTitle() {
	return title;
}

string Book::getAuthor() {
	return author;
}

string Book::getCategory() {
	return category;
}

int Book::getId() {
	return bookID;
}
void Book::setPersonPtr(Person * ptr) {
	personPtr = ptr;
} 

Person * Book::getPersonPtr() {
	return  personPtr; 
}
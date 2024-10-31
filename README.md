A simple console-based Library Management System in C that allows users to manage a collection of books. The program lets users add, display, search, delete, issue, and return books.

Features
Add Book: Add a new book to the library with a unique ID, title, and author.
Display Books: View all books currently in the library with details such as ID, title, author, and issue status.
Search Book: Search for a book by ID to get its details.
Delete Book: Remove a book from the library by its ID.
Issue Book: Mark a book as issued, so it's unavailable for others.
Return Book: Mark a previously issued book as returned, making it available again.

Project Structure
Library_Management.c: Main program file containing the source code for the library system functions.
README.md: Project documentation.

How to Run
Prerequisites
To run this project, you need a C compiler. GCC is recommended.

Compilation
Clone or download the project to your local machine.
Open a terminal or command prompt in the project directory.
Compile the C file using GCC:
gcc Library_Management.c -o Library_Management

Execution
To run the compiled program, use:
bash:  ./Library_Management
windows:  Library_Management

Library_Management
Sample Menu
Upon running, you’ll see the following menu:

Library Management System
1. Add Book
2. Display Books
3. Search Book
4. Delete Book
5. Issue Book
6. Return Book
0. Exit
Enter your choice:

Code Explanation
struct Book: Defines the structure of a book with fields for ID, title, author, and issue status.
> Functions:
addBook(): Adds a new book to the library.
displayBooks(): Displays all books in the library.
searchBook(): Searches for a book by its ID.
deleteBook(): Deletes a book by its ID.
issueBook(): Marks a book as issued.
returnBook(): Marks a book as returned.
Main Loop: Provides a menu-driven interface to access the program's functions.

Limitations
The maximum number of books is set to 100 (MAX_BOOKS).
Book ID is used to identify books uniquely but is not checked for duplicates during addition.

Future Enhancements
Improve error handling and validation.
Add support for saving/loading book data to/from a file.
Add support for more user operations and more fields, such as publication year or genre.

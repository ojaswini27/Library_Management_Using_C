#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int isIssued;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount < MAX_BOOKS) {
        struct Book newBook;
        printf("Enter Book ID: ");
        scanf("%d", &newBook.id);
        getchar(); // consume newline character left by scanf
        printf("Enter Book Title: ");
        fgets(newBook.title, sizeof(newBook.title), stdin);
        newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline
        printf("Enter Book Author: ");
        fgets(newBook.author, sizeof(newBook.author), stdin);
        newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline
        newBook.isIssued = 0;
        library[bookCount++] = newBook;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full!\n");
    }
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
    } else {
        for (int i = 0; i < bookCount; i++) {
            printf("ID: %d, Title: %s, Author: %s, Issued: %s\n",
                   library[i].id, library[i].title, library[i].author,
                   library[i].isIssued ? "Yes" : "No");
        }
    }
}

void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            printf("Book Found - ID: %d, Title: %s, Author: %s, Issued: %s\n",
                   library[i].id, library[i].title, library[i].author,
                   library[i].isIssued ? "Yes" : "No");
            return;
        }
    }
    printf("Book not found.\n");
}

void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            printf("Book deleted successfully.\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id && !library[i].isIssued) {
            library[i].isIssued = 1;
            printf("Book issued successfully.\n");
            return;
        }
    }
    printf("Book not found or already issued.\n");
}

void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id && library[i].isIssued) {
            library[i].isIssued = 0;
            printf("Book returned successfully.\n");
            return;
        }
    }
    printf("Book not found or not issued.\n");
}

int main() {
    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Issue Book\n");
        printf("6. Return Book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: issueBook(); break;
            case 6: returnBook(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
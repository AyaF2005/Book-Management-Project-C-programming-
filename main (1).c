/*name : aya abdelrahman fares shejaya ,, id : 1222654 ,, lab & L number : 1 */

#include <stdio.h>
#include <stdlib.h>

void displayMainMenu();
void addBook();
void removeBook();
void searchBook();
void uploadDataFile();
void updateDataFile();
int main() {
    printf("\nWelcome to My BookStore Management System:\n\n");
    uploadDataFile();
    int choice = 0;
    while (choice != 4) {
        displayMainMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                removeBook();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("Thank you for using My BookStore Management System. Goodbye.\n");
                break;
            default:
                printf("No such operation? Please try again.\n");
                break;
        }
    }

    return 0;
}
void displayMainMenu(){
    printf("\nPlease Select an Operation <1-4> :\n");
    printf("1- Add a Book:\n");
    printf("2- Remove a Book:\n");
    printf("3- Search for a Book:\n");
    printf("4- Exit System:\n");
}
void addBook(){
    printf("Book info has been added\n");
}
void removeBook(){
    printf("Book info has been removed\n");
}
void searchBook(){
    printf("Book has been searched for\n");
}
void uploadDataFile(){
    printf("Uploading Data File...\n");
    printf("Data File Uploaded\n");
}
void updateDataFile(){
    printf("Updating Data File...\n");
    printf("Data File Updated\n");
}



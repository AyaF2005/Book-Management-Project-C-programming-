/*name : aya abdelrahman fares shejaya ,, id : 1222654 ,, lab & L number : 1 */

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100


void displayMainMenu();
void addBook(int bins[],double prices[],int *size);
void removeBook(int bins[],double prices[],int *size);
void searchBook(int bins[],double prices[],int size);
void uploadDataFile(int bins[],double prices[],int *size);
void updateDataFile(int bins[],double prices[],int size);
void printBooks(int bins[], double prices[],int size);

int main() {
    printf("\nWelcome to My BookStore Management System:\n\n");
    double prices[MAXSIZE];;
    int bins[MAXSIZE],size=0;
    uploadDataFile(bins,prices,&size);
    int choice = 0 ;
    while (choice != 5) {
        displayMainMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook(bins, prices,&size);
                break;
            case 2:
                removeBook(bins, prices,&size);
                break;
            case 3:
                searchBook(bins, prices,size);
                break;
            case 4:
                printBooks(bins, prices,size);
                break;
            case 5:
                updateDataFile(bins, prices,size);
                printf("Thank you fot using My BookStore Managment System. GOOD BYE.\n");
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
    printf("4- print book list:\n");
    printf("5- Exit System:\n");
}
void addBook(int bins[],double prices[],int *size){
     int bin_number,i;
     double price;
    if(*size<MAXSIZE){
        printf("Enter bin number for book :\n");
        scanf("%d",&bin_number);
        for(i=0;i< *size; i++){
                if(bins[i]==bin_number){
                        printf("error this book bin_number %d is exists \n",bin_number);
                        return 0 ; }
            }
        printf("enter price of book\n");
        scanf("%lf",price);
        bins[*size]= bin_number;
        prices[*size]= price;
        (*size)++;
        printf("book with bin %d has been add \n",bin_number);
        }
}
void removeBook(int bins[],double prices[],int *size){
    if(*size>0){
        int bin_number,i,bookloc = -1;
        printf("enter bin number for book to remove \n");
        scanf("%d",&bin_number);
        for(i=0;i< *size; i++){
                if(bins[i]==bin_number){
                    bookloc = i;
                    break;}
    }
    if(bookloc!=-1){
            for(i=bookloc;i< *size-1; i++){
                bins[i] = bins[i+1];
                prices[i] = prices[i+1];
            }
            (*size)--;
            printf("book with bin %d had been removrd\n",bin_number);
    }
    else{printf("book with bin %d does not exist\n",bin_number);}
}
void searchBook(int bins[],double prices[],int size){
    int bin_number,i,pos=-1;
    if(size>0){
    printf("enter bin number for book to search for \n");
    scanf("%d",&bin_number);
    for(i=0;i< size; i++){
             if(bins[i]==bin_number){
                pos = i;
                break;
             }

    }
    if(pos!=-1){
        printf("bin# = %d     price = %lf \n", bin_number,prices[pos]);
    }
    }
}
void printBooks(int bins[], double prices[],int size)
{
    if(size>0){
    for(int i=0;i< size; i++){
        printf("bin# = %d     price = %0.2lf\n",bins[i], prices[i]);}
   }
}

void uploadDataFile(int bins[],double prices[],int *size){
    FILE*file=fopen("books.txt","r");
    if(file==NULL){
        return 0;
    }
    int bin_number,count = 0;
    double price;
    while(fscanf(file,"%d %lf",&bin_number,&price)==2 &&count<MAXSIZE){
        bins[count] = bin_number;
        prices[count]= price;
        count++; }
        *size= count;
        fclose(file);
         printf("Uploading Data File...\n");
         printf("Data File Uploaded\n");
}

void updateDataFile(int bins[],double prices[],int size){
    FILE* ifile = fopen("books.txt","W");
    if(ifile==NULL){
        //printf("error to open the fill\n");
        return 0;
    }
    for(int i=0;i< size; i++){
        fprintf(ifile,"bin# = %d    price = %0.2lf",bins[i], prices[i]);}
        fclose(ifile);
         printf("Updating Data File...\n");
         printf("Data File Updated\n");
}}

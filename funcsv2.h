#ifndef FUNCS_H
#define FUNCS_H

// Importing standard libraries' headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Importing user-defined headers (homepage and add)
#include "interfacev2.h"



// Macros to define the maximum number of columns, rows and string length
#define MAX_COLUMNS 100
#define MAX_ROWS 1000
#define MAX_STRING_LENGTH 100


// Declaring functions from other headers
void end_request(int x);
void record_prior_next_read(int user_record, int direction);
void end_request_prior_record(int current_record_index);


// 0. SET UP
char path[] = "/Users/anze/Documents/University/Y1S2/Principles of Programming/Database Management System - C/Cleaned code/MUSIC - DATASET - Sheet1 (1) copy.csv";


// 1. DATABASE STRUCTURE
typedef struct {

      char title[99];
      char author[99];
      char duration[99];
      char genre[99];
      int year;
      long int views;
      
} records;

records edit_data;
records songs[MAX_ROWS]; // Create an array of records to store the data
int num_records = 0; // Initialize the number of records to 0

char header[MAX_STRING_LENGTH]; // Create a string to store the header row

// 2. LOADING DATABASE
void load_csv(char* path) { 

    /*
    
    Description: this function reads a CSV file and stores its content in a database structure.
    Paramters: 
        - path: the path to the CSV file.
    
    
    */
    memset(songs, 0, sizeof(songs)); // Clear the array of records

    num_records = 0; // Reset the number of records

    FILE* fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Error opening file. Please make sure the link is correct.\n");
        return;
    }

    else{
        printf("File opened successfully.\n");
    }

    // Read the header row
    fscanf(fp, "%s\n", header);
    do{
        fscanf(fp, "%[^,], %[^,], %[^,], %[^,], %d, %ld\n", songs[num_records].title, songs[num_records].author, songs[num_records].duration, songs[num_records].genre, &songs[num_records].year, &songs[num_records].views);
        num_records++;
    } while (!feof(fp) && num_records < MAX_ROWS); // Read the file until the end or until the maximum number of records is reached

    // Store header row
    fclose(fp);
}


// 3. READING DATABASE

void complete_db_read() { // FINISHED


    /*

    Description: this function reads the entire database and prints it to the console.

    */

    system("clear");

    header_element();

    // Header 
    
    printf("\n\n\n DATABASE DATA:");
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    printf("%s\n", header);

    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    // Records
    for (int i = 0; i < num_records; i++) {
        printf("|%d| %s  %s  %s  %s %d %ld", i, songs[i].title, songs[i].author, songs[i].duration, songs[i].genre, songs[i].year, songs[i].views);
        printf("\n");
    }
    
    printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
    printf("\n\nTotal records in the database: %d\n", num_records);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    end_request(1);

}

void partial_db_read(int mode) { // FINISHED


    /*

    Description: this function reads the entire database and prints it to the console.

    */

    // Header 
    
    printf("\n\n\n DATABASE DATA (REDUCED):");
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    printf("%s\n", header);

    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    // Records
    for (int i = 0; i < 5; i++) {
        printf("|%d| %s, %s, %s, %s, %d, %ld", i, songs[i].title, songs[i].author, songs[i].duration, songs[i].genre, songs[i].year, songs[i].views);
        printf("\n");
    }
    if (mode == 1){
    printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
    printf("\n\nTotal records: %d\n", 5);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("\n");
    end_request(2);
    }
    else if (mode == 2){
        printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
        printf("\n\nTotal records in the database: %d\n", num_records);
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    }
    else{
        printf("You have selected a mode that does not exist.");
        sleep(2);
       
    }
    

}



// 4. READ SUBSCRIPTING (ROWS AND COLUMNS)


void subscripts_record_read(){

    /*
    

    Description: this function reads a record for a selected index 
    
    
    */

    system("clear");

    header_element();

    int user_decision_index;

    partial_db_read(2);

    printf("\n\n\n(*) Provide index of record: \n");
    printf("==> ");
    scanf("%d", &user_decision_index);

    if (user_decision_index > num_records - 1){
        system("clear");
        printf("ERROR: You have selected an empty record. Please try again.");
        sleep(2);
        subscripts_record_read();
    }
    else{

    system("clear");

    printf("\n\n\n DATABASE DATA (record: %d):", user_decision_index);
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    printf("%s\n", header);

    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    printf("|%d| %s, %s, %s, %s, %d, %ld\n", user_decision_index, songs[user_decision_index].title, songs[user_decision_index].author, songs[user_decision_index].duration, songs[user_decision_index].genre, songs[user_decision_index].year, songs[user_decision_index].views);

    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    }


    end_request_prior_record(user_decision_index);

}

void record_prior_next_read(int current_record, int direction){

    
    system("clear");

    header_element();


    int adjusted_record = current_record + direction;

    if (adjusted_record > num_records - 1 || adjusted_record < 0){  // XXX => IS NOT WORKING
        printf("\nERROR: You have selected an empty record. Please try again.\n\n\n");
        subscripts_record_read();
    }
    else{

    printf("\n\n\n DATABASE DATA (record: %d):", current_record + 1);
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    printf("%s\n", header);

    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    printf("|%d| %s, %s, %s, %s, %d, %ld", adjusted_record, songs[adjusted_record].title, songs[adjusted_record].author, songs[adjusted_record].duration, songs[adjusted_record].genre, songs[adjusted_record].year, songs[adjusted_record].views);

    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");


    }

    end_request_prior_record(adjusted_record);


}

void subscripts_column_read(){


    /*
    
    
    Description: this functions prints a column for a selected index
    
    */

    system("clear");

    header_element();

    unsigned int user_decision_col; // Important for the input to be unsigned

    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");

    printf("\t   COLUMNS");

    printf("\n%s\n", header);
    
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    printf("\n\n(*) Select index of column:\n ");
    printf("==> ");
    scanf("%d", &user_decision_col);

    switch(user_decision_col)
    {
        case 0:
            system("clear");
            header_element();

            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
            printf("\t  Title: ");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");

            for (int i = 0; i < num_records; i++){
                printf("%s", songs[i].title);
                printf("\n");
            }
            break;
        case 1:
            system("clear");
            header_element();

            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
            printf("\t   Author: "); 
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");

            for (int i = 0; i < num_records; i++){
                printf("%s", songs[i].author);
                printf("\n");
            }
            break;
        case 2:
            system("clear");
            header_element();

            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
            printf("\t   Duration: ");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");

            for (int i = 0; i < num_records; i++){
                printf("%s", songs[i].duration);
                printf("\n");
            }
            break;
        case 3:
            system("clear");
            header_element();

            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
            printf("\t   Genre: "); 
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");

            for (int i = 0; i < num_records; i++){
                printf("%s", songs[i].genre);
                printf("\n");
            }
            break;
        case 4:
            system("clear");
            header_element();

            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
            printf("\t   Year: "); 
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");

            for (int i = 0; i < num_records; i++){
                printf("%d", songs[i].year);
                printf("\n");
            }
        case 5:
            system("clear");
            header_element();

            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
            printf("\t    Views: "); 
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");

            for (int i = 0; i < num_records; i++){
                printf("%ld", songs[i].views);
                printf("\n");
            }
        default:
            system("clear");
            printf("ERROR: You have selected a column that does not exist. Please try again.\n\n");
            sleep(2);
            subscripts_column_read();
    }
    
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
    printf("\n\nTotal records: %d\n", num_records);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");

    
    end_request(0);
}

#endif
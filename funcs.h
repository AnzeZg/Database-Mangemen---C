#ifndef FUNCS_H
#define FUNCS_H

// Importing standard libraries' headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Importing user-defined headers (homepage and add)
#include "add.h"
#include "interface.h"



// Macros to define the maximum number of columns, rows and string length
#define MAX_COLUMNS 100
#define MAX_ROWS 1000
#define MAX_STRING_LENGTH 100


// Declaring functions from other headers
void end_request(int x);
void record_prior_next_read(int user_record, int direction);
void end_request_prior_record(int current_record_index);


// 0. SET UP
char path[] = "/Users/anze/Documents/University/Y1S2/Principles of Programming/Database Management System - C/New Code/MUSIC - DATASET - Sheet1 (1).csv";


// 1. DATABASE STRUCTURE
typedef struct {

    // Dimensions
    int num_columns; 
    int num_records;

    // Headers
    char column_names[MAX_COLUMNS][MAX_STRING_LENGTH]; 

    // Records
    char records[MAX_ROWS][MAX_COLUMNS][MAX_STRING_LENGTH];

} Database;


Database db;


// 2. LOADING DATABASE
void load_csv(char* path) { 

    /*
    
    Description: this function reads a CSV file and stores its content in a database structure.
    Paramters: 
        - path: the path to the CSV file.
    
    
    */

    FILE* fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Error opening file. Please make sure the link is correct.\n");
        return;
    }

    // Read header row
    char header[MAX_STRING_LENGTH];
    fgets(header, MAX_STRING_LENGTH, fp); // Read the first line of the file and store it in the header variable (prints a string of the first (header) row)
    char* token = strtok(header, ","); // Separate the stored str of the header with comman as a separator

    // Create columns from the tokens of the header
    db.num_columns = 0;
    while (token != NULL) {
        strncpy(db.column_names[db.num_columns], token, MAX_STRING_LENGTH - 1); 
        db.num_columns++;
        token = strtok(NULL, ",");
    }

    // Read data rows
    db.num_records = 0;
    while (fgets(header, MAX_STRING_LENGTH, fp) != NULL) {

        token = strtok(header, ",");
        for (int i = 0; i < db.num_columns; i++) {
            strncpy(db.records[db.num_records][i], token, MAX_STRING_LENGTH - 1); // First dimension is row, second dimension is column
            token = strtok(NULL, ","); // Move to the next token
        }

        db.num_records++;
    }

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
    for (int i = 0; i < db.num_columns; i++) {
        if (i == 0){
            printf("    %s", db.column_names[i]);
        }
        else{
        printf("%s", db.column_names[i]);
        }
        if (i < db.num_columns - 1) { // Print a comma separator if it is not the last element in the row
            printf(" , ");
        }
    }
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    // Records
    for (int i = 0; i < db.num_records; i++) {
        printf("\n");
        for (int j = 0; j < db.num_columns; j++) {
            if (j == 0){
                printf("|%d| %s",i, db.records[i][j]);
            }
            else{
            printf("%s", db.records[i][j]);
            }

            if (j < db.num_columns - 1) {
                printf(", ");
            }
           
        }
    }
    
    printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
    printf("\n\nTotal records in the database: %d\n", db.num_records);
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
    for (int i = 0; i < db.num_columns; i++) {
        if (i == 0){
            printf("    %s", db.column_names[i]);
        }
        else{
        printf("%s", db.column_names[i]);
        }
        if (i < db.num_columns - 1) { // Print a comma separator if it is not the last element in the row
            printf(" , ");
        }
    }
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    // Records
    for (int i = 0; i < 5; i++) {
        printf("\n");
        for (int j = 0; j < db.num_columns; j++) {
            if (j == 0){
                printf("|%d| %s",i, db.records[i][j]);
            }
            else{
            printf("%s", db.records[i][j]);
            }

            if (j < db.num_columns - 1) {
                printf(", ");
            }
           
        }
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
        printf("\n\nTotal records in the database: %d\n", db.num_records);
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

    if (user_decision_index > db.num_records - 1){
        system("clear");
        printf("ERROR: You have selected an empty record. Please try again.");
        sleep(2);
        subscripts_record_read();
    }
    else{

    system("clear");

    printf("\n\n\n DATABASE DATA (record: %d):", user_decision_index);
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    for (int i = 0; i < db.num_columns; i++) {
        if (i == 0){
            printf("\t%s", db.column_names[i]);
        }
        else{
        printf("%s", db.column_names[i]);
        }
        if (i < db.num_columns - 1) { // Print a comma separator if it is not the last element in the row
            printf(" , ");
        }
    }
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    for (int i = 0; i < db.num_columns; i++){
        if (i == 0){
            printf("\t%s", db.records[user_decision_index][i]);
        }
        else{
        printf("%s", db.records[user_decision_index][i]);
        }
        if (i < db.num_columns - 1) {
                printf(", ");
            }
    }

    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    }


    end_request_prior_record(user_decision_index);




}

void record_prior_next_read(int current_record, int direction){

    
    system("clear");

    header_element();


    int adjusted_record = current_record + direction;

    if (adjusted_record > db.num_records - 1 || adjusted_record < 0){  // XXX => IS NOT WORKING
        printf("\nERROR: You have selected an empty record. Please try again.\n\n\n");
        subscripts_record_read();
    }
    else{

    printf("\n\n\n DATABASE DATA (record: %d):", current_record + 1);
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    for (int i = 0; i < db.num_columns; i++) {
        if (i == 0){
            printf("\t%s", db.column_names[i]);
        }
        else{
        printf("%s", db.column_names[i]);
        }
        if (i < db.num_columns - 1) { // Print a comma separator if it is not the last element in the row
            printf(" , ");
        }
    }
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    for (int i = 0; i < db.num_columns; i++){
        if (i == 0){
            printf("\t%s", db.records[adjusted_record][i]);
        }
        else{
        printf("%s", db.records[adjusted_record][i]);
        }
        if (i < db.num_columns - 1) {
                printf(", ");
            }
    }

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
    for (int i = 0; i < db.num_columns; i++){
        if (i == 0){
            printf("\t%s", db.column_names[i]);
        }
        else {
        printf("%s", db.column_names[i]);
        }
        if (i != db.num_columns - 1){
            printf(", ");
        }
    }
     printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    printf("\n\n(*) Select index of column:\n ");
    printf("==> ");
    scanf("%d", &user_decision_col);

    if (user_decision_col > db.num_columns - 1){
        system("clear");
        printf("ERROR: You have selected a column that does not exist. Please try again.\n\n");
        sleep(2);
        subscripts_column_read();
    }
    else{

    system("clear");
    header_element();

    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
    printf("\t   %s", db.column_names[user_decision_col]); 
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");


    for (int i = 0; i < db.num_records; i++){
 
        printf("\n\t|%d| %s\n", i,db.records[i][user_decision_col]);
    

    }
    }

    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
    printf("\n\nTotal records: %d\n", db.num_records);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");

    
    end_request(0);



}




#endif
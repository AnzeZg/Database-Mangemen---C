#ifndef EDIT_H
#define EDIT_H

// 0. SET UP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "interface.h"
#include "funcs.h"
#include "add.h"

//Function declarations
void database_edit(records *edit_data);
void save_edit();
void user_decision_edit(records *sample_data);
void confirm_update_edit(records *sample_data);
void record_edit();

// Will have to redine the path here (with a different name)
char file_path[] = "/Users/anze/Documents/University/Y1S2/Principles of Programming/Database Management System - C/New Code/MUSIC - DATASET - Sheet1 (1).csv";

Database db;
int index_to_edit;

void database_edit(records *edit_data){
    /*
    
    Description: this function allows the user to edit the database
    
    */

    
    char str[MAX_STRING_LENGTH];    
    strncpy(db.records[index_to_edit][0], edit_data->title, MAX_STRING_LENGTH - 1);
    strncpy(db.records[index_to_edit][1], edit_data->author, MAX_STRING_LENGTH - 1);
    strncpy(db.records[index_to_edit][2], edit_data->duration, MAX_STRING_LENGTH - 1);
    strncpy(db.records[index_to_edit][3], edit_data->genre, MAX_STRING_LENGTH - 1);
    sprintf(str, "%d", edit_data->year);
    strncpy(db.records[index_to_edit][4], str, MAX_STRING_LENGTH - 1);
    sprintf(str, "%ld\n", edit_data->views);
    strncpy(db.records[index_to_edit][5], str, MAX_STRING_LENGTH - 1);  
    save_edit(); 
}

void save_edit(){
    FILE* file = fopen(file_path, "w");
    if (file == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "title,author,duration,genre,year,views\n");
    for (int i = 0; i < db.num_records; i++){
        for (int j = 0; j < db.num_columns; j++){
            fprintf(file, "%s", db.records[i][j]);
            if (j < db.num_columns - 1){
                fprintf(file, ",");
            }
        }
    }
    fclose(file);
}


void user_decision_edit(records *sample_data){

      /*
      
      Definition: this function prompts the user to input the data for a new record.
      It then calls the function 'save_csv_add' to add the new record to the database.
      
      */

      system("clear");

      header_element();

      char buffer[256];

      printf("\nTitle {str}: ");
      scanf(" %[^\n]", buffer);  // Reads entire line until newline is encountered - (REGEX)
      strcpy(sample_data->title, buffer);

      printf("Author {str}: ");
      scanf(" %[^\n]", buffer);
      strcpy(sample_data->author, buffer);

      printf("Duration {str} (MM:SS): ");
      scanf(" %[^\n]", buffer);
      strcpy(sample_data->duration, buffer);

      printf("Genre {str}: ");
      scanf(" %[^\n]", buffer);
      strcpy(sample_data->genre, buffer);

      printf("Year {int}: ");
      scanf("%d", &sample_data->year);

      printf("Views {long int}: ");
      scanf("%ld", &sample_data->views);

}

void confirm_update_edit(records *sample_data){

      /*
      
      Definition: this function prompts the user to confirm the data they have entered.
      If the user confirms the data, the function 'save_csv_add' is called to add the new record to the database.
      If the user does not confirm the data, the function 'user_decision_add' is called to allow the user to re-enter the data.
      
      */

      system("clear");

      header_element();

      printf("\n\nTitle: %s\n", sample_data->title);
      printf("Author: %s\n", sample_data->author);
      printf("Duration: %s\n", sample_data->duration);
      printf("Genre: %s\n", sample_data->genre);
      printf("Year: %d\n", sample_data->year);
      printf("Views: %ld\n", sample_data->views);

      char user_decision_confirm[99];

      printf("\n\n(*) Confirm the data entered? (Y/N): ");
      printf("\n==> ");
      scanf("%s", user_decision_confirm);

      if (strcmp(user_decision_confirm, "Y") == 0 || strcmp(user_decision_confirm, "y") == 0){
              database_edit(sample_data);
      }
      else if (strcmp(user_decision_confirm, "N") == 0 || strcmp(user_decision_confirm, "n") == 0){
              user_decision_edit(sample_data);
      }
      else{
              printf("Invalid input. Please try again.\n");
              sleep(2);
              confirm_update_edit(sample_data);
      }
}

void record_edit(){
    system("clear");

    header_element();

    printf("\n\n\n(*) Provide index of record: \n");
    printf("==> ");
    scanf("%d", &index_to_edit);

    if (index_to_edit > db.num_records - 1){
        system("clear");
        printf("ERROR: You have selected an empty record. Please try again.");
        sleep(2);
        subscripts_record_read();
    }
    else{
    records edit_data;
    user_decision_edit(&edit_data);
    confirm_update_edit(&edit_data);
    }
}

#endif
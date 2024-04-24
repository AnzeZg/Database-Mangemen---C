#ifndef EDIT_H
#define EDIT_H

// 0. SET UP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "interfacev2.h"
#include "funcsv2.h"
#include "addv2.h"

//Function declarations
void database_edit(records *edit_data);
void save_edit();
void user_decision_edit(records *sample_data);
void confirm_update_edit(records *sample_data);
void record_edit();

// Will have to redine the path here (with a different name)
char file_path[] = "/Users/anze/Documents/University/Y1S2/Principles of Programming/Database Management System - C/Cleaned code/MUSIC - DATASET - Sheet1 (1) copy.csv";

int index_to_edit;
records edit_data;


void save_edit(){
    FILE* file = fopen(file_path, "w");
    if (file == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "title,author,duration,genre,year,views\n");
    for (int i = 0; i < num_records; i++){
        fprintf(file, "%s,%s,%s,%s,%d,%ld\n", songs[i].title, songs[i].author, songs[i].duration, songs[i].genre, songs[i].year, songs[i].views);
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

      char keep[99] = "//keep";
      char buffer[256];
      int buffer_int;
      long buffer_long;

      printf("Enter a value for each field. If you do not wish to change a field, type //keep for the string values and -1 for the integer values.\n");

      printf("\nTitle {str}: ");
      scanf(" %[^\n]", buffer);  // Reads entire line until newline is encountered - (REGEX)
      if(buffer[0] != '\0')
        strcpy(songs[index_to_edit].title, buffer);

      printf("Author {str}: ");
      scanf(" %[^\n]", buffer);
      if(strcmp(buffer, keep) != 0){
        strcpy(songs[index_to_edit].author, buffer);}

      printf("Duration {str} (MM:SS): ");
      scanf(" %[^\n]", buffer);
      if(strcmp(buffer, keep) != 0){
        strcpy(songs[index_to_edit].duration, buffer);}

      printf("Genre {str}: ");
      scanf(" %[^\n]", buffer);
      if(strcmp(buffer, keep) != 0){
            strcpy(songs[index_to_edit].genre, buffer);}

      printf("Year {int}: ");
      scanf("%d", &buffer_int);
      if(buffer_int != -1){
        songs[index_to_edit].year = buffer_int;}

      printf("Views {long int}: ");
      scanf("%ld", &buffer_long);
      if(buffer_long != -1){
            songs[index_to_edit].views = buffer_long;}

}

void confirm_update_edit(records *sample_data){

      /*
      
      Definition: this function prompts the user to confirm the data they have entered.
      If the user confirms the data, the function 'save_csv_add' is called to add the new record to the database.
      If the user does not confirm the data, the function 'user_decision_add' is called to allow the user to re-enter the data.
      
      */

      system("clear");

      header_element();

      printf("\n\nTitle: %s\n", songs[index_to_edit].title);
      printf("Author: %s\n", songs[index_to_edit].author);
      printf("Duration: %s\n", songs[index_to_edit].duration);
      printf("Genre: %s\n", songs[index_to_edit].genre);
      printf("Year: %d\n", songs[index_to_edit].year);
      printf("Views: %ld\n", songs[index_to_edit].views);

      char user_decision_confirm[99];

      printf("\n\n(*) Confirm the data entered? (Y/N): ");
      printf("\n==> ");
      scanf("%s", user_decision_confirm);

      if (strcmp(user_decision_confirm, "Y") == 0 || strcmp(user_decision_confirm, "y") == 0){
              save_edit();
      }
      else if (strcmp(user_decision_confirm, "N") == 0 || strcmp(user_decision_confirm, "n") == 0){
              return;
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

    if (index_to_edit > num_records || index_to_edit < 0){
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
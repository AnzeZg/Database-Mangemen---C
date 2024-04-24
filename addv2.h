#ifndef ADD_H
#define ADD_H

// 0. SET UP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "interfacev2.h"

// Will have to redine the path here (with a different name)
char url[] = "/Users/anze/Documents/University/Y1S2/Principles of Programming/Database Management System - C/Cleaned code/MUSIC - DATASET - Sheet1 (1) copy.csv";


// 1. DATABASE STRUCTURE

records edit_data;

void user_decision_add(records *sample_data);
void save_csv_add(records *sample_data);
void create_instance_add();
void confirm_update_add(records *sample_data);
void header_element();

void record_add(){

      /*
      
      Definition: this function creates a new record and adds it to the database. It only calls functions as it needs to rely on independet calls to properly aggreagate the data (to create a 'records' instance at every call)
      
      */
    records edit_data;
    user_decision_add(&edit_data);
}

void user_decision_add(records *sample_data){

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

      confirm_update_add(sample_data);
}

void confirm_update_add(records *sample_data){

      /*
      
      Definition: this function confirms the user's input and asks for confirmation.
      
      */



      system("clear");

      char *ptr;

      ptr = (char *)malloc(1);


      printf("(*) Do you want to save the following data (y/n) ?\n\n");
      printf("---------------------------\n\n");

      printf("\n\nTitle: %s", sample_data->title);
      printf("\nAuthor: %s", sample_data->author);
      printf("\nDuration: %s", sample_data->duration);
      printf("\nGenre: %s", sample_data->genre);
      printf("\nYear: %d", sample_data->year);
      printf("\nViews: %ld", sample_data->views);

      printf("\n\n---------------------------\n\n");


      printf("\n==> ");
      scanf("%c", ptr);
      

      switch (*ptr)
      {
      case 'y':
            save_csv_add(sample_data);
            break;
      case 'n':
            printf("\n\nData has not been saved.\n\n");
      default:
            printf("\n\n Your option has not been registered. Please, try again.\n\n");
            confirm_update_add(sample_data);
            break;
      }

      free(ptr);

}


void save_csv_add(records *sample_data){

      /*
      
      Definition: aggreagate user input's data to the database.
      
      */


      FILE* file = fopen(url, "a");

      if (file == NULL) {
        printf("Error opening file. Please make sure the link is correct.\n");
        return;
      }
      else {

            printf("\nFiles has been opened succesfully.\n\n");

      }


      fputc('\n', file);
      fprintf(file, "%s,", sample_data->title);       
      fprintf(file, "%s,", sample_data->author);
      fprintf(file, "%s,", sample_data->duration);  
      fprintf(file, "%s,", sample_data->genre);
      fprintf(file, "%d,", sample_data->year);
      fprintf(file, "%ld", sample_data->views); 


      fputc('\n', file);

      fclose(file);

      system("clear");
      printf("\n\nData has been saved succesfully.\n\n");
      end_request(0);

}

#endif
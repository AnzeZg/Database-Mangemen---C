#ifndef INTERFACE_H
#define INTERFACE_H

#include "funcs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


void partial_db_read(int mode);
void complete_db_read();
void record_prior_next_read(int user_record, int direction);
void header_element();



void end_request(int mode){

      int user_decision;


      if (mode == 0){
      printf("\n\n\n\n ----------------------------------------\n");
      printf("(*) Return to homepage (0) or exit program (1): \n");
      printf("==> ");
      scanf("%d", &user_decision);

      switch (user_decision)
      {
      case 0:
            system("clear");
            break;
      case 1:
            system("clear");
            printf("\n\n Goodbye!");
            exit(0);
      default:
            system("clear");
            printf("Your option has not been registered. Please, try again.\n");
            fflush(stdout);  // Flush the output buffer to make sure the message appears before sleep
            end_request(0);
            break;
      }
      }

      else if (mode == 1){

            printf("\n\n\n\n --------------------------------------\n");
            printf("(*) Return to homepage (0), exit program (1) or show only partial details (2): \n");
            printf("==> ");
            scanf("%d", &user_decision);

            switch (user_decision)
            {
            case 0:
                  system("clear");
                  break;
            case 1:
                  system("clear");
                  printf("\n\n Goodbye!");
                  exit(0);
            case 2:
                  system("clear");
                  header_element();
                  partial_db_read(1);
                  break;
            default:
                  system("clear");
                  printf("Your option has not been registered. Please, try again.\n");
                  fflush(stdout);  // Flush the output buffer to make sure the message appears before sleep
                  sleep(2);
                  complete_db_read();
                  break;
            }
      }
      else if (mode == 2){

            printf("\n\n\n\n ------------------------------------\n");
            printf("(*) Return to homepage (0), exit program (1) or show all details (2): \n");
            printf("==> ");
            scanf("%d", &user_decision);

            switch (user_decision)
            {
            case 0:
                  system("clear");
                  break;
            case 1:
                  system("clear");
                  printf("\n\n Goodbye!");
                  exit(0);
            case 2:
                  complete_db_read();
                  break;
            default:
                  system("clear");
                  printf("Your option has not been registered. Please, try again.");
                  fflush(stdout);
                  sleep(2);
                  partial_db_read(1);
                  break;
            }
      }
}

void end_request_prior_record(int current_record_index){

      int user_decision;

      printf("\n\n\n\n ------------------------------------\n");
      printf("(*) Return to homepage (0), exit program (1), prior record (2) or next record (3): \n");
      printf("==> ");
      scanf("%d", &user_decision);

      switch (user_decision)
      {
      case 0:
            system("clear");
            break;
      case 1:
            system("clear");
            printf("\n\n Goodbye!");
            exit(0);
      case 2:
            record_prior_next_read(current_record_index, -1);
            break;
      case 3:
            record_prior_next_read(current_record_index, 1);

      default:
            system("clear");
            printf("Your option has not been registered. Please, try again.\n");
            fflush(stdout);
            sleep(2);
            end_request_prior_record(current_record_index);
            break;
      }
            


      
}

void header_element(){


      printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t\tDATABASE MANAGEMENT SYSTEM");
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    Session info: %s", asctime (timeinfo)); 
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");



}






#endif
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "funcs.h"
#include "interface.h"
#include "add.h"
#include "edit.h"


// Function declarations
void homepage();
void complete_db_read();
void record_add();
void header_element();
void record_edit();
 

int main(){

        while (1){
        homepage();
        }

        return 0;
}

void homepage(){

    load_csv(path);
      
    system("clear");

    header_element();

    printf("\n\n|-> READ MODE\n");
    printf("      |--> Read full database (1.1)\n");
    printf("      |--> Read by columns (1.2)\n");
    printf("      |--> Read by rows (1.3)\n");
    printf("                                       \n");
     printf("|-> WRITE/SAVE MODE \n");
    printf("      |--> Add a row to the db (2.1)\n");
    printf("      |--> Edit an existing row in the db (2.2)\n");

    char user_decision_homepage[99];   

    printf("\n\n\n(*) Select an option here: ");
    printf("\n==> ");
    scanf("%s", user_decision_homepage);

    if (strcmp(user_decision_homepage, "1.1") == 0){
            complete_db_read();
    }
    else if (strcmp(user_decision_homepage, "1.2") == 0){
            subscripts_column_read();
    }
    else if (strcmp(user_decision_homepage, "1.3") == 0){
            subscripts_record_read();
    }
    else if (strcmp(user_decision_homepage, "2.1") == 0){
            record_add();
  
    }
    else if (strcmp(user_decision_homepage, "2.2") == 0){
        record_edit();
    }
    else{
            printf("Invalid input. Please try again.\n");
            sleep(2);
            homepage();
    }

}



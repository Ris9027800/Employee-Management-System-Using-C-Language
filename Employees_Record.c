#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_GMAIL_LENGTH 40
typedef struct Employee
{
    char name[MAX_NAME_LENGTH];
    int emp_id;
    long long int mobile_no;
    char Gmail[MAX_GMAIL_LENGTH];
} Record;

// Function to read employee details from file and load them into the array
int load_from_file(Record employees[100]) {
    char fileName[100];
    printf("Enter the File Which you Want to Open: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("The file hasn't been generated yet or can't be opened.\n");
        return 0;
    }

    int i = 0;
    char buffer[100];  // buffer to hold each line of the file

    // Reading file line by line and parsing the employee data
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (sscanf(buffer, "Employee Name - %s", employees[i].name) == 1) {
            // Read the next lines for employee ID, mobile no, and Gmail
            fgets(buffer, sizeof(buffer), file);  // Reading Employee ID
            sscanf(buffer, "Employee Id - %d", &employees[i].emp_id);

            fgets(buffer, sizeof(buffer), file);  // Reading Mobile no
            sscanf(buffer, "Employee Mobile no - %lld", &employees[i].mobile_no);

            fgets(buffer, sizeof(buffer), file);  // Reading Gmail
            sscanf(buffer, "Employee Gmail - %s", employees[i].Gmail);

            // Skip the separator line (----------------------------------)
            fgets(buffer, sizeof(buffer), file);

            i++;  // Move to the next employee
        }
    }

    fclose(file);
    return i;  // Return the number of employees loaded
}
 
 // Another Method to read file but It'll Arise a Problem 

// int load_from_file(Record employees[100])
// {

//     char fileName[100];
//     printf("Enter the File Which you Want to Open ");
//     scanf("%s", fileName);
//     FILE *file;
//     file = fopen(fileName, "r");
//     if (file == NULL)
//     {
//         printf("The file hasn't been generated yet or can't be opened.\n");
//         return 0;
//     }

//     int i = 0;
//     while (fscanf(file, "Employee %*d Details are - \n") != EOF)
//     {   fscanf(file, "Employee Name - %s \n", employees[i].name);
//         fscanf(file, "Employee Id - %d \n", &employees[i].emp_id);
//         fscanf(file, "Employee Mobile no - %lld \n", &employees[i].mobile_no);
//         fscanf(file, "Employee Gmail - %s \n", employees[i].Gmail);
//         fscanf(file, "\n\n----------------------------------\n");
//         i++;
//     }

//     fclose(file);
//     return i; 
//     // Return the number of employees loaded
// }

// Updation of Employee Details with the Help of Modify Function

void Modify(Record employees[100], int count, int Modify_id)
{
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (Modify_id == employees[i].emp_id)
        {
            printf("Employee %d Details are - \n", i + 1);
            printf("Employee Name - %s \n", employees[i].name);
            printf("Employee Id - %d \n", employees[i].emp_id);
            printf("Employee Mobile no - %lld \n", employees[i].mobile_no);
            printf("Employee Gmail Id - %s \n", employees[i].Gmail);
            printf("\n\n----------------------------------\n");

            // prompt for new details
            printf("   Enter the Details for new user :- \n");

            // Prompt for new details

            printf("Enter the new employee name: ");
            scanf(" %[^\n]%*c", employees[i].name);
            printf("Enter the new mobile number: ");
            scanf("%lld", &employees[i].mobile_no);
            printf("Enter the new Gmail: ");
            scanf("%s", employees[i].Gmail);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("employee with Id %d does not Found ..", Modify_id);
    }
    else
    {
        char fileName[100];
        printf("Enter the file in which you want to Modify The Details : ");
        scanf("%s", fileName);
        FILE *file;
        file = fopen(fileName, "w");
        for (int i = 0; i < count; i++)
        {
            fprintf(file, "Employee %d Details are - \n", i + 1);
            fprintf(file, "Employee Name - %s \n", employees[i].name);
            fprintf(file, "Employee Id - %d \n", employees[i].emp_id);
            fprintf(file, "Employee Mobile no - %lld \n", employees[i].mobile_no);
            fprintf(file, "Employee Gmail - %s \n", employees[i].Gmail);
            fprintf(file, "\n\n----------------------------------\n");
        }
        fclose(file);
        printf("The Details are updated Succesfully . \n");
    }
}

void NEw_data(Record employees[100], int *count)
{
    char fileName[100];
    FILE *file;
    while(getchar()!= '\n');
    printf("Enter the file name : ");
  fgets(fileName , sizeof(fileName), stdin);
  fileName[strcspn(fileName , "\n")] = '\0';
    
    file = fopen(fileName, (const char *)"w");
    if (file == NULL)
    {
        printf("The File has'nt Generated\n");
        return;
    }
    for (int i = 0; i < *count; i++)
    {
        printf("Enter the employee name :  ");
        scanf(" %[^\n]%*c", employees[i].name);
        printf("Enter the employee Id :  ");
        scanf("%d", &employees[i].emp_id);
        // printf("\n");
        printf("Enter the employee mobile no :  ");
        scanf("%lld", &employees[i].mobile_no);
        // printf("\n");
        printf("Enter the employee  Gmail :  ");
        scanf("%39s",employees[i].Gmail);
        printf("\n------------------------------------------------\n");

        // Entering Information in Info File....
        fprintf(file, "Employee %d Details are - \n", i + 1);
        fprintf(file, "Employee Name - %s \n", employees[i].name);
        fprintf(file, "Employee Id - %d \n", employees[i].emp_id);
        fprintf(file, "Employee Mobile no - %lld \n", employees[i].mobile_no);
        fprintf(file, "Employee Gmail - %s \n", employees[i].Gmail);
        fprintf(file, "\n----------------------------------\n");
    }
    fclose(file);
    for (int i = 0; i < *count; i++)
    {
        printf("All the details are here of employee %d\nName - %s\nEmp_ID - %d\nMobile_no - %lld\nGmail - %s\n", i + 1, employees[i].name, employees[i].emp_id, employees[i].mobile_no, employees[i].Gmail);
        printf("\n-----------------------------------------------------------------------\n");
    }
    printf("The File has been Generated\n");
}

void Append(Record employees[100], int *count)
{
    char fileName[100];
     FILE *file;
   while(getchar()!= '\n');
    printf("Enter the File in which you want Append The details : ");
    fgets(fileName , sizeof(fileName), stdin);
    fileName[strcspn(fileName , "\n")] = '\0';
   
    file = fopen(fileName, (const char *)"a");
    if (file == NULL)
    {
        printf("The File has'nt Generated\n");
        return;
    }
    for (int i = 0; i < *count; i++)
    {
        printf("Enter the employee name :  ");
        scanf(" %[^\n]%*c", employees[i].name);
        printf("Enter the employee Id :  ");
        scanf("%d", &(employees[i].emp_id));
        printf("Enter the employee mobile no :  ");
        scanf("%lld", &(employees[i].mobile_no));
        printf("Enter the employee  Gmail :  ");
        scanf("%s", &(employees[i].Gmail));
        printf("\n------------------------------------------------\n");

        
    time_t current_time;  // creating a time_t variable to store current_time.
    time(&current_time);  // Getting the Current time.

    // Convert the current time in to local time format
    struct tm*local_time = localtime(&current_time);
//Printing the date and time in specific Format
    fprintf(file,"The Details Below Was Appended on  : %2d-%02d-%04d %02d:%02d:%02d\n\n", local_time->tm_mday,local_time->tm_mon +1,local_time->tm_year + 1900,local_time->tm_hour,local_time->tm_min,local_time->tm_sec);

 // Entering Information in Info File....
        fprintf(file, "Employee %d Details are - \n", i + 1);
        fprintf(file, "Employee Name - %s \n", employees[i].name);
        fprintf(file, "Employee Id - %d \n", employees[i].emp_id);
        fprintf(file, "Employee Mobile no - %lld \n", employees[i].mobile_no);
        fprintf(file, "Employee Gmail - %s \n", employees[i].Gmail);
        fprintf(file, "\n----------------------------------\n");

    }
    fclose(file);
    for (int i = 0; i < *count; i++)
    {
        printf("All the details are here of employee %d\nName - %s\nEmp_ID - %d\nMobile_no - %lld\nGmail - %s\n", i + 1, employees[i].name, employees[i].emp_id, employees[i].mobile_no, employees[i].Gmail);
        printf("\\n -----------------------------------------------------------------------\n");
    }
}

void Delete(Record employees[100], int *count, int delete_id) {
    int found = 0;  // To track if the employee is found

    // Search for the employee with the given ID
    for (int i = 0; i < *count; i++) {
        if (employees[i].emp_id == delete_id) {
            found = 1;  // Employee found

            // Shift all employees after the found one to the left
            for (int j = i; j < *count - 1; j++) {
                employees[j] = employees[j + 1];  // Overwrite with the next employee
            }
            (*count)--;  // Decrease the count of employees
            break;  // Exit the loop after deleting
        }
    }

    // If employee is not found, display a message
    if (!found) {
        printf("Employee with ID %d not found.\n", delete_id);
    } else {
        printf("The details of an employee has been Deleted Successfully \n");
        // If employee is found, update the file
        char fileName[100];
        printf("Confirm your Action with Entering  the File Name: ");
        scanf("%s", fileName);

        FILE *file = fopen(fileName, "w");  // Open file for writing

        // Write all remaining employees to the file
        for (int i = 0; i < *count; i++) {
            fprintf(file, "Employee %d Details are - \n", i + 1);
            fprintf(file, "Employee Name - %s \n", employees[i].name);
            fprintf(file, "Employee Id - %d \n", employees[i].emp_id);
            fprintf(file, "Employee Mobile no - %lld \n", employees[i].mobile_no);
            fprintf(file, "Employee Gmail - %s \n", employees[i].Gmail);
            fprintf(file, "\n\n----------------------------------\n");
        }

        fclose(file);  // Close the file
    }
}


int main()
{
    Record employees[100];
    int count = 0;
    int Modify_id;
    int choice;
    int delete_id;
    int exit_flag = 0;


 while(!exit_flag){
        // Clear screen before displaying the menu
#ifdef _WIN32
        system("cls"); // For Windows
#else
        system("clear"); // For Unix-like systems
#endif

        printf("                                                      Main Menu\n");
        printf("                                  Press 1.)For creating a New Record to store \n ");
        printf("                                       2.) For Modifying or Updating Information In Records \n ");
        printf("                                       3.) For Appending the details in Pre-Exist Records\n ");
        printf("                                       4.) To Delete Specific Info From The Record : \n ");
        printf("                                       5.) To View File Details\n");
        printf("                                        6.) Exit The Program\n ");
        printf("                                           Enter Your Choice :  ");
         scanf("%d", &choice);
       
    
   
    switch (choice)
    {
    case 1:
        printf("Enter the number of employee,s data you want to store : ");
        scanf("%d", &count);
        NEw_data(employees, &count);
        break;

    case 2:
        count = load_from_file(employees);
        printf("Enter The Employee Id to modify : ");
        scanf("%d", &Modify_id);
        Modify(employees, count, Modify_id);
        break;

    case 3:
        printf("Enter The num of employee : ");
        scanf("%d", &count);
        Append(employees, &count);
        printf("The details of employee has been added and \n");
        break;
case 4:
        // if(load_from_file !=NULL){
        count = load_from_file(employees);
        printf("Enter The ID of an Employee Which you Want to Delete : ");
        scanf("%d", &delete_id);
        Delete(employees,&count,delete_id);
        // printf("The details of an employee has been Deleted Successfully \n");
        break;

case 5:
       count = load_from_file(employees);
        for(int i = 0; i<count; i++){
            printf("Employee Name - %s \n", employees[i].name);
            printf("Employee Id - %d \n", employees[i].emp_id);
            printf("Employee Mobile no - %lld \n", employees[i].mobile_no);
            printf("Employee Gmail Id - %s \n", employees[i].Gmail);
            printf("\n----------------------------------\n");
        }
        
        break;

case 6:
        exit_flag = 1;
        printf("Exiting The Program:  \n");
        break;

    default:
        printf("You have Entered the invailid Option ///");
        break;
    }

        // Pause the program for the user to see the result before clearing the screen
        printf("Press Enter to continue...");
        getchar();  // Wait for user input
        getchar();  // This ensures proper pause after a choice
    }

    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgpa_calculator.h" // Header for CGPA calculation
#include "student_record.h"  // Header for student records
#include "file_operations.h" // Header for file operations

#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 100  // Maximum number of student records

void welcomeUser(const char *name) {
    printf("Welcome, %s, to Student Record, the portal for all student databases.\n", name);
}

void showMainMenu() {
    printf("\nWhat would you like to do today?\n");
    printf("Press 1 to Calculate CGPA or GPA\n");
    printf("Press 2 for Student Records\n");
    printf("Press 3 to Exit\n");
}

int main() {
    char name[MAX_NAME_LENGTH];  // Array to store the user's name
    int choice;                  // Variable to store the user's menu choice
    struct StudentRecord *students[MAX_RECORDS]; // Array to hold student records
    int student_count = 0;       // Current number of students

    // Display the initial welcome message
    printf("Welcome to Miva Open University Student Record\n");

    // Prompt the user to enter their name
    printf("Please enter your name: ");
    scanf("%49s", name);  // Read the name, limiting input to avoid overflow

    welcomeUser(name); // Greet the user

    do {
        showMainMenu(); // Show the main menu options
        printf("Please enter your choice (1, 2, or 3): ");
        scanf("%d", &choice);  // Read the user's menu choice

        switch (choice) {
            case 1:
                printf("You selected to Calculate CGPA or GPA.\n");
                calculateCGPA();  // Call the CGPA calculation function
                break;

            case 2:
                printf("You selected Records.\n");

                // Prompt to upload existing records
                printf("Would you like to upload your records for faster results? For Yes, press 1, No press 2: ");
                int upload_choice;
                scanf("%d", &upload_choice);
                if (upload_choice == 1) {
                    loadRecordsFromFile(students, &student_count);
                }

                // Student Records Menu
                int record_choice;
                do {
                    printf("\n--- Student Records Menu ---\n");
                    printf("1. Add Student Record\n");
                    printf("2. Display All Student Records\n");
                    printf("3. Search Student Record\n");
                    printf("4. Calculate Average Marks\n");
                    printf("5. Sort Student Records\n");
                    printf("6. Save Records to File\n");
                    printf("7. Return to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &record_choice);

                    switch (record_choice) {
                        case 1:
                            addStudentRecord(students, &student_count); // Function to add a student record
                            break;
                        case 2:
                            displayStudentRecords(students, student_count); // Function to display all records
                            break;
                        case 3:
                            searchStudent(students, student_count); // Function to search for a student
                            break;
                        case 4:
                            calculateAverageMarks(students, student_count); // Function to calculate average marks
                            break;
                        case 5: {
                            printf("Sort in ascending order? For Yes, press 1, No for descending: ");
                            int sort_choice;
                            scanf("%d", &sort_choice);
                            sortStudentRecords(students, student_count, sort_choice == 1); // Sort the records
                            break;
                        }
                        case 6:
                            printf("Would you like to download your records? For Yes, press 1, No press 2: ");
                            int download_choice;
                            scanf("%d", &download_choice);
                            if (download_choice == 1) {
                                saveRecordsToFile(students, student_count); // Save student records to file
                            }
                            break;
                        case 7:
                            printf("Returning to Main Menu...\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (record_choice != 7); // Continue until the user chooses to return to the main menu

                break;

            case 3:
                printf("Exiting the program. Goodbye, %s!\n", name);
                // Free memory logic if needed (for dynamically allocated student records)
                break;

            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    } while (choice != 3); // Loop until the user chooses to exit

    // Free allocated memory before exiting
    for (int i = 0; i < student_count; i++) {
        free(students[i]);
    }

    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgpa_calculator.h" // Header for CGPA calculation
#include "student_record.h"  // Header for student records
#include "file_operations.h" // Header for file operations

#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 100  // Maximum number of student records

// Function to clear input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

void welcomeUser(const char *name) {
    printf("Welcome, %s, to Student Record, the portal for all student databases.\n", name);
}

void showMainMenu() {
    printf("\nWhat would you like to do today?\n");
    printf("Press 1 to Calculate CGPA or GPA\n");
    printf("Press 2 for Student Records\n");
    printf("Press 3 to Exit\n");
}

int main() {
    char name[MAX_NAME_LENGTH];  // Array to store the user's name
    int choice;                  // Variable to store the user's menu choice
    struct StudentRecord *students[MAX_RECORDS]; // Array to hold student records
    int student_count = 0;       // Current number of students

    // Display the initial welcome message
    printf("Welcome to Miva Open University Student Record\n");

    // Prompt the user to enter their name
    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    welcomeUser(name); // Greet the user

    do {
        showMainMenu(); // Show the main menu options
        printf("Please enter your choice (1, 2, or 3): ");
        scanf("%d", &choice);  // Read the user's menu choice
        clearInputBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                printf("You selected to Calculate CGPA or GPA.\n");
                calculateCGPA();  // Call the CGPA calculation function
                break;

            case 2:
                printf("You selected Records.\n");

                // Prompt to upload existing records
                printf("Would you like to upload your records for faster results? For Yes, press 1, No press 2: ");
                int upload_choice;
                scanf("%d", &upload_choice);
                clearInputBuffer();
                if (upload_choice == 1) {
                    loadRecordsFromFile(students, &student_count);
                }

                // Student Records Menu
                int record_choice;
                do {
                    printf("\n--- Student Records Menu ---\n");
                    printf("1. Add Student Record\n");
                    printf("2. Display All Student Records\n");
                    printf("3. Search Student Record\n");
                    printf("4. Calculate Average Marks\n");
                    printf("5. Sort Student Records\n");
                    printf("6. Save Records to File\n");
                    printf("7. Return to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &record_choice);
                    clearInputBuffer();

                    switch (record_choice) {
                        case 1:
                            addStudentRecord(students, &student_count); // Function to add a student record
                            break;
                        case 2:
                            displayStudentRecords(students, student_count); // Function to display all records
                            break;
                        case 3:
                            searchStudent(students, student_count); // Function to search for a student
                            break;
                        case 4:
                            calculateAverageMarks(students, student_count); // Function to calculate average marks
                            break;
                        case 5: {
                            printf("Sort in ascending order? For Yes, press 1, No for descending: ");
                            int sort_choice;
                            scanf("%d", &sort_choice);
                            clearInputBuffer();
                            sortStudentRecords(students, student_count, sort_choice == 1); // Sort the records
                            break;
                        }
                        case 6:
                            printf("Would you like to download your records? For Yes, press 1, No press 2: ");
                            int download_choice;
                            scanf("%d", &download_choice);
                            clearInputBuffer();
                            if (download_choice == 1) {
                                saveRecordsToFile(students, student_count); // Save student records to file
                            }
                            break;
                        case 7:
                            printf("Returning to Main Menu...\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (record_choice != 7); // Continue until the user chooses to return to the main menu

                break;

            case 3:
                printf("Exiting the program. Goodbye, %s!\n", name);
                // Free memory logic if needed (for dynamically allocated student records)
                break;

            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    } while (choice != 3); // Loop until the user chooses to exit

    // Free allocated memory before exiting
    for (int i = 0; i < student_count; i++) {
        free(students[i]);
    }

    return 0;
}

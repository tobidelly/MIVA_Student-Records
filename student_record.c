#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_record.h"
#define MAX_RECORDS 100

void clearInputBuffer();

// Function to determine grade based on total marks
char determineGrade(int total_marks) {
    if (total_marks > 100) return 'I';  // Invalid
    if (total_marks >= 70) return 'A';
    else if (total_marks >= 60) return 'B';
    else if (total_marks >= 50) return 'C';
    else if (total_marks >= 40) return 'D';
    else return 'F';
}

// Function to input data for a student with option to review and correct
void inputStudentRecord(struct StudentRecord *student) {
    int confirm = 0;  // Variable for confirming input
    while (!confirm) {
        printf("Enter full name: ");
        fgets(student->personal.full_name, sizeof(student->personal.full_name), stdin);
        student->personal.full_name[strcspn(student->personal.full_name, "\n")] = '\0'; // Remove newline

        printf("Enter department: ");
        fgets(student->personal.department, sizeof(student->personal.department), stdin);
        student->personal.department[strcspn(student->personal.department, "\n")] = '\0';

        printf("Enter faculty: ");
        fgets(student->personal.faculty, sizeof(student->personal.faculty), stdin);
        student->personal.faculty[strcspn(student->personal.faculty, "\n")] = '\0';

        printf("Enter matriculation number: ");
        scanf("%d", &student->personal.matriculation_number);
        clearInputBuffer(); // Clear newline after integer input

        printf("Enter the number of courses (1-%d): ", MAX_COURSES);
        scanf("%d", &student->num_courses);
        clearInputBuffer();

        if (student->num_courses < 1 || student->num_courses > MAX_COURSES) {
            printf("Invalid number of courses. Setting to maximum (%d).\n", MAX_COURSES);
            student->num_courses = MAX_COURSES;
        }

        for (int i = 0; i < student->num_courses; i++) {
            printf("\nCourse %d Name: ", i + 1);
            fgets(student->courses[i].course_name, sizeof(student->courses[i].course_name), stdin);
            student->courses[i].course_name[strcspn(student->courses[i].course_name, "\n")] = '\0';

            printf("Course %d Code: ", i + 1);
            fgets(student->courses[i].course_code, sizeof(student->courses[i].course_code), stdin);
            student->courses[i].course_code[strcspn(student->courses[i].course_code, "\n")] = '\0';

            printf("Enter CA1 Score (0-40): ");
            scanf("%d", &student->courses[i].CA1);
            printf("Enter CA2 Score (0-40): ");
            scanf("%d", &student->courses[i].CA2);
            printf("Enter Exam Score (0-70): ");
            scanf("%d", &student->courses[i].exam);
            clearInputBuffer();

            // Calculate total and grade automatically
            student->courses[i].total_marks = student->courses[i].CA1 + student->courses[i].CA2 + student->courses[i].exam;
            student->courses[i].grade = determineGrade(student->courses[i].total_marks);
        }

        // Display entered information for review
        printf("\nReview the entered information:\n");
        displayStudentRecord(student);

        printf("\nConfirm all information is correct? (1 for Yes, 0 to re-enter): ");
        scanf("%d", &confirm);
        clearInputBuffer();
    }
}

// Function to display data for a single student
void displayStudentRecord(const struct StudentRecord *student) {
    printf("\n--- Student Personal Information ---\n");
    printf("Name: %s\n", student->personal.full_name);
    printf("Department: %s\n", student->personal.department);
    printf("Faculty: %s\n", student->personal.faculty);
    printf("Matriculation Number: %d\n", student->personal.matriculation_number);

    printf("\n--- Course Information ---\n");
    printf("Course Code\tCourse Name\tCA1\tCA2\tExam\tTotal\tGrade\n");
    for (int i = 0; i < student->num_courses; i++) {
        struct CourseInfo course = student->courses[i];
        printf("%s\t\t%s\t\t%d\t%d\t%d\t%d\t%c\n",
               course.course_code, course.course_name,
               course.CA1, course.CA2, course.exam,
               course.total_marks, course.grade);
    }
}

// Other functions like displayStudentRecords, searchStudent, calculateAverageMarks, etc., remain unchanged.


// Function to display all student records
void displayStudentRecords(struct StudentRecord *students[], int count) {
    if (count == 0) {
        printf("No student records to display.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        displayStudentRecord(students[i]);
    }
}

// Function to search for a student by name or matriculation number
void searchStudent(struct StudentRecord *students[], int count) {
    char searchTerm[100];
    printf("Enter student name or matriculation number to search: ");
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        // Convert matriculation number to string for comparison
        char matricStr[20];
        sprintf(matricStr, "%d", students[i]->personal.matriculation_number);

        if (strcmp(students[i]->personal.full_name, searchTerm) == 0 ||
            strcmp(matricStr, searchTerm) == 0) {
            printf("\n--- Found Record ---\n");
            displayStudentRecord(students[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No records found for '%s'.\n", searchTerm);
    }
}

// Function to calculate average marks for all students
void calculateAverageMarks(struct StudentRecord *students[], int count) {
    if (count == 0) {
        printf("No student records available to calculate average.\n");
        return;
    }

    float totalMarks = 0;
    int totalCourses = 0;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < students[i]->num_courses; j++) {
            totalMarks += students[i]->courses[j].total_marks;
            totalCourses++;
        }
    }

    if (totalCourses == 0) {
        printf("No course marks available to calculate average.\n");
        return;
    }

    float averageMarks = totalMarks / totalCourses;
    printf("Average Marks of all students across all courses: %.2f\n", averageMarks);
}

// Function to sort student records based on total marks
void sortStudentRecords(struct StudentRecord *students[], int count, int ascending) {
    // Simple bubble sort based on total marks of the first course (for demonstration)
    // Modify the sorting criteria as needed
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            // Calculate average marks per student for sorting
            float avg_j = 0.0, avg_j1 = 0.0;
            for (int k = 0; k < students[j]->num_courses; k++) {
                avg_j += students[j]->courses[k].total_marks;
            }
            avg_j /= students[j]->num_courses;

            for (int k = 0; k < students[j + 1]->num_courses; k++) {
                avg_j1 += students[j + 1]->courses[k].total_marks;
            }
            avg_j1 /= students[j + 1]->num_courses;

            if ((ascending && avg_j > avg_j1) ||
                (!ascending && avg_j < avg_j1)) {
                // Swap the records
                struct StudentRecord *temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("Student records sorted successfully.\n");
}

// Function to add a student record
void addStudentRecord(struct StudentRecord *students[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Maximum student records reached. Cannot add more.\n");
        return;
    }

    struct StudentRecord *student = (struct StudentRecord *)malloc(sizeof(struct StudentRecord));
    if (student == NULL) {
        perror("Memory allocation failed.");
        return;
    }

    inputStudentRecord(student);
    students[*count] = student;
    (*count)++;

    printf("Student record added successfully.\n");
}

// Function to remove a student record by matriculation number
void removeStudentRecord(struct StudentRecord *students[], int *count, int matriculation_number) {
    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (students[i]->personal.matriculation_number == matriculation_number) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("No student found with matriculation number %d.\n", matriculation_number);
        return;
    }

    // Free the memory for the student being removed
    free(students[index]);

    // Shift the remaining students
    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--;
    printf("Student record with matriculation number %d removed successfully.\n", matriculation_number);
}

// Function to modify a student record by matriculation number
void modifyStudentRecord(struct StudentRecord *students[], int count, int matriculation_number) {
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (students[i]->personal.matriculation_number == matriculation_number) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("No student found with matriculation number %d.\n", matriculation_number);
        return;
    }

    printf("Modifying record for student with matriculation number %d:\n", matriculation_number);
    inputStudentRecord(students[index]);
    printf("Student record modified successfully.\n");
}



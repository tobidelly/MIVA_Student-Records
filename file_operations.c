#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operations.h"

// Function to save student records to a file
void saveRecordsToFile(struct StudentRecord *students[], int count) {
    FILE *file = fopen("student_records.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing.");
        return;
    }

    fprintf(file, "%d\n", count); // Write number of students

    for (int i = 0; i < count; i++) {
        struct StudentRecord *student = students[i];
        // Write personal info
        fprintf(file, "%s\n%s\n%s\n%d\n%d\n",
                student->personal.full_name,
                student->personal.department,
                student->personal.faculty,
                student->personal.matriculation_number,
                student->num_courses);

        // Write course info
        for (int j = 0; j < student->num_courses; j++) {
            struct CourseInfo *course = &student->courses[j];
            fprintf(file, "%s\n%s\n%d\n%d\n%d\n%d\n%c\n",
                    course->course_name,
                    course->course_code,
                    course->CA1,
                    course->CA2,
                    course->exam,
                    course->total_marks,
                    course->grade);
        }
    }

    fclose(file);
    printf("Records saved successfully to 'student_records.txt'.\n");
}

// Function to load student records from a file
int loadRecordsFromFile(struct StudentRecord *students[], int *count) {
    FILE *file = fopen("student_records.txt", "r");
    if (file == NULL) {
        printf("No existing records found.\n");
        return 0;
    }

    int total_students;
    if (fscanf(file, "%d\n", &total_students) != 1) {
        printf("Failed to read the number of students.\n");
        fclose(file);
        return 0;
    }

    for (int i = 0; i < total_students; i++) {
        struct StudentRecord *student = (struct StudentRecord *)malloc(sizeof(struct StudentRecord));
        if (student == NULL) {
            perror("Memory allocation error.");
            fclose(file);
            return 0;
        }

        // Read personal info
        if (fgets(student->personal.full_name, sizeof(student->personal.full_name), file) == NULL ||
            fgets(student->personal.department, sizeof(student->personal.department), file) == NULL ||
            fgets(student->personal.faculty, sizeof(student->personal.faculty), file) == NULL ||
            fscanf(file, "%d\n", &student->personal.matriculation_number) != 1 ||
            fscanf(file, "%d\n", &student->num_courses) != 1) {
            printf("Failed to read personal information for student %d.\n", i + 1);
            free(student);
            continue;
        }

        // Remove trailing newlines
        student->personal.full_name[strcspn(student->personal.full_name, "\n")] = '\0';
        student->personal.department[strcspn(student->personal.department, "\n")] = '\0';
        student->personal.faculty[strcspn(student->personal.faculty, "\n")] = '\0';

        // Read course info
        for (int j = 0; j < student->num_courses; j++) {
            struct CourseInfo *course = &student->courses[j];
            if (fgets(course->course_name, sizeof(course->course_name), file) == NULL ||
                fgets(course->course_code, sizeof(course->course_code), file) == NULL ||
                fscanf(file, "%d\n%d\n%d\n%d\n%c\n",
                       &course->CA1,
                       &course->CA2,
                       &course->exam,
                       &course->total_marks,
                       &course->grade) != 5) {
                printf("Failed to read course information for student %d, course %d.\n", i + 1, j + 1);
                break;
            }

            // Remove trailing newlines
            course->course_name[strcspn(course->course_name, "\n")] = '\0';
            course->course_code[strcspn(course->course_code, "\n")] = '\0';
        }

        students[*count] = student;
        (*count)++;
    }

    fclose(file);
    printf("Records loaded successfully from 'student_records.txt'.\n");
    return 1;
}


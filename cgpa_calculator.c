/*#include <stdio.h>
#include "cgpa_calculator.h"


// Function to determine letter grade based on marks
char determineGrade(int marks) {
    if (marks >= 80 && marks <= 100) {
        return 'A';
    } else if (marks >= 70 && marks <= 79) {
        return 'B';
    } else if (marks >= 60 && marks <= 69) {
        return 'C';
    } else if (marks >= 50 && marks <= 59) {
        return 'D';
    } else {
        return 'F';
    }
}

// Function to convert letter grade to grade points
float gradePoints(char grade) {
    switch (grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return 0.0;
    }
}

// Function to calculate GPA
float calculateGPA(int num_courses, int credits[], char grades[]) {
    int total_credits = 0;
    float total_points = 0.0;

    for (int i = 0; i < num_courses; i++) {
        total_credits += credits[i];
        total_points += credits[i] * gradePoints(grades[i]);
    }

    return total_credits > 0 ? total_points / total_credits : 0;
}

// Function to calculate CGPA
float calculateCGPA(float previous_total_grade_points, int previous_total_credits, float current_total_grade_points, int current_credits) {
    float new_total_grade_points = previous_total_grade_points + current_total_grade_points;
    int new_total_credits = previous_total_credits + current_credits;

    return new_total_credits > 0 ? new_total_grade_points / new_total_credits : 0;
}

// Function to start GPA/CGPA calculation
void startGpaCgpaCalculation() {
    int choice;
    int num_courses;
    float previous_total_grade_points = 0;
    int previous_total_credits = 0;
    float current_gpa = 0;

    printf("Do you want to calculate your CGPA or GPA for the semester?\n");
    printf("Enter 1 for CGPA or 2 for GPA: ");
    scanf("%d", &choice);

    if (choice == 2) {
        printf("How many courses did you offer this semester? ");
        scanf("%d", &num_courses);

        char course_codes[num_courses][100];
        int credits[num_courses];
        int marks[num_courses];
        char grades[num_courses];

        // Input course details from user
        for (int i = 0; i < num_courses; i++) {
            printf("Course %d code: ", i + 1);
            scanf(" %[^\n]", course_codes[i]);

            printf("Course %d unit credit: ", i + 1);
            scanf("%d", &credits[i]);

            do {
                printf("Course %d score: ", i + 1);
                scanf("%d", &marks[i]);
            } while (marks[i] < 0 || marks[i] > 100); // Loop until valid input is provided

            // Determine letter grade for the course
            grades[i] = determineGrade(marks[i]);
        }

        // Calculate GPA
        current_gpa = calculateGPA(num_courses, credits, grades);

        // Display results
        printf("\nNumber of courses offered: %d\n", num_courses);
        printf("Course Code\tUnit Credit\tGrade\n");
        for (int i = 0; i < num_courses; i++) {
            printf("%s\t\t%d\t\t%c\n", course_codes[i], credits[i], grades[i]);
        }
        printf("GPA: %.2f\n", current_gpa);

    } else if (choice == 1) {
        int more_semesters;

        // Loop to input previous semester GPAs
        do {
            float semester_gpa;
            int semester_credits;

            printf("Enter previous semester GPA: ");
            scanf("%f", &semester_gpa);

            printf("Enter total credits for that semester: ");
            scanf("%d", &semester_credits);

            // Calculate total grade points for the previous semester
            float previous_grade_points = semester_gpa * semester_credits;
            previous_total_grade_points += previous_grade_points;
            previous_total_credits += semester_credits;

            printf("Is there another previous semester GPA to add? (1 for yes, 0 for no): ");
            scanf("%d", &more_semesters);
        } while (more_semesters);

        printf("How many courses did you offer this semester? ");
        scanf("%d", &num_courses);

        char course_codes[num_courses][100];
        int credits[num_courses];
        int marks[num_courses];
        char grades[num_courses];

        // Input course details from user for current semester
        for (int i = 0; i < num_courses; i++) {
            printf("Course %d code: ", i + 1);
            scanf(" %[^\n]", course_codes[i]);

            printf("Course %d unit credit: ", i + 1);
            scanf("%d", &credits[i]);

            do {
                printf("Course %d score: ", i + 1);
                scanf("%d", &marks[i]);
            } while (marks[i] < 0 || marks[i] > 100); // Loop until valid input is provided

            // Determine letter grade for the course
            grades[i] = determineGrade(marks[i]);
        }

        // Calculate GPA for current semester
        current_gpa = calculateGPA(num_courses, credits, grades);

        // Calculate total grade points for current semester
        float current_total_grade_points = 0.0;
        int current_total_credits = 0;
        for (int i = 0; i < num_courses; i++) {
            current_total_grade_points += credits[i] * gradePoints(grades[i]);
            current_total_credits += credits[i];
        }

        // Calculate overall CGPA
        float cgpa = calculateCGPA(previous_total_grade_points, previous_total_credits, current_total_grade_points, current_total_credits);

        // Display results
        printf("\nNumber of courses offered this semester: %d\n", num_courses);
        printf("Course Code\tUnit Credit\tGrade\n");
        for (int i = 0; i < num_courses; i++) {
            printf("%s\t\t%d\t\t%c\n", course_codes[i], credits[i], grades[i]);
        }
        printf("GPA for this semester: %.2f\n", current_gpa);
        printf("CGPA: %.2f\n", cgpa);
    } else {
        printf("Invalid choice.\n");
    }
}*/
#include <stdio.h>
#include <stdlib.h>
#include "cgpa_calculator.h"
#include "student_record.h" // Include if you need to access student records

// Function to calculate CGPA or GPA
void calculateCGPA() {
    int choice;
    float previous_total_grade_points = 0.0;
    int previous_total_credits = 0;
    float current_gpa = 0.0;

    printf("Do you want to calculate your CGPA or GPA for the semester?\n");
    printf("Enter 1 for CGPA or 2 for GPA: ");
    scanf("%d", &choice);
    clearInputBuffer(); // Ensure the input buffer is clear

    if (choice == 2) {
        int num_courses;
        printf("How many courses did you offer this semester? ");
        scanf("%d", &num_courses);
        clearInputBuffer();

        struct CourseInfo courses[num_courses];
        for (int i = 0; i < num_courses; i++) {
            printf("Course %d name: ", i + 1);
            fgets(courses[i].course_name, sizeof(courses[i].course_name), stdin);
            courses[i].course_name[strcspn(courses[i].course_name, "\n")] = '\0';

            printf("Course %d unit credit: ", i + 1);
            scanf("%d", &courses[i].CA1); // Assuming CA1 represents credits
            clearInputBuffer();

            printf("Course %d score: ", i + 1);
            scanf("%d", &courses[i].CA2); // Assuming CA2 represents marks
            clearInputBuffer();

            courses[i].total_marks = courses[i].CA1 + courses[i].CA2; // Example calculation
            courses[i].grade = determineGrade(courses[i].total_marks);
        }

        // Calculate GPA
        // Example logic: GPA = average of grade points
        float total_grade_points = 0.0;
        for (int i = 0; i < num_courses; i++) {
            float gp = 0.0;
            switch (courses[i].grade) {
                case 'A': gp = 4.0; break;
                case 'B': gp = 3.0; break;
                case 'C': gp = 2.0; break;
                case 'D': gp = 1.0; break;
                default: gp = 0.0; break;
            }
            total_grade_points += gp;
        }
        current_gpa = total_grade_points / num_courses;

        printf("GPA for this semester: %.2f\n", current_gpa);
    }
    else if (choice == 1) {
        // Similar logic for CGPA calculation
        // This would typically involve multiple semesters
        printf("CGPA calculation is under development.\n");
    }
    else {
        printf("Invalid choice.\n");
    }
}

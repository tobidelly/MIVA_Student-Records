#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H

#define MAX_COURSES 10

// Structure for storing Personal Information
struct PersonalInfo {
    char full_name[100];
    char department[50];
    char faculty[50];
    int matriculation_number;
};

// Structure for storing Course Information
struct CourseInfo {
    char course_name[100];
    char course_code[20];
    int CA1;     // Continuous Assessment 1 marks (optional)
    int CA2;     // Continuous Assessment 2 marks (optional)
    int exam;    // Exam marks (optional)
    int total_marks;
    char grade;  // Calculated or user-entered grade
};

// Structure to store a Student Record (Personal Info + Courses)
struct StudentRecord {
    struct PersonalInfo personal;
    struct CourseInfo courses[MAX_COURSES];
    int num_courses;
};

// Function declarations
void inputStudentRecord(struct StudentRecord *student);
void displayStudentRecord(const struct StudentRecord *student);
void displayStudentRecords(struct StudentRecord *students[], int count);
void searchStudent(struct StudentRecord *students[], int count);
void calculateAverageMarks(struct StudentRecord *students[], int count);
void sortStudentRecords(struct StudentRecord *students[], int count, int ascending);
void addStudentRecord(struct StudentRecord *students[], int *count);
void removeStudentRecord(struct StudentRecord *students[], int *count, int matriculation_number);
void modifyStudentRecord(struct StudentRecord *students[], int count, int matriculation_number);

#endif // STUDENT_RECORD_H


# Student Records Management System

This project is a **Student Records Management System** written in C, which allows you to add, manage, and display student records. It includes various functionalities such as adding new student records, modifying existing ones, calculating averages, sorting records, and removing students from the system. The program stores information about each student's courses, including scores for coursework, exams, and final grades.

## Features

- **Add Student Record**: Allows input of student's personal information and course scores.
- **Display Records**: Shows all student records or individual details based on search.
- **Modify Record**: Updates an existing student record using the matriculation number.
- **Remove Record**: Deletes a student record by matriculation number.
- **Search Record**: Search for a student record by full name or matriculation number.
- **Calculate Average Marks**: Computes average marks across all students and courses.
- **Sort Records**: Sorts student records based on total or average marks.

## Structure

The project consists of the following key components:

- **`student_record.c`**: Implements all the main functionalities.
- **`student_record.h`**: Header file defining structures and function prototypes.
- **`main.c`**: Contains the main function to interact with users through a menu-based interface.

### Student Record Structure

Each student record contains:
- **Personal Information**:
  - Full Name
  - Department
  - Faculty
  - Matriculation Number
- **Course Information**:
  - Course Name
  - Course Code
  - CA1 Score, CA2 Score, Exam Score
  - Total Marks and Final Grade

## Usage

1. **Clone the Repository**:
    ```bash
    git clone <repository-url>
    ```
   
2. **Compile the Program**:
    Compile with a C compiler such as `gcc`:
    ```bash
    gcc main.c student_record.c -o student_records
    ```

3. **Run the Program**:
    ```bash
    ./student_records
    ```

### Menu Options

The program provides a command-line interface with the following options:

1. **Add Student Record**: Input new student data, including scores.
2. **Display All Records**: Show information of all students.
3. **Display Single Record**: View a student's record by searching their name or matriculation number.
4. **Modify Record**: Edit a student’s details by matriculation number.
5. **Remove Student Record**: Delete a student’s record from the system.
6. **Calculate Average Marks**: Calculate average marks across all students.
7. **Sort Records**: Sort students by their total or average marks in ascending/descending order.
8. **Exit Program**: Close the application.

### Grading

Grades are determined based on total marks, as follows:
- **A**: 70–100
- **B**: 60–69
- **C**: 50–59
- **D**: 40–49
- **F**: Below 40

### Validations
- Marks input for CA1, CA2, and Exam are validated within their respective ranges.
- Courses can be manually graded if score data is not available.
- Invalid or out-of-range data prompts re-entry.

## Example

Below is an example workflow for adding a new student and displaying their details.

```plaintext
Enter full name: John Doe
Enter department: Computer Science
Enter faculty: Science
Enter matriculation number: 12345
Enter the number of courses (1-5): 3

Course 1 Name: Data Structures
Course 1 Code: CSC201
Enter CA1 Score (0-40): 35
Enter CA2 Score (0-40): 30
Enter Exam Score (0-70): 60

... (Enter additional courses)

Student record added successfully.
```

## Functions and File Structure

- **student_record.h**: Defines all structures (`StudentRecord`, `CourseInfo`) and function prototypes.
- **student_record.c**: Contains the core logic:
  - `inputStudentRecord()`: Collects student data.
  - `displayStudentRecord()`: Prints a single student's data.
  - `calculateAverageMarks()`: Computes average marks across records.
  - `sortStudentRecords()`: Sorts students by total or average marks.
  - `modifyStudentRecord()`: Edits data for a specified student.
- **main.c**: Main entry point, handles user menu.

## Requirements

- **C Compiler**: The program requires a C compiler such as GCC.
- **Terminal/Command Line**: The program is CLI-based and does not have a GUI.

## Contributing

Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`feature/add-feature`).
3. Commit changes and push the branch.
4. Open a pull request.

## License

This project is open-source and available under the MIT License.

## Acknowledgements

Special thanks to contributors and C programming communities for their support and feedback.

---

Happy Coding!

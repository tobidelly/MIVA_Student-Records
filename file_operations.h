
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "student_record.h"

// Function declarations
void saveRecordsToFile(struct StudentRecord *students[], int count);
int loadRecordsFromFile(struct StudentRecord *students[], int *count);

#endif // FILE_OPERATIONS_H

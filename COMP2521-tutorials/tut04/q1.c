#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    int zid;
    char name[15];
};
typedef struct record *Record;

void RecordShow(Record r) {
    printf("%d | %s\n", r->zid, r->name);
}

Record func(struct record students[], int size, int (*cmp)(Record, Record)) {
    Record retStudent = &students[0];

    if (size == 1) return retStudent;

    for (int i = 1; i < size; i++) {              
        if (cmp(&students[i], retStudent) < 0) {     
            retStudent = &students[i];
        }
    }

    return retStudent; 
}

int cmpId(Record r1, Record r2) {
    return (r1->zid - r2->zid); 
}

int myCmpId(Record r1, Record r2) {
    return (r2->zid - r1->zid);
}

int myCmpName(Record r1, Record r2) {
    return strcmp(r2->name, r1->name);
}

int main(void) {
    struct record students[] = {
        { 15, "John" },
        { 32, "Mary" },
        { 12, "Rita" },
        { 11, "Jack" },
    }; 

    // Record myRec1 = func(students, 4, cmpId);
    // RecordShow(myRec1);

    // Record myRec2 = func(students, 4, myCmpId);
    // RecordShow(myRec2);

    Record myRec3 = func(students, 4, myCmpName);
    RecordShow(myRec3);
}
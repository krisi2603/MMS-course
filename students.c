#include <stdio.h>
#include <stdint.h>

//Homework 3 
//not working so well

uint64_t setAttendance(uint64_t students, unsigned number) {
    return students | (1 << number);
}

uint64_t clearAttendance(uint64_t students, unsigned number) {
    return students & ~(1 << number);
}

int checkAttendance(uint64_t students, unsigned number){
    return (students & (1 << number)) ? 1 : 0;
}

uint64_t changeAttendance(uint64_t students, unsigned number) {
    return students ^ (1 << number);
}

void printStudents(uint64_t students) {
    for(int i = sizeof(uint64_t)*8 - 1 ; i >= 0; i--) {
        printf("%d",checkAttendance(students,i));
    }
    printf("\n");

}

void printNumsOfStudentsInClass(uint64_t students) {
    for (int i = 0; i<sizeof(uint64_t)*8 ;i++) {
        if(checkAttendance(students, i)) {
            printf("%d ", i);
        }
    }
    putchar('\n');
}

void printNumsOfStudentsMissing(uint64_t students) {
    for (int i = 0; i< sizeof(uint64_t)*8; i++){
        if(!checkAttendance(students, i)) {
            printf("%d ", i);
        }
    }
    putchar('\n');
}

int main() {

    uint64_t students = 0x8B5;
    printStudents(students); 
    //when is sizeof(uint64_t)*8 - it repeats the same 32 bits again

    unsigned numStudent;
    int option, doTask = 1;

    while(doTask) {
        printf("Option1: Set attendance\n");
        printf("Option2: Clear attendance\n");
        printf("Option3: Attendance info\n");
        printf("Option4: Change attendance\n");
        printf("Option5: End\n");
        printf("\n");

        printf("Choose an option: ");
        scanf("%d", &option);
        printf("\n");

        switch(option) {
            case 1:
                printf("Enter number of student: ");
                do {
                    scanf("%u", &numStudent);
                }
                while(numStudent > 61 || numStudent < 0);
                students = setAttendance(students, numStudent);
                printf("The student %u attendance has been marked\n", numStudent);
                printf("\n");
                printf("Students: ");
                printStudents(students);  
                break;
            case 2:
                printf("Enter number of student: ");
                do {
                    scanf("%u", &numStudent);
                }
                while(numStudent > 61 || numStudent < 0);
                students = clearAttendance(students, numStudent);
                printf("The student %u attendance has been cleared\n", numStudent);
                printf("\n");
                printf("Students: ");
                printStudents(students); 
                break;
            case 3:
                printf("Students: ");
                printStudents(students); 
                printf("\n");
                printf("The numbers of students in class: ");
                printNumsOfStudentsInClass(students);
                printf("\n");
                printf("The numbers of students missing: ");
                printNumsOfStudentsMissing(students);
                printf("\n");
                break;
            case 4:
                printf("Enter number of student: ");
                do {
                    scanf("%u", &numStudent);
                }
                while(numStudent > 61 || numStudent < 0);
                students = changeAttendance(students,numStudent);
                printf("The student %u attendance has been changed\n", numStudent);
                printf("\n");
                printf("Students: ");
                printStudents(students); 
                printf("\n");
                break;
            case 5:
                printf("End of work\n");
                doTask = 0;
                break;
            default: 
                printf("You have entered invalid option! Please enter new option\n");
                printf("\n");
        }
    }

    return 0;
}


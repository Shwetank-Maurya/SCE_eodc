#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[100];
    int roll_number;
    float marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student *students = (struct student *)malloc(n * sizeof(struct student));
    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter the details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", (students + i)->name);
        printf("Roll Number: ");
        scanf("%d", &(students + i)->roll_number);
        printf("Marks: ");
        scanf("%f", &(students + i)->marks);
    }

    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: %s\n", (students + i)->name);
        printf("Roll Number: %d\n", (students + i)->roll_number);
        printf("Marks: %.2f\n", (students + i)->marks);
    }

    free(students);
    return 0;
}

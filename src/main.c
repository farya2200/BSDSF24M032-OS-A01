#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main()
{
    printf("--- Testing String Functions ---\n");

    // Test mystrlen
    char str1[] = "Hello";
    printf("mystrlen(\"%s\") = %d\n", str1, mystrlen(str1));

    // Test mystrcpy
    char dest1[100];
    mystrcpy(dest1, "Hello World");
    printf("mystrcpy = %s\n", dest1);

    // Test mystrncpy
    char dest2[100];
    mystrncpy(dest2, "Operating System", 10);
    printf("mystrncpy = %s\n", dest2);

    // Test mystrcat
    char dest3[100] = "Hello ";
    mystrcat(dest3, "World");
    printf("mystrcat = %s\n", dest3);


    printf("\n--- Testing File Functions ---\n");

    // Create a test file
    FILE* file = fopen("test.txt", "w");

    if (file == NULL)
    {
        printf("Error creating test file.\n");
        return 1;
    }

    fprintf(file, "Hello world\n");
    fprintf(file, "Operating System\n");
    fprintf(file, "Git and Makefile\n");

    fclose(file);


    // Test wordCount
    file = fopen("test.txt", "r");

    if (file == NULL)
    {
        printf("Error opening test file.\n");
        return 1;
    }

    int lines = 0;
    int words = 0;
    int chars = 0;

    if (wordCount(file, &lines, &words, &chars) == 0)
    {
        printf("Lines: %d\n", lines);
        printf("Words: %d\n", words);
        printf("Characters: %d\n", chars);
    }

    fclose(file);


    // Test mygrep
    file = fopen("test.txt", "r");

    if (file == NULL)
    {
        printf("Error opening test file.\n");
        return 1;
    }

    char** matches = NULL;

    int count = mygrep(file, "Operating", &matches);

    if (count >= 0)
    {
        printf("mygrep found %d matching line(s):\n", count);

        for (int i = 0; i < count; i++)
        {
            printf("%s", matches[i]);
            free(matches[i]);
        }

        free(matches);
    }

    fclose(file);

    return 0;
}

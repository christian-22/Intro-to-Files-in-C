#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int RemoveEndingWhiteSpace(char TheString[])
{
        TheString[strcspn(TheString, "\r\n")] = 0;
        return strlen(TheString);
}

int InputInteger(FILE* in_file)
{
    int num;

    fscanf(in_file, "%d\n", &num);

    return num;
}

float InputFloat(FILE* in_file)
{
    float Towing;
    fscanf(in_file, "%f\n", &Towing);

    return Towing;
}

void InputString(FILE* in_file, char InString[])
{
    fgets(InString, 50, in_file);
    RemoveEndingWhiteSpace(InString);

}
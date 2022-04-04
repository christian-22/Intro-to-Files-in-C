#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "util.h"


// BOAT INPUT
void InputBoat(FILE* in_file, char Make[], char Model[], int* Year, char VIN[], char Motor[])
{
    InputString(in_file, Make);
    InputString(in_file, Model);
    *Year = InputInteger(in_file);
    InputString(in_file, VIN);
    InputString(in_file, Motor);    
}

// CAR INPUT
void InputCar(FILE* in_file, char Make[], char Model[], int* Year, char VIN[], int* Doors, char Trunk[])
{
    
    InputString(in_file, Make);
    InputString(in_file, Model);
    *Year = InputInteger(in_file);
    InputString(in_file, VIN);
    *Doors = InputInteger(in_file);
    InputString(in_file, Trunk);
    
}

// TRUCK INPUT
void InputTruck(FILE* in_file, char Make[], char Model[], int* Year, char VIN[], int* Doors, float* Towing)
{
    
    InputString(in_file, Make);
    InputString(in_file, Model);
    *Year = InputInteger(in_file);
    InputString(in_file, VIN);
    *Doors = InputInteger(in_file);
    *Towing = InputFloat(in_file);
    
}

// PRINT BOAT INFO
void OutputBoat(FILE* out_file, char Make[], char Model[], int Year, char VIN[], char Motor[])
{
    fprintf(out_file, "%d %s %s\nVIN: %s\nMotor: %s\n\n", 
                        Year, Make, Model, VIN, Motor);    
}

// PRINT CAR INFO
void OutputCar(FILE* out_file, char Make[], char Model[], int Year, char VIN[], int Doors, char Trunk[])
{
    fprintf(out_file, "%d %s %s\nVIN: %s\nDoors: %d\nRear Configuration: %s\n\n", 
                        Year, Make, Model, VIN, Doors, Trunk);
}

// PRINT TRUCK INFO
void OutputTruck(FILE* out_file, char Make[], char Model[], int Year, char VIN[], int Doors, float Towing)
{
    fprintf(out_file, "%d %s %s\nVIN: %s\nDoors: %d\nMax Towing Capacity: %3f\n\n", 
                        Year, Make, Model, VIN, Doors, Towing);
}

int main()
{
    // vehicle enums to use in the switch statement
    enum Vehicle {car, truck, boat};
    enum Vehicle vehicleType;

    // array for each line read in the file
    char line[50];

    // pointer to read from TestInput.txt
    FILE *in_file;
    in_file = fopen("./TestInput.txt", "r");

    // pointer to write to out.txt
    FILE *out_file;
    out_file = fopen("./out.txt", "w");

    // check if input file exists, return error if not
    if (in_file == NULL)
    {
        printf("ERROR: Input file not found!");
        exit(1);
    }

    // read data from input file, line by line, until EOF
    while (fgets(line, 50, in_file) != NULL)
    {
        // remove /n and /r
        RemoveEndingWhiteSpace(line);

        // variables for vehicles
        char Make[50];
        char Model[50];
        char VIN[50];
        char Motor[50];
        char Trunk[50];

        // if line = "car" then change enum value for switch statement
        if (strcmp(line, "car") == 0)
        {
            vehicleType = car;
        }

        // if line = "truck" then change enum value for switch statement
        else if (strcmp(line, "truck") == 0)
        {
            vehicleType = truck;
        }
        
        // if line = "boat" then change enum value for switch statement
        else if (strcmp(line, "boat") == 0)
        {
            vehicleType = boat;
        }

        // switch statement with enums to choose data to read/store/print
        switch (vehicleType)
        {
            // car data
            case (car):
            {
                // variables for vehicle info
                int Year;
                int Doors;
                InputCar(in_file, &Make[50], &Model[50], &Year, &VIN[50], &Doors, &Trunk[50]);
                OutputCar(out_file, &Make[50], &Model[50], Year, &VIN[50], Doors, &Trunk[50]);
                break;
            }
            
            // truck data
            case (truck):
            {
                // variables for vehicle info
                int Year;
                int Doors;
                float Towing;
                InputTruck(in_file, &Make[50], &Model[50], &Year, &VIN[50], &Doors, &Towing);
                OutputTruck(out_file, &Make[50], &Model[50], Year, &VIN[50], Doors, Towing);
                break;
            }

            // boat data
            case (boat):
            {
                // variables for vehicle info
                int Year;
                InputBoat(in_file, &Make[50], &Model[50], &Year, &VIN[50], &Motor[50]);
                OutputBoat(out_file, &Make[50], &Model[50], Year, &VIN[50], &Motor[50]);
                break;
            }

            // for testing to see if a file is being read
            default:
            {
                printf("Invalid vehicle type!\n");
            }
        }
    }

    // closing files when process is completed
    fclose(in_file);
    fclose(out_file);
    return 0;
}


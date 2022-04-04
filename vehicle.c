#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // vehicle enums to use in the switch statement
    enum Vehicle {car, truck, boat};
    enum Vehicle vehicleType;

    // array for each line read in the file
    char line[50];

    // string arrays for vehicle info
    char carData[6][50];
    char boatData[5][50];
    char truckData[6][50];

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
        line[strcspn(line, "\r\n")] = 0;
        
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
                fgets(carData[0], 50, in_file);
                fgets(carData[1], 50, in_file);
                fgets(carData[2], 50, in_file);
                fgets(carData[3], 50, in_file);
                fgets(carData[4], 50, in_file);
                fgets(carData[5], 50, in_file);
                
                // remove \n and \r
                carData[0][strcspn(carData[0], "\r\n")] = 0;
                carData[1][strcspn(carData[1], "\r\n")] = 0;
                carData[2][strcspn(carData[2], "\r\n")] = 0;

                fprintf(out_file, "%s %s %s\nVIN: %sDoors: %sRear Configuration: %s\n", 
                        carData[2], carData[0], carData[1], carData[3], carData[4], carData[5]);
                break;
            }
            
            // truck data
            case (truck):
            {
                fgets(truckData[0], 50, in_file);
                fgets(truckData[1], 50, in_file);
                fgets(truckData[2], 50, in_file);
                fgets(truckData[3], 50, in_file);
                fgets(truckData[4], 50, in_file);
                fgets(truckData[5], 50, in_file);
                
                // remove \n and \r
                truckData[0][strcspn(truckData[0], "\r\n")] = 0;
                truckData[1][strcspn(truckData[1], "\r\n")] = 0;
                truckData[2][strcspn(truckData[2], "\r\n")] = 0;

                fprintf(out_file, "%s %s %s\nVIN: %sDoors: %sMax Towing Capacity: %s\n", 
                        truckData[2], truckData[0], truckData[1], truckData[3], truckData[4], truckData[5]);
                break;
            }

            // boat data
            case (boat):
            {
                fgets(boatData[0], 50, in_file);
                fgets(boatData[1], 50, in_file);
                fgets(boatData[2], 50, in_file);
                fgets(boatData[3], 50, in_file);
                fgets(boatData[4], 50, in_file);

                // remove \n and \r
                boatData[0][strcspn(boatData[0], "\r\n")] = 0;
                boatData[1][strcspn(boatData[1], "\r\n")] = 0;
                boatData[2][strcspn(boatData[2], "\r\n")] = 0;

                fprintf(out_file, "%s %s %s\nVIN: %sMotor: %s\n", 
                        boatData[2], boatData[0], boatData[1], boatData[3], boatData[4]);
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
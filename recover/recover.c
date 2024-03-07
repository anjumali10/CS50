#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int JPEG_SIZE = 512;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check that it should accept exactly one command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open the forensic image
    FILE *file = fopen(argv[1], "r");

    //Check that the file open successfully otherwise return error message
    if (file == NULL)
    {
        printf("Can't open file\n");
        return 1;
    }

    BYTE buffer[JPEG_SIZE];
    int image_count = 0;
    char image_name[8];
    FILE *output_file = NULL;

    while (fread(&buffer, 1, JPEG_SIZE, file) == JPEG_SIZE)
    {
        // Check the header of JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Check if image is first then make its name, open new file of that name and write image in that file
            if (image_count == 0)
            {
                sprintf(image_name, "%03i.jpg", image_count);
                output_file = fopen(image_name, "w");
                fwrite(buffer, 1, JPEG_SIZE, output_file);
                image_count += 1;
            }
            else
            {
                // Check if its not first image than close previous file and open another file to write
                fclose(output_file);
                sprintf(image_name, "%03i.jpg", image_count);
                output_file = fopen(image_name, "w");
                fwrite(buffer, 1, JPEG_SIZE, output_file);
                image_count += 1;
            }
        }
        else
        {
            if (image_count > 0)
            {
                fwrite(buffer, 1, JPEG_SIZE, output_file);
            }
        }
    }
    fclose(file);
    fclose(output_file);
}

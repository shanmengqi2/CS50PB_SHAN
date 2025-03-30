#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

string generateID(int new);

// Number of bytes in FAT BLOCK
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("usage ./recover fileName\n");
        return 1;
    }

    // Open the memory card
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t *block = malloc(BLOCK_SIZE);
    // While there's still data left to read from the memory card

    int idNo = 0;
    FILE *output = NULL;
    string newID = NULL;
    while (fread(block, BLOCK_SIZE, 1, input))
    {

        if (block[0] == 255 && block[1] == 216 && block[2] == 255 &&
            (block[3] > 223 && block[3] < 240))
        {

            // close last file
            if (output != NULL)
            {
                fclose(output);
            }

            newID = generateID(idNo);

            output = fopen(newID, "a");
            free(newID);

            idNo++;

            if (output == NULL)
            {
                printf("Could not Create Photo File.\n");
                return 1;
            }
            fwrite(block, BLOCK_SIZE, 1, output);
        }
        else if (output != NULL)
        {

            fwrite(block, BLOCK_SIZE, 1, output);
        }
    }
    fclose(input);
    if (output != NULL)
    {
        fclose(output);
    }

    free(block);
}

string generateID(int new)
{
    string id = malloc(8);
    if (new < 10)
    {
        id[0] = '0';
        id[1] = '0';
        id[2] = new + '0';
    }
    else if (new < 100)
    {
        id[0] = '0';
        id[1] = new / 10 + '0';
        id[2] = new % 10 + '0';
    }
    else
    {
        id[2] = new % 10 + '0';
        id[1] = new / 10 % 10 + '0';
        id[0] = new / 10 / 10 + '0';
    }

    id[3] = '.';
    id[4] = 'j';
    id[5] = 'p';
    id[6] = 'g';
    id[7] = '\0';
    printf("id: %s", id);
    return id;
}

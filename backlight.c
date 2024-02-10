#include <stdio.h>
#include <stdlib.h>

// The purpose of this program is to set the backlight on my laptop which refuses to work with xbacklight.

// Constants, should be changed to suit your system.
const int maxBrightness = 512;
const int minBrightness = 0;
const char * fileLocation = "/sys/class/backlight/intel_backlight/brightness";

// Prototype
void usage(char * argv[], int max, int min);

int main(int argc, char * argv[])
{
    if ((argc < 2) || (argc > 2) || (atoi(argv[1]) > maxBrightness) || (atoi(argv[1]) < minBrightness))
    {
        usage(argv, maxBrightness, minBrightness);
        return 1;
    }

    FILE * fp;
    fp = fopen(fileLocation, "w");

    if (!fp)
    {
        printf("Backlight control file not found. Run with sudo, run as root, or modify file path in source.\n");
        return 1;
    }

    fprintf(fp, argv[1]);
    return 0;
}

void usage(char* argv[], int max, int min)
{
    printf("Usage: # %s %d-%d\n", argv[0], min, max);
}

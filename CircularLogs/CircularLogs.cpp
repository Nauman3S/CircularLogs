#include "CircularLogs.h"

int logCharPointer = 0;

void writeToFile(char *data) // a function to handle logs to file writing operations
{
    FILE *filePtr;
    char filename[30];
    sprintf(filename, "logs/log_%d.txt", clock()); //use clocktime as a unique file name

    filePtr = fopen(filename, "w");
    if (filePtr == NULL)
    {
        printf("Error while opening the file.");
    }
    else
    {
        fprintf(filePtr, "%s", data);
        fclose(filePtr);
    }
}
int main()
{

    char LogEntriesStr[LOG_ENTRY_STR_SIZE];

    initscr();
    noecho();
    // nodelay(stdscr, TRUE);
    timeout(1);
    printw("Circular Logs Program \n\n");
    int ch;
    for (;;)
    {

        ch = getch();
        char logEntiresBuffer[LOG_ENTRIES_BUFFER_SIZE];
        if (ch == 'S') //log file save mechanism
        {
            if (logCharPointer < 100)
            { //if log entries are less than 100 chars, save from index 0 uptil the last entered char
                memcpy(logEntiresBuffer, &LogEntriesStr[0], logCharPointer);
                writeToFile(logEntiresBuffer); //save 100 char length buffer to the file
            }
            else
            {

                memcpy(logEntiresBuffer, &LogEntriesStr[logCharPointer - 100], 100); //copy the last 100 chars to a buffer
                writeToFile(logEntiresBuffer);                                       //save 100 char length buffer to the file
            }
        }
        else if (ch != ERR)//checks if something is pressed before the timeout (1ms)
        {
            printw("%c", ch); //show on screen whatever key is being pressed.

            if (logCharPointer > LOG_ENTRY_STR_SIZE)
            {
                logCharPointer = 0; //start overwriting//reset the pointer
            }
            else
            {

                LogEntriesStr[logCharPointer] = ch;
                logCharPointer++;
            }
        }
        refresh();
    }
    refresh();
    endwin();

    return 0;
}
#include "CircularLogs.h"

int logCharPointer = 0;

void writeToFile(char *data)
{
    FILE *filePtr;
    char filename[30];
    sprintf(filename, "log_%d.txt", clock()); //use clocktime as a unique file name

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

    int EntrylogTime = 1000 * 1; //1 ms
    clock_t start_time = clock();

    initscr();
    noecho();
    // nodelay(stdscr, TRUE);
    timeout(1);
    printw("Circular Logs Program \n\n");
    int ch;
    for (;;)
    {
        // if (clock() >= start_time + EntrylogTime) //try to get char after every 1 ms(timeout logic)
        // {
            ch = getch();
            char logEntiresBuffer[LOG_ENTRIES_BUFFER_SIZE];
            if (ch == 'S') //log file save mechanism
            {
                if (logCharPointer < 100)
                { //if log entries are less than 100 chars, save from index 0 uptil the last entered char
                    memcpy(logEntiresBuffer, &LogEntriesStr[0], logCharPointer);
                    writeToFile(logEntiresBuffer);
                }
                else
                { //save last 100 chars to file

                    memcpy(logEntiresBuffer, &LogEntriesStr[logCharPointer - 100], 100);
                    writeToFile(logEntiresBuffer);
                }

                //break;
            }
            else if (ch != ERR)
            {
                printw("%c", ch); //show on screen whatever key is being pressed.

                if (logCharPointer > LOG_ENTRY_STR_SIZE)
                {
                    logCharPointer = 0; //start overwriting
                }
                else
                {

                    LogEntriesStr[logCharPointer] = ch;
                    logCharPointer++;
                }
            }
            refresh();

            // start_time = clock(); //reset timer

          //  refresh();
        }
    // }
    refresh();
    endwin();

    return 0;
}
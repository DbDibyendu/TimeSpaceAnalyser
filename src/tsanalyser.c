/**
 * @file tsanalyser.c
 * 
 * @defgroup   TIME_SPACE time space
 *
 * @brief      This file implements time space analysis library.
 *
 * @author     Yogesh
 * @bugs        No Known Bugs 
 */
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/resource.h>
#include <time.h>
#include "tsanalyser/tsanalyser.h"

//TODO: Write to Log function which writes the print output to log

/* Global variable to store the start time value*/
static clock_t begin;

/* Global variable to store the mode */
static int8_t mode; 

/**
 * @brief      Debug option for the library
 *
 * @param[in]  argc  The count of arguments
 * @param      argv  The arguments array
 */
void setDebugOption(int argc, char *argv[])
{
        int opt;

        while ((opt = getopt(argc, argv, "d")) != -1) {
                switch (opt) {
                        case 'd': 
                                mode = DEBUG_MODE; 
                                break;
                        default:
                            fprintf(stderr, "Usage: %s [-d] for turning on Debug mode.\n", argv[0]);
                }
        }        
}

/**
 * @brief      Starts keeping time.
 */
void startKeepingTime()
{

	begin = clock();
}


/**
 * @brief      Gets the time report by taking a difference between start and 
 *             end times
 *
 * @return     time in seconds.
 */
float getTimeTaken()
{

        clock_t end = clock();

        if (DEBUG_MODE == mode) {
                printf("Total Time Taken: %f secs \n", (float)(end - begin) / CLOCKS_PER_SEC);               
        }
        return (float)(end - begin) / CLOCKS_PER_SEC; 
}

/**
 * @brief      Returns the current RAM usage of the program
 *
 * @return     Current RAM usage in bytes.
 */
size_t getCurrentRSS( )
{
	long rss = 0L;
	FILE* fp = NULL;
	if ( (fp = fopen( "/proc/self/statm", "r" )) == NULL )
		return (size_t)0L;      /* Can't open? */
	if ( fscanf( fp, "%*s%ld", &rss ) != 1 )
	{
		fclose( fp );
		return (size_t)0L;      /* Can't read? */
	}
	fclose( fp );
	return (size_t)rss * (size_t)sysconf( _SC_PAGESIZE);
}

/**
 * @brief      Prints a Report on Max RAM used by program and Total CPU time 
 *             taken by the program
 *             
 *             The function uses getrusage() linux function
 *             http://man7.org/linux/man-pages/man2/getrusage.2.html
 */     
void getTSAnlaysis()
{
        struct rusage rusage;
        struct timeval  user, sys;

        getrusage( RUSAGE_SELF, &rusage );

        user = rusage.ru_utime;
        sys = rusage.ru_stime;

        double utime = (double)(user.tv_usec) / 1000000 + (double) (user.tv_sec);
        double stime = (double)(sys.tv_usec) / 1000000 + (double) (sys.tv_sec);

        if (DEBUG_MODE == mode) {
                printf("Peak RAM (memory) usage: %ld KB \n", (ssize_t) rusage.ru_maxrss);
                printf("Total CPU Time Used: %f secs \n", (float) utime + stime);               
        } 

}
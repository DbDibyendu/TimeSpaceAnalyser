/**
 * @file tsanalyser.h
 *         
 * @defgroup   TIME_SPACE time space
 *
 * @brief      This file implements time space analysis library.
 *
 * @author     Yogesh
 * @bugs        No known Bugs
 */

/*! Include Guard */
#ifndef __TSANALYSER_H__
#define __TSANALYSER_H__

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif

#define DEBUG_MODE 100

/**
 * @brief      Debug option for the library
 *
 * @param[in]  argc  The count of arguments
 * @param      argv  The arguments array
 */
void setDebugOption(int argc, char *argv[]);

/**
 * @brief      Starts keeping time.
 */
extern void startKeepingTime();

/**
 * @brief      Gets the time report by taking a difference between start and 
 *             end times
 *
 * @return     time in seconds.
 */
extern float getTimeTaken();

/**
 * @brief      Returns the current RAM usage of the program
 *
 * @return     Current RAM usage in bytes.
 */
extern size_t getCurrentRSS( );

/**
 * @brief      Prints a Report on Max RAM used by program and Total CPU time 
 *             taken by the program
 *             
 *             The function uses getrusage() linux function
 *             http://man7.org/linux/man-pages/man2/getrusage.2.html
 */     
extern void getTSAnlaysis();

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __TSANALYSER_H__ */  /* End of Include Guard */
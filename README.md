# Time Space Analyser Library

Library is made to analyse time and memory taken by a program.

## Example Program

```c
#include <tsanalyser/tsanalyser.h>

int main(int argc, char *argv[])
{
        setDebugOption(argc,argv);

        /* Example array*/
        double tp[2048];
        
        /* Start Keeping time before the loop 
         * Since we want to measure the time taken by the loop.
         */
        startKeepingTime();
        
        /* --------------------------------------------- */

        /* In a typical program this is where you will run the
         * Time Intensive code or the code which you may want to measure 
         * time.
         */
        
        for(int i=0; i<2048; i++) {
                tp[i] = i + 100000;
        }

        /* --------------------------------------------- */

        /* End Keeping time after the loop 
         * Since we want to measure the time taken by the loop.
         */
        getTimeTaken();

        /*Print total time taken and total RAM usage*/
        getTSAnlaysis();

        return 0;
}


```

## How to Compile the Example

To compile the example, run command
```
gcc -o example example.c -ltsanalyser
```

## API's 

| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `getTSAnalysis()` | Prints, Peak RAM used in KB and Total CPU time taken in secs by the program | [Read More](#gettsanalysis) |
| `startKeepingTime()` | Starts keeping time | [Read More](#startkeepingtime) |
| `getTimeTaken()` | Gets the Total time Taken from start time | [Read More](#gettimetaken) |
| `setDebugOption()` | Adds the debug option to the program, i.e library will print only if -d option is added while running the program | [Read More](#setdebugoption) |

---

### `getTSAnalysis()`

**Description** : Prints, Peak RAM used in KB and Total CPU time taken in secs by the program

**Return-type** : void

**Usage** : getTSAnalysis();

---

### `startKeepingTime()`

**Description** : Starts keeping time

**Return-type** : void

**Usage** : startKeepingTime();

---

### `getTimeTaken()`

**Description** : Gets the Total time Taken from start time

**Return-type** : float

**Returns** : (float) Time taken from start till now in seconds.

**Usage** : getTimeTaken();

---

### `setDebugOption()`

**Description** : Adds the debug option to the program, i.e library will print only if -d option is added while running the program.

**Parameter** :
- argc - The count of arguments passed from main()
- argv - The arguments array passed from main()


**Return-type** : void

**Usage** : startKeepingTime();

---

## Features Coming Soon

1. Ability to write to Log file

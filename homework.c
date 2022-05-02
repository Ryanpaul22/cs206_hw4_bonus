#include <stdio.h>
#include <stdlib.h>  // rand(), srand()
#include <time.h>    // time()
int main()
{
    unsigned seed = time(0);
    srand(seed);
    int currEvent = 0;
    double totalEvents = 100000000; // number of events you want to run (I suggest atleast 1,000,000, the program might take a few seconds to complete based on how big this number is)
    double eValTot = 0; // keeping track of the number of people who recieved their sandwich over the course of all events
    double eValAvg = 0; // average number of people who recieved their sandwich per event (approx expected number)
    while (currEvent <= totalEvents) { // while loop to run a certain number of events (the higher the number, the closer eValAvg is to the actual expected number)
        int N = 100; // number of customers
        int randN = 0; // random number holder
        int currCustomer = N; // starts with N customer at beginning of new event
        int eVal = N; // initial eVal value at start of new event
        for (int i = N; i > 1; i--) {
            randN = rand() % (currCustomer);
            randN++;
            if (randN == currCustomer) { // if the current customer randomly chooses their own sandwich
                i = 1;
            }
            else if (randN == 1) { // if the current customer randomly chooses the last person's sandwich, the current customer doesn't get their sandwich, the last person doesn't get their sandwich, and everyone else remaining in line does get their sandwich.
                i = 1;
                eVal = eVal - 2;
            }
            else { // if the current customer randomly chooses a sandwich that is not theirs
                currCustomer = randN; 
                eVal--;
            }
        }
        eValTot = eValTot + eVal; // adding the value of eVal from this event to the total eValTotal of all events
        currEvent++;
        if(currEvent == totalEvents) { // if all events are completed, print results
            eValAvg = eValTot / totalEvents;
            printf("eValAvg = %f\n", eValAvg);
        }
    }
    return 0;
}

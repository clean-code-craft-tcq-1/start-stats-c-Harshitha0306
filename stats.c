#include "stdio.h"
#include "decl.hpp"
#include "stats.h"
#include "math.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    
    int i;
    float minimum = numberset[0], maximum = numberset[0], sum=0;
    float avg =0;
    for(i=0;i<setlength;i++)
    {
        if(numberset[i] > maximum)
        {
            maximum=numberset[i];
        }
        if(numberset[i]<minimum)
        {
            minimum=numberset[i];
        }
        sum =sum+numberset[i];
        avg =sum/setlength;
    }
    s.average = avg;
    s.min = minimum;
    s.max = maximum;

    if(setlength==0)
    {
        s.average = NAN;
        s.max = NAN;
        s.min = NAN;
        
    }
   return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void emailAlerter(void)
{
    emailAlertCallCount = 1;
}

void ledAlerter(void)
{
    ledAlertCallCount = 1;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.max > maxThreshold)
    {
        alerters[0]();
        alerters[1]();
    }
}

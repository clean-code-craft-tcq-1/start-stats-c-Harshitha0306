#include "stdio.h"
#include "decl.hpp"
#include "stats.h"
#include "math.h"

/* Defining a function which calculates average, maximum and minimum of an array*/
struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
	int i;
    float f_max = numberset[0],f_min = numberset[0], f_sum = 0;
    float f_avg = 0;
	
	/* Return NAN incase if input is an empty array(resulting in undefined behaviour)*/
    if(setlength == 0 && numberset == NULL)
    {
        s.average = NAN;
        s.max = NAN;
        s.min = NAN;
        return s;
    }
   
    for(i = 0;i < setlength;i++)
    {
        if(numberset[i] > f_max)
        {
            f_max=numberset[i];
        }
        if(numberset[i] < f_min)
        {
            f_min=numberset[i];
        }
        f_sum =f_sum + numberset[i];
        f_avg =f_sum / setlength;
    }
    s.average = f_avg;
	s.max = f_max;
    s.min = f_min;
	
    return s;
}

/* Functions returning call-counters on function call*/
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
/*Functions raising alerts when max is greater than threshold*/
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.max > maxThreshold)
    {
        alerters[0]();
        alerters[1]();
    }
}

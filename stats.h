
struct Stats compute_statistics(const float* numberset, int setlength);

typedef void (*alerter_funcptr)(void);
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);
void emailAlerter(void);
void ledAlerter(void);

extern int emailAlertCallCount;
extern int ledAlertCallCount;

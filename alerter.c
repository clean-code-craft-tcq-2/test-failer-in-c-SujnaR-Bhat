#include <stdio.h>
#include <assert.h>

#define TEMPTHRESHOLD 200 
int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if ( celsius <= TEMPTHRESHOLD )
    {
        return 200 ;  // Return 200 for ok
    }
    else
    {
        return 500 ;  // Return 500 for not-ok
    }
    // stub always succeeds and returns 200
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(500.8);
    assert(alertFailureCount > 0);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double angleClock(int hour, int minutes) {
    hour %= 12;
    long double angleH = ((long double)hour / 12.0)*360.0+((long double)minutes / 60.0)*30.0;
    long double angleM = ((long double)minutes / 60.0)*360.0;
    return fabs(angleH - angleM);
}
int main() {
	printf("%lf", angleClock(3, 30));
}
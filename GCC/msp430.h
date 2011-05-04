#include <io.h>
#include <signal.h>

#ifndef TA0CTL_
#define TA0CTL TACTL
#define TA0CCR0 TACCR0
#define TA0CCR1 TACCR1
#define TA0CCTL0 TACCTL0
#define TA0CCTL1 TACCTL1
#endif

#ifndef P1SEL2_
#define P1SEL2_               0x0041    /* Port 1 Selection 2 */
sfrb(P1SEL2, P1SEL2_);
#endif

#ifndef P2SEL2_
#define P2SEL2_               0x0042    /* Port 2 Selection 2 */
sfrb(P2SEL2, P2SEL2_);
#endif

static inline uint16_t
__get_SR_register()
{
	return READ_SR;
}

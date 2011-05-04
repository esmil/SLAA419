//******************************************************************************
//******************************************************************************
#include  "CTS_Layer.h"

// Define User Configuration values //
//----------------------------------//
#define DELAY 5000 		// Timer delay timeout count - 5000*0.1msec = 500 msec

// Sensor settings
#define KEY_lvl     150                  // Defines the min count for a "key press"
                                        // Set to ~ half the max delta expected
// Global variables for sensing
unsigned int base_cnt;
unsigned int meas_cnt;
unsigned int delta_cnt;

char key_pressed, key_loc;
int cycles;

// Sleep Function
// Configures Timer A to run off ACLK, count in UP mode, places the CPU in LPM3 
// and enables the interrupt vector to jump to ISR upon timeout 
void sleep(unsigned int time)
{
    TA0CCR0 = time;
    TA0CTL = TASSEL_1+MC_1+TACLR;
    TA0CCTL0 &= ~CCIFG;
    TA0CCTL0 |= CCIE; 
    __bis_SR_register(LPM3_bits+GIE);
    __no_operation();
}

// Main Function
void main(void)
{ 
  volatile unsigned int i,j;

  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
  BCSCTL1 = CALBC1_1MHZ;                // Set DCO to 1, 8, 12 or 16MHz
  DCOCTL = CALDCO_1MHZ;
  BCSCTL1 |= DIVA_0;                    // ACLK/(0:1,1:2,2:4,3:8)
  BCSCTL3 |= LFXT1S_2;                  // LFXT1 = VLO
  
  P1OUT = 0x00;							// Clear Port 1 bits
  P1DIR |= BIT0;						// Set P1.0 as output pin

  P2SEL &= ~(BIT6 + BIT7);				// Configure XIN (P2.6) and XOUT (P2.7) to GPIO
  P2OUT = 0x00;							// Drive all Port 2 pins low
  P2DIR = 0xFF;							// Configure all Port 2 pins outputs  
  
  // Initialize Baseline measurement
  TI_CAPT_Raw(&middle_button,&base_cnt);
  
  // Main loop starts here
  while (1)
  {
  	  // Take raw delta measurement
      TI_CAPT_Raw(&middle_button,&meas_cnt);
      
      if(base_cnt < meas_cnt)
      // Handle baseline measurment for a base C decrease
      {                                 // beyond baseline, i.e. cap decreased
          base_cnt = (base_cnt+meas_cnt) >> 1; // Re-average baseline up quickly
          delta_cnt = 0;             // Zero out delta for position determination
      }
      else 
      {
          delta_cnt = base_cnt - meas_cnt;  // Calculate delta: c_change
      }

      if (delta_cnt > KEY_lvl)       // Determine if each key is pressed per a preset threshold
      {
        // turn on LED
        P1OUT |= BIT0;
      }
      else
      {
        // turn off LED
        base_cnt = base_cnt - 1;  // Adjust baseline down, should be slow to
        P1OUT &= ~BIT0;
      }
      
    // Put the MSP430 into LPM3 for a certain DELAY period
    sleep(DELAY);	      

  }
} // End Main

/******************************************************************************/
// Timer0_A0 Interrupt Service Routine: Disables the timer and exists LPM3  
/******************************************************************************/
#ifdef __GNUC__
interrupt(TIMERA0_VECTOR) ISR_Timer0_A0(void)
#else
#pragma vector=TIMER0_A0_VECTOR
__interrupt void ISR_Timer0_A0(void)
#endif
{
  TA0CTL &= ~(MC_1);
  TA0CCTL0 &= ~(CCIE);
  __bic_SR_register_on_exit(LPM3_bits+GIE);
}


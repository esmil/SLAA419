//******************************************************************************
// RO_PINOSC_TA0_WDTp example
// RO method capactiance measurement using PinOsc IO, TimerA0, and WDT+
//
//          Schematic Description: 
// 
//                         MSP430G2452
//                      +---------------+
//                      |
//             C--------|P2.4
//           C----------|P2.1
//               C------|P2.3
//             C--------|P2.2
//                      |
//           C----------|P2.5
//                      |
//           C----------|P2.0
// 
//        The WDT+ interval represents the measurement window.  The number of 
//        counts within the TA0R that have accumulated during the measurement
//        window represents the capacitance of the element. This is lowest 
//        power option with either LPM3 (ACLK WDTp source) or LPM0 (SMCLK WDTp 
//        source).
//
//******************************************************************************
#include "CTS_Layer.h"

// Uncomment to have this compiler directive run characterization functions only
// Comment to have this compiler directive run example application
//#define ELEMENT_CHARACTERIZATION_MODE	

#define DELAY 5000 		// Timer delay timeout count, 5000*0.1msec = 500 msec

#ifdef ELEMENT_CHARACTERIZATION_MODE
// Delta Counts returned from the API function for the sensor during characterization
unsigned int dCnt;
#endif

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
  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
  BCSCTL1 = CALBC1_1MHZ;                // Set DCO to 1, 8, 12 or 16MHz
  DCOCTL = CALDCO_1MHZ;
  BCSCTL1 |= DIVA_0;                    // ACLK/1 [ACLK/(0:1,1:2,2:4,3:8)]
  BCSCTL2 |= DIVS_3;                    // SMCLK/8 [SMCLK/(0:1,1:2,2:4,3:8)]
  BCSCTL3 |= LFXT1S_2;                  // LFXT1 = VLO Clock Source
  
  P1OUT = 0x00;							// Drive all Port 1 pins low
  P1DIR = 0xFF;							// Configure all Port 1 pins outputs
  
  P2SEL &= ~(BIT6 + BIT7);				// Configure XIN (P2.6) and XOUT (P2.7) to GPIO
  P2OUT = 0x00;							// Drive all Port 2 pins low
  P2DIR = 0xFF;							// Configure all Port 2 pins outputs

  // Initialize Baseline measurement
  TI_CAPT_Init_Baseline(&proximity_sensor);
  
  // Update baseline measurement (Average 5 measurements)
  TI_CAPT_Update_Baseline(&proximity_sensor,5);    

  // Main loop starts here
  while (1)
  {
  	
  	#ifdef ELEMENT_CHARACTERIZATION_MODE
	// Get the raw delta counts for element characterization 
	TI_CAPT_Custom(&proximity_sensor,&dCnt);
	__no_operation(); 					// Set breakpoint here	
	#endif
	
	
	#ifndef ELEMENT_CHARACTERIZATION_MODE
	// Check if the proximity sensor has been triggered. The API call
	// compares the value from the sensor against the threshold to determine
	// trigger condition
          
        if(TI_CAPT_Button(&proximity_sensor))   
        {    	
          // Do something
          P1OUT |= BIT0;                           // Turn on center LED   
        }
        else
        {
          // Do something else
          P1OUT &= ~BIT0;                           // Turn off center LED 
        }      
        
    // Put the MSP430 into LPM3 for a certain DELAY period
    sleep(DELAY);
    #endif

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

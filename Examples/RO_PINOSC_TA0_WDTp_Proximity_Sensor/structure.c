//******************************************************************************
//  RO_PINOSC_TA_WDTp example with the MSP430G2452
//  threshold and maxResponse values must be updated for electrode design,
//  system clock settings, selection of gate measurement source, and 
//  accumulation cycles
//******************************************************************************

#include "structure.h"

////////////////////////////////////////////////////////////////////////////////
// Define the compiler directive to configure the appropriate sensor structure
#define STRUCTURE_CONFIG_2
////////////////////////////////////////////////////////////////////////////////

/* *****************************************************************************
 * Structure Configuration 0
 * Watchdog Timer Source = ACLK/64, ACLK sourced by VLO
 * ****************************************************************************/
#ifdef STRUCTURE_CONFIG_0

//Proximity Element (P2.0)
const struct Element proximity_element = {

              .inputPxselRegister = (unsigned char *)&P2SEL,  
              .inputPxsel2Register = (unsigned char *)&P2SEL2,  
              .inputBits = BIT0,
              .maxResponse = 200,
              .threshold = 100			
};      

//*** Sensor   *******************************************************/
// This defines the grouping of sensors, the method to measure change in
// capacitance, and the function of the group

// Proximity Sensor
const struct Sensor proximity_sensor =
               { 
                  .halDefinition = RO_PINOSC_TA0_WDTp,
                  .numElements = 1,
                  .baseOffset = 0,
                  // Pointer to elements
                  .arrayPtr[0] = &proximity_element,  // point to first element
                  // Timer Information
                  .measGateSource= GATE_WDT_ACLK,     //  0->SMCLK, 1-> ACLK
                  .accumulationCycles= WDTp_GATE_64   //64 - Default                 
               };
               
#endif 


/* *****************************************************************************
 * Structure Configuration 1
 * Watchdog Timer Source = ACLK/512, ACLK sourced by VLO
 * ****************************************************************************/
#ifdef STRUCTURE_CONFIG_1

//Proximity Element (P2.0)
const struct Element proximity_element = {

              .inputPxselRegister = (unsigned char *)&P2SEL,  
              .inputPxsel2Register = (unsigned char *)&P2SEL2,  
              .inputBits = BIT0,
              .maxResponse = 200,
              .threshold = 100			       
};      

//*** Sensor   *******************************************************/
// This defines the grouping of sensors, the method to measure change in
// capacitance, and the function of the group

// Proximity Sensor
const struct Sensor proximity_sensor =
               { 
                  .halDefinition = RO_PINOSC_TA0_WDTp,
                  .numElements = 1,
                  .baseOffset = 0,
                  // Pointer to elements
                  .arrayPtr[0] = &proximity_element,  // point to first element
                  // Timer Information
                  .measGateSource= GATE_WDT_ACLK,     //  0->SMCLK, 1-> ACLK
                  .accumulationCycles= WDTp_GATE_512             //512             
               };
               
#endif     

/* *****************************************************************************
 * Structure Configuration 2
 * Watchdog Timer Source = SMCLK/8192, SMCLK sourced by DCO
 * ****************************************************************************/
#ifdef STRUCTURE_CONFIG_2

//Proximity Element (P2.0)
const struct Element proximity_element = {

              .inputPxselRegister = (unsigned char *)&P2SEL,  
              .inputPxsel2Register = (unsigned char *)&P2SEL2,  
              .inputBits = BIT0,
              .maxResponse = 200,
              .threshold = 100		       
};      

//*** Sensor   *******************************************************/
// This defines the grouping of sensors, the method to measure change in
// capacitance, and the function of the group

// Proximity Sensor 
const struct Sensor proximity_sensor =
               { 
                  .halDefinition = RO_PINOSC_TA0_WDTp,
                  .numElements = 1,
                  .baseOffset = 0,
                  // Pointer to elements
                  .arrayPtr[0] = &proximity_element,  // point to first element
                  // Timer Information
                  .measGateSource= GATE_WDT_SMCLK,     //  0->SMCLK, 1-> ACLK
                  //.accumulationCycles= WDTp_GATE_32768             //32768
                  .accumulationCycles= WDTp_GATE_8192               // 8192 - Default
                  //.accumulationCycles= WDTp_GATE_512             //512
//                  .accumulationCycles= WDTp_GATE_64             //64                  
               };
#endif                 

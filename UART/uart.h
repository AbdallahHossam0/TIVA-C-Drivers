/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <uart.h here>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: < 25 - 8 - 2021 >
 *
 * [DESCRIPTION]: <Header file for UART Driver for TIVA C EK-TM4C123GH6PM>
 * ---------------------------------------------------------------------------------------------------
 */


#ifndef UART_H_
#define UART_H_

#include "std_types.h"
#include "common_macros.h"
#include "uart_cfg.h"
#include "uart_priv.h"


/*-------- Function Prototypes -----------*/

/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:             vUART_init
 *
 * [DESCRIPTION]:               Function to initialize the UART
 *
 * [Args]:
 *
 * [IN]:                        <UART_Config* config> pointer to structure that has the configurations of the UART
 *
 * [OUT]:                       None
 *
 * [IN / OUT]:                  None
 *
 * [RETURNS]:                   Void
 * ---------------------------------------------------------------------------------------------------
 */
void vUART_init(UART_Config*);


/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:             vUART_sendByte
 *
 * [DESCRIPTION]:               Function to send a word in the UART
 *
 * [Args]:
 *
 * [IN]:                        <UART_Channel channel> to select the channel that will send the word
 *                              <uint8 data> contains the word to be sent
 *
 * [OUT]:                       None
 *
 * [IN / OUT]:                  None
 *
 * [RETURNS]:                   Void
 * ---------------------------------------------------------------------------------------------------
 */
void vUART_sendByte(UART_Channel, uint8);


/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:             u8UART_receiveByte
 *
 * [DESCRIPTION]:               Function to receive data from a specific UART channel using polling technique
 *
 * [Args]:
 *
 * [IN]:                        <UART_Channel channel> to select the channel you want to receive from
 *
 * [OUT]:                       None
 *
 * [IN / OUT]:                  None
 *
 * [RETURNS]:                   <uint8> contains the data received from the channel.
 * ---------------------------------------------------------------------------------------------------
 */
uint8 u8UART_receiveByte(UART_Channel);


/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:                 vUART_sendString
 *
 * [DESCRIPTION]:                   Function to send multiple words.
 *
 * [Args]:
 *
 * [IN]:                            <UART_Channel channel> to select the channel you want to use to send.
 *                                  <const uint8* string> the string you want to send.
 *
 * [OUT]:                           None.
 *
 * [IN / OUT]:                      None.
 *
 * [RETURNS]:                       Void.
 * ---------------------------------------------------------------------------------------------------
 */
void vUART_sendString(UART_Channel, const uint8*);


/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:         vUART_setCallBack
 *
 * [DESCRIPTION]:           Function to set the Call Back function address.
 *
 * [Args]:
 *
 * [IN]:                    <UART_Channel channel> contains the number of the UART Channel
 *                          <void (*a_ptr)(void) >pointer to function to be set to be called back in the interrupt handler
 *
 * [OUT]:                   None
 *
 * [IN / OUT]:              None
 *
 * [RETURNS]:               Void
 * ---------------------------------------------------------------------------------------------------
 */
void vUART_setCallBack(UART_Channel, void (*a_ptr)(void));

#endif /* UART_H_ */

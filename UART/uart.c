/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <uart.c here>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: < 25 - 8 - 2021 >
 *
 * [DESCRIPTION]: <Source file for UART Driver for TIVA C EK-TM4C123GH6PM>
 * ---------------------------------------------------------------------------------------------------
 */

#include "uart.h"

#ifndef NULL_PTR
#define NULL_PTR        (void*) 0
#endif


/****************** Pointers to function to be assigned to UART channel Interrupt Handler *******************/

#ifdef UART0
static void (*g_UART0_callBackPtr)(void) = NULL_PTR;
#endif
#ifdef UART1
static void (*g_UART1_callBackPtr)(void) = NULL_PTR;
#endif
#ifdef UART2
static void (*g_UART2_callBackPtr)(void) = NULL_PTR;
#endif
#ifdef UART3
static void (*g_UART3_callBackPtr)(void) = NULL_PTR;
#endif
#ifdef UART4
static void (*g_UART4_callBackPtr)(void) = NULL_PTR;
#endif
#ifdef UART5
static void (*g_UART5_callBackPtr)(void) = NULL_PTR;
#endif
#ifdef UART6
static void (*g_UART6_callBackPtr)(void) = NULL_PTR;
#endif
#ifdef UART7
static void (*g_UART7_callBackPtr)(void) = NULL_PTR;
#endif




/*---------------- Function Implementation -------------------*/

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
void vUART_setCallBack(UART_Channel channel, void (*a_ptr)(void)){
    switch(channel){
    case UART_0:
#ifdef UART0
        g_UART0_callBackPtr = a_ptr;

#endif

        break;
    case UART_1:
#ifdef UART1
        g_UART1_callBackPtr = a_ptr;


#endif
        break;
    case UART_2:
#ifdef UART2
        g_UART2_callBackPtr = a_ptr;


#endif
        break;
    case UART_3:
#ifdef UART3
        g_UART3_callBackPtr = a_ptr;


#endif

        break;
    case UART_4:
#ifdef UART4
        g_UART4_callBackPtr = a_ptr;


#endif
        break;
    case UART_5:
#ifdef UART5
        g_UART5_callBackPtr = a_ptr;


#endif
        break;
    case UART_6:
#ifdef UART6
        g_UART6_callBackPtr = a_ptr;


#endif

        break;
    case UART_7:
#ifdef UART7
        g_UART7_callBackPtr = a_ptr;


#endif
        break;
    default: break;
    }
}


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
void vUART_init(UART_Config* config){
    float32 number;
    uint8 IBRD;
    uint8 FBRD;

    number = SYS_CLK / (16.0 * (config -> baudRate));
    IBRD = (uint8)number;
    number = number - (uint8)number;
    number = number * 64.0 + 0.5;
    FBRD = (uint8) number;

    switch(config -> channel){
    case UART_0:

#ifdef UART0

        /* Enable the UART module using the RCGCUART register */
        SET_BIT(RCGCUART, 0);

        /* Disable UART0 */
        CLEAR_BIT(UART0_CTL, 0);

        /* set the baud rate */
        UART0_IBRD = IBRD;
        UART0_FBRD = FBRD;

        /* set the data word length */
        switch(config->wordLength){
        case _5_BIT:
            CLEAR_BIT(UART0_LCRH, 5);
            CLEAR_BIT(UART0_LCRH, 6);
            break;
        case _6_BIT:
            SET_BIT(UART0_LCRH, 5);
            CLEAR_BIT(UART0_LCRH, 6);
            break;
        case _7_BIT:
            CLEAR_BIT(UART0_LCRH, 5);
            SET_BIT(UART0_LCRH, 6);
            break;
        case _8_BIT:
            SET_BIT(UART0_LCRH, 5);
            SET_BIT(UART0_LCRH, 6);
            break;
        default: break;
        }
        /* Set the parity */
        switch(config -> parity){
        case NO_PARITY:
            CLEAR_BIT(UART0_LCRH, 1);
            break;
        case EVEN_PARITY:
            SET_BIT(UART0_LCRH, 1);
            SET_BIT(UART0_LCRH, 2);
            break;
        case ODD_PARITY:
            SET_BIT(UART0_LCRH, 1);
            CLEAR_BIT(UART0_LCRH, 2);
            break;
        default: break;
        }

        /* set 1 or 2 stop bits */
        switch(config -> stopBit){
        case _1_STOP_BIT:
            CLEAR_BIT(UART0_LCRH, 3);
            break;
        case _2_STOP_BITS:
            SET_BIT(UART0_LCRH, 3);
            break;
        default: break;
        }

        /* to set the system clock to the UART0 */
        UART0_CC &= ~(0x0000000F);

        /* Enable of disable the receiver of UART0 */
        switch(config -> receiverEnable){
        case RECEIVER_DISABLE:
            CLEAR_BIT(UART0_CTL, 9);
            break;
        case RECEIVER_ENABLE:
            SET_BIT(UART0_CTL, 9);
            break;
        default: break;
        }

        /* Enable of disable the transmitter of UART0 */
        switch(config -> transmitterEnable){
        case TRANSMITTER_DISABLE:
            CLEAR_BIT(UART0_CTL, 8);
            break;
        case TRANSMITTER_ENABLE:
            SET_BIT(UART0_CTL, 8);
            break;
        default: break;
        }

        /* Enable the UART0 */
        SET_BIT(UART0_CTL, 0);

        /* Enable UART0 Peripheral Receiver Interrupt*/
        switch(config -> interruptReceiveEnable){
        case INTERRUPT_DISABLE:
            CLEAR_BIT(UART0_IM, 4);
            break;
        case INTERRUPT_ENABLE:
            SET_BIT(UART0_IM, 4);
            break;
        default: break;
        }

        // Enable The Interrupt for UART0 in NVIC
        SET_BIT(NVICEN0, 5);

#endif
        break;
        case UART_1:
#ifdef UART1

            /* Enable the UART module using the RCGCUART register */
            SET_BIT(RCGCUART, 1);

            /* Disable UART1 */
            CLEAR_BIT(UART1_CTL, 0);

            /* set the baud rate */
            UART1_IBRD = IBRD;
            UART1_FBRD = FBRD;

            /* set the data word length */
            switch(config->wordLength){
            case _5_BIT:
                CLEAR_BIT(UART1_LCRH, 5);
                CLEAR_BIT(UART1_LCRH, 6);
                break;
            case _6_BIT:
                SET_BIT(UART1_LCRH, 5);
                CLEAR_BIT(UART1_LCRH, 6);
                break;
            case _7_BIT:
                CLEAR_BIT(UART1_LCRH, 5);
                SET_BIT(UART1_LCRH, 6);
                break;
            case _8_BIT:
                SET_BIT(UART1_LCRH, 5);
                SET_BIT(UART1_LCRH, 6);
                break;
            default: break;
            }
            /* Set the parity */
            switch(config -> parity){
            case NO_PARITY:
                CLEAR_BIT(UART1_LCRH, 1);
                break;
            case EVEN_PARITY:
                SET_BIT(UART1_LCRH, 1);
                SET_BIT(UART1_LCRH, 2);
                break;
            case ODD_PARITY:
                SET_BIT(UART1_LCRH, 1);
                CLEAR_BIT(UART1_LCRH, 2);
                break;
            default: break;
            }

            /* set 1 or 2 stop bits */
            switch(config -> stopBit){
            case _1_STOP_BIT:
                CLEAR_BIT(UART1_LCRH, 3);
                break;
            case _2_STOP_BITS:
                SET_BIT(UART1_LCRH, 3);
                break;
            default: break;
            }

            /* to set the system clock to the UART1 */
            UART1_CC &= ~(0x0000000F);

            /* Enable of disable the receiver of UART1 */
            switch(config -> receiverEnable){
            case RECEIVER_DISABLE:
                CLEAR_BIT(UART1_CTL, 9);
                break;
            case RECEIVER_ENABLE:
                SET_BIT(UART1_CTL, 9);
                break;
            default: break;
            }

            /* Enable of disable the transmitter of UART1 */
            switch(config -> transmitterEnable){
            case TRANSMITTER_DISABLE:
                CLEAR_BIT(UART1_CTL, 8);
                break;
            case TRANSMITTER_ENABLE:
                SET_BIT(UART1_CTL, 8);
                break;
            default: break;
            }

            /* Enable the UART1 */
            SET_BIT(UART1_CTL, 0);

            /* Enable UART1 Peripheral Receiver Interrupt*/
            switch(config -> interruptReceiveEnable){
            case INTERRUPT_DISABLE:
                CLEAR_BIT(UART1_IM, 4);
                break;
            case INTERRUPT_ENABLE:
                SET_BIT(UART1_IM, 4);
                break;
            default: break;
            }

            // Enable The Interrupt for UART1 in NVIC
            SET_BIT(NVICEN0, 6);


#endif
            break;
            case UART_2:
#ifdef UART2

                /* Enable the UART module using the RCGCUART register */
                SET_BIT(RCGCUART, 2);

                /* Disable UART2 */
                CLEAR_BIT(UART2_CTL, 0);

                /* set the baud rate */
                UART3_IBRD = IBRD;
                UART3_FBRD = FBRD;

                /* set the data word length */
                switch(config->wordLength){
                case _5_BIT:
                    CLEAR_BIT(UART2_LCRH, 5);
                    CLEAR_BIT(UART2_LCRH, 6);
                    break;
                case _6_BIT:
                    SET_BIT(UART2_LCRH, 5);
                    CLEAR_BIT(UART2_LCRH, 6);
                    break;
                case _7_BIT:
                    CLEAR_BIT(UART2_LCRH, 5);
                    SET_BIT(UART2_LCRH, 6);
                    break;
                case _8_BIT:
                    SET_BIT(UART2_LCRH, 5);
                    SET_BIT(UART2_LCRH, 6);
                    break;
                default: break;
                }
                /* Set the parity */
                switch(config -> parity){
                case NO_PARITY:
                    CLEAR_BIT(UART2_LCRH, 1);
                    break;
                case EVEN_PARITY:
                    SET_BIT(UART2_LCRH, 1);
                    SET_BIT(UART2_LCRH, 2);
                    break;
                case ODD_PARITY:
                    SET_BIT(UART2_LCRH, 1);
                    CLEAR_BIT(UART2_LCRH, 2);
                    break;
                default: break;
                }

                /* set 1 or 2 stop bits */
                switch(config -> stopBit){
                case _1_STOP_BIT:
                    CLEAR_BIT(UART2_LCRH, 3);
                    break;
                case _2_STOP_BITS:
                    SET_BIT(UART2_LCRH, 3);
                    break;
                default: break;
                }

                /* to set the system clock to the UART2 */
                UART2_CC &= ~(0x0000000F);

                /* Enable of disable the receiver of UART2 */
                switch(config -> receiverEnable){
                case RECEIVER_DISABLE:
                    CLEAR_BIT(UART2_CTL, 9);
                    break;
                case RECEIVER_ENABLE:
                    SET_BIT(UART2_CTL, 9);
                    break;
                default: break;
                }

                /* Enable of disable the transmitter of UART2 */
                switch(config -> transmitterEnable){
                case TRANSMITTER_DISABLE:
                    CLEAR_BIT(UART2_CTL, 8);
                    break;
                case TRANSMITTER_ENABLE:
                    SET_BIT(UART2_CTL, 8);
                    break;
                default: break;
                }

                /* Enable the UART2 */
                SET_BIT(UART2_CTL, 0);

                /* Enable UART2 Peripheral Receiver Interrupt*/
                switch(config -> interruptReceiveEnable){
                case INTERRUPT_DISABLE:
                    CLEAR_BIT(UART2_IM, 4);
                    break;
                case INTERRUPT_ENABLE:
                    SET_BIT(UART2_IM, 4);
                    break;
                default: break;
                }

                // Enable The Interrupt for UART2 in NVIC
                SET_BIT(NVICEN1, 1);


#endif

                break;
                case UART_3:
#ifdef UART3

                    /* Enable the UART module using the RCGCUART register */
                    SET_BIT(RCGCUART, 3);

                    /* Disable UART3 */
                    CLEAR_BIT(UART3_CTL, 0);

                    /* set the baud rate */
                    UART3_IBRD = IBRD;
                    UART3_FBRD = FBRD;

                    /* set the data word length */
                    switch(config->wordLength){
                    case _5_BIT:
                        CLEAR_BIT(UART3_LCRH, 5);
                        CLEAR_BIT(UART3_LCRH, 6);
                        break;
                    case _6_BIT:
                        SET_BIT(UART3_LCRH, 5);
                        CLEAR_BIT(UART3_LCRH, 6);
                        break;
                    case _7_BIT:
                        CLEAR_BIT(UART3_LCRH, 5);
                        SET_BIT(UART3_LCRH, 6);
                        break;
                    case _8_BIT:
                        SET_BIT(UART3_LCRH, 5);
                        SET_BIT(UART3_LCRH, 6);
                        break;
                    default: break;
                    }
                    /* Set the parity */
                    switch(config -> parity){
                    case NO_PARITY:
                        CLEAR_BIT(UART3_LCRH, 1);
                        break;
                    case EVEN_PARITY:
                        SET_BIT(UART3_LCRH, 1);
                        SET_BIT(UART3_LCRH, 2);
                        break;
                    case ODD_PARITY:
                        SET_BIT(UART3_LCRH, 1);
                        CLEAR_BIT(UART3_LCRH, 2);
                        break;
                    default: break;
                    }

                    /* set 1 or 2 stop bits */
                    switch(config -> stopBit){
                    case _1_STOP_BIT:
                        CLEAR_BIT(UART3_LCRH, 3);
                        break;
                    case _2_STOP_BITS:
                        SET_BIT(UART3_LCRH, 3);
                        break;
                    default: break;
                    }

                    /* to set the system clock to the UART3 */
                    UART3_CC &= ~(0x0000000F);

                    /* Enable of disable the receiver of UART3 */
                    switch(config -> receiverEnable){
                    case RECEIVER_DISABLE:
                        CLEAR_BIT(UART3_CTL, 9);
                        break;
                    case RECEIVER_ENABLE:
                        SET_BIT(UART3_CTL, 9);
                        break;
                    default: break;
                    }

                    /* Enable of disable the transmitter of UART3 */
                    switch(config -> transmitterEnable){
                    case TRANSMITTER_DISABLE:
                        CLEAR_BIT(UART3_CTL, 8);
                        break;
                    case TRANSMITTER_ENABLE:
                        SET_BIT(UART3_CTL, 8);
                        break;
                    default: break;
                    }

                    /* Enable the UART3 */
                    SET_BIT(UART3_CTL, 0);

                    /* Enable UART3 Peripheral Receiver Interrupt*/
                    switch(config -> interruptReceiveEnable){
                    case INTERRUPT_DISABLE:
                        CLEAR_BIT(UART3_IM, 4);
                        break;
                    case INTERRUPT_ENABLE:
                        SET_BIT(UART3_IM, 4);
                        break;
                    default: break;
                    }

                    // Enable The Interrupt for UART3 in NVIC
                    SET_BIT(NVICEN1, 27);

#endif

                    break;
                    case UART_4:
#ifdef UART4

                        /* Enable the UART module using the RCGCUART register */
                        SET_BIT(RCGCUART, 4);

                        /* Disable UART4 */
                        CLEAR_BIT(UART4_CTL, 0);

                        /* set the baud rate */
                        UART4_IBRD = IBRD;
                        UART4_FBRD = FBRD;

                        /* set the data word length */
                        switch(config->wordLength){
                        case _5_BIT:
                            CLEAR_BIT(UART4_LCRH, 5);
                            CLEAR_BIT(UART4_LCRH, 6);
                            break;
                        case _6_BIT:
                            SET_BIT(UART4_LCRH, 5);
                            CLEAR_BIT(UART4_LCRH, 6);
                            break;
                        case _7_BIT:
                            CLEAR_BIT(UART4_LCRH, 5);
                            SET_BIT(UART4_LCRH, 6);
                            break;
                        case _8_BIT:
                            SET_BIT(UART4_LCRH, 5);
                            SET_BIT(UART4_LCRH, 6);
                            break;
                        default: break;
                        }
                        /* Set the parity */
                        switch(config -> parity){
                        case NO_PARITY:
                            CLEAR_BIT(UART4_LCRH, 1);
                            break;
                        case EVEN_PARITY:
                            SET_BIT(UART4_LCRH, 1);
                            SET_BIT(UART4_LCRH, 2);
                            break;
                        case ODD_PARITY:
                            SET_BIT(UART4_LCRH, 1);
                            CLEAR_BIT(UART4_LCRH, 2);
                            break;
                        default: break;
                        }

                        /* set 1 or 2 stop bits */
                        switch(config -> stopBit){
                        case _1_STOP_BIT:
                            CLEAR_BIT(UART4_LCRH, 3);
                            break;
                        case _2_STOP_BITS:
                            SET_BIT(UART4_LCRH, 3);
                            break;
                        default: break;
                        }

                        /* to set the system clock to the UART4 */
                        UART4_CC &= ~(0x0000000F);

                        /* Enable of disable the receiver of UART4 */
                        switch(config -> receiverEnable){
                        case RECEIVER_DISABLE:
                            CLEAR_BIT(UART4_CTL, 9);
                            break;
                        case RECEIVER_ENABLE:
                            SET_BIT(UART4_CTL, 9);
                            break;
                        default: break;
                        }

                        /* Enable of disable the transmitter of UART4 */
                        switch(config -> transmitterEnable){
                        case TRANSMITTER_DISABLE:
                            CLEAR_BIT(UART4_CTL, 8);
                            break;
                        case TRANSMITTER_ENABLE:
                            SET_BIT(UART4_CTL, 8);
                            break;
                        default: break;
                        }

                        /* Enable the UART4 */
                        SET_BIT(UART4_CTL, 0);

                        /* Enable UART4 Peripheral Receiver Interrupt*/
                        switch(config -> interruptReceiveEnable){
                        case INTERRUPT_DISABLE:
                            CLEAR_BIT(UART4_IM, 4);
                            break;
                        case INTERRUPT_ENABLE:
                            SET_BIT(UART4_IM, 4);
                            break;
                        default: break;
                        }

                        // Enable The Interrupt for UART4 in NVIC
                        SET_BIT(NVICEN1, 28);

#endif

                        break;
                        case UART_5:
#ifdef UART5

                            /* Enable the UART module using the RCGCUART register */
                            SET_BIT(RCGCUART, 5);

                            /* Disable UART5 */
                            CLEAR_BIT(UART5_CTL, 0);

                            /* set the baud rate */
                            UART5_IBRD = IBRD;
                            UART5_FBRD = FBRD;

                            /* set the data word length */
                            switch(config->wordLength){
                            case _5_BIT:
                                CLEAR_BIT(UART5_LCRH, 5);
                                CLEAR_BIT(UART5_LCRH, 6);
                                break;
                            case _6_BIT:
                                SET_BIT(UART5_LCRH, 5);
                                CLEAR_BIT(UART5_LCRH, 6);
                                break;
                            case _7_BIT:
                                CLEAR_BIT(UART5_LCRH, 5);
                                SET_BIT(UART5_LCRH, 6);
                                break;
                            case _8_BIT:
                                SET_BIT(UART5_LCRH, 5);
                                SET_BIT(UART5_LCRH, 6);
                                break;
                            default: break;
                            }
                            /* Set the parity */
                            switch(config -> parity){
                            case NO_PARITY:
                                CLEAR_BIT(UART5_LCRH, 1);
                                break;
                            case EVEN_PARITY:
                                SET_BIT(UART5_LCRH, 1);
                                SET_BIT(UART5_LCRH, 2);
                                break;
                            case ODD_PARITY:
                                SET_BIT(UART5_LCRH, 1);
                                CLEAR_BIT(UART5_LCRH, 2);
                                break;
                            default: break;
                            }

                            /* set 1 or 2 stop bits */
                            switch(config -> stopBit){
                            case _1_STOP_BIT:
                                CLEAR_BIT(UART5_LCRH, 3);
                                break;
                            case _2_STOP_BITS:
                                SET_BIT(UART5_LCRH, 3);
                                break;
                            default: break;
                            }

                            /* to set the system clock to the UART5 */
                            UART5_CC &= ~(0x0000000F);

                            /* Enable of disable the receiver of UART5 */
                            switch(config -> receiverEnable){
                            case RECEIVER_DISABLE:
                                CLEAR_BIT(UART5_CTL, 9);
                                break;
                            case RECEIVER_ENABLE:
                                SET_BIT(UART5_CTL, 9);
                                break;
                            default: break;
                            }

                            /* Enable of disable the transmitter of UART5 */
                            switch(config -> transmitterEnable){
                            case TRANSMITTER_DISABLE:
                                CLEAR_BIT(UART5_CTL, 8);
                                break;
                            case TRANSMITTER_ENABLE:
                                SET_BIT(UART5_CTL, 8);
                                break;
                            default: break;
                            }

                            /* Enable the UART5 */
                            SET_BIT(UART5_CTL, 0);

                            /* Enable UART5 Peripheral Receiver Interrupt*/
                            switch(config -> interruptReceiveEnable){
                            case INTERRUPT_DISABLE:
                                CLEAR_BIT(UART5_IM, 4);
                                break;
                            case INTERRUPT_ENABLE:
                                SET_BIT(UART5_IM, 4);
                                break;
                            default: break;
                            }

                            // Enable The Interrupt for UART5 in NVIC
                            SET_BIT(NVICEN1, 29);

#endif
                            break;
                            case UART_6:
#ifdef UART6

                                /* Enable the UART module using the RCGCUART register */
                                SET_BIT(RCGCUART, 6);

                                /* Disable UART6 */
                                CLEAR_BIT(UART6_CTL, 0);

                                /* set the baud rate */
                                UART6_IBRD = IBRD;
                                UART6_FBRD = FBRD;

                                /* set the data word length */
                                switch(config->wordLength){
                                case _5_BIT:
                                    CLEAR_BIT(UART6_LCRH, 5);
                                    CLEAR_BIT(UART6_LCRH, 6);
                                    break;
                                case _6_BIT:
                                    SET_BIT(UART6_LCRH, 5);
                                    CLEAR_BIT(UART6_LCRH, 6);
                                    break;
                                case _7_BIT:
                                    CLEAR_BIT(UART6_LCRH, 5);
                                    SET_BIT(UART6_LCRH, 6);
                                    break;
                                case _8_BIT:
                                    SET_BIT(UART6_LCRH, 5);
                                    SET_BIT(UART6_LCRH, 6);
                                    break;
                                default: break;
                                }
                                /* Set the parity */
                                switch(config -> parity){
                                case NO_PARITY:
                                    CLEAR_BIT(UART6_LCRH, 1);
                                    break;
                                case EVEN_PARITY:
                                    SET_BIT(UART6_LCRH, 1);
                                    SET_BIT(UART6_LCRH, 2);
                                    break;
                                case ODD_PARITY:
                                    SET_BIT(UART6_LCRH, 1);
                                    CLEAR_BIT(UART6_LCRH, 2);
                                    break;
                                default: break;
                                }

                                /* set 1 or 2 stop bits */
                                switch(config -> stopBit){
                                case _1_STOP_BIT:
                                    CLEAR_BIT(UART6_LCRH, 3);
                                    break;
                                case _2_STOP_BITS:
                                    SET_BIT(UART6_LCRH, 3);
                                    break;
                                default: break;
                                }

                                /* to set the system clock to the UART6 */
                                UART6_CC &= ~(0x0000000F);

                                /* Enable of disable the receiver of UART6 */
                                switch(config -> receiverEnable){
                                case RECEIVER_DISABLE:
                                    CLEAR_BIT(UART6_CTL, 9);
                                    break;
                                case RECEIVER_ENABLE:
                                    SET_BIT(UART6_CTL, 9);
                                    break;
                                default: break;
                                }

                                /* Enable of disable the transmitter of UART6 */
                                switch(config -> transmitterEnable){
                                case TRANSMITTER_DISABLE:
                                    CLEAR_BIT(UART6_CTL, 8);
                                    break;
                                case TRANSMITTER_ENABLE:
                                    SET_BIT(UART6_CTL, 8);
                                    break;
                                default: break;
                                }

                                /* Enable the UART6 */
                                SET_BIT(UART6_CTL, 0);

                                /* Enable UART6 Peripheral Receiver Interrupt*/
                                switch(config -> interruptReceiveEnable){
                                case INTERRUPT_DISABLE:
                                    CLEAR_BIT(UART6_IM, 4);
                                    break;
                                case INTERRUPT_ENABLE:
                                    SET_BIT(UART6_IM, 4);
                                    break;
                                default: break;
                                }

                                // Enable The Interrupt for UART6 in NVIC
                                SET_BIT(NVICEN1, 30);

#endif

                                break;
                                case UART_7:
#ifdef UART7

                                    /* Enable the UART module using the RCGCUART register */
                                    SET_BIT(RCGCUART, 7);

                                    /* Disable UART6 */
                                    CLEAR_BIT(UART7_CTL, 0);

                                    /* set the baud rate */
                                    UART7_IBRD = IBRD;
                                    UART7_FBRD = FBRD;

                                    /* set the data word length */
                                    switch(config->wordLength){
                                    case _5_BIT:
                                        CLEAR_BIT(UART7_LCRH, 5);
                                        CLEAR_BIT(UART7_LCRH, 6);
                                        break;
                                    case _6_BIT:
                                        SET_BIT(UART7_LCRH, 5);
                                        CLEAR_BIT(UART7_LCRH, 6);
                                        break;
                                    case _7_BIT:
                                        CLEAR_BIT(UART7_LCRH, 5);
                                        SET_BIT(UART7_LCRH, 6);
                                        break;
                                    case _8_BIT:
                                        SET_BIT(UART7_LCRH, 5);
                                        SET_BIT(UART7_LCRH, 6);
                                        break;
                                    default: break;
                                    }
                                    /* Set the parity */
                                    switch(config -> parity){
                                    case NO_PARITY:
                                        CLEAR_BIT(UART7_LCRH, 1);
                                        break;
                                    case EVEN_PARITY:
                                        SET_BIT(UART7_LCRH, 1);
                                        SET_BIT(UART7_LCRH, 2);
                                        break;
                                    case ODD_PARITY:
                                        SET_BIT(UART7_LCRH, 1);
                                        CLEAR_BIT(UART7_LCRH, 2);
                                        break;
                                    default: break;
                                    }

                                    /* set 1 or 2 stop bits */
                                    switch(config -> stopBit){
                                    case _1_STOP_BIT:
                                        CLEAR_BIT(UART7_LCRH, 3);
                                        break;
                                    case _2_STOP_BITS:
                                        SET_BIT(UART7_LCRH, 3);
                                        break;
                                    default: break;
                                    }

                                    /* to set the system clock to the UART7 */
                                    UART7_CC &= ~(0x0000000F);

                                    /* Enable of disable the receiver of UART7 */
                                    switch(config -> receiverEnable){
                                    case RECEIVER_DISABLE:
                                        CLEAR_BIT(UART7_CTL, 9);
                                        break;
                                    case RECEIVER_ENABLE:
                                        SET_BIT(UART7_CTL, 9);
                                        break;
                                    default: break;
                                    }

                                    /* Enable of disable the transmitter of UART7 */
                                    switch(config -> transmitterEnable){
                                    case TRANSMITTER_DISABLE:
                                        CLEAR_BIT(UART7_CTL, 8);
                                        break;
                                    case TRANSMITTER_ENABLE:
                                        SET_BIT(UART7_CTL, 8);
                                        break;
                                    default: break;
                                    }

                                    /* Enable the UART7 */
                                    SET_BIT(UART7_CTL, 0);

                                    /* Enable UART7 Peripheral Receiver Interrupt*/
                                    switch(config -> interruptReceiveEnable){
                                    case INTERRUPT_DISABLE:
                                        CLEAR_BIT(UART7_IM, 4);
                                        break;
                                    case INTERRUPT_ENABLE:
                                        SET_BIT(UART7_IM, 4);
                                        break;
                                    default: break;
                                    }

                                    // Enable The Interrupt for UART7 in NVIC
                                    SET_BIT(NVICEN1, 31);

#endif

                                    break;
                                    default: break;
    }
}

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
void vUART_sendByte(UART_Channel channel, uint8 data){
    switch(channel){
    case UART_0:
#ifdef UART0
    while((UART0_FR & (1 << 5)));
    UART0_DR = data;
#endif
    break;
    case UART_1:
#ifdef UART1
    while((UART1_FR & (1 << 5)));
    UART1_DR = data;

#endif
    break;
    case UART_2:
#ifdef UART2
    while((UART2_FR & (1 << 5)));
    UART2_DR = data;
#endif
    break;
    case UART_3:
#ifdef UART3
    while((UART3_FR & (1 << 5)));
    UART3_DR = data;
#endif
    break;
    case UART_4:
#ifdef UART4
    while((UART4_FR & (1 << 5)));
    UART4_DR = data;
#endif
    break;
    case UART_5:
#ifdef UART5
    while((UART5_FR & (1 << 5)));
    UART5_DR = data;
#endif
    break;
    case UART_6:
#ifdef UART6
    while((UART6_FR & (1 << 5)));
    UART6_DR = data;
#endif
    break;
    case UART_7:
#ifdef UART7
    while((UART7_FR & (1 << 5)));
    UART7_DR = data;
#endif
    break;
    default: break;
    }
}

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
uint8 u8UART_receiveByte(UART_Channel channel){
    char receivedByte;
    switch(channel){
    case UART_0:
#ifdef UART0
    while((UART0_FR & (1 << 4)));
    receivedByte = (uint8) UART0_DR;
#endif
    break;
    case UART_1:
#ifdef UART1
    while((UART1_FR & (1 << 4)));
    receivedByte = (uint8) UART1_DR;
#endif
    break;
    case UART_2:
#ifdef UART2
    while((UART2_FR & (1 << 4)));
    receivedByte = (uint8) UART2_DR;
#endif
    break;
    case UART_3:
#ifdef UART3
    while((UART3_FR & (1 << 4)));
    receivedByte = (uint8) UART3_DR;
#endif
    break;
    case UART_4:
#ifdef UART4
    while((UART4_FR & (1 << 4)));
    receivedByte = (uint8) UART4_DR;
#endif
    break;
    case UART_5:
#ifdef UART5
    while((UART5_FR & (1 << 4)));
    receivedByte = (uint8) UART5_DR;
#endif
    break;
    case UART_6:
#ifdef UART6
    while((UART6_FR & (1 << 4)));
    receivedByte = (uint8) UART6_DR;
#endif
    break;
    case UART_7:
#ifdef UART7
    while((UART7_FR & (1 << 4)));
    receivedByte = (uint8) UART7_DR;
#endif
    break;
    default: break;
    }
    return receivedByte;
}


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
void vUART_sendString(UART_Channel channel, const uint8* string){
    switch(channel){
    case UART_0:
    #ifdef UART0
    while(*string != '\0'){
            vUART_sendByte(UART_0, *string);
            string++;
        }
    #endif
    break;
    case UART_1:
    #ifdef UART1
    while(*string != '\0'){
            vUART_sendByte(UART_1, *string);
            string++;
        }

    #endif
    break;
    case UART_2:
    #ifdef UART2
    while(*string != '\0'){
            vUART_sendByte(UART_2, *string);
            string++;
        }
    #endif
    break;
    case UART_3:
    #ifdef UART3
    while(*string != '\0'){
            vUART_sendByte(UART_3, *string);
            string++;
        }
    #endif
    break;
    case UART_4:
    #ifdef UART4
    while(*string != '\0'){
            vUART_sendByte(UART_4, *string);
            string++;
        }
    #endif
    break;
    case UART_5:
    #ifdef UART5
    while(*string != '\0'){
            vUART_sendByte(UART_5, *string);
            string++;
        }
    #endif
    break;
    case UART_6:
    #ifdef UART6
    while(*string != '\0'){
            vUART_sendByte(UART_6, *string);
            string++;
        }
    #endif
    break;
    case UART_7:
    #ifdef UART7
    while(*string != '\0'){
            vUART_sendByte(UART_7, *string);
            string++;
        }
    #endif
    break;
    default: break;
    }

}
#ifdef UART0




/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:                 UARTx_handler  x = [0 : 7]
 *
 * [DESCRIPTION]:                   Function to be executed if an interrupt happen
 *                                  you have to copy these function names to the startup code in the vector table
 *                                  instead of IntDefaultHandler
 *
 * [Args]:
 *
 * [IN]:                            None.
 *
 * [OUT]:                           None.
 *
 * [IN / OUT]:                      None.
 *
 * [RETURNS]:                       void
 * ---------------------------------------------------------------------------------------------------
 */
void UART0_handler(void){
    if(g_UART0_callBackPtr != NULL_PTR){
        (*g_UART0_callBackPtr)();
    }
}
#endif
#ifdef UART1
void UART1_handler(void){
    if(g_UART1_callBackPtr != NULL_PTR){
        (*g_UART1_callBackPtr)();
    }
}
#endif

#ifdef UART2
void UART2_handler(void){
    if(g_UART2_callBackPtr != NULL_PTR){
        (*g_UART2_callBackPtr)();
    }
}
#endif

#ifdef UART3
void UART3_handler(void){
    if(g_UART3_callBackPtr != NULL_PTR){
        (*g_UART3_callBackPtr)();
    }
}
#endif

#ifdef UART4
void UART4_handler(void){
    if(g_UART4_callBackPtr != NULL_PTR){
        (*g_UART4_callBackPtr)();
    }
}
#endif

#ifdef UART5
void UART5_handler(void){
    if(g_UART5_callBackPtr != NULL_PTR){
        (*g_UART5_callBackPtr)();
    }
}
#endif

#ifdef UART6
void UART6_handler(void){
    if(g_UART6_callBackPtr != NULL_PTR){
        (*g_UART6_callBackPtr)();
    }
}
#endif

#ifdef UART7
void UART7_handler(void){
    if(g_UART7_callBackPtr != NULL_PTR){
        (*g_UART7_callBackPtr)();
    }
}
#endif


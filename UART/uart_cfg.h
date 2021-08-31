/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <uart_cfg.h here>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: < 25 - 8 - 2021 >
 *
 * [DESCRIPTION]: <configuration file for UART Driver for TIVA C EK-TM4C123GH6PM>
 * ---------------------------------------------------------------------------------------------------
 */



/* ---------------------------------------------------------------------------------------------------
 *   This driver is specially for the UART module in TIVA C (EK-TM4C123GH6PM).
 *   It can enable any you UART channel using the vUART_init function and pass UART_Config as
 *   an argument by address.
 *
 *
 *   for example to enable the UART channel 0 and enable the TX and RX
 *   and with 8 bits word length, No parity, 1 stop bit with polling technique.
 *
 *
 *  The code will be like that:

    UART_Config UART0_configurations;

    UART0_configurations.channel = UART_0;
    UART0_configurations.transmitterEnable = TRANSMITTER_ENABLE;
    UART0_configurations.receiverEnable = RECEIVER_ENABLE;
    UART0_configurations.stopBit = _1_STOP_BIT;
    UART0_configurations.parity = NO_PARITY;
    UART0_configurations.wordLength = _8_BIT;
    UART0_configurations.baudRate = _9600;
    UART0_configurations.interruptReceiveEnable = INTERRUPT_DISABLE;

    vUART_init(&UART0_configurations);

 * ---------------------------------------------------------------------------------------------------
 */
#ifndef UART_CFG_H_
#define UART_CFG_H_


/* ---------------------- you have to set the system clock of the system here, the driver use it to get the baud rate -----------------*/
#define SYS_CLK              16000000


/*
 * To enable the UART channel, you have to define its name.
 */
#define UART0
//#define UART1
//#define UART2
//#define UART3
//#define UART4
//#define UART5
//#define UART6
//#define UART7



#endif /* UART_CFG_H_ */

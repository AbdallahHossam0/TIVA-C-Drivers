/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <uart_priv.h here>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: < 25 - 8 - 2021 >
 *
 * [DESCRIPTION]: <private file for UART Driver for TIVA C EK-TM4C123GH6PM>
 * ---------------------------------------------------------------------------------------------------
 */



#ifndef UART_PRIV_H_
#define UART_PRIV_H_



/*---------------- Register Definition -------------------*/

/*---------------- Base addresses -------------------*/
#define UART0_BASE_ADDRESS                (*((volatile uint32 *) 0x4000C000))
#define UART1_BASE_ADDRESS                (*((volatile uint32 *) 0x4000D000))
#define UART2_BASE_ADDRESS                (*((volatile uint32 *) 0x4000E000))
#define UART3_BASE_ADDRESS                (*((volatile uint32 *) 0x4000F000))
#define UART4_BASE_ADDRESS                (*((volatile uint32 *) 0x40010000))
#define UART5_BASE_ADDRESS                (*((volatile uint32 *) 0x40011000))
#define UART6_BASE_ADDRESS                (*((volatile uint32 *) 0x40012000))
#define UART7_BASE_ADDRESS                (*((volatile uint32 *) 0x40013000))

/*---------------- UART0 Registers -------------------*/
#define UART0_DR                          (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x000))
#define UART0_RSR                         (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x004))
#define UART0_FR                          (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x018))
#define UART0_ILPR                        (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x020))
#define UART0_IBRD                        (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x024))
#define UART0_FBRD                        (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x028))
#define UART0_LCRH                        (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x02C))
#define UART0_CTL                         (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x030))
#define UART0_IFLS                        (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x034))
#define UART0_IM                          (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x038))
#define UART0_RIS                         (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x03C))
#define UART0_MIS                         (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x040))
#define UART0_ICR                         (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x044))
#define UART0_DMACTL                      (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x048))
#define UART0_9BITADDR                    (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x0A4))
#define UART0_9BITAMASK                   (*((volatile uint32 *) UART0_BASE_ADDRESS + 0x0A8))
#define UART0_PP                          (*((volatile uint32 *) UART0_BASE_ADDRESS + 0xFC0))
#define UART0_CC                          (*((volatile uint32 *) UART0_BASE_ADDRESS + 0xFC8))

/*---------------- UART1 Registers -------------------*/
#define UART1_DR                          (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x000))
#define UART1_RSR                         (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x004))
#define UART1_FR                          (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x018))
#define UART1_ILPR                        (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x020))
#define UART1_IBRD                        (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x024))
#define UART1_FBRD                        (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x028))
#define UART1_LCRH                        (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x02C))
#define UART1_CTL                         (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x030))
#define UART1_IFLS                        (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x034))
#define UART1_IM                          (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x038))
#define UART1_RIS                         (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x03C))
#define UART1_MIS                         (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x040))
#define UART1_ICR                         (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x044))
#define UART1_DMACTL                      (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x048))
#define UART1_9BITADDR                    (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x0A4))
#define UART1_9BITAMASK                   (*((volatile uint32 *) UART1_BASE_ADDRESS + 0x0A8))
#define UART1_PP                          (*((volatile uint32 *) UART1_BASE_ADDRESS + 0xFC0))
#define UART1_CC                          (*((volatile uint32 *) UART1_BASE_ADDRESS + 0xFC8))


/*---------------- UART2 Registers -------------------*/
#define UART2_DR                          (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x000))
#define UART2_RSR                         (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x004))
#define UART2_FR                          (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x018))
#define UART2_ILPR                        (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x020))
#define UART2_IBRD                        (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x024))
#define UART2_FBRD                        (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x028))
#define UART2_LCRH                        (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x02C))
#define UART2_CTL                         (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x030))
#define UART2_IFLS                        (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x034))
#define UART2_IM                          (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x038))
#define UART2_RIS                         (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x03C))
#define UART2_MIS                         (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x040))
#define UART2_ICR                         (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x044))
#define UART2_DMACTL                      (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x048))
#define UART2_9BITADDR                    (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x0A4))
#define UART2_9BITAMASK                   (*((volatile uint32 *) UART2_BASE_ADDRESS + 0x0A8))
#define UART2_PP                          (*((volatile uint32 *) UART2_BASE_ADDRESS + 0xFC0))
#define UART2_CC                          (*((volatile uint32 *) UART2_BASE_ADDRESS + 0xFC8))



/*---------------- UART3 Registers -------------------*/
#define UART3_DR                          (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x000))
#define UART3_RSR                         (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x004))
#define UART3_FR                          (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x018))
#define UART3_ILPR                        (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x020))
#define UART3_IBRD                        (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x024))
#define UART3_FBRD                        (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x028))
#define UART3_LCRH                        (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x02C))
#define UART3_CTL                         (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x030))
#define UART3_IFLS                        (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x034))
#define UART3_IM                          (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x038))
#define UART3_RIS                         (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x03C))
#define UART3_MIS                         (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x040))
#define UART3_ICR                         (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x044))
#define UART3_DMACTL                      (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x048))
#define UART3_9BITADDR                    (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x0A4))
#define UART3_9BITAMASK                   (*((volatile uint32 *) UART3_BASE_ADDRESS + 0x0A8))
#define UART3_PP                          (*((volatile uint32 *) UART3_BASE_ADDRESS + 0xFC0))
#define UART3_CC                          (*((volatile uint32 *) UART3_BASE_ADDRESS + 0xFC8))


/*---------------- UART4 Registers -------------------*/
#define UART4_DR                          (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x000))
#define UART4_RSR                         (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x004))
#define UART4_FR                          (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x018))
#define UART4_ILPR                        (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x020))
#define UART4_IBRD                        (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x024))
#define UART4_FBRD                        (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x028))
#define UART4_LCRH                        (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x02C))
#define UART4_CTL                         (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x030))
#define UART4_IFLS                        (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x034))
#define UART4_IM                          (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x038))
#define UART4_RIS                         (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x03C))
#define UART4_MIS                         (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x040))
#define UART4_ICR                         (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x044))
#define UART4_DMACTL                      (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x048))
#define UART4_9BITADDR                    (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x0A4))
#define UART4_9BITAMASK                   (*((volatile uint32 *) UART4_BASE_ADDRESS + 0x0A8))
#define UART4_PP                          (*((volatile uint32 *) UART4_BASE_ADDRESS + 0xFC0))
#define UART4_CC                          (*((volatile uint32 *) UART4_BASE_ADDRESS + 0xFC8))


/*---------------- UART5 Registers -------------------*/
#define UART5_DR                          (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x000))
#define UART5_RSR                         (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x004))
#define UART5_FR                          (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x018))
#define UART5_ILPR                        (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x020))
#define UART5_IBRD                        (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x024))
#define UART5_FBRD                        (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x028))
#define UART5_LCRH                        (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x02C))
#define UART5_CTL                         (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x030))
#define UART5_IFLS                        (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x034))
#define UART5_IM                          (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x038))
#define UART5_RIS                         (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x03C))
#define UART5_MIS                         (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x040))
#define UART5_ICR                         (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x044))
#define UART5_DMACTL                      (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x048))
#define UART5_9BITADDR                    (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x0A4))
#define UART5_9BITAMASK                   (*((volatile uint32 *) UART5_BASE_ADDRESS + 0x0A8))
#define UART5_PP                          (*((volatile uint32 *) UART5_BASE_ADDRESS + 0xFC0))
#define UART5_CC                          (*((volatile uint32 *) UART5_BASE_ADDRESS + 0xFC8))


/*---------------- UART6 Registers -------------------*/
#define UART6_DR                          (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x000))
#define UART6_RSR                         (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x004))
#define UART6_FR                          (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x018))
#define UART6_ILPR                        (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x020))
#define UART6_IBRD                        (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x024))
#define UART6_FBRD                        (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x028))
#define UART6_LCRH                        (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x02C))
#define UART6_CTL                         (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x030))
#define UART6_IFLS                        (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x034))
#define UART6_IM                          (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x038))
#define UART6_RIS                         (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x03C))
#define UART6_MIS                         (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x040))
#define UART6_ICR                         (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x044))
#define UART6_DMACTL                      (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x048))
#define UART6_9BITADDR                    (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x0A4))
#define UART6_9BITAMASK                   (*((volatile uint32 *) UART6_BASE_ADDRESS + 0x0A8))
#define UART6_PP                          (*((volatile uint32 *) UART6_BASE_ADDRESS + 0xFC0))
#define UART6_CC                          (*((volatile uint32 *) UART6_BASE_ADDRESS + 0xFC8))

/*---------------- UART7 Registers -------------------*/
#define UART7_DR                          (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x000))
#define UART7_RSR                         (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x004))
#define UART7_FR                          (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x018))
#define UART7_ILPR                        (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x020))
#define UART7_IBRD                        (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x024))
#define UART7_FBRD                        (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x028))
#define UART7_LCRH                        (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x02C))
#define UART7_CTL                         (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x030))
#define UART7_IFLS                        (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x034))
#define UART7_IM                          (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x038))
#define UART7_RIS                         (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x03C))
#define UART7_MIS                         (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x040))
#define UART7_ICR                         (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x044))
#define UART7_DMACTL                      (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x048))
#define UART7_9BITADDR                    (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x0A4))
#define UART7_9BITAMASK                   (*((volatile uint32 *) UART7_BASE_ADDRESS + 0x0A8))
#define UART7_PP                          (*((volatile uint32 *) UART7_BASE_ADDRESS + 0xFC0))
#define UART7_CC                          (*((volatile uint32 *) UART7_BASE_ADDRESS + 0xFC8))

/*---------------- RCG For UART Register -------------------*/
#define RCGCUART                          (*((volatile uint32 *) 0x400FE618))

/*---------------- NVIC For UART Register -------------------*/
#define NVICEN0                          (*((volatile uint32 *) 0xE000E100))
#define NVICEN1                          (*((volatile uint32 *) 0xE000E104))

/*---------------- UART objects -------------------*/

/* ---------------------------------------------------------------------------
 *          Enum to select the channel of UART as UART module in TIVA C has 8 channels.
 *          From UART0 to UART7
 * ---------------------------------------------------------------------------
 */
typedef enum
{
    UART_0 = 0,
    UART_1,
    UART_2,
    UART_3,
    UART_4,
    UART_5,
    UART_6,
    UART_7
}UART_Channel;


/* ---------------------------------------------------------------------------
 *          Enum to disable or enable the RX of the module
 * ---------------------------------------------------------------------------
 */
typedef enum
{
    RECEIVER_DISABLE,
    RECEIVER_ENABLE
}UART_Receive;


/* ---------------------------------------------------------------------------
 *          Enum to disable or enable the TX of the module
 * ---------------------------------------------------------------------------
 */
typedef enum
{
    TRANSMITTER_DISABLE,
    TRANSMITTER_ENABLE
}UART_Transmit;

/* ---------------------------------------------------------------------------
 *          Enum to select the length of the data in the UART frame
 * ---------------------------------------------------------------------------
 */
typedef enum{
    _5_BIT,
    _6_BIT,
    _7_BIT,
    _8_BIT
}UART_WordLength;


/* ---------------------------------------------------------------------------
 *          Enum to disable or enable parity.
 *          And choose if to enable the even or the odd parity.
 * ---------------------------------------------------------------------------
 */
typedef enum{
    NO_PARITY,
    EVEN_PARITY,
    ODD_PARITY
}UART_ParitySelect;

/* ---------------------------------------------------------------------------
 *          Enum to select 1 or 2 stop bits at the end of the frame.
 * ---------------------------------------------------------------------------
 */
typedef enum{
    _1_STOP_BIT,
    _2_STOP_BITS
}UART_StopBitSelect;


/* ---------------------------------------------------------------------------
 *          Enum to disable or enable the Interrupts of the module.
 * ---------------------------------------------------------------------------
 */
typedef enum{
    INTERRUPT_DISABLE,
    INTERRUPT_ENABLE
}UART_InterruptReceiveSelect;

/* ---------------------------------------------------------------------------
 *          Enum to choose the baud rate you wnat to work with.
 * ---------------------------------------------------------------------------
 */
typedef enum{
    _110 = 110,
    _300 = 300,
    _600 = 600,
    _1200 = 1200,
    _2400 = 2400,
    _4800 = 4800,
    _9600 = 9600,
    _14400 = 14400,
    _19200 = 19200,
    _38400 = 38400,
    _57600 = 57600,
    _115200 = 115200,
    _128000 = 128000,
    _256000 = 256000
}UART_BaudRate;


/* ---------------------------------------------------------------------------
 *          struct has all the configurations to initialize the UART.
 * ---------------------------------------------------------------------------
 */
typedef struct{
    UART_Channel channel;
    UART_Receive receiverEnable;
    UART_Transmit transmitterEnable;
    UART_WordLength wordLength;
    UART_ParitySelect parity;
    UART_BaudRate baudRate;
    UART_StopBitSelect stopBit;
    UART_InterruptReceiveSelect interruptReceiveEnable;
}UART_Config;

#endif /* UART_PRIV_H_ */

//-- For using USART
#define BAUD 9600
#define MYUBBR F_CPU/16/BAUD-1

/* USART Buffer Defines */
#define USART_RX_BUFFER_SIZE 256     /* 2,4,8,16,32,64,128 or 256 bytes */
#define USART_TX_BUFFER_SIZE 256     /* 2,4,8,16,32,64,128 or 256 bytes */
#define USART_RX_BUFFER_MASK (USART_RX_BUFFER_SIZE - 1)
#define USART_TX_BUFFER_MASK (USART_TX_BUFFER_SIZE - 1)

/* Static Variables */
static unsigned char USART_RxBuf[USART_RX_BUFFER_SIZE];
static volatile unsigned char USART_RxHead;
static volatile unsigned char USART_RxTail;
static unsigned char USART_TxBuf[USART_TX_BUFFER_SIZE];
static volatile unsigned char USART_TxHead;
static volatile unsigned char USART_TxTail;

/* Prototypes */
void USART0_Init(unsigned int ubrr_val);
unsigned char USART0_Receive(void);
void USART0_Transmit(unsigned char data);
void USART_putstring(char* StringPtr);
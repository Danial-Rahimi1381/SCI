#include <stdio.h>
#include <string.h>
/*---------------------------------------------------------------------------*/
#define FIFO_SIZE 16    // Define FIFO size as per your requirement

char checksum = 0;

struct ProtocolStructure {char Header1;char Header2;char Header3;char Header4;
                char length;char *data;Uint16 Checksum;char EndofFrame;};
static enum StateFramne{ FRAME_IDLE,FRAME_A_WAIT,
                 FRAME_B_WAIT,FRAME_C_WAIT,
                 FRAME_D_WAIT,FRAME_ERROR,FRAME_Data}FrameState;

char FIFOTX[50] = {0} ;
char FIFORX[50] = {0} ;
char recive;
static int flag = 0;
static int number = 0;
volatile Uint16 head_send = 0;           // Initialize FIFO head index
volatile Uint16 tail_send = 0;           // Initialize FIFO tail index
volatile Uint16 head_Recive = 0;           // Initialize FIFO head index
volatile Uint16 tail_Recive = 0;           // Initialize FIFO tail index

/*--------------------------Functions prototype-----------------------------------*/

void itoa(int value, char* str, int base);
void ClearFIFO(char *FIFO);
void writeFIFO(Uint16 data);
void initProtocole()
{
    ClearFIFO(FIFORX);
    ClearFIFO(FIFOTX);
    head_send = 0;
    tail_send = 0;
    flag = 0;
    number = 0;

}
/*--------------------------------The body of Send functions--------------------------*/
void SendOrderFrame(char *data)
{
    while(SciaRegs.SCIFFTX.bit.TXFFST < 16) // Check if TX FIFO is not full and FIFO is not empty
    {
        SciaRegs.SCITXBUF = data[tail_send];     // Send data from FIFO to TX buffer
        tail_send = (tail_send + 1) % head_send;      // Increment tail index with wrap-around
    }
}

void SendMessage(char *data,int length)
{
    int i;
    for(i = 0; i< length; i++)
    {
        SciaRegs.SCITXBUF = data[i];     // Send data from FIFO to TX buffer
    }
}

// Function to write data to FIFO
void writeFIFO(Uint16 data)
{
    FIFOTX[head_send] = data;                   // Write data to FIFO buffer
    head_send = head_send + 1;     // Increment head index with wrap-around
   // if(head_send >= 60 || data == '\n') head_send = 0;

}


Uint16 calculateChecksumArray(char *data) {
    Uint16 checksum = 0;

    int n =strlen(data);

  //  checksum += FIFOTX[0];


    for (i = 0; i < n; i++) {
        checksum += data[i];
    }

    return checksum;
}

void sendFrame(char* NumberOfData,const struct ProtocolStructure protocole)
{
    int i;
    // Send headers
  //  ClearFIFO(FIFOTX);


    int n  = sizeof(NumberOfData) / sizeof(char);




    writeFIFO(protocole.Header1);
    writeFIFO(protocole.Header2);
    writeFIFO(protocole.Header3);
    writeFIFO(protocole.Header4);
    writeFIFO(protocole.length);
    // Send data
    n  = strlen(protocole.data);

    for(i = 0; i < n ; i++)
    {
        writeFIFO(protocole.data[i]);
    }
    // Send checksum
   writeFIFO(protocole.Checksum);
    // Send end of frame
   writeFIFO(protocole.EndofFrame); // Assuming 0xFFFF as end of frame indicator

   //SendOrderFrame(FIFOTX);
}


///////////////////////////////////////////////////////////////////


void itoa(int value, char* str, int base)
{
    int i = 0;
    int is_negative = 0;


    if (value < 0 && base == 10)
    {
         is_negative = 1;
         value = -value;
    }

    do {
           int digit = value % base;
           str[i++] = (digit < 10) ? (digit + '0'): 0;
           value /= base;
        } while (value != 0);


        if (is_negative) {
            str[i++] = '-';
        }

        str[i] = '\0';
        int j = 0;
        int len = i;

    for (j = 0; j < len / 2; j++)
    {
            char temp = str[j];
            str[j] = str[len - j - 1];
            str[len - j - 1] = temp;
    }
}

void ClearFIFO(char *FIFO)
{
    int i;
    for(i = 0; i < 50;i++)
    {
          FIFO[i] = NULL;
    }
}

void ClearFIFO_(char *FIFO,int num)
{
    int i;
    for(i = 0; i < num;i++)
    {
          FIFO[i] = NULL;
    }
}

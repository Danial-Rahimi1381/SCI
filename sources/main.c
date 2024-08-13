#include "DSP28x_Project.h"
#include "DSP2833x_Sci.h"
#include "sci.h"
#include "protocole.h"



/*-------------------------------------------------------*/

int DataSize = 0;
volatile Uint16 rx_fifo_head = 0;
volatile Uint16 rx_fifo_tail = 0;
struct ProtocolStructure message;
struct ProtocolStructure ReciveMessage;
#define MAX_DATA_SIZE 100
Uint32 loop_cntr = 0;
char numdata[3] = {0};
int length = 0;
int Headers_flag = 0;
int Recive_Counter = 0;
int recive_count  = 0;

/*-------------------------------------------------------*/
void ReadFIFORXtwo();
void ReadFIFORX();
void ReadFIFORX1();
void ReadFIFORXthree();
void ReadFIFORXCombined();
void Read_Word_Frame();
interrupt void timer0_isr(void);
void RxReader();
void ReadRx();

int main(void)
{
    //  MemCopy(RamfuncsLoadStart,RamfuncsLoadEnd,RamfuncsRunStart);
   //    InitFlash();
     // Initialize system
     InitSysCtrl();
     // Initialize PIE control registers to their default state
     InitPieCtrl();
     InitPieVectTable();
     // Disable CPU interrupts and clear all CPU interrupt flags
     DINT;
     IER = 0x0000;
     IFR = 0x0000;
     // Initialize PIE vector table

     // Configure CPU timer 0
     InitCpuTimers();
     ConfigCpuTimer(&CpuTimer0, 150, 500); // 150MHz CPU, 1ms period
     // Set up interrupt handling for CPU timer 0
     EALLOW;
     PieVectTable.TINT0 = &timer0_isr;
     EDIS;
     // Enable CPU timer 0 interrupt
     PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
     // Enable global interrupts
     IER |= M_INT1;
     EINT;
     Init_Sci();
     initProtocole();
     message.Header1 =0xA1;message.Header2 =0xB2;message.Header3 = 0xC3;
     message.Header4 = 0xD4;message.length ='0';message.data = "Danial123456";
     message.Checksum = '3';message.EndofFrame = '4';
    // Start CPU tiemr 0
           StartCpuTimer0();
     ClearFIFO(FIFORX);
     ReciveMessage.Header1 = 0;
     ReciveMessage.Header2 = 0;
     ReciveMessage.Header3 = 0;
     ReciveMessage.Header4 = 0;
     ReciveMessage.length = 0;
    while(1){
}

}


__interrupt void timer0_isr(void)
{
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    loop_cntr++;
    if(loop_cntr == 4)
    {
     //  ReadRx();
    //    RxReader();
    }
    if(loop_cntr %  5 == 0 && number < 100)
    {
     //   loop_cntr = 0;
      //  SendOrderFrame(FIFOTX);
    }

}



/*

void RxReader()
{

   // int s;
    head_Recive = SciaRegs.SCIFFRX.bit.RXFFST;
    if(head_Recive > 0 )
    {
        for(i = head_Recive; i > 0 ; i--)
        {
            recive =SciaRegs.SCIRXBUF.all;

                ReciveMessage.Header1 = ReciveMessage.Header2;
                ReciveMessage.Header2 = ReciveMessage.Header3;
                ReciveMessage.Header3 = ReciveMessage.Header4;
                ReciveMessage.Header4 = recive;

                if((ReciveMessage.Header1 == 0xA1 && ReciveMessage.Header2 == 0xB2) &&
                 (ReciveMessage.Header3 == 0xC3 && ReciveMessage.Header4 == 0xD4))
                {
                    Headers_flag = 1;


                }


            else if(Headers_flag == 1)
            {
                if(tail_Recive == 0)
                {
                    ReciveMessage.length = recive;
                    tail_Recive++;
                }
                else if(tail_Recive > 0)
                {
                   FIFORX[tail_Recive - 1] = recive;
                   tail_Recive++;
                }
                if(FIFORX[tail_Recive - 1] == 0x81)
                {
                    for(s = 0; s < tail_Recive - 1 ;s++)
                    {
                        checksum += ReciveMessage.data[s];
                    }
                   // if(checksum == ReciveMessage.data[tail_Recive - 1])
                    number++;
                    tail_Recive = 0;
                    checksum = 0;
                    Headers_flag = 0;
                }
            }
        }
    }
}


*/

void RxReader()
{
    head_Recive = SciaRegs.SCIFFRX.bit.RXFFST;

    if(head_Recive > 0)
    {
        for(i = head_Recive; i > 0 ; i--)
        {
            Uint16 receivedData = SciaRegs.SCIRXBUF.all;

            if(Headers_flag != 1)
            {
                ReciveMessage.Header1 = ReciveMessage.Header2;
                ReciveMessage.Header2 = ReciveMessage.Header3;
                ReciveMessage.Header3 = ReciveMessage.Header4;
                ReciveMessage.Header4 = receivedData;
            }
            else if(Headers_flag == 1)
            {
                if(tail_Recive == 0)
                {
                    ReciveMessage.length = receivedData;
                    tail_Recive++;
                }
                else if(tail_Recive > 0 && tail_Recive < 30)
                {
                   FIFORX[tail_Recive - 1] = receivedData;
                   tail_Recive++;
                }
                if(FIFORX[19] == 0x81)
                {
                    // Perform checksum calculation and verification here if needed
                    tail_Recive = 0;
                    Headers_flag = 0;
                    checksum = 0;
                 //   ClearFIFO_(FIFORX, 50);
                }
            }

            if((ReciveMessage.Header1 == 0xA1 && ReciveMessage.Header2 == 0xB2) &&
               (ReciveMessage.Header3 == 0xC3 && ReciveMessage.Header4 == 0xD4))
            {
                Headers_flag = 1;
            }
        }
    }
}



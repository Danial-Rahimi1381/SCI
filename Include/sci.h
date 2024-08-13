/*
 * #define LSPCLK_FREQ     (150000000/4)          // Default value at reset
 * #define SCI_FREQ        9600U                         // Change the Bauds Speed
 * #define SCI_PRD         ((LSPCLK_FREQ/(SCI_FREQ*8))-1)  // Baud Rate LSB bit
 */


int i ;
int j = 0;
int s = 0;
void Init_Sci(void)
{
    // Initialize SCI-A
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.SCIAENCLK = 1;
     // Hardware settings for SCI pins
     GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1;   // Configure GPIO28 to SCIRXDA
     GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1;   // Configure GPIO29 to SCITXDA
     GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;  // Enable pull-up for GPIO28 (SCIRXDA)
     GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;  // Enable pull-up for GPIO29 (SCITXDA)
     GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (SCIRXDA)
//////////////////////////////////////////////////////////////////////////
     // Configure SCI control registers
     SciaRegs.SCICCR.all = 0x0007;  // 1 stop bit, No loopback
     SciaRegs.SCICTL1.all = 0x0003; // Enable TX, RX
     SciaRegs.SCICTL2.all = 0x0003;
     SciaRegs.SCICTL2.bit.TXINTENA = 1; // Enable TX interrupt
     SciaRegs.SCICTL2.bit.RXBKINTENA = 1; // Enable RX interrupt
     SciaRegs.SCICTL1.bit.RXENA = 1;
     // Enable transmit FIFO module
     SciaRegs.SCIFFTX.bit.SCIFFENA = 1;
     SciaRegs.SCIHBAUD = 0x0000;
     SciaRegs.SCILBAUD =0x27;// 0xE7; // 9600 baud rate
//////////////////////////////////////////////////////////////////////////
     SciaRegs.SCICTL1.all = 0x0023;  // Relinquish SCI from Reset
    // SciaRegs.SCICCR.bit.LOOPBKENA = 1; // Enable loopback mode
     EDIS;

}

void TS_DspDrv_SciTransChar(char p_u8Char)
{
    while(SciaRegs.SCICTL2.bit.TXRDY != 1);//Transmitter buffer register ready flag
    SciaRegs.SCICTL1.bit.TXWAKE = 1;
    SciaRegs.SCITXBUF =  p_u8Char;
    SciaRegs.SCICTL1.bit.TXWAKE = 0;

}

void TS_DspDrv_SciTransCharArray(char *p_u8Char)
{

    for(j = 0; j < 16; j++){

        SciaRegs.SCITXBUF =  p_u8Char[j];
    }
}


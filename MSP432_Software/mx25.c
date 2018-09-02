
#include "mx25.h"
#include "driverlib.h"
//#include "delay_u.h"



void writeEnable(void)
{

    while (!(SPI_isBusy(EUSCI_B0_BASE)));

   MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));
    SPI_transmitData(EUSCI_B0_BASE, CMD_WREN);
    //delay_ums(20);
    MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);

}

void writeDisable(void)
{


    while (!(SPI_isBusy(EUSCI_B0_BASE)));

       MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
        while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));
        SPI_transmitData(EUSCI_B0_BASE, CMD_WRDI);
        //delay_u(20);
        MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);



}

void resetEnable(void)
{

    while (!(SPI_isBusy(EUSCI_B0_BASE)));

       MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
        while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));
        SPI_transmitData(EUSCI_B0_BASE, CMD_RSTEN);
        //delay_u(20);
        MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);


}

void reset(void)
{

    while (!(SPI_isBusy(EUSCI_B0_BASE)));

       MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
        while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));
        SPI_transmitData(EUSCI_B0_BASE, CMD_RST);
        //delay_u(20);
        MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);


}

void pgmersSuspend(void)
{


    while (!(SPI_isBusy(EUSCI_B0_BASE)));

           MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
            while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));
            SPI_transmitData(EUSCI_B0_BASE, CMD_PESUS);
            //delay_u(20);
            MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);

}

void pgmersResume(void)
{


    while (!(SPI_isBusy(EUSCI_B0_BASE)));

               MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
                while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));
                SPI_transmitData(EUSCI_B0_BASE, CMD_PERES);
                //delay_u(20);
                MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);



}

void deepPowerdown(void)
{

    while (!(SPI_isBusy(EUSCI_B0_BASE)));

                 MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
                  while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));
                  SPI_transmitData(EUSCI_B0_BASE, CMD_DP);
                  //delay_u(20);
                  MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);

}

void setBurstlength(void)
{

    while (!(SPI_isBusy(EUSCI_B0_BASE)));

                       MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
                        while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));
                        SPI_transmitData(EUSCI_B0_BASE, CMD_SBL);
                        //delay_u(20);
                        MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);

}

void releaseReadenhaced(void)
{


    while (!(SPI_isBusy(EUSCI_B0_BASE)));

                   MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
                    while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));
                    SPI_transmitData(EUSCI_B0_BASE, CMD_RRE);
                    //delay_u(20);
                    MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);


}


void enterSecureOTP(void)
{

    while (!(SPI_isBusy(EUSCI_B0_BASE)));

                       MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
                        while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));
                        SPI_transmitData(EUSCI_B0_BASE, CMD_ENSO);
                        //delay_u(20);
                        MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);

}

void exitSecureOTP(void)
{


    while (!(SPI_isBusy(EUSCI_B0_BASE)));

                       MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
                        while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));
                        SPI_transmitData(EUSCI_B0_BASE, CMD_EXSO);
                        //delay_u(20);
                        MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);

}

uint8_t readStatus(void)
{
    uint8_t data ;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_RDSR) ;
    data = SPI_receiveData(EUSCI_B0_BASE) ;                     // dummy
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    return( data ) ;
}

uint32_t readConfig(void)
{
    uint8_t data;
    uint32_t config32 = 0 ;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_RDCR) ;                         // send 15h
    data= SPI_receiveData(EUSCI_B0_BASE)  ;                     // dumy to get 1st Byte out
    config32 = config32 | data ;                    // put in 32b reg
    data= SPI_receiveData(EUSCI_B0_BASE) ;                      // dummy to get 2nd Byte out
    config32 = (config32 << 8) | data ;             // shift and put in reg
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    return( config32 ) ;
}

uint8_t readSecurity(void)
{
    uint8_t data ;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_RDSCUR) ;                       // send 2Bh
    data = SPI_receiveData(EUSCI_B0_BASE) ;                     // dummy
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    return( data ) ;
}

uint32_t readID(void)
{
    uint8_t data;
    uint32_t data32 = 0 ;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_RDID) ;                         // send 9Fh
    data= SPI_receiveData(EUSCI_B0_BASE)  ;                     // dumy to get 1st Byte out
    data32 = data32 | data ;                        // put in 32b reg
    data= SPI_receiveData(EUSCI_B0_BASE) ;                      // dummy to get 2nd Byte out
    data32 = (data32 << 8) | data ;                 // shift and put in reg
    data= SPI_receiveData(EUSCI_B0_BASE)  ;                     // dummy to get 3rd Byte out
    data32 = (data32 << 8) | data ;                 // shift again and put in reg
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    return( data32 ) ;










}

uint32_t readREMS(void)
{
    uint8_t data;
    uint32_t data32 = 0 ;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_REMS) ;                         // send 90h
    SPI_transmitData(EUSCI_B0_BASE,DUMMY) ;                            // send DUMMY1
    SPI_transmitData(EUSCI_B0_BASE,DUMMY) ;                            // send DUMMY2
    SPI_transmitData(EUSCI_B0_BASE,0) ;                                // send address=0x00 to get Manu ID 1st.
    data= SPI_receiveData(EUSCI_B0_BASE)  ;                     // dumy to get Manufacturer ID= C2h out
    data32 = data32 | data ;                        // put in 32b reg
    data= SPI_receiveData(EUSCI_B0_BASE) ;                      // dummy to get 2nd Byte = Device ID out
    data32 = (data32 << 8) | data ;                 // shift and put in reg
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    return( data32 ) ;
}

uint8_t readRES(void)
{
    uint8_t data;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_RES) ;                          // send ABh
    SPI_transmitData(EUSCI_B0_BASE,DUMMY) ;                            // send DUMMY1
    SPI_transmitData(EUSCI_B0_BASE,DUMMY) ;                            // send DUMMY2
    SPI_transmitData(EUSCI_B0_BASE,DUMMY) ;                            // send DUMMY3
    data= SPI_receiveData(EUSCI_B0_BASE)  ;                     // dumy to get Electronic Sig. out
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    return( data ) ;
}

void programPage(int addr, uint8_t *data, int numData)
{
    int i ;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_PP) ;                           // Program Page 02h
    SPI_transmitData(EUSCI_B0_BASE,(addr >> 16)&0xFF) ;                // adr 23:16
    SPI_transmitData(EUSCI_B0_BASE,(addr >>  8)&0xFF) ;                // adr 15:8
    SPI_transmitData(EUSCI_B0_BASE,addr & 0xFF) ;                      // adr 7:0
    for (i = 0 ; i < numData ; i++ ) {              // data = 00, 01, 02, .. to FEh, FFh = all 256 Bytes in 1 page.
        SPI_transmitData(EUSCI_B0_BASE,data[i]) ;
    }
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    // poll in main
}

void writeStatusreg(int addr)            // Write SR cmd 01h + 3B data
{
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_WRSR) ;                         // Write SR cmd 01h
    SPI_transmitData(EUSCI_B0_BASE,(addr >> 16)&0xFF) ;                // address
    SPI_transmitData(EUSCI_B0_BASE,(addr >>  8)&0xFF) ;
    SPI_transmitData(EUSCI_B0_BASE,addr & 0xFF) ;
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
}

void writeSecurityreg(int addr)          // WRSCUR cmd 2Fh + 1B data
{
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_WRSCUR) ;                         // Write SR cmd 01h
    SPI_transmitData(EUSCI_B0_BASE,addr & 0xFF) ;
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
}

void blockErase(int addr)                // 64KB Block Erase
{
    int i;
    uint8_t data[3] ;
    data[0] = (addr >> 16) & 0xFF ;
    data[1] = (addr >> 8) & 0xFF ;
    data[2] = (addr & 0xFF) ;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_BE) ;
    for ( i = 0 ; i < 3 ; i++ ) {                // Address setting
        SPI_transmitData(EUSCI_B0_BASE,data[i]) ;
    }
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    // poll in main
}

void blockErase32KB(int addr)            // 32KB Block Erase
{
    int i;
    uint8_t data[3] ;
    data[0] = (addr >> 16) & 0xFF ;
    data[1] = (addr >> 8) & 0xFF ;
    data[2] = (addr & 0xFF) ;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_32KBE) ;
    for (i = 0 ; i < 3 ; i++ ) {                // Address Setting
        SPI_transmitData(EUSCI_B0_BASE,data[i]) ;
    }
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    // poll in main
}

void sectorErase(int addr)               //  4KB Sector Erase
{
    int i;
    uint8_t data[3] ;
    data[0] = (addr >> 16) & 0xFF ;
    data[1] = (addr >> 8) & 0xFF ;
    data[2] = (addr & 0xFF) ;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_SE) ;
    for ( i = 0 ; i < 3 ; i++ ) {                // Address Setting
        SPI_transmitData(EUSCI_B0_BASE,data[i]) ;
    }
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    // poll in main
}

void chipErase(void)                     // Chip Erase
{
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_CE) ;
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    // poll in main
}

uint8_t read8(int addr)                  // Single Byte Read
{
    uint8_t data ;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_READ) ;                         // send 03h
    SPI_transmitData(EUSCI_B0_BASE,(addr >> 16)&0xFF) ;
    SPI_transmitData(EUSCI_B0_BASE,(addr >>  8)&0xFF) ;
    SPI_transmitData(EUSCI_B0_BASE,addr & 0xFF) ;
    data = SPI_receiveData(EUSCI_B0_BASE) ;                     // write data is dummy
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    return( data ) ;                                // return 1 byte
}

uint8_t readSFDP(int addr)               // Read SFDP
{
    uint8_t data ;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_RDSFDP) ;                       // send cmd 5Ah
    SPI_transmitData(EUSCI_B0_BASE,(addr >> 16)&0xFF) ;                // address[23:16]
    SPI_transmitData(EUSCI_B0_BASE,(addr >>  8)&0xFF) ;                // address[15:8]
    SPI_transmitData(EUSCI_B0_BASE,addr & 0xFF) ;                      // address[7:0]
    SPI_transmitData(EUSCI_B0_BASE,DUMMY) ;                            // dummy cycle
    data = SPI_receiveData(EUSCI_B0_BASE) ;                     // return 1 byte
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    return( data ) ;
}

uint8_t readFREAD(int addr)              // x1 Fast Read Data Byte
{
    uint8_t data ;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_FREAD) ;                        // send cmd 0BH
    SPI_transmitData(EUSCI_B0_BASE,(addr >> 16)&0xFF) ;                // address[23:16]
    SPI_transmitData(EUSCI_B0_BASE,(addr >>  8)&0xFF) ;                // address[15:8]
    SPI_transmitData(EUSCI_B0_BASE,addr & 0xFF) ;                      // address[7:0]
    SPI_transmitData(EUSCI_B0_BASE,DUMMY) ;                            // dummy cycle
    data = SPI_receiveData(EUSCI_B0_BASE) ;                     // return 1 byte
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
    return( data ) ;
}


void readNBytes(int addr, uint8_t *data, int nBytes) // read sequential n bytes
{
    int i;
  MAP_GPIO_setOutputLowOnPin (GPIO_PORT_P5, GPIO_PIN0);
    SPI_transmitData(EUSCI_B0_BASE,CMD_READ) ;                         // send 03h
    SPI_transmitData(EUSCI_B0_BASE,(addr >> 16)&0xFF) ;
    SPI_transmitData(EUSCI_B0_BASE,(addr >>  8)&0xFF) ;
    SPI_transmitData(EUSCI_B0_BASE,addr & 0xFF) ;
    for (i = 0 ; i < nBytes ; i++ ) {              // data: sequential data bytes
        data[i] = SPI_receiveData(EUSCI_B0_BASE) ;
    }
     MAP_GPIO_setOutputHighOnPin (GPIO_PORT_P5, GPIO_PIN0);
}

/*
void EUSCIB0_IRQHandler(void)
{
    uint32_t status = SPI_getEnabledInterruptStatus(EUSCI_B0_BASE);
    uint32_t jj;

    SPI_clearInterruptFlag(EUSCI_B0_BASE, status);

    if(status & EUSCI_B_SPI_RECEIVE_INTERRUPT)
    {

        while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));

        RXData = SPI_receiveData(EUSCI_B0_BASE);


        //delay_u(20);
    }

}*/



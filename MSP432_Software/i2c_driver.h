

#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_


typedef enum {
    eUSCI_IDLE = 0,
    eUSCI_SUCCESS = 0,
    eUSCI_BUSY = 1,
    eUSCI_NACK = 2,
    eUSCI_STOP,
    eUSCI_START
} eUSCI_status;

uint8_t TXData[2];
static uint8_t RXData[10];
static volatile uint32_t xferIndex;
static volatile bool stopSent;

extern void initI2C(void);
extern bool writeI2C(uint8_t ui8Addr, uint8_t ui8Reg, uint8_t *Data, uint8_t ui8ByteCount);
extern bool readI2C(uint8_t ui8Addr, uint8_t ui8Reg, uint8_t *Data, uint8_t ui8ByteCount);
//extern bool readBurstI2C(uint8_t ui8Addr, uint8_t ui8Reg, uint8_t *Data, uint32_t ui32ByteCount);




#endif /* I2C_DRIVER_H_ */


#ifndef MX25_H_
#define MX25_H_

#include <stdbool.h>
#include <stdint.h>




 #define MX25R_PAGES 0x7FFF // total memory size - Addresses 0x7FFFFF

#define DUMMY          0x00 // Dummy byte which can be changed to any value

#define CMD_READ      0x03  // x1 Normal Read Data Byte
#define CMD_FREAD     0x0B  // x1 Fast Read Data Byte
#define CMD_2READ     0xBB  // x2 2READ
#define CMD_DREAD     0x3B  // x2 DREAD
#define CMD_4READ     0xEB  // x4 4READ
#define CMD_QREAD     0x6B  // x4 QREAD
#define CMD_PP        0x02  // Page Program
#define CMD_4PP       0x38  // x4 PP
#define CMD_SE        0x20  // 4KB Sector Erase
#define CMD_32KBE     0x52  // 32KB Block Erase
#define CMD_BE        0xD8  // 64KB Block Erase
#define CMD_CE        0xC7  // Chip Erase
#define CMD_RDSFDP    0x5A  // Read SFDP
#define CMD_WREN      0x06  // Write Enable
#define CMD_WRDI      0x04  // Write Disable
#define CMD_RDSR      0x05  // Read Status Register
#define CMD_RDCR      0x15  // Read Configuration Register
#define CMD_WRSR      0x01  // Write Status Register
#define CMD_PESUS     0xB0  // Program/Erase Suspend
#define CMD_PERES     0x30  // Program/Erase Resume
#define CMD_DP        0xB9  // Enter Deep Power Down
#define CMD_SBL       0xC0  // Set Burst Length
#define CMD_RDID      0x9F  // Read Manufacturer and JDEC Device ID
#define CMD_REMS      0x90  // Read Electronic Manufacturer and Device ID
#define CMD_RES       0xAB  // Read Electronic ID
#define CMD_ENSO      0xB1  // Enter Secure OTP
#define CMD_EXSO      0xC1  // Exit Secure OTP
#define CMD_RDSCUR    0x2B  // Read Security Register
#define CMD_WRSCUR    0x2F  // Write Security Register
#define CMD_NOP       0x00  // No Operation
#define CMD_RSTEN     0x66  // Reset Enable
#define CMD_RST       0x99  // Reset
#define CMD_RRE       0xFF  // Release Read Enhanced Mode




 int _mode ;


  void writeEnable(void) ;


  void writeDisable(void) ;


  void resetEnable(void) ;


  void reset(void) ;


  void pgmersSuspend(void) ;


  void pgmersResume(void) ;


  void deepPowerdown(void) ;


  void setBurstlength(void) ;


  void releaseReadenhaced(void) ;


  void enterSecureOTP(void) ;


  void exitSecureOTP(void) ;

  void chipErase(void) ;


  void writeStatusreg(int addr) ;


  void writeSecurityreg(int addr) ;


  void programPage(int addr, uint8_t *data, int numData) ;


  void sectorErase(int addr) ;


  void blockErase(int addr) ;

  void blockErase32KB(int addr) ;


  uint8_t readStatus(void) ;


  uint8_t readSecurity(void) ;


  uint32_t readID(void) ;


  uint32_t readREMS(void) ;

/** Read Electronic ID
 *
 * @returns uint8_t Device ID
 */
  uint8_t readRES(void) ;

/** Read Configuration Register
 *
 * @returns uint32_t configuration register value
 */
  uint32_t readConfig(void) ;
  uint8_t readSFDP(int addr) ;
  uint8_t readFREAD(int addr) ;
  uint8_t read8(int addr) ;
  void write8(int addr, uint8_t data) ;
  // read sequential n bytes
  void readNBytes(int addr, uint8_t *data, int nBytes);




#endif /* MX25_H_ */

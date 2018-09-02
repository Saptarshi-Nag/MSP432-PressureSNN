//#include <delay_u.h>
#include <stdint.h>
#include <stdbool.h>
#include "ms5837.h"
#include "i2c_driver.h"
#include "driverlib.h"


void MS5837Init(void)
{
    MS5837Reset();
    MS5837ReadProm();
    return;
}


void MS5837Reset(void)
{

    if ( writeI2C( device_address,  ms5837_reset, 0,1 ) );
    //delay_u(20);
}

// read the sensor calibration data from rom
void MS5837ReadProm(void)
{
    int i,j;
    for (i=0; i<8; i++) {
        j = i;

        if ( writeI2C( device_address, ms5837_PROMread + (j<<1),0 , 1 ) );
        if ( readI2C( device_address, 0, ms5837_rx_data, 2 ) );
        C[i]   = ms5837_rx_data[1] + (ms5837_rx_data[0]<<8);
    }
}

// Start the sensor pressure conversion
void MS5837ConvertD1(void)
{

    if ( writeI2C( device_address,  ms5837_convD1,0, 1 ) );
}

// Start the sensor temperature conversion
void  MS5837ConvertD2(void)
{

    if ( writeI2C( device_address,  ms5837_convD2 ,0, 1 ) );
}


int32_t MS5837ReadADC(void)
{
    int32_t adc;
    //delay_u(150);

    if ( writeI2C( device_address, ms5837_ADCread,0 , 1 ) );
    if ( readI2C( device_address,0,  ms5837_rx_data, 3 ) );
    adc = ms5837_rx_data[2] + (ms5837_rx_data[1]<<8) + (ms5837_rx_data[0]<<16);

    return (adc);
}


float MS5837_Pressure (void)
{
    return P_MS5837;
}


float MS5837_Temperature (void)
{
    return T_MS5837;
}


void readSensor_MS5837(void)
{
    int32_t dT, temp;
    int64_t OFF, SENS, press;


    int32_t SENSi = 0;
    int32_t OFFi = 0;
    int32_t Ti = 0;
    int64_t OFF_2ORDER = 0;
    int64_t SENS_2ORDER = 0;




    MS5837ConvertD1();             // start pressure conversion
    D1 = MS5837ReadADC();        // read the pressure value
    MS5837ConvertD2();             // start temperature conversion
    D2 = MS5837ReadADC();         // read the temperature value


    dT       = D2 - ((uint32_t)C[5]* 256);
    OFF      = (int64_t)C[2] * (1<<17) + ((int64_t)dT * (int64_t)C[4]) / (1<<6);
    SENS     = (int64_t)C[1] * (1<<16) + ((int64_t)dT * (int64_t)C[3]) / (1<<7);

    temp     = 2000 + ((int64_t)dT * C[6]) / (1<<23);
    press    = (((int64_t)D1 * SENS) / (1<<21) - OFF) / (1<<15);

    if((temp/100)<20){         //Low temp

           Ti = (11*dT*dT)/(34359738368LL);
            OFFi = (31*(temp-2000)*(temp-2000))/8;
            SENSi = (63*(temp-2000)*(temp-2000))/32;
    }

    OFF_2ORDER = OFF-OFFi;           //Calculate pressure and temp second order
    SENS_2ORDER = SENS-SENSi;

    temp = (temp-Ti);
    press = (((D1*SENS_2ORDER)/2097152l-OFF_2ORDER)/32768l);

    T_MS5837 = (float) temp / 100.0f;                 // result of temperature in deg C in this var
    P_MS5837 = (float) press / 100.0f;                 // result of pressure in mBar in this var

}





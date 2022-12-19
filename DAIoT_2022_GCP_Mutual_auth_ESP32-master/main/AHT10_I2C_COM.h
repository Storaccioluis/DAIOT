/*      ESP32--I2C--COMUNICATION
     SDA--------------> pin xx
     SCL--------------> pin xx

*/
#ifndef __AHT10_I2C_COM_H
#define __AHT10_I2C_COM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "esp_log.h"
#include "time.h"
#include "I2C_DRIVER.h"

#define AHT10_TIMEOUT 0x64 // 100ms



#define AHT10_ADDR 0x38              /*!< Slave address of the AHT10 sensor */
#define AHT10_WHO_AM_I_REG_ADDR 0xE1 /*!< Register addresses of the "who am I" register */
#define AHT10_READ_REG 0x33          /*!< Register addresses of the "who am I" register */

#define AHT10_REGISTER_WRITE 0xAC
#define AHT10_READ_REG1 0x00

#define I2C_PERIOD 100

esp_err_t i2c_master_init(void);
uint32_t aht10_read(uint8_t *);
// static void aht10_write(uint8_t *buffer);

#endif /* __AHT10_I2C_COM_H */
/**
 * @file AHT10_I2C_COM.c
 * @author Storaccio Luis Sebastián (storaccioluis@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "AHT10_I2C_COM.h"



uint32_t aht10_read(uint8_t *dbuffer)
{
    uint32_t ret = 0;
    uint8_t len = 6;
    uint8_t write_buf[3] = {AHT10_REGISTER_WRITE, AHT10_READ_REG, AHT10_READ_REG1};
    uint8_t read_buf[1] = {AHT10_READ_REG1};
    ret = i2c_master_write_to_device(I2C_MASTER_NUM, AHT10_ADDR, write_buf, sizeof(write_buf), I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS);
    if (ret == -1)
    {
        return ret;
    }
    ret = i2c_master_write_read_device(I2C_MASTER_NUM, AHT10_ADDR, read_buf, 1, dbuffer, len, 1000);
    return ret;
}
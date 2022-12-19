
/**
 * @brief Definition typedef of structures for receiver humidity's data.
 *
 */
#ifndef __AHT10_H
#define __AHT10_H

#include "stdbool.h"
#include <stdio.h>
#include "AHT10_I2C_COM.h"

#define TAM_DATA_TEMP 10
#define TAM_DATA_HUM 10

static bool init_array = false;

typedef struct
{
    float OldTemperature;
    float ActualTemperature;
    float PromTemperature;
    float ArrayDataTemp[TAM_DATA_TEMP];
    uint8_t index;
    bool TemperatureRise;
    bool TemperatureFall;
    // void (*FunctionReadTemperature)(float *address,uint32_t *status); //llamar a header.h que contanga la función para leer datos del sensor
    uint32_t StatusRead;
} dataTemperature_t;

/**
 * @brief Definition typedef of structures for receiver humidity's data.
 *
 */

typedef struct
{
    uint32_t OldHumidity;
    uint32_t ActualHumidity;
    uint32_t PromHumidity;
    uint32_t ArrayDataHum[TAM_DATA_HUM];
    uint8_t index;
    bool HumidityRise;
    bool HumidityFall;
    // void (*FunctionReadHumidity)(float *address,uint32_t *status);  //llamar a header.h que contanga la función para leer datos del sensor
    uint32_t StatusRead;
} dataHumidity_t;

/**
 * @brief Declaration of function that read temperature's value
 *
 * @param address
 * @param dir_buff
 * @param bytes
 * @return uint8_t: code return of function.
 */
/*void *FunctionReadTemperature (uint8_t address,*uint32_t dir_buff,uint32_t bytes);
 */

uint8_t aht10Init(void);

uint8_t getDataHumidity(dataHumidity_t *);

uint8_t getDataTemperature(dataTemperature_t *);

void read_led_status(uint8_t *);

#endif /* __AHT10_H */
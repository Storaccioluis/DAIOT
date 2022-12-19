
#include <AHT10.h>

void read_led_status(uint8_t *status)
{
    *status = !(*status);
}

/**
 * Funcion sensor temperatura
 **/

static uint8_t buffer_read[6] = {0U};

uint8_t aht10Init()
{
    // init aht10 registers.
    // return 1;   //init
    return -1; // No init
}

uint8_t getDataTemperature(dataTemperature_t *dataTemperature_t)
{
    float temp = 0;
    float acum = 0;
    aht10_read(&buffer_read[0]);
    // check data receive                       %%%%%%%%%%%%%%%%
    temp = ((buffer_read[3] & 0x0F) << 16) | (buffer_read[4] << 8) | buffer_read[5];
    temp = ((temp * 200) / 1048576) - 50;
    dataTemperature_t->OldTemperature = dataTemperature_t->ActualTemperature;
    dataTemperature_t->ActualTemperature = temp;
    dataTemperature_t->ArrayDataTemp[dataTemperature_t->index] = temp;
    dataTemperature_t->index++;

    if (!init_array)
    {
        for (uint8_t j = 0; j < TAM_DATA_TEMP; j++)
        {
            dataTemperature_t->ArrayDataTemp[j] = temp;
        }
        dataTemperature_t->PromTemperature = temp;
        init_array = true;
    }

    if (TAM_DATA_TEMP <= dataTemperature_t->index)
    {
        dataTemperature_t->index = 0u;
        for (uint8_t i = 0; i < TAM_DATA_TEMP; i++)
        {
            acum = acum + dataTemperature_t->ArrayDataTemp[i];
        }
        dataTemperature_t->PromTemperature = acum / TAM_DATA_TEMP;
    }

    if (dataTemperature_t->ActualTemperature > dataTemperature_t->OldTemperature)
    {
        // rise temperature
        dataTemperature_t->TemperatureRise = true;
        dataTemperature_t->TemperatureFall = false;
    }
    else
    {
        if (dataTemperature_t->ActualTemperature < dataTemperature_t->OldTemperature)
        {
            dataTemperature_t->TemperatureFall = true;
            dataTemperature_t->TemperatureRise = false;
        }
        else
        {
            dataTemperature_t->TemperatureFall = false;
            dataTemperature_t->TemperatureRise = false;
        }
    }
    dataTemperature_t->StatusRead = 1; // Status read OK

    return 1;
}

uint8_t getDataHumidity (dataHumidity_t *dataHumidityHandler)
{   uint32_t hum=0;
    uint32_t acum=0;
    aht10_read(&buffer_read[0]);
    hum =((((buffer_read[1] << 16) | (buffer_read[2] << 8) |buffer_read[3]) >> 4) * 100 / 1048576);
     //check data receive                       %%%%%%%%%%%%%%%%
     //caclculate hum                           %%%%%%%%%%%%%%%%
    dataHumidityHandler->OldHumidity=dataHumidityHandler->ActualHumidity;
    dataHumidityHandler->ActualHumidity=hum;
    dataHumidityHandler->ArrayDataHum[dataHumidityHandler->index]=hum;
    dataHumidityHandler->index++;
     if(TAM_DATA_HUM<=dataHumidityHandler->index)
     {
        dataHumidityHandler->index=0u;
        for(uint8_t i=0;i<TAM_DATA_HUM;i++)
            {  acum=acum+dataHumidityHandler->ArrayDataHum[i];

            } 
             dataHumidityHandler->PromHumidity=acum/TAM_DATA_HUM;   

     }

     if(dataHumidityHandler->ActualHumidity>dataHumidityHandler->OldHumidity)
       {
        //rise humidity
        dataHumidityHandler->HumidityRise=true;
        dataHumidityHandler->HumidityFall=false;
       }
     else{ if(dataHumidityHandler->ActualHumidity<dataHumidityHandler->OldHumidity)  
                {
                     dataHumidityHandler->HumidityFall=true;
                     dataHumidityHandler->HumidityRise=false;
                }
              else{ 
                     dataHumidityHandler->HumidityFall=false;
                     dataHumidityHandler->HumidityRise=false;
                     }
         }
      dataHumidityHandler->StatusRead=1; //Status read OK

     return 1; 
    
}

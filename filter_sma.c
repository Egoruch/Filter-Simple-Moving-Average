#include "filter_sma.h"

  uint16_t Filter_SMA(uint16_t For_Filtration)
{
    /* Load new value */
    Filter_Buffer[Filter_SMA_Order-1] = For_Filtration;
 
    /* For the output value */
    uint32_t Output = 0;
 
    /* The sum of the values */
        for(uint8_t i = 0; i < Filter_SMA_Order; i++)
    {
        Output += Filter_Buffer[i];
    }
 
    /* Divide by the number of elements */
    Output /= Filter_SMA_Order;
 
    /* Left Shift */
    for(uint8_t i = 0; i < Filter_SMA_Order; i++){
        Filter_Buffer[i] = Filter_Buffer[i+1];
    }
 
    /* Return filtered value */
    return (uint16_t) Output;
}

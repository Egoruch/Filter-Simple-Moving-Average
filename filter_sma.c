#include "filter_sma.h"

uint16_t Filter_Buffer[FILTER_SMA_ORDER] = {0,};

/**
  * @brief Simple Moving Average (SMA) filter.
  * @note Before use define filter order.
  * @param[in] Input raw (unfiltered) value.
  * @retval Return filtered data.
  */
	uint16_t Filter_SMA(uint16_t For_Filtered)
{
	/* Load new value */
	Filter_Buffer[FILTER_SMA_ORDER - 1] = For_Filtered;
	
	/* For output value */
	uint32_t Output = 0;
	
	/* Sum */
	for(uint8_t i = 0; i < FILTER_SMA_ORDER; i++)
	{
		Output += Filter_Buffer[i];
	}
	
	/* Divide */
	Output /= FILTER_SMA_ORDER;
	
	/* Left Shift */
	for(uint8_t i = 0; i < FILTER_SMA_ORDER; i++)
				Filter_Buffer[i] = Filter_Buffer[i+1];

	/* Return filtered value */
	return (uint16_t) Output;
	
}

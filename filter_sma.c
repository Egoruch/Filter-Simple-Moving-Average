#include "filter_sma.h"

/* Structure BEGIN */
sma_s SMA[SMA_QUANTITY];
/* Structure END */

/**
  * @brief Simple Moving Average (SMA) filter
  * @note Before use define filter order
  * @param Filter name (see enumeration), Input raw (unfiltered) uint16_t value
  * @retval Return filtered data
  */
	uint16_t Filter_SMA(sma_name_e name, uint16_t input_value)
{
	/* Subtract the oldest stored value */
	SMA[name].Sum -= SMA[name].Buffer[SMA[name].Index];

	/* Add new value to the sum */
	SMA[name].Sum += input_value;

	/* Store current value */
	SMA[name].Buffer[SMA[name].Index] = input_value;

	/* Increment index */
	SMA[name].Index++;

	/* If index bigger is equal of bigger than filter order (window) -> nullify it */
	if (SMA[name].Index >= FILTER_SMA_ORDER){
		SMA[name].Index = 0;
	}

	/* Divide sum by filter order */
	uint16_t output_value =  SMA[name].Sum/FILTER_SMA_ORDER;

	/* Return filtered data */
	return output_value;
}

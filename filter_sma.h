#ifndef INC_SMA_H_
#define INC_SMA_H_

#include "main.h"

/* Choose filter order */

#define FILTER_SMA_ORDER 16

/* Enumerations BEGIN */

typedef enum FilterName{
	SMA_1 = 0,
	SMA_2,

	SMA_QUANTITY
}sma_name_e;

/* Enumerations END */

/* Each filter should have this set of variables */
typedef struct SMA_Params{
	uint32_t Sum;
	uint8_t Index;
	uint16_t Buffer[FILTER_SMA_ORDER];
}sma_s;

/* Prototype BEGIN */

/**
  * @brief Simple Moving Average (SMA) filter
  * @note Before use define filter order
  * @param Filter name (enumeration), Input raw (unfiltered) uint16_t value
  * @retval Return filtered data
  */
uint16_t Filter_SMA(sma_name_e num, uint16_t For_Filtered);

/* Prototype END */

#endif /* INC_SMA_H_ */

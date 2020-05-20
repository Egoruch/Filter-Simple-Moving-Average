#include "main.h"

/**
  * @brief Simple Moving Average (SMA) filter.
  * @note Before use define filter order.
  * @param[in] Input raw (unfiltered) value.
  * @retval Return filtered data.
  */

#define Filter_SMA_Order 6 // Choose filter order

uint16_t Filter_Buffer[Filter_SMA_Order] = {0,};

uint16_t Filter_SMA(uint16_t To_Filtered);

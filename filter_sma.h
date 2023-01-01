#ifndef INC_SMA_H_
#define INC_SMA_H_

#include "main.h"

/* Choose filter order */
#define FILTER_SMA_ORDER 12

/**
  * @brief Simple Moving Average (SMA) filter.
  * @note Before use define filter order.
  * @param[in] Input raw (unfiltered) value.
  * @retval Return filtered data.
  */
uint16_t Filter_SMA(uint16_t For_Filtered);

#endif /* INC_SMA_H_ */

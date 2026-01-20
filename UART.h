// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

/**
 *  @file
 *
 *  @brief Platform UART Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_UART UART
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_UART_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef UART_H_
    #define UART_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include <stdint.h>

    #include "UART_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief UART Operation Status
     *
     *  @enum UART_Status_t
     */
    typedef enum UART_Status
    {
        UART_Status_Success = 0,     ///< Success
        UART_Status_ArgumentInvalid, ///< Argument Invalid
        UART_Status_NotSupported,    ///< Not Supported
        UART_Status_Error,           ///< General Error
        UART_Status_Busy,            ///< Busy
        UART_Status_Timeout,         ///< Timeout
    } UART_Status_t;

    /**
     *  @brief UART Data Type
     */
    typedef uint8_t UART_Data_t;

    /**
     *  @brief UART Data Length Type
     */
    typedef uint32_t UART_DataLength_t;

    /**
     *  @brief UART On-Complete Callback
     *
     *  @param[in] UARTx   Instance
     *  @param[in] Status Execution status
     *
     *  @return UART_Status_t
     */
    typedef UART_Status_t ( *UART_CallbackOnComplete_t )( UART_t UARTx, UART_Status_t Status );

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize UART peripheral
     *
     *  @note MUST BE called before using any UART API
     *
     *  @param[in] UARTx Peripheral
     *
     *  @return UART_Status_t
     */
    UART_Status_t UART_Initialize( UART_t UARTx );

    /**
     *  @brief Cycle UART peripheral
     *
     *  @param[in] UARTx Peripheral
     *
     *  @return UART_Status_t
     */
    UART_Status_t UART_Cycle( UART_t UARTx );

    /**
     *  @brief De-Initialize UART peripheral
     *
     *  @param[in] UARTx Peripheral
     *
     *  @return UART_Status_t
     */
    UART_Status_t UART_DeInitialize( UART_t UARTx );

    /**
     *  @brief Set callback for on-complete of UART instance
     *
     *  @param[in] UARTx     Instance
     *  @param[in] Callback On-complete callback
     *
     *  @return UART_Status_t
     */
    UART_Status_t UART_SetCallbackOnComplete( UART_t UARTx, UART_CallbackOnComplete_t Callback );

    /**
     *  @brief Write data to UART peripheral
     *
     *  @param[in] UARTx      Peripheral
     *  @param[in] Data       Data buffer
     *  @param[in] DataLength Length of data buffer
     *
     *  @return UART_Status_t
     */
    UART_Status_t UART_Write( UART_t UARTx, UART_Data_t * Data, UART_DataLength_t DataLength );

    /**
     *  @brief Read data from UART peripheral
     *
     *  @param[in] UARTx      Peripheral
     *  @param[in] Data       Data buffer
     *  @param[in] DataLength Length of data buffer
     *
     *  @return UART_Status_t
     */
    UART_Status_t UART_Read( UART_t UARTx, UART_Data_t * Data, UART_DataLength_t DataLength );

    // TODO More APIs

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char UART_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* UART_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################

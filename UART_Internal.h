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

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef UART_INTERNAL_H_
    #define UART_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "UART_Port.h"
    #include "driver/STM32L496VGT6P/UART_STM32L496VGT6P.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef UART_TIM
        #define UART_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef UART_LOG
        #define UART_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define UART_NAME       "UART"
    #define UART_LOG_PREFIX UTIL_StringConcatenateConstant( UART_NAME, "> " )

    #ifdef DEBUG
        #define UART_Raw( Level, Format, ... ) LOG_Raw( UART_LOG, Level, Format, ##__VA_ARGS__ )
        #define UART_Trace( Format, ... )      LOG_Trace( UART_LOG, UTIL_StringConcatenateConstant( UART_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define UART_Debug( Format, ... )      LOG_Debug( UART_LOG, UTIL_StringConcatenateConstant( UART_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define UART_Info( Format, ... )       LOG_Info( UART_LOG, UTIL_StringConcatenateConstant( UART_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define UART_Warning( Format, ... )    LOG_Warning( UART_LOG, UTIL_StringConcatenateConstant( UART_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define UART_Error( Format, ... )      LOG_Error( UART_LOG, UTIL_StringConcatenateConstant( UART_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define UART_Fatal( Format, ... )      LOG_Fatal( UART_LOG, UTIL_StringConcatenateConstant( UART_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define UART_Raw( Level, Format, ... )
        #define UART_Trace( Format, ... )
        #define UART_Debug( Format, ... )
        #define UART_Info( Format, ... )
        #define UART_Warning( Format, ... )
        #define UART_Error( Format, ... )
        #define UART_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef enum UART_Type
    {
        UART_Type_Unknown = 0,
        UART_Type_Null,
        UART_Type_STM32L496VGT6P,
    } UART_Type_t;

    typedef struct UART_Instance
    {
        UART_Type_t Type;

        union
        {
            UART_STM32L496VGT6P_t STM32L496VGT6Px;
        };

        UART_CallbackOnComplete_t OnComplete;
    } UART_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    UART_Status_t UART_Port_Initialize( UART_t UARTx );
    UART_Status_t UART_Port_Cycle( UART_t UARTx );
    UART_Status_t UART_Port_DeInitialize( UART_t UARTx );

    UART_Status_t UART_Port_SetCallbackOnComplete( UART_t UARTx, UART_CallbackOnComplete_t Callback );

    UART_Status_t UART_Port_IsReady( UART_t UARTx );

    UART_Status_t UART_Port_Write( UART_t UARTx, UART_Data_t * Data, UART_DataLength_t DataLength );
    UART_Status_t UART_Port_Read( UART_t UARTx, UART_Data_t * Data, UART_DataLength_t DataLength );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* UART_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################

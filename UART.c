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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "UART.h"
#include "UART_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

UART_Status_t UART_Initialize( UART_t UARTx )
{
    UART_Status_t Status = UART_Status_Success;
    UART_Status_t UART_Status = UART_Status_Success;

    do
    {
        UART_Trace( "%s( UARTx=%d )", __FUNCTION__, UARTx );

        UART_t UART_start = ( UARTx == UART_All ? UART_Null : UARTx );
        UART_t UART_end = ( UARTx == UART_All ? UART_Count : UARTx + 1 );
        for ( UART_t UART_x = UART_start; UART_x < UART_end; ++UART_x )
        {
            if ( ( UART_Status = UART_Port_Initialize( UART_x ) ) != UART_Status_Success )
            {
                Status = UART_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

UART_Status_t UART_Cycle( UART_t UARTx )
{
    UART_Status_t Status = UART_Status_Success;
    UART_Status_t UART_Status = UART_Status_Success;

    do
    {
        UART_Trace( "%s( UARTx=%d )", __FUNCTION__, UARTx );

        UART_t UART_start = ( UARTx == UART_All ? UART_Null : UARTx );
        UART_t UART_end = ( UARTx == UART_All ? UART_Count : UARTx + 1 );
        for ( UART_t UART_x = UART_start; UART_x < UART_end; ++UART_x )
        {
            if ( ( UART_Status = UART_Port_Cycle( UART_x ) ) != UART_Status_Success )
            {
                Status = UART_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

UART_Status_t UART_DeInitialize( UART_t UARTx )
{
    UART_Status_t Status = UART_Status_Success;
    UART_Status_t UART_Status = UART_Status_Success;

    do
    {
        UART_Trace( "%s( UARTx=%d )", __FUNCTION__, UARTx );

        UART_t UART_start = ( UARTx == UART_All ? UART_Null : UARTx );
        UART_t UART_end = ( UARTx == UART_All ? UART_Count : UARTx + 1 );
        for ( UART_t UART_x = UART_start; UART_x < UART_end; ++UART_x )
        {
            if ( ( UART_Status = UART_Port_DeInitialize( UART_x ) ) != UART_Status_Success )
            {
                Status = UART_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

UART_Status_t UART_IsReady( UART_t UARTx )
{
    UART_Status_t Status = UART_Status_Success;
    UART_Status_t UART_Status = UART_Status_Success;

    do
    {
        UART_Trace( "%s( UARTx=%d )", __FUNCTION__, UARTx );

        UART_t UART_start = ( UARTx == UART_All ? UART_Null : UARTx );
        UART_t UART_end = ( UARTx == UART_All ? UART_Count : UARTx + 1 );
        for ( UART_t UART_x = UART_start; UART_x < UART_end; ++UART_x )
        {
            if ( ( UART_Status = UART_Port_IsReady( UART_x ) ) != UART_Status_Success )
            {
                Status = UART_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

UART_Status_t UART_SetCallbackOnComplete( UART_t UARTx, UART_CallbackOnComplete_t Callback )
{
    UART_Status_t Status = UART_Status_Success;
    UART_Status_t UART_Status = UART_Status_Success;

    do
    {
        UART_Trace( "%s( UARTx=%d )", __FUNCTION__, UARTx );

        UART_t UART_start = ( UARTx == UART_All ? UART_Null : UARTx );
        UART_t UART_end = ( UARTx == UART_All ? UART_Count : UARTx + 1 );
        for ( UART_t UART_x = UART_start; UART_x < UART_end; ++UART_x )
        {
            if ( ( UART_Status = UART_Port_SetCallbackOnComplete( UART_x, Callback ) ) != UART_Status_Success )
            {
                Status = UART_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

UART_Status_t UART_Write( UART_t UARTx, UART_Data_t * Data, UART_DataLength_t DataLength )
{
    UART_Status_t Status = UART_Status_Success;
    UART_Status_t UART_Status = UART_Status_Success;

    do
    {
        UART_Trace( "%s( UARTx=%d )", __FUNCTION__, UARTx );

        UART_t UART_start = ( UARTx == UART_All ? UART_Null : UARTx );
        UART_t UART_end = ( UARTx == UART_All ? UART_Count : UARTx + 1 );
        for ( UART_t UART_x = UART_start; UART_x < UART_end; ++UART_x )
        {
            if ( ( UART_Status = UART_Port_Write( UART_x, Data, DataLength ) ) != UART_Status_Success )
            {
                Status = UART_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

UART_Status_t UART_Read( UART_t UARTx, UART_Data_t * Data, UART_DataLength_t DataLength )
{
    UART_Status_t Status = UART_Status_Success;
    UART_Status_t UART_Status = UART_Status_Success;

    do
    {
        UART_Trace( "%s( UARTx=%d )", __FUNCTION__, UARTx );

        if ( UARTx == UART_All )
        {
            // FIXME What should be done while reading from all ?!
            Status = UART_Status_NotSupported;
            break;
        }

        UART_t UART_start = ( UARTx == UART_All ? UART_Null : UARTx );
        UART_t UART_end = ( UARTx == UART_All ? UART_Count : UARTx + 1 );
        for ( UART_t UART_x = UART_start; UART_x < UART_end; ++UART_x )
        {
            if ( ( UART_Status = UART_Port_Read( UART_x, Data, DataLength ) ) != UART_Status_Success )
            {
                Status = UART_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char UART_VERSION[] = "0.0.0.v20260818-0345";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################

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

typedef struct UART_Context
{
    UART_Instance_t Instance[ UART_Count ];
} UART_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static UART_Status_t UART_Context_Initialize( void );
static UART_Status_t UART_Context_Cycle( void );
static UART_Status_t UART_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static UART_Context_t UART_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static UART_Status_t UART_Context_Initialize( void )
{
    UART_Status_t Status = UART_Status_Error;

    do
    {
        UART_Trace( "%s( void )", __FUNCTION__ );

        for ( UART_t UART_x = UART_Null; UART_x < UART_Count; ++UART_x )
        {
            UART_Context.Instance[ UART_x ].UARTx = UART_x;
        }

        Status = UART_Status_Success;
    }
    while ( 0 );

    return Status;
}

static UART_Status_t UART_Context_Cycle( void )
{
    UART_Status_t Status = UART_Status_Error;

    do
    {
        UART_Trace( "%s( void )", __FUNCTION__ );

        Status = UART_Status_Success;
    }
    while ( 0 );

    return Status;
}

static UART_Status_t UART_Context_DeInitialize( void )
{
    UART_Status_t Status = UART_Status_Error;

    do
    {
        UART_Trace( "%s( void )", __FUNCTION__ );

        Status = UART_Status_Success;
    }
    while ( 0 );

    return Status;
}

UART_Status_t UART_GetInstance( UART_t UARTx, UART_Instance_t ** Instance )
{
    UART_Status_t Status = UART_Status_Error;

    do
    {
        UART_Trace( "%s( UARTx=%d, Instance=%p )", __FUNCTION__, UARTx, Instance );

        if ( Instance == NULL )
        {
            Status = UART_Status_ArgumentInvalid;
            break;
        }

        *Instance = &UART_Context.Instance[ UARTx ];

        Status = UART_Status_Success;
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

UART_Status_t UART_Initialize( UART_t UARTx )
{
    UART_Status_t Status = UART_Status_Error;

    do
    {
        UART_Trace( "%s( UARTx=%d )", __FUNCTION__, UARTx );

        if ( ( Status = UART_IsValid( UARTx ) ) != UART_Status_Success )
        {
            break;
        }

        if ( ( Status = UART_Context_Initialize( ) ) != UART_Status_Success )
        {
            break;
        }

        for ( UART_t UART_x = UART_Null; UART_x < UART_Count; ++UART_x )
        {
            if ( UARTx != UART_All && UARTx != UART_x )
            {
                continue;
            }

            UART_Status_t UART_Status = UART_Status_Success;
            if ( ( UART_Status = UART_Instance_Initialize( &UART_Context.Instance[ UART_x ] ) ) != UART_Status_Success )
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
    UART_Status_t Status = UART_Status_Error;

    do
    {
        UART_Trace( "%s( UARTx=%d )", __FUNCTION__, UARTx );

        if ( ( Status = UART_IsValid( UARTx ) ) != UART_Status_Success )
        {
            break;
        }

        if ( ( Status = UART_Context_Cycle( ) ) != UART_Status_Success )
        {
            break;
        }

        for ( UART_t UART_x = UART_Null; UART_x < UART_Count; ++UART_x )
        {
            if ( UARTx != UART_All && UARTx != UART_x )
            {
                continue;
            }

            UART_Status_t UART_Status = UART_Status_Success;
            if ( ( UART_Status = UART_Instance_Cycle( &UART_Context.Instance[ UART_x ] ) ) != UART_Status_Success )
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
    UART_Status_t Status = UART_Status_Error;

    do
    {
        UART_Trace( "%s( UARTx=%d )", __FUNCTION__, UARTx );

        if ( ( Status = UART_IsValid( UARTx ) ) != UART_Status_Success )
        {
            break;
        }

        for ( UART_t UART_x = UART_Null; UART_x < UART_Count; ++UART_x )
        {
            if ( UARTx != UART_All && UARTx != UART_x )
            {
                continue;
            }

            UART_Status_t UART_Status = UART_Status_Success;
            if ( ( UART_Status = UART_Instance_DeInitialize( &UART_Context.Instance[ UART_x ] ) ) != UART_Status_Success )
            {
                Status = UART_Status;
            }
        }

        Status = UART_Context_DeInitialize( );
    }
    while ( 0 );

    return Status;
}

UART_Status_t UART_IsReady( UART_t UARTx )
{
    UART_Status_t Status = UART_Status_Error;

    do
    {
        UART_Trace( "%s( UARTx=%d )", __FUNCTION__, UARTx );

        if ( ( Status = UART_IsValid( UARTx ) ) != UART_Status_Success )
        {
            break;
        }

        for ( UART_t UART_x = UART_Null; UART_x < UART_Count; ++UART_x )
        {
            if ( UARTx != UART_All && UARTx != UART_x )
            {
                continue;
            }

            UART_Status_t UART_Status = UART_Status_Success;
            if ( ( UART_Status = UART_Instance_IsReady( &UART_Context.Instance[ UART_x ] ) ) != UART_Status_Success )
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
    UART_Status_t Status = UART_Status_Error;

    do
    {
        UART_Trace( "%s( UARTx=%d, Callback=%p )", __FUNCTION__, UARTx, Callback );

        if ( ( Status = UART_IsValid( UARTx ) ) != UART_Status_Success )
        {
            break;
        }

        for ( UART_t UART_x = UART_Null; UART_x < UART_Count; ++UART_x )
        {
            if ( UARTx != UART_All && UARTx != UART_x )
            {
                continue;
            }

            UART_Status_t UART_Status = UART_Status_Success;
            if ( ( UART_Status = UART_Instance_SetCallbackOnComplete( &UART_Context.Instance[ UARTx ], Callback ) ) != UART_Status_Success )
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
    UART_Status_t Status = UART_Status_Error;

    do
    {
        UART_Trace( "%s( UART=%d, Data=%p, Length=%d )", __FUNCTION__, UARTx, Data, DataLength );

        if ( ( Status = UART_IsValid( UARTx ) ) != UART_Status_Success )
        {
            break;
        }

        for ( UART_t UART_x = UART_Null; UART_x < UART_Count; ++UART_x )
        {
            if ( UARTx != UART_All && UARTx != UART_x )
            {
                continue;
            }

            UART_Status_t UART_Status = UART_Status_Success;
            if ( ( UART_Status = UART_Instance_Write( &UART_Context.Instance[ UART_x ], Data, DataLength ) ) != UART_Status_Success )
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
    UART_Status_t Status = UART_Status_Error;

    do
    {
        UART_Trace( "%s( UART=%d, Data=%p, Length=%d )", __FUNCTION__, UARTx, Data, DataLength );

        if ( ( Status = UART_IsValid( UARTx ) ) != UART_Status_Success )
        {
            break;
        }

        if ( UARTx == UART_All )
        {
            // FIXME What should be done while reading from all ?!
            Status = UART_Status_NotSupported;
            break;
        }

        for ( UART_t UART_x = UART_Null; UART_x < UART_Count; ++UART_x )
        {
            if ( UARTx != UART_All && UARTx != UART_x )
            {
                continue;
            }

            UART_Status_t UART_Status = UART_Status_Success;
            if ( ( UART_Status = UART_Instance_Read( &UART_Context.Instance[ UART_x ], Data, DataLength ) ) != UART_Status_Success )
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

const char UART_VERSION[] = "0.0.0.v20260526-1736";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################

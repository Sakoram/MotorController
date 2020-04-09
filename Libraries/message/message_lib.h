/*
 * message_lib.h
 */

#ifndef MESSAGE_LIB_H_
#define MESSAGE_LIB_H_


#include <stdint.h>
#include <stdbool.h>


#define POLYNOMIAL          0x9b
#define ADDRESS             1


typedef enum
{
    MSG_NOT_VALID,
    MSG_BTN_STATE,
} MSG_Command;


#pragma pack(1)
typedef struct
{
    uint8_t Address;
    //MSG_Command Command;
    uint8_t Command;
    uint8_t Length;
    uint8_t Payload[];
} MSG_Message;


void MSG_CrcInit(void);
uint8_t MSG_CalculateCrc(uint8_t *data, uint8_t len);
bool MSG_ValidateCrc(uint8_t *data, uint8_t len, uint8_t crc);

uint8_t MSG_Pack(MSG_Command cmd, uint8_t *data, uint8_t len, uint8_t *buff);
uint8_t MSG_PackButtonStates(bool a, bool b, bool c, bool d, uint8_t *buff);


#endif

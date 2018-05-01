
#include "stdafx.h"
#include "MsgQueue.h"
#include "stdio.h"
#include "string.h"

/*Create a Massage Queue*/
MsgQueue g_MsgQueue;

/*
 Function: Msg Queue Init
 */
void MsgQueue_Init(MsgQueue *msgqueue)
{
	msgqueue->w_idx = 0;
	msgqueue->r_idx = 0;
	memset(msgqueue->msgQueue, 0, sizeof(msgqueue->msgQueue[MSGQUEUE_LENGTH]));
}

/*
 Function: Msg Queue Set Msg
 */
int MsgQueue_SetMsg(MsgQueue *msgqueue, MsgQueue_Data *MsgData)
{
	/*save the Message data*/
	msgqueue->msgQueue[msgqueue->w_idx].data = MsgData->data;
	msgqueue->msgQueue[msgqueue->w_idx].type = MsgData->type;

	/*w_idx++*/
	msgqueue->w_idx++;

	return MSGQUEUE_OK;
}

/*
 Function: Msg Queue Get Msg
 */
int MsgQueue_GetMsg(MsgQueue *msgqueue, MsgQueue_Data *MsgData)
{
	MsgData->data = msgqueue->msgQueue[msgqueue->r_idx].data;
	MsgData->type = msgqueue->msgQueue[msgqueue->r_idx].type;

	/*r_idx++*/
	msgqueue->r_idx++;

	return MSGQUEUE_OK;
}

/*
 Function: Get Msg Queue length
 */
int MsgQueue_GetLength(MsgQueue *msgqueue)
{
	return (msgqueue->w_idx - msgqueue->r_idx);
}
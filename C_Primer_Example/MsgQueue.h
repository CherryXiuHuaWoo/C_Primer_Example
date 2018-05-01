#pragma once

#define MSGQUEUE_LENGTH		64
#define MSGQUEUE_OK			0
#define MSGQUEUE_FAIL		-1

/*Message Queue Data Struct*/
struct MsgQueue_Data
{
	int data;
	int type;
};

/*Message Queue Struct*/
struct MsgQueue
{
	int w_idx;
	int r_idx;
	MsgQueue_Data msgQueue[MSGQUEUE_LENGTH];
};

extern MsgQueue g_MsgQueue;

void MsgQueue_Init(MsgQueue *msgqueue);
int MsgQueue_SetMsg(MsgQueue *msgqueue, MsgQueue_Data *MsgData);
int MsgQueue_GetMsg(MsgQueue *msgqueue, MsgQueue_Data *MsgData);
int MsgQueue_GetLength(MsgQueue *msgqueue);

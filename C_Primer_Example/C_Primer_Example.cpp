// C_Primer_Example.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MsgQueue.h"


int main(void)
{
	int w = 0, r = 0;
	MsgQueue_Data msgData;

	MsgQueue_Init(&g_MsgQueue);

	for (w = 0; w < MSGQUEUE_LENGTH-1; w++)
	{
		msgData.data = w;
		msgData.type = w;

		MsgQueue_SetMsg(&g_MsgQueue, &msgData);
		printf("NO%d, Set Message. data=%d, type = %d, Message Queue Length= %d\r\n", \
			w, g_MsgQueue.msgQueue[g_MsgQueue.w_idx - 1].data, g_MsgQueue.msgQueue[g_MsgQueue.w_idx - 1].type, MsgQueue_GetLength(&g_MsgQueue));
	}

	for (r = 0; r < MSGQUEUE_LENGTH - 1; r++)
	{
		MsgQueue_GetMsg(&g_MsgQueue, &msgData);
		printf("NO%d, Get Message. data=%d, type = %d, Message Queue Length= %d\r\n", \
			r, g_MsgQueue.msgQueue[g_MsgQueue.r_idx].data, g_MsgQueue.msgQueue[g_MsgQueue.r_idx].type, MsgQueue_GetLength(&g_MsgQueue));
	}
	getchar();
    return 0;
}


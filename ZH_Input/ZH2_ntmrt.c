#include <stdio.h>  // 此標頭檔其中定義了 輸出與輸入功能
#include <stdlib.h>  // 此標頭檔其中定義了 系統暫停指令
#include "..\ZH_Input.h"  // 此標頭檔定義了 中文使用者輸入
#include "..\Output.h"  // 此標頭檔定義了 各種輸出內容
#include "..\Exit.h"  // 此標頭檔定義了 程式如何結束

void ZH_ntmrt()  // 定義 中文功能2：新北捷運/輕軌 資料輸入函式
{
	printf("\n\033[38;5;43m目前正在輸入：功能2：新北捷運/輕軌\033[0m\n");  // 列印中文使用者輸入內容
	ZH_zero_exit();  // 調用 中文訊息：0表示返回 輸出函式
input_ntmrt:  // 定義 輸入_新北捷運/輕軌 區塊
	printf("請問您想輸入票價多少元的資料 --> ");  // 詢問中文用戶欲輸入的搭乘 新北捷運/輕軌 金額
	scanf_s("%d", &temp_fare);  //接收使用者輸入至 價格緩存 變數
	if (temp_fare == 0)  // 如果 輸入金額 等於0
	{
		printf("\n\033[38;5;45m正在為您統計本月搭乘 新北捷運/輕軌 數據\n");  // 輸出中文功能訊息
		printf("本月搭乘 %d 次 新北捷運/輕軌，花費 %d 元\033[0m\n\n", ntmrt_times, ntmrt_fare);  // 列印中文使用者輸入內容
		printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 輸出中文功能訊息
	}
	else
	{
		fflush(stdin);  // 清除緩衝區資料
		printf("本月搭 新北捷運/輕軌 %d 元次數 ---> ", temp_fare);  // 詢問在 價格緩存 元下，中文用戶搭乘 新北捷運/輕軌 次數
		scanf_s("%d", &temp_times);  //接收使用者輸入至 次數緩存 變數
		if (temp_times == 0)  // 如果 輸入次數 等於0
		{
			printf("這個月沒有搭乘 %d 元 的 新北捷運/輕軌，正在為您統計數據\n", temp_fare);  // 列印中文使用者輸入內容
			printf("\033[38;5;45m本月搭乘 %d 次 新北捷運/輕軌，最後花費 %d 元\033[0m\n\n", ntmrt_times, ntmrt_fare);
			printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 輸出中文功能訊息
		}
		else if (temp_times > 0)  // 如果 輸入次數 大於0
		{
			printf("\033[38;5;111m本月搭 %d 元 新北捷運/輕軌 %d 次\033[0m\n\n", temp_fare, temp_times);  // 列印中文使用者輸入內容
			ntmrt_times = ntmrt_times + temp_times;  // 計算用戶搭乘 新北捷運/輕軌 的總次數（若使用者曾輸入過，原數據不會被覆蓋）
			ntmrt_fare = ntmrt_fare + temp_fare * temp_times;  // 計算用戶搭乘 新北捷運/輕軌 的總票價（若使用者曾輸入過，原數據不會被覆蓋）
			goto input_ntmrt;  // 跳到 輸入_新北捷運/輕軌 區塊
		}
		else  // 其他情況
		{
			printf("\033[38;5;197m輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出中文錯誤訊息， \a 為 溢出字元 警告聲
			system("pause");  // 暫停程式運行
			exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
		}
	}
}

#include<windows.h>
#include<pthread.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
void* con(void* arg)
{
	bool onshow=1;
	HWND hwnd;
	hwnd=FindWindow("ConsoleWindowClass",NULL);
	while(1)
	{
		if(KEY_DOWN(123))
			{
				ShowWindow(hwnd,SW_HIDE);
			}
		if(KEY_DOWN(19))
			{
				ShowWindow(hwnd,SW_SHOW);
			}
		_sleep(10);
	}
} 
int main()
{
	pthread_t tid;  
    pthread_create(&tid, NULL, con, NULL);
	system("\"C:\\Program Files\\Java\\jdk-14.0.1\\bin\\java.exe\" -Xms4G -Xmx6G -Xverify:none -XX:+UseParallelOldGC -XX:MaxInlineSize=420 -jar 1.16.jar nogui");
	return 0;
}

#include <tccore/custom.h>
#include <epm/epm.h>
#include <server_exits/user_server_exits.h>
#include "Debug.h"
#include "ActionHandler_KhITKStudy.h"
// KhITKStudy.cpp: 定义 DLL 应用程序的导出函数。
//兼容C语言，C和C++混合编程
#ifdef __cplusplus
//extern “C”是由Ｃ＋＋提供的一个连接交换指定符号，用于告诉Ｃ＋＋这段代码是Ｃ函数
//extern 可以置于变量或者函数前，以标示变量或者函数的定义在别的文件中，提示编译器遇到此变量和函数时在其他模块中寻找其定义
extern "C" {
#endif
	/******************************************************************
	程序主函数
	*******************************************************************/
	/*
	*	DLLAPI：
	*		决定dll导出格式，TC严格使用C语言导出格式导出的dll文件，
	*
	*		这样才能读取编译好的dll文件，入口函数必须严格使用C语言导出格式，
	*
	*		其他方法可以使用C++格式，此宏用于确保符号是在Windows平台上正确导出。
	*
	*	入口函数名定义：需要与工程名、文件名第一部分、CUSTOM_register_exit第一参数和首选项一致
	*
	*/

	DLLAPI int MyITK_register_callbacks()
	{
		int CUST_init_module(int *decision, va_list args);
		int ifail = ITK_ok;
		//注册函数，并非是注册user service函数，其需要另外定义
		ifail = CUSTOM_register_exit(
			//注册dll是有要求的，与工程名一致
			"MyITK",
			//调用不同的模块标识字符串，系统根据该字符串查找模块访问这个注册的方法
			"USER_gs_shell_init_module",
			//CUSTOM_EXIT_ftn_t是一个函数指针，用于指向需要注册的方法名
			(CUSTOM_EXIT_ftn_t)CUST_init_module);
		if (0 == ifail) {
			Debug("初始化MyITK成功");
		}
		else {
			Debug("初始化MyITK失败");
		}
		return ifail;
	}

	extern DLLAPI int CUST_init_module(int *decision, va_list args)
	{
		int Regist_ActionHandler_KhITKStudy();
		int ifail = ITK_ok;
		//允许注册多个注册函数
		*decision = ALL_CUSTOMIZATIONS;
		//注册内控标准-制造action handler
		ifail = Regist_ActionHandler_KhITKStudy();
		return ifail;
	}
#ifdef __cplusplus
}
#endif
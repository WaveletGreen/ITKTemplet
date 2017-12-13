#include"ActionHandler_KhITKStudy.h"
#include "Debug.h"
/**注册制造handler*/
extern int Regist_ActionHandler_KhITKStudy() {
	int ActionHandler_KhITKStudy(EPM_action_message_t msg);
	int ifail = ITK_ok;
	/*使用EPM_register_action_handler函数注册Handler，该函数用于注册ActionHalder，
	*	如果需要注册RuleHandler，则需要使用EPM_register_rule_handler函数
	*	参数1：需要注册Handler名，用于系统唯一标识的Handler名
	*
	*	参数2：Handler描述
	*
	*	参数3：EPM_action_handler_t函数指针，该函数指针指向需要注册的
	*			ActionHadnler处理函数，	即具体业务逻辑，调用Hanlder时
	*			系统自动触发处理函数。如需要注册RuleHandler，须指向
	*			EPM_rule_handler_t处理函数即可。
	*
	*/
	ifail = EPM_register_action_handler("KhITKStudy", "KhITKStudy",

		(EPM_action_handler_t)ActionHandler_KhITKStudy);
	if (0 == ifail) {
		Debug("注册ActionHandler KhITKStudy成功");
	}
	else {
		Debug("注册ActionHandler KhITKStudy失败");
	}
	return ifail;
}
/*参数1是结构体EPM_action_message_t类型，系统自动传入。该结构体记录了
*一系列触发Handler的数据，包括触发的任务，action和流程配置中配置好的参数
*当然不定义该形参也是可以的，但建议定义这形参，因为我们只能根据这个参数获取
*一系列后续参数（任务以及任务下挂载的信息），方便编程
*/
extern int ActionHandler_KhITKStudy(EPM_action_message_t msg) {
	/***********************************
	具体业务逻辑
	************************************/
	Debug("测试开始");
	Debug("Hello ActionHandler_KhITKStudy");
	Debug("测试结束");
	return ITK_ok;
}

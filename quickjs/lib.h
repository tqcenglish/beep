#include "quickjs.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "../beep.h"

#define JS_INIT_MODULE js_init_module
#define countof(x) (sizeof(x) / sizeof((x)[0]))

static JSValue js_test_beep(JSContext *ctx, JSValueConst this_val,
                           int argc, JSValueConst *argv);

/* 定义API的函数入口名称及列表 */
static const JSCFunctionListEntry js_test_funcs[] = {
    /* JS_CFUNC_DEF(函数入口名称，入参个数，QuickJS C 函数) */
    JS_CFUNC_DEF("testBeep", 2, js_test_beep),
};

/* 定义初始化回调方法（由系统调用，入参格式固定），将函数入口列表 在模块中暴露 */
static int js_init(JSContext *ctx, JSModuleDef *m)
{
    return JS_SetModuleExportList(ctx, m, js_test_funcs,
                                  countof(js_test_funcs));
}

/* 定义初始化模块方法，由系统自动调用，且函数名称不可更改 */
JSModuleDef *JS_INIT_MODULE(JSContext *ctx, const char *module_name)
{
    JSModuleDef *m;
    m = JS_NewCModule(ctx, module_name, js_init);
    if (!m)
        return NULL;
    JS_AddModuleExportList(ctx, m, js_test_funcs, countof(js_test_funcs));
    return m;
}
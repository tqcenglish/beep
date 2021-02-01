
#include "lib.h"

/* 自定义原生C函数 */
static int callBeep(int a, int b)
{
    beep(a, b);
    return 0;
}

/* 
    定义 QuickJS C 函数 
    *ctx     : 运行时上下文
    this_val : this对象
    argc     : 入参个数
    *argv    : 入参列表
*/
static JSValue js_test_beep(JSContext *ctx, JSValueConst this_val,
                           int argc, JSValueConst *argv)
{
    int a;
    int b;
    if (JS_ToInt32(ctx, &a, argv[0]))
        return JS_EXCEPTION;
    if (JS_ToInt32(ctx, &b, argv[1]))
        return JS_EXCEPTION;
    return JS_NewInt32(ctx, callBeep(a, b));
}


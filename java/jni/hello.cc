#include <stdio.h>
#include "com_houbin_jni_Hello.h"

JNIEXPORT void JNICALL Java_com_houbin_jni_Hello_native_1say_1hello
  (JNIEnv *env, jclass clz, jstring j_name)
{
    const char *name = NULL;
    if (j_name)
    {
        name = env->GetStringUTFChars(j_name, NULL);
        if (!name)
        {
            return;
        }
    }

    printf("come from c, name is %s\n", name);
    return;
}


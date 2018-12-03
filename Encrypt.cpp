//
// Created by Administrator on 2018/12/3.
//

#include "com_ft_encrypt_Encrypt.h"

JNIEXPORT jbyteArray JNICALL Java_com_ft_encrypt_Encrypt_encrypt
        (JNIEnv *_env, jobject thisObj, jbyteArray _buf) {

    jsize len =_env->GetArrayLength(_buf);

    unsigned char* dst = (unsigned char*)_env->GetByteArrayElements(_buf, 0);

    for (int i = 0; i < len; ++i) {
        dst[i] = dst[i] ^ 0x07;
    }

    _env->SetByteArrayRegion(_buf, 0, len, (jbyte *)dst);
    return _buf;
}

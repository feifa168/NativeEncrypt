## 简介 
> NativeEncrypt用于加密java字节码文件

## 用法
* 实现java接口文件com_ft_encrypt_Encrypt_encrypt.h，生成libencrypt.dll
> 加密算法可以任意修改，这里只给出一种简单的实现以供测试。
```java
JNIEXPORT jbyteArray JNICALL Java_com_ft_encrypt_Encrypt_encrypt
  (JNIEnv *, jobject, jbyteArray) {
    jsize len =_env->GetArrayLength(_buf);
    unsigned char* dst = (unsigned char*)_env->GetByteArrayElements(_buf, 0);

    for (int i = 0; i < len; ++i) {
        dst[i] = dst[i] ^ 0x07;
    }

    _env->SetByteArrayRegion(_buf, 0, len, (jbyte *)dst);
    return _buf;
}
```
* java中com.ft.encrypt.Encrypt类加载libencrypt.dll
```java
    static {
        System.loadLibrary("libNativeEncrypt");
    }
```
* 调用接口函数encrypt得到加密后的buffer。
    * 遍历jar包中所有的类，只加密指定的类，这里只加密com.ft.encrypt包下的文件(这个可以通过配置文件或参数传入修改，也可以加密所有类)
    * 执行加密算法
    * 返回加密后的buffer


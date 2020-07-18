//jni_call.cpp


// equivalent java code
/*
    package com.example.it;
    public class ClassA{
        public class ClassB{
            public float f;
            public float g;
        }
        public void addsomething(vector<ClassB_cpp> data)
        {
            ArrayList<ClassB_cpp> array = new ArrayList();
            for(int i =0;i<data.size();++i)
            {
                ClassB d = new ClassB();
                d.f = data[i].f;
                d.g = data[i].g;
                array.add(d)
            }

        }
    }
*/

extern "C"
{
    // 对应的是java的 com.example.it.ClassA的addsomething 方法
JNIEXPORT  void JNICALL Java_com_example_it_ClassA_addsomething(JNIEnv*env,jobject thiz, vector<ClassB_cpp> data)
{
    // java/util/ArrayList 对应 java.util.ArrayList
    jclass ArrayList_t = env->FindClass("java/util/ArrayList");
    // new时用的构造函数名固定是 <init> , "()V"是函数类型的签名
    jmethodID ArrayList_Constructor = env->GetMethodID(ArrayList_t,"<init>", "()V");
    //  正常的函数就是对应的函数名,add方法签名是 boolean add(E ),虽然是泛型,但是java类型擦除,最后E还是java.lang.Object . Z表示boolean类型
    jmethodID ArrayList_Add = env->GetMethodID(ArrayList_t,"add", "(Ljava/lang/Object;)Z");
    // 内部类用$连接
    jclass ClassB_t= env->FindClass("com/example/it/ClassA$ClassB");
    jmethodID ClassB_Constructor =  env->GetMethodID(ClassB_t,"<init>","()V");
    // F表示float类型
    jfieldID  f = env->GetFieldID(ClassB_t,"f","F");
    // 其他类型参考 https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/types.html#wp9502
    jfieldID  g = env->GetFieldID(ClassB_t,"g","F");


    jobject array  = env->NewObject(ArrayList_t,ArrayList_Constructor);
    for(int i =0;i<data.size();++i)
    {
        jobject a_classB = env->NewObject(ClassB_t,bbox_Constructor);
        env->SetFloatField(a_classB,f,data[i].f);
        env->SetFloatField(a_classB,g,data[i].g);
        env->CallBooleanMethod(array,ArrayList_Add,a_classB);
    }
}
}
//
// Created by Abao Zhang on 2021/7/9.
//

#include "my_object.h"

Napi::Object MyObject::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "MyObject", {
                                                               InstanceMethod("getValue", &MyObject::getValue),
                                                               InstanceMethod("plusOne", &MyObject::plusOne),
                                                               InstanceMethod("multiply", &MyObject::multiply),
                                                       });
    Napi::FunctionReference *constructor = new Napi::FunctionReference();
    *constructor = Napi::Persistent(func);
    env.SetInstanceData(constructor);
    exports.Set("MyObject", func);
    return exports;
}

Napi::Object MyObject::NewInstance(Napi::Env env, Napi::Value arg) {
    Napi::EscapableHandleScope scope(env);
    Napi::Object obj = env.GetInstanceData<Napi::FunctionReference>()->New({arg});
    return scope.Escape(napi_value(obj)).ToObject();
}

MyObject::MyObject(const Napi::CallbackInfo &info) : ObjectWrap(info) {
    Napi::Env env = info.Env();
    if (info.Length() > 1) {
        Napi::TypeError::New(env, Napi::String::New(env, "Wrong number of arguments")).ThrowAsJavaScriptException();
        return;
    } else if (info.Length() == 1) {
        m_value = info[0].As<Napi::Number>().DoubleValue();
    }
}
Napi::Value MyObject::getValue(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, m_value);
}
Napi::Value MyObject::plusOne(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    if (info.Length() != 1) {
        Napi::TypeError::New(env, Napi::String::New(env, "Wrong number of arguments")).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    m_value += info[0].As<Napi::Number>().DoubleValue();
    return Napi::Value();
}
Napi::Value MyObject::multiply(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    if (info.Length() != 1) {
        Napi::TypeError::New(env, Napi::String::New(env, "Wrong number of arguments")).ThrowAsJavaScriptException();
        return Napi::Value();
    }
    m_value *= info[0].As<Napi::Number>().DoubleValue();
    return Napi::Value();
}

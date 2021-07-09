//
// Created by Abao Zhang on 2021/7/9.
//

#include <napi.h>

#include "my_object.h"

Napi::Object CreateWrapObject(const Napi::CallbackInfo &info) {
    return MyObject::NewInstance(info.Env(), info[0]);
}

Napi::Object Add(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    double result = MyObject::Unwrap(info[0].ToObject())->value() + MyObject::Unwrap(info[1].ToObject())->value();
    return MyObject::NewInstance(env, Napi::Number::New(env, result));
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "createWrapObject"), Napi::Function::New(env, CreateWrapObject));
    exports.Set(Napi::String::New(env, "addWrapObject"), Napi::Function::New(env, Add));
    return MyObject::Init(env, exports);
}


NODE_API_MODULE(ObjectWrap, InitAll)

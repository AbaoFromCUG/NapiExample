//
// Created by Abao Zhang on 2021/7/9.
//

#include <napi.h>

#include "my_object.h"

Napi::Object Method(const Napi::CallbackInfo &info) {
    return MyObject::NewInstance(info.Env(), info[0]);
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "createWrapObject"), Napi::Function::New(env, Method));
    return MyObject::Init(env, exports);
}


NODE_API_MODULE(ObjectWrap, InitAll)

//
// Created by Abao Zhang on 2021/7/9.
//

#include <napi.h>

Napi::Function Method(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    auto name = info[0].ToString().Utf8Value();
    Napi::Function func = Napi::Function::New(env, [name](const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), "Hello " + name);
    });
    return func;
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "createFunction"), Napi::Function::New(env, Method));
    return exports;
}


NODE_API_MODULE(FunctionFactory, Init)

//
// Created by Abao Zhang on 2021/7/9.
//
#include <napi.h>

void Method(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return;
    }
    Napi::Function callback = info[0].As<Napi::Function>();
    callback.Call(env.Global(), {Napi::String::New(env, "Hello Callback")});
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "runCallback"), Napi::Function::New(env, Method));
    return exports;
}

NODE_API_MODULE(Callbacks, Init)

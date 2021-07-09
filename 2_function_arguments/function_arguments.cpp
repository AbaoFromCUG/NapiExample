//
// Created by Abao Zhang on 2021/7/9.
//

#include <napi.h>

Napi::Value Method(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    double arg0 = info[0].As<Napi::Number>();
    double arg1 = info[1].As<Napi::Number>();
    return Napi::Number::New(env, arg0 + arg1);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Method));
    return exports;
}


NODE_API_MODULE(FunctionArgumentss, Init)

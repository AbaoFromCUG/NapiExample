//
// Created by Abao Zhang on 2021/7/9.
//

#include <napi.h>

Napi::Object Method(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Object newObj = Napi::Object::New(env);
    if (info.Length() != 1) {
        Napi::TypeError::New(env, Napi::String::New(env, "Wrong number of arguments")).ThrowAsJavaScriptException();
        return newObj;
    }

    static int id = 0;
    newObj.Set(Napi::String::New(env, "id"), Napi::Number::New(env, id++));
    newObj.Set(Napi::String::New(env, "name"), info[0].As<Napi::String>());
    return newObj;
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "createObject"), Napi::Function::New(env, Method));
    return exports;
}


NODE_API_MODULE(ObjectFactory, Init)

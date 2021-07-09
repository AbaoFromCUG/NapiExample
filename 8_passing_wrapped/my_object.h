//
// Created by Abao Zhang on 2021/7/9.
//

#ifndef HELLNAPI_OBJECTFACTORY_H
#define HELLNAPI_OBJECTFACTORY_H

#include <napi.h>


class MyObject : public Napi::ObjectWrap<MyObject> {

public:
    static Napi::Object Init(Napi::Env info, Napi::Object exports);
    static Napi::Object NewInstance(Napi::Env env, Napi::Value arg);
    MyObject(const Napi::CallbackInfo &info);


public:
    Napi::Value getValue(const Napi::CallbackInfo &info);
    Napi::Value plusOne(const Napi::CallbackInfo &info);
    Napi::Value multiply(const Napi::CallbackInfo &info);

    inline double value() { return m_value; }

private:
    double m_value = 0;
};


#endif//HELLNAPI_OBJECTFACTORY_H

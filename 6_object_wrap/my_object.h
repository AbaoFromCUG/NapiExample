//
// Created by Abao Zhang on 2021/7/9.
//

#ifndef HELLONAPI_MY_OBJECT_H
#define HELLONAPI_MY_OBJECT_H

#include <napi.h>


class MyObject : public Napi::ObjectWrap<MyObject> {

public:
    static Napi::Object Init(Napi::Env info, Napi::Object exports);
    MyObject(const Napi::CallbackInfo &info);


public:
    Napi::Value getValue(const Napi::CallbackInfo &info);
    Napi::Value plusOne(const Napi::CallbackInfo &info);
    Napi::Value multiply(const Napi::CallbackInfo &info);


private:
    double m_value = 0;
};


#endif//HELLONAPI_MY_OBJECT_H

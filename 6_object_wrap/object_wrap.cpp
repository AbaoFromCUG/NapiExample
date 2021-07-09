//
// Created by Abao Zhang on 2021/7/9.
//

#include <napi.h>

#include "my_object.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    MyObject::Init(env, exports);
    return exports;
}


NODE_API_MODULE(ObjectWrap, InitAll)

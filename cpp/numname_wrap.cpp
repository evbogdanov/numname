#include <nan.h>
#include "numname.hpp"

namespace numname_wrap {
////////////////////////////////////////////////////////////////////////////////

void
GetName(const Nan::FunctionCallbackInfo<v8::Value>& args)
{
    if (args.Length() != 1 || !args[0]->IsNumber()) {
        Nan::ThrowTypeError("Gimme exactly one numeric argument");
        return;
    }

    unsigned long long num = args[0]->NumberValue();
    numname::NumName nn (num);
    const char* name = nn.get_name().c_str();

    args.GetReturnValue().Set(Nan::New(name).ToLocalChecked());
}

void
Init(v8::Local<v8::Object> exports)
{
    exports->Set(Nan::New("getName").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(GetName)->GetFunction());
}

NODE_MODULE(addon, Init)

////////////////////////////////////////////////////////////////////////////////
}

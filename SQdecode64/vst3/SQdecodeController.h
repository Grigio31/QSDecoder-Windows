#pragma once
#include "public.sdk/source/vst/vsteditcontroller.h"
namespace sqdecode64::vst3 { class Controller final:public Steinberg::Vst::EditController { public: static Steinberg::FUnknown* createInstance(void*){return static_cast<Steinberg::Vst::IEditController*>(new Controller);} }; }

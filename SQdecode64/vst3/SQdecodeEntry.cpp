#include "public.sdk/source/main/pluginfactory.h"
#include "pluginterfaces/vst/ivstaudioprocessor.h"
#include "SQdecodeProcessor.h"
#include "SQdecodeController.h"
#include "SQdecodeIDs.h"
#define SQDECODE64_VERSION_STR "0.1.0"
using namespace Steinberg;using namespace Steinberg::Vst;using namespace sqdecode64::vst3;
BEGIN_FACTORY_DEF("SQdecode64 project","","")
DEF_CLASS2(INLINE_UID_FROM_FUID(kProcessorUID),PClassInfo::kManyInstances,kVstAudioEffectClass,"SQdecode64",Vst::kDistributable,"Fx|Spatial",SQDECODE64_VERSION_STR,kVstVersionString,Processor::createInstance)
DEF_CLASS2(INLINE_UID_FROM_FUID(kControllerUID),PClassInfo::kManyInstances,kVstComponentControllerClass,"SQdecode64 Controller",0,"",SQDECODE64_VERSION_STR,kVstVersionString,Controller::createInstance)
END_FACTORY

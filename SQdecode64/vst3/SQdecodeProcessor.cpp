#include "SQdecodeProcessor.h"
#include "SQdecodeIDs.h"
#include "pluginterfaces/vst/ivstaudioprocessor.h"
namespace sqdecode64::vst3 { using namespace Steinberg; using namespace Steinberg::Vst;
Processor::Processor(){setControllerClass(kControllerUID);}
tresult PLUGIN_API Processor::initialize(FUnknown* c){auto r=AudioEffect::initialize(c);if(r!=kResultOk)return r;addAudioInput(STR16("SQ Stereo In"),SpeakerArr::kStereo);addAudioOutput(STR16("SQ Quad Out"),SpeakerArr::k40Music);return kResultOk;}
tresult PLUGIN_API Processor::setBusArrangements(SpeakerArrangement* i,int32 ni,SpeakerArrangement* o,int32 no){if(ni!=1||no!=1||i[0]!=SpeakerArr::kStereo||o[0]!=SpeakerArr::k40Music)return kResultFalse;return AudioEffect::setBusArrangements(i,ni,o,no);}
tresult PLUGIN_API Processor::canProcessSampleSize(int32 s){return(s==kSample32||s==kSample64)?kResultTrue:kResultFalse;}
tresult PLUGIN_API Processor::setActive(TBool s){if(s)decoder_.reset();return AudioEffect::setActive(s);}
template<typename Sample> void Processor::processBlock(ProcessData& d) noexcept {if(d.numInputs<1||d.numOutputs<1||d.numSamples<=0)return;auto& in=d.inputs[0];auto& out=d.outputs[0];if(in.numChannels<2||out.numChannels<4)return;Sample** ic=nullptr;Sample** oc=nullptr;if constexpr(sizeof(Sample)==sizeof(Sample32)){ic=reinterpret_cast<Sample**>(in.channelBuffers32);oc=reinterpret_cast<Sample**>(out.channelBuffers32);}else{ic=reinterpret_cast<Sample**>(in.channelBuffers64);oc=reinterpret_cast<Sample**>(out.channelBuffers64);}if(!ic||!oc||!ic[0]||!ic[1]||!oc[0]||!oc[1]||!oc[2]||!oc[3])return;for(int32 n=0;n<d.numSamples;++n){double lf,rf,ls,rs;decoder_.process(static_cast<double>(ic[0][n]),static_cast<double>(ic[1][n]),lf,rf,ls,rs);oc[0][n]=static_cast<Sample>(lf);oc[1][n]=static_cast<Sample>(rf);oc[2][n]=static_cast<Sample>(ls);oc[3][n]=static_cast<Sample>(rs);}out.silenceFlags=0;}
tresult PLUGIN_API Processor::process(ProcessData& d){if(d.symbolicSampleSize==kSample64)processBlock<Sample64>(d);else processBlock<Sample32>(d);return kResultOk;}
}

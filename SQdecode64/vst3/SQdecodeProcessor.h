#pragma once
#include "public.sdk/source/vst/vstaudioeffect.h"
#include "dsp/SQDecoder.h"
namespace sqdecode64::vst3 {
class Processor final:public Steinberg::Vst::AudioEffect {
public:
 Processor(); static Steinberg::FUnknown* createInstance(void*){return static_cast<Steinberg::Vst::IAudioProcessor*>(new Processor);}
 Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown*) override;
 Steinberg::tresult PLUGIN_API setBusArrangements(Steinberg::Vst::SpeakerArrangement*,Steinberg::int32,Steinberg::Vst::SpeakerArrangement*,Steinberg::int32) override;
 Steinberg::tresult PLUGIN_API canProcessSampleSize(Steinberg::int32) override;
 Steinberg::tresult PLUGIN_API setActive(Steinberg::TBool) override;
 Steinberg::tresult PLUGIN_API process(Steinberg::Vst::ProcessData&) override;
 Steinberg::uint32 PLUGIN_API getLatencySamples() override{return SQDecoder::kLatencySamples;}
 Steinberg::uint32 PLUGIN_API getTailSamples() override{return SQDecoder::kTailSamples;}
private:
 template<typename Sample> void processBlock(Steinberg::Vst::ProcessData&) noexcept;
 SQDecoder decoder_{};
};
}

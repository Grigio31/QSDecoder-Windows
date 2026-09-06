#pragma once
#include <array>
#include <cstdint>
namespace sqdecode64 {
class SQDecoder {
public:
 static constexpr std::uint32_t kLatencySamples=250;
 static constexpr std::uint32_t kTailSamples=250;
 void reset() noexcept;
 void process(double left,double right,double& lf,double& rf,double& ls,double& rs) noexcept;
private:
 struct Ring { std::array<double,502> x{}; int pos=0; std::uint64_t pushed=0; void reset() noexcept; void push(double v) noexcept; double delayed250() const noexcept; double hilbert() const noexcept; };
 Ring left_{},right_{};
};
}

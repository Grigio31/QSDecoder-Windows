#include "SQDecoder.h"
#include "HilbertCoefficients.h"
namespace sqdecode64 {
void SQDecoder::Ring::reset() noexcept { x.fill(0.0); pos=0; pushed=0; }
void SQDecoder::Ring::push(double v) noexcept { pos=(pos==501)?1:pos+1; x[static_cast<std::size_t>(pos)]=v; ++pushed; }
double SQDecoder::Ring::delayed250() const noexcept { if(pushed<=250||pos==0)return 0.0; int i=pos-250; if(i<1)i+=501; return x[static_cast<std::size_t>(i)]; }
double SQDecoder::Ring::hilbert() const noexcept { if(pos==0)return 0.0; int i=pos-500; if(i<1)i+=501; double sum=0.0; for(std::size_t k=0;k<kHilbert.size();++k){ sum-=kHilbert[k]*x[static_cast<std::size_t>(i)]; if(++i>501)i-=501; } return sum; }
void SQDecoder::reset() noexcept { left_.reset(); right_.reset(); }
void SQDecoder::process(double left,double right,double& lf,double& rf,double& ls,double& rs) noexcept { left_.push(left); right_.push(right); const double dl=left_.delayed250(); const double dr=right_.delayed250(); lf=dl; rf=dr; ls=-0.7071*(left_.hilbert()+dr); rs=0.7071*(right_.hilbert()+dl); }
}

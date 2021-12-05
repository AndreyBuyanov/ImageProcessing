#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib
{
namespace Filters
{

struct Kernel3x3
{
	float k1;
	float k2;
	float k3;
	float k4;
	float k5;
	float k6;
	float k7;
	float k8;
	float k9;

	Kernel3x3(
		const float _k1,
		const float _k2,
		const float _k3,
		const float _k4,
		const float _k5,
		const float _k6,
		const float _k7,
		const float _k8,
		const float _k9):
		k1(_k1),
		k2(_k2),
		k3(_k3),
		k4(_k4),
		k5(_k5),
		k6(_k6),
		k7(_k7),
		k8(_k8),
		k9(_k9) {}

	Kernel3x3() :
		k1(0.0f),
		k2(0.0f),
		k3(0.0f),
		k4(0.0f),
		k5(0.0f),
		k6(0.0f),
		k7(0.0f),
		k8(0.0f),
		k9(0.0f) {}

	float Summ() {
		return k1 + k2 + k3 + k4 + k5 + k6 + k7 + k8 + k9;
	}

};

class IConvolution3x3 :
	public IFilter
{
public:
	virtual ~IConvolution3x3() {}

	virtual void SetKernel(
		const Kernel3x3 &kerenl) = 0;
};

}
}

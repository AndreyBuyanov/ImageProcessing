#pragma once

#include "ImageLib/Filters/IConvolution.hpp"
#include "ImageLib/IThread.hpp"

namespace ImageLib
{
namespace Filters
{

using ImageLib::IRunnable;
using ImageLib::IThread;

class Convolution3x3 :
	public IConvolution3x3,
	public IRunnable
{
public:
	Convolution3x3();
	virtual ~Convolution3x3() {}

	// IConvolution
	void ProcessBitmap() override;

	void SetBitmap(
		IBitmap *bitmap) override;

	void RegisterProgressEventHandler(
		IProgressEventHandler *handler) override;
	void RegisterFilterControlEventHandler(
		IFilterControlEventHandler *handler) override;

    string GetName() const override;

	void SetKernel(
		const Kernel3x3 &kernel) override;

	// IRunnable
	void Run() override;

private:
	IBitmap *m_Bitmap;
	IProgressEventHandler *m_ProgressEventHandler;
	IFilterControlEventHandler *m_FilterControlEventHandler;
	IThread *m_Thread;
	Kernel3x3 m_Kernel;
};

}
}

#pragma once

#include "ImageLib/Filters/IConvultion.hpp"
#include "ImageLib/IThread.hpp"

namespace ImageLib
{
namespace Filters
{

using ImageLib::IRunnable;
using ImageLib::IThread;

class Convultion3x3 :
	public IConvultion3x3,
	public IRunnable
{
public:
	Convultion3x3();
	virtual ~Convultion3x3() {}

	// IConvultion
	void ProcessBitmap() override;

	void SetBitmap(
		IBitmap *bitmap) override;

	void RegisterProgressEventHandler(
		IProgressEventHandler *handler) override;
	void RegisterFilterControlEventHandler(
		IFilterControlEventHandler *handler) override;

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

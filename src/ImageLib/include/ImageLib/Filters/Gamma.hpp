#pragma once

#include "ImageLib/Filters/IGamma.hpp"
#include "ImageLib/IThread.hpp"

namespace ImageLib
{
namespace Filters
{

using ImageLib::IRunnable;
using ImageLib::IThread;

class Gamma :
	public IGamma,
	public IRunnable
{
public:
	Gamma();
	virtual ~Gamma() {}

	// IFilter
	void ProcessBitmap() override;

	void SetBitmap(
		IBitmap *bitmap) override;

	void RegisterProgressEventHandler(
		IProgressEventHandler *handler) override;
	void RegisterFilterControlEventHandler(
		IFilterControlEventHandler *handler) override;

	// IGamma
	void SetGamma(
		const float gamma) override;

	// IRunnable
	void Run() override;

private:
	IBitmap *m_Bitmap;
	IProgressEventHandler *m_ProgressEventHandler;
	IFilterControlEventHandler *m_FilterControlEventHandler;
	IThread *m_Thread;
	float m_Gamma;
};

}
}

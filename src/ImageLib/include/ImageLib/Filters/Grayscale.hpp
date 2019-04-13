#pragma once

#include "ImageLib/Filters/IGrayscale.hpp"
#include "ImageLib/IThread.hpp"

namespace ImageLib
{
namespace Filters
{

using ImageLib::IRunnable;
using ImageLib::IThread;

class Grayscale :
	public IGrayscale,
	public IRunnable
{
public:
	Grayscale();
	virtual ~Grayscale() {}

	// IGrayscale
	void ProcessBitmap() override;

	void SetBitmap(
		IBitmap *bitmap) override;

	void RegisterProgressEventHandler(
		IProgressEventHandler *handler) override;
	void RegisterFilterControlEventHandler(
		IFilterControlEventHandler *handler) override;

    string GetName() const override;

	// IRunnable
	void Run() override;

private:
	IBitmap *m_Bitmap;
	IProgressEventHandler *m_ProgressEventHandler;
	IFilterControlEventHandler *m_FilterControlEventHandler;
	IThread *m_Thread;
};

}
}

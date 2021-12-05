#pragma once

#include "ImageLib/Filters/ISobel.hpp"
#include "ImageLib/IThread.hpp"

namespace ImageLib
{
namespace Filters
{

using ImageLib::IRunnable;
using ImageLib::IThread;

class Sobel :
	public ISobel,
	public IRunnable
{
public:
	Sobel();
	virtual ~Sobel() {}

	// ISobel
	void ProcessBitmap() override;

	void SetBitmap(
		IBitmap *bitmap) override;

	void RegisterProgressEventHandler(
		IProgressEventHandler *handler) override;
	void RegisterFilterControlEventHandler(
		IFilterControlEventHandler *handler) override;

    std::string GetName() const override;

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
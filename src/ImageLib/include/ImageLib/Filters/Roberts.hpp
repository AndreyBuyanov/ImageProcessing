#pragma once

#include "ImageLib/Filters/IRoberts.hpp"
#include "ImageLib/IThread.hpp"

namespace ImageLib::Filters
{

using ImageLib::IRunnable;
using ImageLib::IThread;

class Roberts :
	public IRoberts,
	public IRunnable
{
public:
	Roberts();
	~Roberts() override = default;

	// IRoberts
	void ProcessBitmap() override;

	void SetBitmap(
		IBitmap *bitmap) override;

	void RegisterProgressEventHandler(
		IProgressEventHandler *handler) override;
	void RegisterFilterControlEventHandler(
		IFilterControlEventHandler *handler) override;

    [[nodiscard]] std::string GetName() const override;

	// IRunnable
	void Run() override;

private:
	IBitmap *m_Bitmap;
	IProgressEventHandler *m_ProgressEventHandler;
	IFilterControlEventHandler *m_FilterControlEventHandler;
	IThread *m_Thread;
};

}

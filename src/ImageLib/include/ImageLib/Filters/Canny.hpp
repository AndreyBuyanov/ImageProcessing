#pragma once

#include "ImageLib/Filters/ICanny.hpp"
#include "ImageLib/IThread.hpp"

namespace ImageLib
{
namespace Filters
{

using ImageLib::IRunnable;
using ImageLib::IThread;

class Canny :
	public ICanny,
	public IRunnable
{
public:
	Canny();
	virtual ~Canny() {}

	// IFilter
	void ProcessBitmap() override;

	void SetBitmap(
		IBitmap *bitmap) override;

	void RegisterProgressEventHandler(
		IProgressEventHandler *handler) override;
	void RegisterFilterControlEventHandler(
		IFilterControlEventHandler *handler) override;

    string GetName() const override;

	// ICanny
	void SetSigma(
		const float sigma) override;

	void SetLowThreshold(
		const std::uint8_t lowThreshold) override;

	void SetHighThreshold(
		const std::uint8_t highThreshold) override;

	// IRunnable
	void Run() override;

private:
	IBitmap *m_Bitmap;
	IProgressEventHandler *m_ProgressEventHandler;
	IFilterControlEventHandler *m_FilterControlEventHandler;
	IThread *m_Thread;
	float m_Sigma;
	std::uint8_t m_LowThreshold;
	std::uint8_t m_HighThreshold;
};

}
}

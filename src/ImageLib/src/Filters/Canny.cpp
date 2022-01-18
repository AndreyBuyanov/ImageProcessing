#include "ImageLib/Filters/Canny.hpp"
#include "ImageLib/ImageLib.hpp"

#include <opencv2/imgproc.hpp>

namespace ImageLib::Filters
{

Canny::Canny() :
    m_Bitmap(nullptr),
    m_ProgressEventHandler(nullptr),
    m_FilterControlEventHandler(nullptr),
    m_Thread(CreateThread(this)),
    m_Sigma(1.0f),
    m_LowThreshold(30),
    m_HighThreshold(80) {}

void Canny::ProcessBitmap()
{
    m_Thread->Start();
}

void Canny::SetBitmap(
    IBitmap *bitmap)
{
    if (m_Thread->IsStopped()) {
        m_Bitmap = bitmap;
    }
}

void Canny::RegisterProgressEventHandler(
    IProgressEventHandler *handler)
{
    if (m_Thread->IsStopped()) {
        m_ProgressEventHandler = handler;
    }
}

void Canny::RegisterFilterControlEventHandler(
    IFilterControlEventHandler *handler)
{
    if (m_Thread->IsStopped()) {
        m_FilterControlEventHandler = handler;
    }
}

std::string Canny::GetName() const
{
    return "Canny";
}

void Canny::SetSigma(
    const float sigma)
{
    m_Sigma = sigma;
}

void Canny::SetLowThreshold(
    const std::uint8_t lowThreshold)
{
    m_LowThreshold = lowThreshold;
}

void Canny::SetHighThreshold(
    const std::uint8_t highThreshold)
{
    m_HighThreshold = highThreshold;
}

void Canny::Run()
{
    if (m_FilterControlEventHandler) {
        m_FilterControlEventHandler->FilterStarted();
    }

    if (m_Bitmap) {
        cv::Mat inputImage;
        cv::Mat inputView {
            static_cast<int>(m_Bitmap->Height()),
            static_cast<int>(m_Bitmap->Width()),
            CV_8UC4,
            m_Bitmap->Data() };
        cv::cvtColor(inputView, inputImage, cv::COLOR_BGRA2GRAY);
        cv::Mat blurredImage;
        cv::GaussianBlur(inputImage, blurredImage, cv::Size(3, 3), m_Sigma);
        cv::Mat cannyImage;
        cv::Canny(blurredImage, cannyImage, m_LowThreshold, m_HighThreshold);
        cv::cvtColor(cannyImage, inputView, cv::COLOR_GRAY2BGRA);
    }

    if (m_FilterControlEventHandler) {
        m_FilterControlEventHandler->FilterFinished();
    }
}

}

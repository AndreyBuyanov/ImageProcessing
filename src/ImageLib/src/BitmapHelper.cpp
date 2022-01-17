#include "ImageLib/BitmapHelper.hpp"

//#include <stdexcept>
#include <cstring>

namespace ImageLib
{

static void ExpandLine(
    std::size_t inputSize,
    const uint8_t* input,
    std::uint8_t* output)
{
    output[0] = input[0];
    std::memcpy(&output[1], input, inputSize * sizeof(std::uint8_t));
    output[inputSize + 1] = input[inputSize - 1];
}

std::unique_ptr<IBitmap> BitmapHelper::CreateEdgeHandledBitmap(
    const IBitmap* source)
{
    std::unique_ptr<IBitmap> result(CreateBitmap(
        source->Width() + 2,
        source->Height() + 2,
        source->Format()));

    std::uint32_t pixelSize = 1;
    if (BitmapFormat::RGBA == source->Format()) {
        pixelSize = 4;
    }

    std::size_t inputPosition = 0;
    std::size_t outputPosition = 0;
    ExpandLine(
        source->Width() * pixelSize,
        &source->Data()[inputPosition],
        &result->Data()[outputPosition]);
    for (std::size_t line = 0; line < source->Height(); line++)
    {
        inputPosition = line * source->Width() * pixelSize;
        outputPosition = (line + 1) * result->Width() * pixelSize;
        ExpandLine(
            source->Width() * pixelSize,
            &source->Data()[inputPosition],
            &result->Data()[outputPosition]);
    }
    inputPosition = (source->Height() - 1) * source->Width() * pixelSize;
    outputPosition = (result->Height() - 1) * result->Width() * pixelSize;
    ExpandLine(
        source->Width() * pixelSize,
        &source->Data()[inputPosition],
        &result->Data()[outputPosition]);
    
    return result;
}

std::size_t BitmapHelper::GetPixelPosition(
    const IBitmap* bitmap,
    std::uint32_t x,
    std::uint32_t y,
    std::uint32_t channel)
{
    /*if (x >= bitmap->Width() || y >= bitmap->Height()) {
        throw std::out_of_range("");
    }
    if ((BitmapFormat::Grayscale == bitmap->Format() && channel != 0)
        || (BitmapFormat::RGBA == bitmap->Format() && channel > 3))
    {
        throw std::runtime_error("");
    }*/
    std::uint32_t pixelSize = 1;
    if (BitmapFormat::RGBA == bitmap->Format()) {
        pixelSize = 4;
    }
    return (bitmap->Width() * y + x) * pixelSize + channel;
}

}

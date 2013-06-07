#include <Nebula/Stacker.hpp>
#include <gmock/gmock.h>
#include <boost/make_shared.hpp>
#include <Nebula/ImageReaderMock.hpp>
#include <Nebula/ImageWriterMock.hpp>
#include <Nebula/FrameCombinerFactoryMock.hpp>
#include <Nebula/FrameCombinerMock.hpp>

using namespace testing;

namespace Nebula
{

struct StackerTest : testing::Test
{
    StrictMock<ImageReaderMock> imageReader;
    StrictMock<ImageWriterMock> imageWriter;
    FrameCombinerMockPtr frameCombiner = boost::make_shared<StrictMock<FrameCombinerMock>>();
    StrictMock<FrameCombinerFactoryMock> frameCombinerFactory;
    Stacker stacker{imageReader, imageWriter, frameCombinerFactory};
    RawImage FRAME_1{2, 2, Color::luminance(1), 0};
    RawImage FRAME_2{2, 2, Color::luminance(2), 0};
    RawImage IMAGE{2, 2, Color::white(), 0};
    std::string FRAME_NAME_1 = "frame1.tif";
    std::string FRAME_NAME_2 = "frame2.tif";
    std::string OUTPUT_IMAGE_NAME = "out.tif";
};

TEST_F(StackerTest, shouldReadAndCombineAllFrames)
{
    EXPECT_CALL(imageReader, readImage(FRAME_NAME_1)).WillOnce(Return(FRAME_1));
    EXPECT_CALL(imageReader, readImage(FRAME_NAME_2)).WillOnce(Return(FRAME_2));

    stacker.setLightFrames({ FRAME_NAME_1, FRAME_NAME_2 });

    ExpectationSet addFrames;
    addFrames += EXPECT_CALL(*frameCombiner, addFrame(FRAME_1));
    addFrames += EXPECT_CALL(*frameCombiner, addFrame(FRAME_2));

    EXPECT_CALL(frameCombinerFactory, createFrameCombiner()).WillOnce(Return(frameCombiner));
    EXPECT_CALL(*frameCombiner, getCombinedFrame()).After(addFrames).WillOnce(Return(IMAGE));

    EXPECT_CALL(imageWriter, writeImage(OUTPUT_IMAGE_NAME, IMAGE));

    stacker.stack(OUTPUT_IMAGE_NAME);
}

}
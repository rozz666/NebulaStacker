#include <Nebula/Gui/EnvironmentFixture.hpp>
#include <Nebula/Gui/QFileDialogMock.hpp>
#include <Nebula/StarImageGenerator.hpp>
#include <Nebula/NoiseFrameGenerator.hpp>
#include <boost/range/algorithm.hpp>

using namespace testing;

namespace Nebula
{

EnvironmentFixture::EnvironmentFixture()
{
    QFileDialogMock::setUp();
}

EnvironmentFixture::~EnvironmentFixture()
{
    QFileDialogMock::tearDown();
}

void EnvironmentFixture::expectOpenFiles(Strings files)
{
    QStringList list;
    for (auto f : files)
        list.append(QString::fromUtf8(f.c_str()));
    EXPECT_CALL(QFileDialogMock::get(), getOpenFileNames(_, _, _, _, _, _))
        .WillOnce(Return(list));
}

void EnvironmentFixture::expectOpenFilesAndCancel()
{
    expectOpenFiles(Strings());
}

void EnvironmentFixture::expectSaveFile(std::string file)
{
    EXPECT_CALL(QFileDialogMock::get(), getSaveFileName(_, _, _, _, _, _))
        .WillOnce(Return(QString::fromUtf8(file.c_str())));
}

void EnvironmentFixture::expectSaveFileAndCancel()
{
    expectSaveFile("");
}

void EnvironmentFixture::assertFileExists(std::string file)
{
    ASSERT_TRUE(QFile(QString::fromUtf8(file.c_str())).exists()) << "File [" << file << "] does not exist";
    filesToRemove.add(file);
}

Strings EnvironmentFixture::generateLightFrames(unsigned int count)
{
    auto frame = StarImageGenerator(30, 20).withStars({ { 3, 7 }, { 2, 17 }, { 22, 11 } }).build();
    auto frames = NoiseFrameGenerator().from(frame).frames(count).withAmplitude(100).build();
    return frameFiles.writeFrames(frames);
}

}

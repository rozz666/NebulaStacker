#include <Nebula/Gui/EnvironmentFixture.hpp>
#include <Nebula/Gui/QFileDialogMock.hpp>

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

void EnvironmentFixture::expectOpenFiles()
{
    using namespace testing;
    EXPECT_CALL(QFileDialogMock::get(), getOpenFileNames(_, _, _, _, _, _))
        .WillOnce(Return(QStringList()));
}

}

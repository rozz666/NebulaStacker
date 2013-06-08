#ifndef NEBULA_QFILEDIALOGMOCK_HPP
#define NEBULA_QFILEDIALOGMOCK_HPP

#include <Nebula/Gui/QFileDialog.hpp>
#include <gmock/gmock.h>
#include <boost/shared_ptr.hpp>

namespace Nebula {

class QFileDialogMock : private QFileDialog
{
public:

    static void setUp();
    static void tearDown();
    static QFileDialogMock& get();

    MOCK_METHOD6(getOpenFileNames, QStringList(QWidget*, const QString&, const QString&, const QString&, QString*, Options));
    MOCK_METHOD6(getSaveFileName, QString(QWidget*, const QString&, const QString&, const QString&, QString*, Options));

private:

    typedef boost::shared_ptr<QFileDialogMock> MockPtr;
    static MockPtr mock;
};

}

#endif // NEBULA_QFILEDIALOGMOCK_HPP

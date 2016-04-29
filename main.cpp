#include <QLoggingCategory>
#include <QSysInfo>

#include <QDebug>

// http://doc.qt.io/qt-5/qsysinfo.html

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

#ifndef QT_NO_DEBUG_OUTPUT
    // Qt debug output is disabled on some systems, this reenables it at the project level.
    // https://bugzilla.redhat.com/show_bug.cgi?id=1227295
    QLoggingCategory::defaultCategory()->setEnabled(QtDebugMsg, true);
#endif

    qDebug() << "buildAbi : " << QSysInfo::buildAbi();
    qDebug() << "currentCpuArchitecture : " << QSysInfo::currentCpuArchitecture();
    qDebug() << "kernelType : " << QSysInfo::kernelType();
    qDebug() << "kernelVersion : " << QSysInfo::kernelVersion();
    qDebug() << "productType : " << QSysInfo::productType();
    qDebug() << "kernelType : " << QSysInfo::kernelType();
    qDebug() << "productVersion : " << QSysInfo::productVersion();

#ifdef Q_OS_MAC
    qDebug() << "macVersion : " << QSysInfo::macVersion();
    qDebug() << "machineHostName : " << QSysInfo::machineHostName();
#elif Q_OS_WIN
    qDebug() << "windowsVersion : " << QSysInfo::windowsVersion();
#endif

    return 0;
}

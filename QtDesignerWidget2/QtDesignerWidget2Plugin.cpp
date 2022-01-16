#include "QtDesignerWidget2.h"
#include "QtDesignerWidget2Plugin.h"

#include <QtCore/QtPlugin>

QtDesignerWidget2Plugin::QtDesignerWidget2Plugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void QtDesignerWidget2Plugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool QtDesignerWidget2Plugin::isInitialized() const
{
    return initialized;
}

QWidget *QtDesignerWidget2Plugin::createWidget(QWidget *parent)
{
    return new QtDesignerWidget2(parent);
}

QString QtDesignerWidget2Plugin::name() const
{
    return "QtDesignerWidget2";
}

QString QtDesignerWidget2Plugin::group() const
{
    return "My Plugins";
}

QIcon QtDesignerWidget2Plugin::icon() const
{
    return QIcon();
}

QString QtDesignerWidget2Plugin::toolTip() const
{
    return QString();
}

QString QtDesignerWidget2Plugin::whatsThis() const
{
    return QString();
}

bool QtDesignerWidget2Plugin::isContainer() const
{
    return false;
}

QString QtDesignerWidget2Plugin::domXml() const
{
    return "<widget class=\"QtDesignerWidget2\" name=\"QtDesignerWidget2\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QString QtDesignerWidget2Plugin::includeFile() const
{
    return "QtDesignerWidget2.h";
}

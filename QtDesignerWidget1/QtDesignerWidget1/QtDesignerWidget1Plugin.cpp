#include "QtDesignerWidget1.h"
#include "QtDesignerWidget1Plugin.h"

#include <QtCore/QtPlugin>

QtDesignerWidget1Plugin::QtDesignerWidget1Plugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void QtDesignerWidget1Plugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool QtDesignerWidget1Plugin::isInitialized() const
{
    return initialized;
}

QWidget *QtDesignerWidget1Plugin::createWidget(QWidget *parent)
{
    return new QtDesignerWidget1(parent);
}

QString QtDesignerWidget1Plugin::name() const
{
    return "QtDesignerWidget1";
}

QString QtDesignerWidget1Plugin::group() const
{
    return "My Plugins";
}

QIcon QtDesignerWidget1Plugin::icon() const
{
    return QIcon();
}

QString QtDesignerWidget1Plugin::toolTip() const
{
    return QString();
}

QString QtDesignerWidget1Plugin::whatsThis() const
{
    return QString();
}

bool QtDesignerWidget1Plugin::isContainer() const
{
    return false;
}

QString QtDesignerWidget1Plugin::domXml() const
{
    return "<widget class=\"QtDesignerWidget1\" name=\"QtDesignerWidget1\">\n"
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

QString QtDesignerWidget1Plugin::includeFile() const
{
    return "QtDesignerWidget1.h";
}

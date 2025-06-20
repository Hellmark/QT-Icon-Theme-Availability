/*#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    listIcons();
    return a.exec();
}*/


/*#include <QApplication>
#include <QListWidget>
#include <QIcon>
#include <QDirIterator>
#include <QHBoxLayout>
#include <QLabel>
#include <QStyle>
#include <QFileInfoList>
#include <QDebug>
#include <QSysInfo>

QStringList getAllIconNamesFromThemeDirs() {
    QStringList iconNames;
    QStringList iconDirs = QIcon::themeSearchPaths();
    QString themeName = QIcon::themeName();

    for (const QString &baseDir : iconDirs) {
        QDir themeDir(baseDir + "/" + themeName);
        if (!themeDir.exists()) continue;

        QDirIterator it(themeDir.absolutePath(), QStringList() << "*.svg" << "*.png", QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext()) {
            QString path = it.next();
            QFileInfo info(path);
            QString name = info.baseName();
            if (!iconNames.contains(name))
                iconNames << name;
        }
    }
    return iconNames;
}

void addStandardIcons(QListWidget* list) {
    QStyle* style = QApplication::style();
    QList<QStyle::StandardPixmap> icons = {
        QStyle::SP_TitleBarMenuButton,
        QStyle::SP_TitleBarMinButton,
        QStyle::SP_TitleBarMaxButton,
        QStyle::SP_TitleBarCloseButton,
        QStyle::SP_TitleBarNormalButton,
        QStyle::SP_DesktopIcon,
        QStyle::SP_TrashIcon,
        QStyle::SP_ComputerIcon,
        QStyle::SP_DriveHDIcon,
        QStyle::SP_DirHomeIcon,
        QStyle::SP_DirIcon,
        QStyle::SP_FileIcon,
        QStyle::SP_DialogOkButton,
        QStyle::SP_DialogCancelButton
    };

    for (QStyle::StandardPixmap pixmap : icons) {
        QIcon icon = style->standardIcon(pixmap);
        if (!icon.isNull()) {
            QString name = QString("SP_%1").arg(pixmap);
            QListWidgetItem* item = new QListWidgetItem(icon, name);
            list->addItem(item);
        }
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setApplicationName("Icon Browser");
    QApplication::setOrganizationName("ExampleOrg");

    if (QIcon::themeName().isEmpty()) {
#if defined(Q_OS_MAC)
        QIcon::setThemeName("macos"); // dummy value
#else
        QIcon::setThemeName("breeze");
#endif
    }

    QListWidget *listWidget = new QListWidget();
    listWidget->setViewMode(QListView::IconMode);
    listWidget->setResizeMode(QListView::Adjust);
    listWidget->setIconSize(QSize(64, 64));
    listWidget->setSpacing(10);

    // Add themed icons (Linux, optionally on macOS)
    QStringList iconNames = getAllIconNamesFromThemeDirs();
    iconNames.sort();

    for (const QString &iconName : iconNames) {
        QIcon icon = QIcon::fromTheme(iconName);
        if (!icon.isNull()) {
            QListWidgetItem *item = new QListWidgetItem(icon, iconName);
            listWidget->addItem(item);
        }
    }

    // Add fallback icons from QStyle (works on macOS too)
    addStandardIcons(listWidget);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);
    QLabel *label = new QLabel(QString("Found %1 icons").arg(listWidget->count()));
    layout->addWidget(label);
    layout->addWidget(listWidget);

    window.setWindowTitle("Available Icons in Theme (and System)");
    window.resize(800, 600);
    window.show();

    return app.exec();
}*/
/*
#include <QApplication>
#include <QListWidget>
#include <QStyle>
#include <QVBoxLayout>
#include <QLabel>
#include <QMap>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("QStyle Standard Icons");

    QVBoxLayout *layout = new QVBoxLayout(&window);
    QLabel *label = new QLabel("Available Standard Icons:");
    layout->addWidget(label);

    QListWidget *listWidget = new QListWidget();
    listWidget->setViewMode(QListView::IconMode);
    listWidget->setResizeMode(QListView::Adjust);
    listWidget->setIconSize(QSize(48, 48));
    listWidget->setSpacing(10);
    layout->addWidget(listWidget);

    QMap<QStyle::StandardPixmap, QString> iconNames = {
        {QStyle::SP_TitleBarMenuButton, "SP_TitleBarMenuButton"},
        {QStyle::SP_TitleBarMinButton, "SP_TitleBarMinButton"},
        {QStyle::SP_TitleBarMaxButton, "SP_TitleBarMaxButton"},
        {QStyle::SP_TitleBarCloseButton, "SP_TitleBarCloseButton"},
        {QStyle::SP_TitleBarNormalButton, "SP_TitleBarNormalButton"},
        {QStyle::SP_TitleBarShadeButton, "SP_TitleBarShadeButton"},
        {QStyle::SP_TitleBarUnshadeButton, "SP_TitleBarUnshadeButton"},
        {QStyle::SP_TitleBarContextHelpButton, "SP_TitleBarContextHelpButton"},
        {QStyle::SP_MessageBoxInformation, "SP_MessageBoxInformation"},
        {QStyle::SP_MessageBoxWarning, "SP_MessageBoxWarning"},
        {QStyle::SP_MessageBoxCritical, "SP_MessageBoxCritical"},
        {QStyle::SP_MessageBoxQuestion, "SP_MessageBoxQuestion"},
        {QStyle::SP_DesktopIcon, "SP_DesktopIcon"},
        {QStyle::SP_TrashIcon, "SP_TrashIcon"},
        {QStyle::SP_ComputerIcon, "SP_ComputerIcon"},
        {QStyle::SP_DriveFDIcon, "SP_DriveFDIcon"},
        {QStyle::SP_DriveHDIcon, "SP_DriveHDIcon"},
        {QStyle::SP_DriveCDIcon, "SP_DriveCDIcon"},
        {QStyle::SP_DriveDVDIcon, "SP_DriveDVDIcon"},
        {QStyle::SP_DriveNetIcon, "SP_DriveNetIcon"},
        {QStyle::SP_DirOpenIcon, "SP_DirOpenIcon"},
        {QStyle::SP_DirClosedIcon, "SP_DirClosedIcon"},
        {QStyle::SP_DirLinkIcon, "SP_DirLinkIcon"},
        {QStyle::SP_FileIcon, "SP_FileIcon"},
        {QStyle::SP_FileLinkIcon, "SP_FileLinkIcon"},
        {QStyle::SP_ToolBarHorizontalExtensionButton, "SP_ToolBarHorizontalExtensionButton"},
        {QStyle::SP_ToolBarVerticalExtensionButton, "SP_ToolBarVerticalExtensionButton"},
        {QStyle::SP_DialogOkButton, "SP_DialogOkButton"},
        {QStyle::SP_DialogCancelButton, "SP_DialogCancelButton"},
        {QStyle::SP_DialogHelpButton, "SP_DialogHelpButton"},
        {QStyle::SP_DialogOpenButton, "SP_DialogOpenButton"},
        {QStyle::SP_DialogSaveButton, "SP_DialogSaveButton"},
        {QStyle::SP_BrowserReload, "SP_BrowserReload"},
        {QStyle::SP_BrowserStop, "SP_BrowserStop"}
    };

    for (auto it = iconNames.begin(); it != iconNames.end(); ++it) {
        QIcon icon = QApplication::style()->standardIcon(it.key());
        if (!icon.isNull()) {
            QListWidgetItem *item = new QListWidgetItem(icon, it.value());
            listWidget->addItem(item);
        }
    }

    window.resize(800, 600);
    window.show();
    return app.exec();
}*/
/*
#include <QApplication>
#include <QListWidget>
#include <QStyle>
#include <QVBoxLayout>
#include <QLabel>
#include <QMap>
#include <QScrollArea>
#include <QGroupBox>
#include <QIcon>

void addStandardPixmapIcons(QListWidget* list) {
    QMap<QStyle::StandardPixmap, QString> iconNames = {
                                                       {QStyle::SP_TitleBarMenuButton, "SP_TitleBarMenuButton"},
                                                       {QStyle::SP_TitleBarMinButton, "SP_TitleBarMinButton"},
                                                       {QStyle::SP_TitleBarMaxButton, "SP_TitleBarMaxButton"},
                                                       {QStyle::SP_TitleBarCloseButton, "SP_TitleBarCloseButton"},
                                                       {QStyle::SP_TitleBarNormalButton, "SP_TitleBarNormalButton"},
                                                       {QStyle::SP_TitleBarShadeButton, "SP_TitleBarShadeButton"},
                                                       {QStyle::SP_TitleBarUnshadeButton, "SP_TitleBarUnshadeButton"},
                                                       {QStyle::SP_MessageBoxInformation, "SP_MessageBoxInformation"},
                                                       {QStyle::SP_MessageBoxWarning, "SP_MessageBoxWarning"},
                                                       {QStyle::SP_MessageBoxCritical, "SP_MessageBoxCritical"},
                                                       {QStyle::SP_MessageBoxQuestion, "SP_MessageBoxQuestion"},
                                                       {QStyle::SP_DesktopIcon, "SP_DesktopIcon"},
                                                       {QStyle::SP_TrashIcon, "SP_TrashIcon"},
                                                       {QStyle::SP_ComputerIcon, "SP_ComputerIcon"},
                                                       {QStyle::SP_DriveFDIcon, "SP_DriveFDIcon"},
                                                       {QStyle::SP_DriveHDIcon, "SP_DriveHDIcon"},
                                                       {QStyle::SP_DriveCDIcon, "SP_DriveCDIcon"},
                                                       {QStyle::SP_DriveDVDIcon, "SP_DriveDVDIcon"},
                                                       {QStyle::SP_DriveNetIcon, "SP_DriveNetIcon"},
                                                       {QStyle::SP_DirOpenIcon, "SP_DirOpenIcon"},
                                                       {QStyle::SP_DirClosedIcon, "SP_DirClosedIcon"},
                                                       {QStyle::SP_DirLinkIcon, "SP_DirLinkIcon"},
                                                       {QStyle::SP_FileIcon, "SP_FileIcon"},
                                                       {QStyle::SP_FileLinkIcon, "SP_FileLinkIcon"},
                                                       {QStyle::SP_DialogOkButton, "SP_DialogOkButton"},
                                                       {QStyle::SP_DialogCancelButton, "SP_DialogCancelButton"},
                                                       {QStyle::SP_DialogHelpButton, "SP_DialogHelpButton"},
                                                       {QStyle::SP_DialogOpenButton, "SP_DialogOpenButton"},
                                                       {QStyle::SP_DialogSaveButton, "SP_DialogSaveButton"},
                                                       {QStyle::SP_BrowserReload, "SP_BrowserReload"},
                                                       {QStyle::SP_BrowserStop, "SP_BrowserStop"},
                                                       };

    for (auto it = iconNames.begin(); it != iconNames.end(); ++it) {
        QIcon icon = QApplication::style()->standardIcon(it.key());
        if (!icon.isNull()) {
            QListWidgetItem* item = new QListWidgetItem(icon, it.value());
            list->addItem(item);
        }
    }
}

void addThemedIcons(QListWidget* list) {
    QStringList names = {
        "document-new", "document-open", "document-save", "document-save-as",
        "edit-undo", "edit-redo", "edit-cut", "edit-copy", "edit-paste",
        "edit-delete", "window-close", "application-exit", "folder", "folder-open",
        "folder-new", "view-refresh", "view-fullscreen", "media-playback-start",
        "media-playback-pause", "media-playback-stop", "help-about", "go-home",
        "system-search", "system-run", "edit-find", "user-home", "user-trash",
        "mail-send", "mail-forward", "mail-reply-sender", "mail-reply-all"
    };

    for (const QString& name : names) {
        QIcon icon = QIcon::fromTheme(name);
        if (!icon.isNull()) {
            QListWidgetItem* item = new QListWidgetItem(icon, name);
            list->addItem(item);
        }
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("All Available Icons");

    QVBoxLayout *mainLayout = new QVBoxLayout(&window);

    // --- StandardPixmap Icons ---
    QLabel* standardLabel = new QLabel("QStyle::StandardPixmap Icons:");
    QListWidget* standardList = new QListWidget();
    standardList->setViewMode(QListView::IconMode);
    standardList->setResizeMode(QListView::Adjust);
    standardList->setIconSize(QSize(48, 48));
    standardList->setSpacing(10);
    addStandardPixmapIcons(standardList);

    // --- Themed Icons ---
    QLabel* themedLabel = new QLabel("QIcon::fromTheme() Icons (if available):");
    QListWidget* themedList = new QListWidget();
    themedList->setViewMode(QListView::IconMode);
    themedList->setResizeMode(QListView::Adjust);
    themedList->setIconSize(QSize(48, 48));
    themedList->setSpacing(10);
    addThemedIcons(themedList);

    mainLayout->addWidget(standardLabel);
    mainLayout->addWidget(standardList);
    mainLayout->addWidget(themedLabel);
    mainLayout->addWidget(themedList);

    window.resize(900, 800);
    window.show();
    return app.exec();
}
*/

#include <QApplication>
#include <QListWidget>
#include <QStyle>
#include <QVBoxLayout>
#include <QLabel>
#include <QMap>
#include <QIcon>

void addStandardPixmapIcons(QListWidget* list) {
    QMap<QStyle::StandardPixmap, QString> iconNames = {
                                                       {QStyle::SP_TitleBarMenuButton, "SP_TitleBarMenuButton"},
                                                       {QStyle::SP_TitleBarMinButton, "SP_TitleBarMinButton"},
                                                       {QStyle::SP_TitleBarMaxButton, "SP_TitleBarMaxButton"},
                                                       {QStyle::SP_TitleBarCloseButton, "SP_TitleBarCloseButton"},
                                                       {QStyle::SP_TitleBarNormalButton, "SP_TitleBarNormalButton"},
                                                       {QStyle::SP_TitleBarShadeButton, "SP_TitleBarShadeButton"},
                                                       {QStyle::SP_TitleBarUnshadeButton, "SP_TitleBarUnshadeButton"},
                                                       {QStyle::SP_MessageBoxInformation, "SP_MessageBoxInformation"},
                                                       {QStyle::SP_MessageBoxWarning, "SP_MessageBoxWarning"},
                                                       {QStyle::SP_MessageBoxCritical, "SP_MessageBoxCritical"},
                                                       {QStyle::SP_MessageBoxQuestion, "SP_MessageBoxQuestion"},
                                                       {QStyle::SP_DesktopIcon, "SP_DesktopIcon"},
                                                       {QStyle::SP_TrashIcon, "SP_TrashIcon"},
                                                       {QStyle::SP_ComputerIcon, "SP_ComputerIcon"},
                                                       {QStyle::SP_DriveFDIcon, "SP_DriveFDIcon"},
                                                       {QStyle::SP_DriveHDIcon, "SP_DriveHDIcon"},
                                                       {QStyle::SP_DriveCDIcon, "SP_DriveCDIcon"},
                                                       {QStyle::SP_DriveDVDIcon, "SP_DriveDVDIcon"},
                                                       {QStyle::SP_DriveNetIcon, "SP_DriveNetIcon"},
                                                       {QStyle::SP_DirOpenIcon, "SP_DirOpenIcon"},
                                                       {QStyle::SP_DirClosedIcon, "SP_DirClosedIcon"},
                                                       {QStyle::SP_DirLinkIcon, "SP_DirLinkIcon"},
                                                       {QStyle::SP_FileIcon, "SP_FileIcon"},
                                                       {QStyle::SP_FileLinkIcon, "SP_FileLinkIcon"},
                                                       {QStyle::SP_DialogOkButton, "SP_DialogOkButton"},
                                                       {QStyle::SP_DialogCancelButton, "SP_DialogCancelButton"},
                                                       {QStyle::SP_DialogHelpButton, "SP_DialogHelpButton"},
                                                       {QStyle::SP_DialogOpenButton, "SP_DialogOpenButton"},
                                                       {QStyle::SP_DialogSaveButton, "SP_DialogSaveButton"},
                                                       {QStyle::SP_BrowserReload, "SP_BrowserReload"},
                                                       {QStyle::SP_BrowserStop, "SP_BrowserStop"},
                                                       };

    for (auto it = iconNames.begin(); it != iconNames.end(); ++it) {
        QIcon icon = QApplication::style()->standardIcon(it.key());
        if (!icon.isNull()) {
            QListWidgetItem* item = new QListWidgetItem(icon, it.value());
            list->addItem(item);
        }
    }
}

void addThemedIcons(QListWidget* list) {
    QStringList names = {
        "document-new", "document-open", "document-save", "document-save-as",
        "edit-undo", "edit-redo", "edit-cut", "edit-copy", "edit-paste",
        "edit-delete", "window-close", "application-exit", "folder", "folder-open",
        "folder-new", "view-refresh", "view-fullscreen", "media-playback-start",
        "media-playback-pause", "media-playback-stop", "help-about", "go-home",
        "system-search", "system-run", "edit-find", "user-home", "user-trash",
        "mail-send", "mail-forward", "mail-reply-sender", "mail-reply-all"
    };

    for (const QString& name : names) {
        QIcon icon = QIcon::fromTheme(name);
        if (!icon.isNull()) {
            QListWidgetItem* item = new QListWidgetItem(icon, name);
            list->addItem(item);
        }
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("All Available Icons");

    QVBoxLayout *mainLayout = new QVBoxLayout(&window);

    // --- StandardPixmap Icons ---
    QLabel* standardLabel = new QLabel("QStyle::StandardPixmap Icons:");
    QListWidget* standardList = new QListWidget();
    standardList->setViewMode(QListView::IconMode);
    standardList->setResizeMode(QListView::Adjust);
    standardList->setIconSize(QSize(48, 48));
    standardList->setSpacing(10);
    addStandardPixmapIcons(standardList);

    // --- Themed Icons ---
    QString themeName = QIcon::themeName();
    if (themeName.isEmpty()) themeName = "none";

    QLabel* themedLabel = new QLabel(QString("QIcon::fromTheme() Icons (Theme: \"%1\")").arg(themeName));
    QListWidget* themedList = new QListWidget();
    themedList->setViewMode(QListView::IconMode);
    themedList->setResizeMode(QListView::Adjust);
    themedList->setIconSize(QSize(48, 48));
    themedList->setSpacing(10);
    addThemedIcons(themedList);

    // Add all to layout
    mainLayout->addWidget(standardLabel);
    mainLayout->addWidget(standardList);
    mainLayout->addWidget(themedLabel);
    mainLayout->addWidget(themedList);

    window.resize(900, 800);
    window.show();
    return app.exec();
}

#include <QApplication>
#include <QListWidget>
#include <QStyle>
#include <QVBoxLayout>
#include <QLabel>
#include <QMap>
#include <QIcon>

void addStandardPixmapIcons(QListWidget* list) {
    QMap<QStyle::StandardPixmap, QString> iconNames = {
        {QStyle::SP_TitleBarMinButton, "SP_TitleBarMinButton"},
        {QStyle::SP_TitleBarMenuButton, "SP_TitleBarMenuButton"},
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
        {QStyle::SP_DirHomeIcon, "SP_DirHomeIcon"},
        {QStyle::SP_DirOpenIcon, "SP_DirOpenIcon"},
        {QStyle::SP_DirClosedIcon, "SP_DirClosedIcon"},
        {QStyle::SP_DirIcon, "SP_DirIcon"},
        {QStyle::SP_DirLinkIcon, "SP_DirLinkIcon"},
        {QStyle::SP_DirLinkOpenIcon, "SP_DirLinkOpenIcon"},
        {QStyle::SP_FileIcon, "SP_FileIcon"},
        {QStyle::SP_FileLinkIcon, "SP_FileLinkIcon"},
        {QStyle::SP_FileDialogStart, "SP_FileDialogStart"},
        {QStyle::SP_FileDialogEnd, "SP_FileDialogEnd"},
        {QStyle::SP_FileDialogToParent, "SP_FileDialogToParent"},
        {QStyle::SP_FileDialogNewFolder, "SP_FileDialogNewFolder"},
        {QStyle::SP_FileDialogDetailedView, "SP_FileDialogDetailedView"},
        {QStyle::SP_FileDialogInfoView, "SP_FileDialogInfoView"},
        {QStyle::SP_FileDialogContentsView, "SP_FileDialogContentsView"},
        {QStyle::SP_FileDialogListView, "SP_FileDialogListView"},
        {QStyle::SP_FileDialogBack, "SP_FileDialogBack"},
        {QStyle::SP_DockWidgetCloseButton, "SP_DockWidgetCloseButton"},
        {QStyle::SP_ToolBarHorizontalExtensionButton, "SP_ToolBarHorizontalExtensionButton"},
        {QStyle::SP_ToolBarVerticalExtensionButton, "SP_ToolBarVerticalExtensionButton"},
        {QStyle::SP_DialogOkButton, "SP_DialogOkButton"},
        {QStyle::SP_DialogCancelButton, "SP_DialogCancelButton"},
        {QStyle::SP_DialogHelpButton, "SP_DialogHelpButton"},
        {QStyle::SP_DialogOpenButton, "SP_DialogOpenButton"},
        {QStyle::SP_DialogSaveButton, "SP_DialogSaveButton"},
        {QStyle::SP_DialogCloseButton, "SP_DialogCloseButton"},
        {QStyle::SP_DialogApplyButton, "SP_DialogApplyButton"},
        {QStyle::SP_DialogResetButton, "SP_DialogResetButton"},
        {QStyle::SP_DialogDiscardButton, "SP_DialogDiscardButton"},
        {QStyle::SP_DialogYesButton, "SP_DialogYesButton"},
        {QStyle::SP_DialogNoButton, "SP_DialogNoButton"},
        {QStyle::SP_ArrowUp, "SP_ArrowUp"},
        {QStyle::SP_ArrowDown, "SP_ArrowDown"},
        {QStyle::SP_ArrowLeft, "SP_ArrowLeft"},
        {QStyle::SP_ArrowRight, "SP_ArrowRight"},
        {QStyle::SP_ArrowBack, "SP_ArrowBack"},
        {QStyle::SP_ArrowForward, "SP_ArrowForward"},
        {QStyle::SP_CommandLink, "SP_CommandLink"},
        {QStyle::SP_VistaShield, "SP_VistaShield"},
        {QStyle::SP_BrowserReload, "SP_BrowserReload"},
        {QStyle::SP_BrowserStop, "SP_BrowserStop"},
        {QStyle::SP_MediaPlay, "SP_MediaPlay"},
        {QStyle::SP_MediaStop, "SP_MediaStop"},
        {QStyle::SP_MediaPause, "SP_MediaPause"},
        {QStyle::SP_MediaSkipForward, "SP_MediaSkipForward"},
        {QStyle::SP_MediaSkipBackward, "SP_MediaSkipBackward"},
        {QStyle::SP_MediaSeekForward, "SP_MediaSeekForward"},
        {QStyle::SP_MediaSeekBackward, "SP_MediaSeekBackward"},
        {QStyle::SP_MediaVolume, "SP_MediaVolume"},
        {QStyle::SP_MediaVolumeMuted, "SP_MediaVolumeMuted"},
        {QStyle::SP_LineEditClearButton, "SP_LineEditClearButton"},
        {QStyle::SP_CustomBase, "SP_CustomBase"},
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
        "address-book-new", "application-exit", "appointment-new", "call-start",
        "call-stop", "contact-new", "document-new", "document-open", "document-open-recent",
        "document-page-setup", "document-print", "document-print-preview", "document-properties",
        "document-revert", "document-save", "document-save-as", "document-send",
        "edit-clear", "edit-copy", "edit-cut", "edit-delete", "edit-find",
        "edit-find-replace", "edit-paste", "edit-redo", "edit-select-all",
        "edit-undo", "folder-new", "format-indent-less", "format-indent-more",
        "format-justify-center", "format-justify-fill", "format-justify-left", "format-justify-right",
        "format-text-direction-ltr", "format-text-direction-rtl", "format-text-bold", "format-text-italic",
        "format-text-underline", "format-text-strikethrough", "go-bottom", "go-down", "go-first",
        "go-home", "go-jump", "go-last", "go-next", "go-previous",
        "go-top", "go-up", "help-about", "help-contents",
        "help-faq", "insert-image", "insert-link", "insert-object",
        "insert-text", "list-add", "list-remove", "mail-forward",
        "mail-mark-important", "mail-mark-junk", "mail-mark-notjunk", "mail-mark-read",
        "mail-mark-unread", "mail-message-new", "mail-reply-all", "mail-reply-sender",
        "mail-send", "mail-send-receive", "media-eject", "media-playback-pause",
        "media-playback-start", "media-playback-stop", "media-record", "media-seek-backward",
        "media-seek-forward", "media-skip-backward", "media-skip-forward", "object-flip-horizontal",
        "object-flip-vertical", "object-rotate-left", "object-rotate-right", "process-stop",
        "system-lock-screen", "system-log-out", "system-run", "system-search",
        "system-reboot", "system-shutdown", "tools-check-spelling", "view-fullscreen",
        "view-refresh", "view-restore", "view-sort-ascending", "view-sort-descending",
        "window-close", "window-new", "zoom-fit-best", "zoom-in",
        "zoom-original","zoom-out", "process-working", "accessories-calculator",
        "accessories-character-map", "accessories-dictionary", "accessories-text-editor", "help-browser",
        "multimedia-volume-control", "preferences-desktop-accessibility", "preferences-desktop-font", "preferences-desktop-keyboard",
        "preferences-desktop-locale", "preferences-desktop-multimedia", "preferences-desktop-screensaver", "preferences-desktop-theme",
        "preferences-desktop-wallpaper", "system-file-manager", "system-software-install", "system-software-update",
        "utilities-system-monitor", "utilities-terminal", "applications-accessories", "applications-development",
        "applications-engineering", "applications-games", "applications-graphics", "applications-internet",
        "applications-multimedia", "applications-office", "applications-other", "applications-science",
        "applications-system", "applications-utilities", "preferences-desktop", "preferences-desktop-peripherals",
        "preferences-desktop-personal", "preferences-other", "preferences-system", "preferences-system-network",
        "system-help", "audio-card", "audio-input-microphone", "battery",
        "camera-photo", "camera-video", "camera-web", "computer",
        "drive-harddisk", "drive-optical", "drive-removable-media", "input-gaming",
        "input-keyboard", "input-mouse", "input-tablet", "media-flash",
        "media-floppy", "media-optical", "media-tape", "modem",
        "multimedia-player", "network-wired", "network-wireless", "pda",
        "phone", "printer", "scanner", "video-display", "emblem-default",
        "emblem-documents", "emblem-downloads", "emblem-favorite", "emblem-important",
        "emblem-mail", "emblem-photos", "emblem-readonly", "emblem-shared",
        "emblem-symbolic-link", "emblem-synchronized", "emblem-system", "emblem-unreadable",
        "face-angel", "face-angry", "face-cool", "face-crying",
        "face-devilish", "face-embarrassed", "face-kiss", "face-laugh",
        "face-monkey", "face-plain", "face-raspberry", "face-sad",
        "face-sick", "face-smile", "face-smile-big", "face-smirk",
        "face-surprise", "face-tired", "face-uncertain", "face-wink",
        "face-worried", "flag-aa", "application-x-executable", "audio-x-generic",
        "font-x-generic", "image-x-generic", "package-x-generic", "text-html",
        "text-x-generic", "text-x-generic-template", "text-x-script", "video-x-generic",
        "x-office-address-book", "x-office-calendar", "x-office-document", "x-office-presentation",
        "x-office-spreadsheet", "folder", "folder-remote", "network-server",
        "network-workgroup", "start-here", "user-bookmarks", "user-desktop",
        "user-home", "user-trash", "appointment-missed", "appointment-soon",
        "audio-volume-high", "audio-volume-low", "audio-volume-medium", "audio-volume-muted",
        "battery-caution", "battery-low", "dialog-error", "dialog-information",
        "dialog-password", "dialog-question", "dialog-warning", "folder-drag-accept",
        "folder-open", "folder-visiting", "image-loading", "image-missing",
        "mail-attachment", "mail-unread", "mail-read", "mail-replied",
        "mail-signed", "mail-signed-verified", "media-playlist-repeat", "media-playlist-shuffle",
        "network-error", "network-idle", "network-offline", "network-receive",
        "network-transmit", "network-transmit-receive", "printer-error", "printer-printing",
        "security-high", "security-medium", "security-low", "software-update-available",
        "software-update-urgent", "sync-error", "sync-synchronizing", "task-due",
        "task-past-due", "user-available", "user-away", "user-idle",
        "user-offline", "user-trash-full", "weather-clear", "weather-clear-night",
        "weather-few-clouds", "weather-few-clouds-night", "weather-fog", "weather-overcast",
        "weather-severe-alert", "weather-showers", "weather-showers-scattered", "weather-snow",
        "weather-storm"
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
